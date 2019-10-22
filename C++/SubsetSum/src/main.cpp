#include "SubsetSum.hpp"

int main(void) {
	std::cout << "Subset Sum - Divide and Conquer" << std::endl;
	Set set(new int[8]{3,5,3,9,18,4,5,6}, 8);
	SubsetSum sumEngine(set, 28);
	return 0;
}