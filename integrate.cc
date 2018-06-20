#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double function(double x)
{
	x = pow(x, 2);
	return x;
}

int main()
{
	int subdivisions;
	double rangestart = 1;
	double rangeend = 4;
	double partitions;
	double begsum = 0;
	double midsum = 0;
	double endsum = 0;
	double trap = 0;
	
	cout << "Enter the beginning of your range: "; cin >> rangestart;
	cout << "Enter the end of your range: "; cin >> rangeend;
	cout << "Enter the amount of subdivisions: "; cin >> subdivisions;
	
	partitions = (rangeend - rangestart) / (double)subdivisions;
	
	if (rangestart >= rangeend or subdivisions < 1)
	{
		cout << "Sorry, that is an invalid range or amount of subdivisions." << endl;
		return 0;
	}
	
	/*
	//incorrect because of double precision errors
	for (double i = rangestart; i < rangeend; i = i + partitions)
	{
		begsum = begsum + function(i) * partitions;
		midsum = midsum + function(i + 0.5*partitions) * partitions;
		endsum = endsum + function(i + partitions) * partitions;
		trap = trap + partitions * (function(i) + function(i + partitions)) / 2;
	}
	*/
	
	for (int i = 0; i < subdivisions; i++)
	{
		begsum = begsum + function(rangestart + i * partitions) * partitions ;
		midsum = midsum + function(rangestart + i * partitions + 0.5*partitions) * partitions;
		endsum = endsum + function(rangestart + i * partitions + partitions) * partitions;
		trap = trap + partitions * (function(rangestart + i * partitions) + function(rangestart + (i+1) * partitions)) / 2;
	}
	
	cout << "\nEstimating using the first value in the interval: " << begsum << endl;
	cout << "Estimating using the middle value in the interval: " << midsum << endl;
	cout << "Estimating using the end value in the interval: " << endsum << endl;
	cout << "Estimating using the trapezoidal rule: " << trap << endl;
}
