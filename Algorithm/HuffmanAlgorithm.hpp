//HuffmanAlgorithm.hpp
#pragma once
#ifndef HUFFMAN_HPP_INCLUDED
#define HUFFMAN_HPP_INCLUDED

namespace huffman {
#include "stdafx.hpp"
	struct HuffmanNode              //Huffman
	{
	private:
		int data;

	public:
		//constructor
		HuffmanNode * left, *right, *parent;
		HuffmanNode() :left(NULL), right(NULL), parent(NULL), data(-1) {}
		HuffmanNode(int d) :left(NULL), right(NULL), parent(NULL), data(d) {}

		//reload operator
		HuffmanNode &operator=(const HuffmanNode& hn)
		{
			left = hn.left;
			right = hn.right;
			data = hn.data;
			return *this;
		}

		int GetData()const { return data; }                        //get data
		bool SetData(int d) { data = d; return true; }      //set data
	};

	const int DefaultSize = 100;

	class MinHeap
	{
		HuffmanNode * heap;
		int szCurrent;

	public:
		MinHeap(int sz = DefaultSize);
		~MinHeap()
		{
			delete[] heap;
		}

		void CreateMinHeap(int arr[], int n);        //数组构建最小堆
		bool Insert(HuffmanNode * e);               //往堆中插入Huffman节点
		void SiftDown(int start, int m);             //下滑，重建最小堆
		void SiftUp(int start, int m);                   //上滑，在插入的时候用到
		HuffmanNode * GetMinNode();             //获取Huffman节点data值最小的节点，同时维护szCurrent
		bool SwapNode(int i, int j);                     //交换下标为i和j的Huffman节点
		void Print();                                           //打印Huffman节点
	};


	int HuffmanCompression(int argc, char* argv[]);
}

#endif // !HUFFMAN_HPP_INCLUDED