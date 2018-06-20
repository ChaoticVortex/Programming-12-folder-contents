#include <iostream>
#include <cstring>
using namespace std;




int main()
{
	char* array[];
	int x;
	for (x=0; x< 64; x++)
	{
		array[x] = new char[256];
		strncpy(array[x], "Hello", 255);
		printf("%d: %s\n",x , array[x]);
	}
	
	for (int x=0; x<64, x++)
	{
		delete[] array[x];
	}
	return 0;
}
