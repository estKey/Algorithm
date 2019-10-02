#ifndef GRAPH_HPP
#define GRAPH_HPP "GRAPH_HPP"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "MinHeap.hpp"

#define MAX_BUFFER_SIZE 2048

using std::cout, std::cin, std::endl, std::string;

enum State {Unvisted, Visited};

template <typename T>
class Graph
{
public:
    string filename;
private:
    int m_nSize;
    T **m_gMatrix;
public:
    Graph()
    {
        
    }
    Graph(string filename)
    {
        cout << "Creating Craph Instance, Source: " << filename << endl;
        Graph::filename = filename;
        T **m_gMatrix = ExtractMatrix();
    }
    void PrintGraph(T** map, int length, int width)
    {
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < length; j++)
               cout << map[i][j] << " ";
            cout << endl;
        }
    }
    int GetSize() {return m_nSize;}
    T **GetMatrix() {return m_gMatrix;}
private:
    T **ExtractMatrix()
    {
        std::ifstream infile;
        T** m_gMatrix;
        std::stringstream stream;
        char buffer[MAX_BUFFER_SIZE];
        int lineCounter = 0;
        cout << "Opening File " << filename << endl;
        infile.open(filename, std::ios::in);
        if (!infile.is_open())
        {
            cout << "Open File Failed." << endl;
            return NULL;
        }
        while (!infile.eof())
        {
            infile.getline(buffer, sizeof(buffer));
            if (!lineCounter)
            {
                stream << buffer;
                stream >> m_nSize;
                m_gMatrix = new int* [m_nSize];
                for (int i = 0; i < m_nSize; i++)
                {
                    m_gMatrix[i] = new int[m_nSize];
                }
            }
            else
            {
                string line = buffer;
                int i = 0;
                while (!line.empty())
                {
                    if (line.find(" ") == string::npos)
                    {
                        m_gMatrix[lineCounter - 1][i] = (std::stoi(line));
                        line.clear();
                        break;
                    }
                    string s_temp = line.substr(0, line.find(" "));
                    m_gMatrix[lineCounter - 1][i] = (std::stoi(line));
                    line.erase(0, line.find(" ") + 1);
                    i++;
                }
            }
            lineCounter++;
        }
        infile.close();
        cout << "Extraction Complete, Matrix Size: " << m_nSize << endl;
        return m_gMatrix;
    }
};

#endif // !GRAPH_HPP
//DIJKSTRA_HPP
