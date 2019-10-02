#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP "DIJKSTRA_HPP"

#include <iostream>
#include <fstream>
#include <string>
#include "Graph.hpp"
#include "MinHeap.hpp"

#define INF 0 // since the dijkstra can only be positive, we pick 0 to be the infinity, or the weight of the starting points

using std::cout, std::cin, std::endl, std::string;

template <typename T>
class Dijkstra
{
public:
    /* data */
private:
    Graph<T> m_gMap;
    int *m_gShortestPath;
public:
    Dijkstra(string filename)
    {
        cout << "Dijkstra Algorithm\n";
        m_gMap = Graph<T>(filename);
    }
    ~Dijkstra()
    {

    }
    int *GetShortestPath() {return m_gShortestPath;}
    int *General()
    {
        cout << "General Method\n";
        int n = m_gMap.GetSize();
        int *ShortestPath = new int[n];
        m_gShortestPath = ShortestPath;
        T *Visited = new T[n];
        return ShortestPath;
    }
    int *HeapOptimize()
    {
        cout << "Heap Optimized\n";
        int *ShortestPath = new int[m_gMap.GetSize()];
        m_gShortestPath = ShortestPath;
        return ShortestPath;
    }
private:
};

#endif // !DIJKSTRA_HPP
