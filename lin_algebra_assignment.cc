// Mr. Arkiletian ICTP 12
// Simultaneous linear equation assignment (2 team members)
// Solved using the STL generic vector container class 
// Benny Wong and Leo Sim

#include <iostream>
#include <vector>
#include <cmath> // for pow function
#include <string>
#include <ctime>
#include <map>

using namespace std;

typedef vector <double> Dvector;
typedef vector <Dvector> Dmatrix;

map <Dmatrix, double> DETS;

// Prototypes (variable names included, but not needed)
// DO NOT change any prototypes!! NO other functions allowed.

Dmatrix GetA(); 
// gets the matrix A from the user and returns it

Dvector Getb(const int &siz); 
// gets the vector b from the user and returns it

void Display(const Dvector &xvect);
// displays the contents of vector xvect


void Display(const Dmatrix &Amat);
// displays the contents of matrix Amat (Note: Display function is overloaded)

Dvector Solvex(const Dmatrix &Amat, const Dvector &bvect);
// Solves for systems of linear equations in the form Ax=b using cramer's rule 


double Det(const Dmatrix &Amat);
// returns the Determinant of matrix Amat using a recursive algorithm
// base case is 2x2 matrix 

Dmatrix Replace(Dmatrix Rmat, const int col, const Dvector &bvect);
// Replaces the column 'col' in Rmat with bvect and returns Rmat


Dmatrix Minor(const Dmatrix &Amat, const int col);
// Gets the Minor matrix of Amat by crossing out the first row and 
// column 'col' then returns that smaller matrix


//-------------------------------------------
int main(){
clock_t begin = clock();

Dmatrix A;     
Dvector b,x;

A=GetA();
Display(A);
b=Getb(A.size());
Display(b);
x=Solvex(A,b);
Display(x);

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "This code took " << elapsed_secs << "seconds" << cout;
return(0);
}
//-------------------------------------------

Dmatrix GetA()
{
	int size;
	double temp;
	cin >> size;
	Dmatrix A;
	Dvector row(size);
	
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cin >> temp;
			row[j] = temp;
		}
		A.push_back(row);
	}
	return A;
}

Dvector Getb(const int &siz){
	double temp;
	Dvector B(siz);
	
	for (int i = 0; i < siz; i++){
		cin >> temp;
		B[i] = temp;
	}
	return B;
}
void Display(const Dvector &xvect)
{
	cout << endl << '[' << ' ';
	for (unsigned i = 0; i < xvect.size(); i++)
		cout << xvect[i] << ' ';
	cout << ']' << ' ';
}

void Display(const Dmatrix &Amat)
{
	cout << endl;
	for (unsigned i = 0; i < Amat.size(); i++)
	{
		Display(Amat[i]);
	}
	cout << endl;
}

Dvector Solvex(const Dmatrix &Amat, const Dvector &bvect){
	Dvector detAx;
	double detA = Det(Amat);
	for (unsigned i = 0; i < bvect.size(); i++){
		detAx.push_back(Det(Replace(Amat, i, bvect)) / detA);
	}
	return detAx;
	
}

double Det(const Dmatrix &Amat){
	double sum = 0;
	if (DETS.find(Amat) == DETS.end()){
		if (Amat.size() == 2)
			sum = Amat[0][0] * Amat[1][1] - Amat[0][1] * Amat[1][0];
		else{
			for (unsigned c = 0; c < Amat.size(); c++){
				sum += pow(-1.0, (double) c) * Amat[0][c] * Det(Minor(Amat, c));
			}
		}
		DETS[Amat] = sum;
	}
	else
		sum = DETS[Amat];
	return sum;
}

Dmatrix Replace(Dmatrix Rmat, const int col, const Dvector &bvect)
{
	for (unsigned i = 0; i < Rmat.size(); i++)
		Rmat[i][col] = bvect[i];
	return Rmat;
}

Dmatrix Minor(const Dmatrix &Amat, const int col)
{
	Dmatrix min;
	for (unsigned i = 1; i < Amat.size(); i++)
		min.push_back(Amat[i]);
	for (unsigned i = 0; i < min.size(); i++)
		min[i].erase(min[i].begin() + col);
	return min;
}
