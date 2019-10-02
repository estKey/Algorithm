#include "Dijkstra.hpp"

int main(void) {
	cout << "CMPE 365 Assignment 1\n";
	string filenames[] = {"Dijkstra_Data_6.txt"};
	Dijkstra<int> DijkstraEngine(filenames[0]);
	DijkstraEngine.General();
	cout << "Done. Press any Key to continue\n";
	while(getchar() != '\n');
	return 0;
}