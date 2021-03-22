#include <string>

class Graph {
private:
    int size;
    int** matrix;
    
    int** initialize_matrix(int size) {
        int** new_matrix = (int**) calloc(size, sizeof(int*) * size);
        
        for (int i = 0; i < size; i++) {
            new_matrix[i] = (int*) calloc(size, sizeof(int));
            
            for(int j = 0; j < size; j++) {
                new_matrix[i][j] = 0;
            }
        }
        
        return new_matrix;
    }
    
    void copy_matrix(int** destination, int** origin) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                destination[i][j] = origin[i][j];
            }
        }
    }
    
public:
    Graph(int size) {
        this->size = size;
        this->matrix = initialize_matrix(size);
    }
    
    Graph(Graph* g) {
        this->size = g->size;
        this->matrix = initialize_matrix(size);
        copy_matrix(matrix, g->matrix);
    }
    
    void set_matrix_value(int i, int j, int value) {
        matrix[i][j] = value;
    }
    
    void link_vertices(int origin, int destination) {
        if (origin == destination) {
            return;
        }
        
        set_matrix_value(origin, destination, 1);
        set_matrix_value(destination, origin, 1);
    }
    
    void unlink_vertices(int origin, int destination) {
        if (origin == destination) {
            return;
        }
        
        set_matrix_value(origin, destination, 0);
        set_matrix_value(destination, origin, 0);
    }
    
    void debug() {
        for (int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                int value = matrix[i][j];
                
                std::cout << value;
                std::cout << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    };
    
    void print_all_vertices() {
        for (int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if (i > j) {
                    continue;
                }
                
                int value = matrix[i][j];
                if (value == 1) {
                    std::cout << "Vértice (";
                    std::cout << i;
                    std::cout << ", ";
                    std::cout << j;
                    std::cout << ")\n";
                }
            }
        }
    }
    
    bool contains(int value, int length, int list[]) {
        bool contains = false;
        
        for (int i = 0; i < length; i++) {
            if (list[i] == value) {
                contains = true;
                break;
            }
        }
        
        return contains;
    }
    
    int count_bridges() {
        int count = 0;
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int value = matrix[i][j];
                
                if (i >= j) {
                    continue;
                }
                
                if (value == 1) {
                    Graph* g = new Graph(this);
                    g->unlink_vertices(i, j);

                    
                    if (g->count_connections() != size - 1) {
                        std::cout << "Ponte encontrada: ";
                        std::cout << "(";
                        std::cout << i;
                        std::cout << ", ";
                        std::cout << j;
                        std::cout << ")\n";
                        count++;
                    };
                }
            }
        }
        
        return count;
    }
    
    int count_connections() {
        int list[size];
        int* index = (int*)malloc(sizeof(int*));
        *index = 0;
        
        travel(0, 0, list, index);
        
        return *index - 1;
    }
    
    void travel (int row, int col, int list[], int* index) {
        for (int i = 0; i < size; i++) {
            int value = matrix[row][i];
            
            if (value == 1) {
                matrix[row][i] = 0;
                matrix[i][row] = 0;
                bool isInList = contains(i, *index, list);
                
                if (*index == 0) {
                    list[*index] = row;
                    (*index)++;
                }
                
                if (!isInList) {
                    list[*index] = i;
                    (*index)++;
                    
                    travel(i, 0, list, index);
                }
            }
        }
    }
};
