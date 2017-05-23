/*
 * Compute the sum of all elements of 2D array with good cache usage.
 * Complexity: O(n^2)
 */

#include <iostream>
#include <string>
#include <vector>


int main (int argc, char *argv[])
{
	unsigned int size(3000); // 34MB memory!

	// read parameters if specified
	try
	{
		if(argc > 1)
			size = std::stoi(argv[1]);
	}
	catch(...)
	{
		std::cerr << "Usage: " << argv[0] << " <size>\n";
		exit(1);
	}

	std::vector<std::vector<int>> a(size, std::vector<int>(size, 4));
	int sum=0;

	for(unsigned int i=0; i<size; i++)
	{
		for(unsigned int j=0; j<size; j++)
		{
			sum += a[i][j];
		}
	}
}
