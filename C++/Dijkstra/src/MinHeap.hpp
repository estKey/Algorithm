
#ifndef MINHEAP_HPP
#define MINHEAP_HPP "MINHEAP_HPP"

#include <iostream>

#define LEFT(i) (i*2 + 1)
#define RIGHT(i) (LEFT(i) + 1) 

using std::cout, std::cin, std::endl;

///<summary>
///@Array Heap<>
///<summary>
template <typename T>
class MinHeap
{
public:
    /* data */
private:
    int m_nSize;
    int m_nNum;
    T *m_gHeap;
public:
    MinHeap(int m_nSize)
    {
        cout << "Creating Min Heap Instance, Initial Size: " << m_nSize << endl;
        MinHeap::m_nSize= m_nSize;
        m_gHeap = new int[m_nSize];
    }
    T& Top() {return m_gHeap[0];}
    void Push()
    {

    }
    T& Pop()
    {

    }
    int GetSize() {return m_nSize;}
private:
    void Up()
    {

    }
    void Down()
    {

    }
    void Swap(int ifirst, int isecond)
    {
        T& temp = m_gHeap[ifirst];
        m_gHeap[ifirst] = m_gHeap[isecond];
        m_gHeap[isecond] = temp;
    }
};

#endif