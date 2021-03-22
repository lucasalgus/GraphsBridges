#include<iostream>

#include "Graph.h"

int main() {
    Graph* g = new Graph(11);
    
    g->link_vertices(0, 2);
    g->link_vertices(0, 3);
    
    g->link_vertices(1, 8);
    
    g->link_vertices(2, 0);
    g->link_vertices(2, 8);
    g->link_vertices(2, 3);
    
    g->link_vertices(3, 8);
    g->link_vertices(3, 0);
    g->link_vertices(3, 2);
    
    g->link_vertices(4, 9);
    g->link_vertices(4, 7);
    g->link_vertices(4, 10);
    
    g->link_vertices(5, 9);
    g->link_vertices(5, 6);
    
    g->link_vertices(6, 5);
    g->link_vertices(6, 9);
    
    g->link_vertices(7, 4);
    g->link_vertices(7, 10);
    
    g->link_vertices(8, 1);
    g->link_vertices(8, 2);
    g->link_vertices(8, 3);
    g->link_vertices(8, 10);
    
    g->link_vertices(9, 6);
    g->link_vertices(9, 5);
    g->link_vertices(9, 4);
    
    g->link_vertices(10, 8);
    g->link_vertices(10, 4);
    g->link_vertices(10, 7);
    
    int count = g->count_bridges();
    
    std::cout << "Pontes: ";
    std::cout << count;
    
    return 0;
}
