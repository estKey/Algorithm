#ifndef SUBSET_SUM_HPP
#define SUBSET_SUM_HPP "SUBSET_SUM_HPP"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using std::cout, std::endl, std::vector, std::string;


class Set
{
private:
    int m_nSum;
    vector<int> m_gElements;
public:
    Set() : m_nSum(0) {}
    Set(const int a[], int size)
    {
        m_gElements = vector<int>(a, a + size);
        Sum();
    }
    Set(int n, int floor, int ceil)
    {
        Generate(n, floor, ceil);
        Sum();
    }
    Set(const Set &s) {Append(s);}
    Set(const Set &s, int v) {Append(s); Append(v);}
    ~Set()
    {
        delete &m_nSum;
        delete &m_gElements;
    }
    void Generate(int n, int floor, int ceil)
    {
        int range = floor + ceil + 1;
        srand((unsigned)time(0));
        for (int i = 0; i < n; i++)
            m_gElements.push_back(rand()%(range) - floor);
    }
    void Append(int v)
    {
        m_gElements.push_back(v);
    }
    void Append(const Set & s)
    {
		for (auto iter =s.m_gElements.cbegin(); iter != s.m_gElements.cend(); iter++)
			m_gElements.push_back(*iter);
        Sum();
    }
    int GetSum() {return int(m_nSum);}
    vector<int> GetElements() {return vector<int>(m_gElements);}
    int GetSize() {return m_gElements.size();}
    int operator[](int i) {return m_gElements[i];} 
    void PrintElements()
    {
        
    }
private:
    void Sum()
    {
        m_nSum = 0;
		for (auto iter = m_gElements.cbegin(); iter != m_gElements.cend(); iter++)
			m_nSum += (*iter);
    }
};


class SubsetSum
{
private:
    int m_nTarget;
    Set m_gSet;
public:
    SubsetSum(const Set set, int target)
    {
        m_nTarget = target;
        m_gSet = Set(set);
    }
    ~SubsetSum()
    {
        delete &m_nTarget;
        delete &m_gSet;
    }
    Set BFI()
    {
        vector<Set> subsets;
        Set rslt;
        subsets.push_back(Set());
        for (int i = 0; i < m_gSet.GetSize(); i++)
        {
            vector<Set> new_subsets;
            for (auto old_u = subsets.cbegin(); old_u != subsets.cend(); old_u++)
            {
                Set new_u(*old_u, m_gSet[i]);
                if (new_u.GetSum() == m_nTarget)
                    return new_u;
                else
                {
                    new_subsets.push_back(*old_u);
                    new_subsets.push_back(new_u);
                }
                subsets = new_subsets;
            }
        }
        return rslt;
    }
    Set HS()
    {

        Set subset;
        return subset;
    }
private:
    int BinarySearch()
    {
        return 1;
    }
    int *PairSum(vector<int> v1, vector<int> v2, int k)
    {
        int p1 = 1, p2 = v2.size();
        while (p1 <= v1.size() && p2 >= 1)
        {
            int t = v1[p1] + v2[p2];
            if (t == k) return new int[2]{p1, p2};
            else if (t < k) p1++;
            else p2--;
        }
        return new int[2]{-1, -1};
    }
};


#endif // !SUBSET_SUM_HPP