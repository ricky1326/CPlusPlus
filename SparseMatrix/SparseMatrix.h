#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

#include "LinkedList.h"

template<class T>
class SparseMatrix{
	private:
		int numCols;
		int numRows;
		
		LinkedList<T> *List;
		

	public:
		SparseMatrix();
		//~SparseMatrix();
		void read();
		void print();
		void mask(SparseMatrix<bool> mask, SparseMatrix<int> result);
		int getNumRows();
		int getNumCols();
		void setRows(int rows);
		void setCols(int cols);
		void setList(LinkedList<T>* newList);
		LinkedList<T>* getMatrix();

};

template<class T>
SparseMatrix<T>::SparseMatrix(){

}

/*template<class T>
SparseMatrix<T>::~SparseMatrix(){
	delete SparseMatrix<T>*;
}*/


template<class T>
void SparseMatrix<T>::read(){
	
	cout<<"Please enter number of rows and columns"<<endl;
	string dimensions;
    getline(cin,dimensions);
    string dimensionsArr[2];
    int i = 0;
    stringstream ssin(dimensions);
    while (ssin.good() && i < 2){
        ssin >> dimensionsArr[i];
        ++i;
    }
	numRows = atoi(dimensionsArr[0].c_str());
    numCols = atoi(dimensionsArr[1].c_str());
	//cout << "number of rows = "<<numRows<<endl;
    //cout <<"number of columns = "<< numCols<<endl;




	if(numRows < 0 || numCols < 0){
		cout<<"invalid dimensions"<<endl;
		return;
	}

	List = new LinkedList<T>[numRows];
	

	for(int rowAt = 0; rowAt < numRows; rowAt++){
		int numTerms;
		string terms;
		
		
		
		cout<<"Enter number of terms in row " << rowAt+1<<endl;
		cin>>numTerms;
		cin.ignore();
		if(numTerms == 0){
			continue;
		}

		if(numTerms <0 || numTerms > numRows){
			cout<<"Invalid entry, moving onto next row"<<endl;
		
			continue;

		}
		string *termsArr[numTerms*2];
		for(int j = 0; j< numTerms*2; j++){
        	termsArr[j] = new string();
        	//cout<<"hola"<<endl;
    	}
		
		cout<<"Enter element's column, and value of each term in row "<<rowAt+1<<endl;
		int data;
		int index; 
		getline(cin,terms);
		//cout<<"your terms are: "<<terms<<endl;
	

       	for(int i = 0; i<numTerms*2; i++){
       		int k=0;
       		while(k < terms.length()){
       			//cout<<"you are at "<<terms.at(k)<<endl;
       			if(terms.at(k) == ' '){
       				i++;
       			}
       			termsArr[i] -> push_back(terms.at(k));
       			k ++;
       		}
       	}
       			
		for(int i = 0; i<numTerms*2; i++){
    		//cout<<"terms["<<i<<"]= "<< *termsArr[i]<<endl;
    		

    		bool isData = false;
    		while(!isData){
    			if(i%2 != 0){
    				isData = true;
    				data = atoi(termsArr[i]->c_str());
    				//List[i].addNode(index,data);
    			}

    			else{
    				index = atoi(termsArr[i]->c_str());

    				i++;
    			}
    		}
    		//cout<<"your i value is "<<i<<endl;	
    		//cout<<"index = "<< index <<endl;
    		//cout<< "data = " <<data <<endl;
    		if(index > numCols || index <0){
    			cout<<"Invalid column index, moving onto next row"<<endl;
    			continue;
    		}
    		List[rowAt].addNode(index,data);
			//List[k].printList();
    		//isData = false;

    	}
    	//cout<<"this row is "<<rowAt<<endl;
    	//List[rowAt].printList();
    	
    		
    	
    	//cout <<"you are now in row "<<rowAt<< endl;
    

    	//List[i].addNode(index,data);
    	//List[i].printList();

		

	}


}

template<class T>
void SparseMatrix<T>::print(){
	cout<<'\n';
	//cout<<"Printing Matrix"<<endl;
	cout<<"rows = "<<numRows<<" columns = "<<numCols<<endl;
	for(int i=0; i<numRows; i++){
		cout<<"row "<<i+1<<"[ ";
		List[i].printList();
		//cout<<"]";
	}
}

template<class T>
/*SparseMatrix<int>*/ void SparseMatrix<T>::mask(SparseMatrix<bool> mask, SparseMatrix<int> result){
	int bRows;
	int bCols;
	int aRows;
	int aCols;
	int cRows;
	int cCols;
	LinkedList<bool> *MaskMatrix;
	LinkedList<int> *resultMatrix;
	LinkedList<int> *intMatrix;

	//SparseMatrix<int>* c =new SparseMatrix<int>();

	bRows = mask.getNumRows();
	bCols = mask.getNumCols();
	aRows = getNumRows();
	aCols = getNumCols();
	result.setRows(aRows);
	result.setCols(aCols);
	cRows = result.getNumRows();
	cCols = result.getNumCols();

	//cout<<"cRows = "<<cRows<<endl;
	//cout<<"cCols = "<<cCols<<endl;
	
	intMatrix = getMatrix();
	MaskMatrix = mask.getMatrix();

	resultMatrix = new LinkedList<int>[cRows];


	if (bRows != aRows || bCols != aCols){
		cout<<"Matrix A and B are not of the same diemension"<<endl;
		return ;
	}

	else{
		cout<<'\n'<<"Masked Matrix"<<endl;
		cout<<"rows = " <<cRows << " Cols = "<<cCols<<endl;
		for(int i=0; i< aRows; i++){
			//cout<<"In row: "<< i+1<<endl;
			cout<<"row "<< i +1<<"[ ";
			resultMatrix[i] = intMatrix[i].compareLists(MaskMatrix[i],resultMatrix[i]);
		}
	}

	result.setList(resultMatrix);

	//c = &result;
	//return result;



}
template<class T>
int SparseMatrix<T>::getNumRows(){
	return numRows;

	}

template<class T>
int SparseMatrix<T>::getNumCols(){
	return numCols;
	}
template<class T>	
void SparseMatrix<T>::setRows(int rows){
	
	numRows = rows;
	
}
template<class T>	
void SparseMatrix<T>::setCols(int cols){
	
	numCols = cols;

	
}

template<class T>
void SparseMatrix<T>::setList(LinkedList<T>* newList){
	List = newList;
}


template<class T>
LinkedList<T>* SparseMatrix<T>::getMatrix(){
	return List;
}
#endif
