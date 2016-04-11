#include <iostream>

using namespace std;

int main(){
	cout<<"Please Enter Size of Magic Square:"<<endl;
	int n;
	cin>>n;
	cout<< "ONE MAGIC SQUARE FOR A " <<n<< "x" <<n<< " SQUARE IS" <<endl;
	
	//array is created
	int magic[n+1][n+1];
	
	
	int size = n;
	//If the user inputs an invalid size the program will quit and user will have to try again.
	if(size > 15){
		cout<<"INVALID SIZE!!! your number was larger than 15. Please enter an odd number between 3 & 15"<<endl;
			
	}
	else if(size > 15 && size % 2 == 0){
		cout<<"INVALID SIZE!!! your number was larger than 15 and even. Please enter an odd number between 3 & 15"<<endl;

	}

	else if(size < 3){
		cout<<"INVALID ENTRY!!! your number was smaller than 3. Please enter an odd number between 3 & 15"<<endl;

	}
	else if(size < 3 && size % 2 == 0){
		cout<<"INVALID SIZE!!! your number was smaller than 3 and even. Please enter an odd number between 3 & 15"<<endl;

	}
	else if (size % 2 == 0){
		cout<<"INVALID ENTRY!!! your number was between 3 and 15 BUT was even. Please enter an ODD number between 3 & 15"<<endl;

	}
		//magic square is constructed.
		else{
			for(int i=1; i<n+1;i++){
				for(int j=1; j<n+1; j++){
					 //algorithm found on wikipedia
					 magic[i][j] = (n*((i+j-1+((n/2)))%n))+(((i+(2*j)-2)%n)+1);
					
					//prints each number in the array using the algoritm above					
					cout<<magic[i][j]<<"\t";
					
				}
				cout<<"\n";
			}

			//Computes the sum of the columns to verify this is a magic square
			int i = 1;
			int j = 1;
			int colSum = 0;
			cout<<"\n";
			for(int  a = 1; a <n+1; a++){
				for(int b = 1; b <n+1; b++){
				
				i=b;
				colSum = colSum + magic[i][j];
					
					if(b==n && a==1){
						cout<<"CHECKING THE SUMS OF THE COLUMNS: "<<endl;
						cout<<colSum<<"\t";
						colSum = 0;

					}
					else if (b==n && a !=1){	
						cout<<colSum<<"\t";
						colSum = 0;
					}
				}
			}
			
			//Computes rows to verify that this is a magic square
			i = 1;
			j = 1;
			int rowSum=0;
			cout<<"\n";
			for(int c = 1; c<n+1; c++){
				for(int d = 1; d<n+1; d++){
					
					j=d;
					rowSum = rowSum + magic[i][j];
					if(d==n && c==1){
						cout<<"CHECKING THE SUMS OF THE ROWS: "<<endl;
						cout<< rowSum<< "\t";
						rowSum = 0;
					}
					
					if(d==n && c !=1){	
						cout<<rowSum<<"\t";
						rowSum = 0;
						
					}	
				}
			}

			//computes the sum of the first diagonal
			i=0;
			j=1;
			cout<<"\n";
			int diagSum1 = 0;
			for(int e=1; e<n+1; e++){
				j=e;
				i=i+1;
				diagSum1 = diagSum1 + magic[i][j];
				if(e==n){
				cout<<"CHECKING THE SUMS OF THE DIAGONALS: "<<endl;
				cout<<diagSum1<<"\t";
				}
			}
			//computes the sum for the second diagonal
			i=n+1;
			j=1;
			int diagSum2 = 0;
			for(int f=1; f<n+1; f++){
				j=f;
				i=i-1;
				diagSum2 = diagSum2 + magic[i][j];
				if(f==n){
				cout<<diagSum2<<endl;
				}
			}
		}
}