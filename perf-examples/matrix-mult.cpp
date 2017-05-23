/*
 * Matrix multiplication with good cache locality usage.
 * Complexity: O(n^3)
 */

#include <iostream>
#include <string>
#include <vector>


int main (int argc, char *argv[])
{
	unsigned int size(100);

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

	//std::cout << "testing matrix multiplication with size=" << size << "\n";

	std::vector<std::vector<int>> m1(size, std::vector<int>(size, 3));
	std::vector<std::vector<int>> m2(size, std::vector<int>(size, 4));
	std::vector<std::vector<int>> res(size, std::vector<int>(size, 0));

	for(unsigned int i=0; i<size; i++)
	{
		for(unsigned int j=0; j<size; j++)
		{
			int sum = 0;
			for(unsigned int k=0; k<size; k++)
			{
				sum += m1[j][k] * m2[k][j];
			}
			res[i][j] = sum;
		}
	}
	
	// print result
	/*
	for (unsigned int i=0; i<size; i++) 
	{
		for (unsigned int j=0; j<size; j++)
		{
			std::cout << res[i][j] << " ";
		}
		std::cout << "\n";
	}
	*/
}
