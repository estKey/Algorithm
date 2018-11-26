// main.cpp
// @Author EstKey
// @
#include "stdafx.hpp"
void ui(int argc, char* argv[]);

/// <summary>
///Main
/// </summary>
/// <param name="argc, argv">handle the instance of the main entry</param>
int main(int argc, char* argv[])
{
	// UI start
	ui(argc, argv);
	printf("Compiled Successfully\n");
	while (getchar() != '\n');
	return 0;
}

void ui(int argc, char* argv[])
{
	printf("\\\***Welcom to Algorithms Study***///\n");
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	do 
	{
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		int input;
		printf("Please Select an Algorithm to Test or Enter -1 to Leave this Program\n");
		printf("[1] Sorting Algorithm\t[2]Huffman Algorithm\n");
		scanf("%d", &input);
		switch (input)
		{
		case -1: return;
		case 1:
			system("cls");
			sort::SortingAlgorithm(argc, argv);
			break;
		case 2:
			system("cls");
			huffman::HuffmanCompression(argc, argv);
			break;
		default:
			printf("Invalid Input, Press Enter to Select Again or Press e to Exit\n");
			getchar();
			if (getchar() == 'e') return;
		}
		system("cls");
	} while (1);
}