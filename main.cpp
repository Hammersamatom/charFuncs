#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

char newMes[] = {"The quick brown fox jumps over the lazy dog"};

// Takes a pointer as an input and reads the contents, then writes a defined range to the substr pointer. 
char *charSubstr(char *input, long start, long end)
{
	long length = end - start;
	char *substr = new char[length];
	memcpy(substr, input+start, length);
	return substr;
}

char *charCycle(char *input, long count)
{
	long length = std::strlen(input);

	// Error checking.
	if (count > length)
	{
		count = length;		
	}

	char *catstr = new char[length];
	char *partb = charSubstr(input, 0, length - count);
	char *parta = charSubstr(input, length - count, length);
	strcat(catstr, parta);
	strcat(catstr, partb);

	return catstr;
}

int main(int argc, char *argv[])
{
	printf("%s%s\n",charSubstr(newMes, 0, 5), charSubstr(newMes,5,std::strlen(newMes)));
	cout << charCycle(newMes, atoi(argv[1])) << endl;
}
