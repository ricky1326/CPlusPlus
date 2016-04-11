#include "SparseMatrix.h"
#include "LinkedList.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib> 

using namespace std;

int main(){
	SparseMatrix<int>* a = new SparseMatrix<int>();
	SparseMatrix<bool>* b = new SparseMatrix<bool>();
	SparseMatrix<int>* c =new SparseMatrix<int>();
	
	cout<<"Reading Matrix A:"<<endl;
	a->read();
	cout<<"Matrix A:"<<endl;
	a->print();
	cout<<"Reading Matrix B:"<<endl;
	b->read();
	cout<<"Matrix B, the boolean mask matrix:"<<endl;
	b->print();
	a->mask(*b,*c);
	
	//here i could not get c to point to my resulting matrix for some reason. 
	c->print();








}