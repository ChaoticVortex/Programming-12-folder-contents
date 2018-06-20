#include <iostream>
#include <unistd.h>

int main(){
	int x;
	x = 1;

	int y,z;

	double d = 3.14;
	while (true){
		usleep(10000);
		std::cin >> x;
		std::cout << x << std::endl;
	}
}
