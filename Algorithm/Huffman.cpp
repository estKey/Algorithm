#include "Huffman.hpp"

namespace huffman {
	int HuffmanCompression(int argc, char* argv[])
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		return 0;
	}
}