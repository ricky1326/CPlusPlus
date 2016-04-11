#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;



/*void parse(string command){
	//LinkedList<int> x = LinkedList<int>();
	char func = command.at(0);
    
	
		
		
		if(func == 'S'){
			cout<<"printing list"<< '\n';

			x.PrintList();

		}

		else if (func == 'I'){
			cout << "Hello there here is your command: "<< command<<endl;
			int num;
			int index;
			string arr[3];
			int i = 0;
			stringstream ssin(command);
			while(ssin.good() && i<3){
				ssin >> arr[i];
				i++;

			}
			for(i = 0; i < 3; i++){
        		cout << arr[i] << endl;
    		}
			num = atoi(arr[1].c_str()); //int value = atoi(myString.c_str());
			index = atoi(arr[2].c_str());
			cout<<"num = "<<num<<endl;
			cout<<"index = "<< index<<endl;

			
			x.InsertNode(num,index);
			x.PrintList();

		}


		
		else if (func == 'D'){
			int index;
			string arr[2];
			int i = 0;
			stringstream ssin(command);
			while(ssin.good() && i<2){
				ssin >> arr[i];
				i++;
			}
			index = atoi(arr[1].c_str()); //int value = atoi(myString.c_str());
			

			
			x.DeleteNode(index);
			x.PrintList();

		}

		else if(func == 'P'){
			int index;
			string arr[2];
			int i = 0;
			stringstream ssin(command);
			while(ssin.good() && i<2){
				ssin >> arr[i];
				i++;
			}
			index = atoi(arr[1].c_str()); //int value = atoi(myString.c_str());
			

			
			x.PrintNode(index);
			x.PrintList();

		}
		else if(func == 'J'){

		}

		else {
			cout<<"error: invalid command.";
		}


}*/

template<class T>
void LinkedList<T>::josephus(int k){
	PrintList();
	curr = head;
	temp = NULL;
	
	while(size != 1){
		for(int i =0; i != k-1; i++){
			//cout<<"hello there"<<endl;
			temp = curr;
			curr = curr->next;
		}

		/*if (curr == head){
			cout<<"Hi"<<endl;
			curr-> next = head;
			cout<< "node deleted: "<< curr->data<<endl;
			delete curr;
			return;
		}*/

		temp ->next = curr -> next; 
		//cout<< "data: "<< temp->data<<endl;
		cout <<  curr -> data<< ' ';
		delete curr;
		temp = temp->next;
		curr = temp;
		size--;
		//cout << "The size of your list is " << size<<endl;
		//cout<<"The next node is: "<< temp -> data<< endl;
		if(temp -> next == NULL){
			temp -> next = head;
		}
		if(size == 1){
			head = temp;
			//return;
		}

	}

	cout << "The winner is: "<<temp->data<<endl;

}




template <class T>
LinkedList<T>::LinkedList(){
	head  = NULL;
	curr = NULL;
	temp = NULL;
	size = 0;

}
template <class T>
LinkedList<T>::~LinkedList(){
	curr = head;
	temp = head;
	int x =0;
	int y = size;
	while(x <y){
		temp = temp ->next;
		delete curr;
		curr = temp;
		x++;
		size--;
		
	
	}
	PrintList();
	cout << size << '\n';
	cout<<"your list is deleted"<<"\n";
}

template <class T>
void LinkedList<T>::AddNode(T addData){
	nodePtr n = new node();
	n ->data = addData;
	n -> next = NULL;
	if(head == NULL){
		head=n;
		n -> next = head;
		
		size++;
		return;
	}
	int x = 0;
	temp = head;
	
	while(x < size -1){
		temp = temp -> next;
		x++;
	}

	temp -> next = n;
	n -> next = head;
	size++;
}

template <class T>
void LinkedList<T>::InsertNode(T addData, int k){
	if (k > size+1){
		cout<< "The place you chose to add your node is not possible. Please choose a place between 1 and "<< size+1 << '\n';
		return;
	}
	nodePtr n = new node();
	n -> data = addData;
	n -> next = NULL;

	if (k == 1){
		n ->next = head;
		head = n;
		size++;
		return;

	}

	

	temp  = head;
	for (int i = 0; i < k-2; i++){
		temp = temp -> next;
	}
	n -> next = temp -> next;
	temp -> next = n;
	size++;
	if (k == size){
		n -> next = head;
	}
}

template <class T>
void LinkedList<T>::DeleteNode(int k){
	if(head == NULL){
		cout << "Your list is already empty" << '\n';
		return;
	}
	curr = head;
	temp = NULL;
	int x = 0;
	

	if(k == 1){
		head = head -> next;
		temp = head;
		delete curr;
		size --;
		
		while (x< size -1){
			temp = temp-> next;
			x++;
		}
		temp ->next = head;
		return;
	}

	if (k == size){
		for(int i =0; i<k-1; i++){
		temp = curr;
		curr = curr->next;
		}
		temp -> next = head;
		cout << "node deleted "<< curr -> data<< "\n";
		delete curr;
		size--;
		return;	
	}

	
	for(int i =0; i<k-1; i++){
		temp = curr;
		curr = curr->next;
	}

	temp ->next = curr -> next; 
	cout << "node deleted "<< curr -> data<< "\n";
	delete curr;
	size--;
}

template <class T>
void LinkedList<T>::PrintList(){
	if(size == 0){
		cout<< "your list is empty" << '\n';
		return;
	}
	int k = 0;
	temp = head;
	while(k < size){
		cout<< temp -> data<< " ";
		temp = temp->next;
		k++;
	}

	cout<<"\n";
	cout<<"the head of your list is "<< head -> data << '\n';
}

template <class T>
int LinkedList<T>::Size(){
	cout<< "the size of your list is "<< size<< "\n";
	return size;
}

template <class T>
void LinkedList<T>::PrintNode(int k){
	curr = head;
	for(int i = 0; i < k-1; i++){
		curr = curr -> next;
		
	}

	cout << curr->data << "\n";
	curr = curr ->next;
	cout<< "This node points to "<< curr -> data<< "\n";
	cout<< "the head of your list is "<< head -> data<< "\n"; 
}

int main (){
	cout<< "Welcome"<<'\n';
	cout<<"Please ender a command in the form of the following"<<'\n';
	cout<<"​I n i => Insert element n at the ith position"<<'\n';
	cout<<" D i => Delete the element at the ith position"<<'\n';
	cout<<"​S => Print entire List sequentially"<<'\n';
	cout<<"​P i => Print the element at the ith position"<<'\n'<< '\n';
	cout<<"J n k 9 13 7 => Simulate the Josephus problem" << '\n';

	LinkedList<int> x = LinkedList<int>();
	string hi;
	int numOfLines = 0;
	cin >> numOfLines;
	getline(cin,hi);

	//cout<<'\n';
	//cout<< "numOfLines= " << numOfLines<<endl;


	while (numOfLines > 0){
		//cout<< "numOfLines= " << numOfLines<<endl;

		string command;
		cout <<"Please enter your command"<<endl;
		getline(cin,command);
		char func = command.at(0);
    
	
		
		
		if(func == 'S'){
			cout<<"printing list"<< '\n';

			x.PrintList();

		}

		else if (func == 'I'){
			//cout << "Hello there here is your command: "<< command<<endl;
			int num;
			int index;
			string arr[3];
			int i = 0;
			stringstream ssin(command);
			while(ssin.good() && i<3){
				ssin >> arr[i];
				i++;

			}
			/*for(i = 0; i < 3; i++){
        		arr[i];
    		}*/
			num = atoi(arr[1].c_str()); //int value = atoi(myString.c_str());
			index = atoi(arr[2].c_str());
			//cout<<"num = "<<num<<endl;
			//cout<<"index = "<< index<<endl;

			
			x.InsertNode(num,index);
			//x.PrintList();

		}


		
		else if (func == 'D'){
			int index;
			string arr[2];
			int i = 0;
			stringstream stream(command);
			while(stream.good() && i<2){
				stream >> arr[i];
				i++;
			}
			index = atoi(arr[1].c_str()); //int value = atoi(myString.c_str());
			

			
			x.DeleteNode(index);
			x.PrintList();

		}

		else if(func == 'P'){
			int index;
			string arr[2];
			int i = 0;
			stringstream ssin(command);
			while(ssin.good() && i<2){
				ssin >> arr[i];
				i++;
			}
			index = atoi(arr[1].c_str()); //int value = atoi(myString.c_str());
			

			
			x.PrintNode(index);
			x.PrintList();

		}
		else if(func == 'J'){
			int k;
			int numsEntered;
			int num;
			int i = 0;
			
			string arr[256];
			stringstream ssin(command);
			while(ssin.good() && i<256){
				ssin >> arr[i];
				i++;
			}
			numsEntered = atoi(arr[1].c_str());
			//cout<<"numsEntered: "<< numsEntered<<endl;

			k = atoi(arr[1].c_str());
			for(int j = 0; j < numsEntered; j++){
				num = atoi(arr[3+j].c_str());
				cout<< "num: "<< num<<endl;
				x.InsertNode(num,1);

			}

			x.josephus(k);
			
			

		}

		else {
			cout<<"error: invalid command.";
		}

		numOfLines --;

		//cout << numOfLines<<endl;


}

/*LinkedList<int> n = LinkedList<int>();
	n.AddNode(1);
	n.AddNode(2);
	n.AddNode(3);
	n.AddNode(4);
	n.AddNode(5);
	n.AddNode(6);
	n.AddNode(7);
	n.AddNode(8);
	n.AddNode(9);
	n.AddNode(10);
	n.josephus(2);*/


	}


	
//}



	
