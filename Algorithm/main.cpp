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
	do 
	{
		int input;
		printf("Please Select an Algorithm to Test\n");
		scanf("%d", &input);
		switch (input)
		{
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
		}
		getchar();
		if (getchar() == 'e')
			break;
		system("cls");
	} while (1);
}