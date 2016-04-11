#ifndef LIST_H
#define LIST_H
using namespace std;
template <class T>
class LinkedList{
	private: 
		struct node{
			T data;
			int col;
			
			node* next;

		};
		int size;

		bool isEmpty;

		typedef struct node* nodePtr;

		/*nodePtr head;
		nodePtr curr;
		nodePtr temp;*/

	public:
		nodePtr head;
		nodePtr curr;
		nodePtr temp;
		LinkedList();
		//~LinkedList();
		void addNode(int atCol, T addData);
		void printList();
		void printNode(int k);
		int getSize();
		/*getHead(){
			return head;
		}
		node* getCurr(){
			return curr;
		}*/

		LinkedList<int> compareLists(LinkedList<bool>, LinkedList<int>);

	
		
};

template <class T>
LinkedList<T>::LinkedList(){
	head  = NULL;
	curr = NULL;
	temp = NULL;
	size = 0;

}

/*template <class T>
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
	
	cout << size << '\n';
	cout<<"your list is deleted"<<"\n";
}*/

template<class T>
void LinkedList<T>::addNode(int atCol, T addData){
	nodePtr n = new node();
	n -> data = addData;
	n->  col = atCol;
	n -> next = 0;

	

	if(head == 0){
		n -> next = head;
		head = n;
		//size++;
		//return;

	}
	else{
		curr = head;
		/*while(curr -> col < n -> col){
			temp = curr;
			curr = curr ->next;
		}*/

		while(curr != 0){
			if (curr ->col >= n->col){
				break;
			}
			else{
				temp = curr;
				curr = curr ->next;
			}
		}
		if (curr == head){
			n ->next = head;
			head = n;
		}

		else{
			n->next = curr;
			temp->next = n;
		}

		//temp -> next = n;
		//n-> next = curr;
	}
	size++;
}

template <class T>
void LinkedList<T>::printList(){
	if(head == 0){
		//cout<< "your list is empty" << '\n';
		cout<<"]";
		cout<<"\n";
		return;
	}
	
	temp = head;
	while(temp != 0){
		//cout<<"hello"<<endl;
		//cout<< temp -> data<< " ";
		cout<<"col:"<< temp->col<<" val= "<<temp->data<<", ";
		temp = temp->next;
		
	}
	cout<<"]";
	cout<<"\n";
	//cout<<"the head of your list is "<< head -> data << '\n';
}

template <class T>
void LinkedList<T>::printNode(int k){
	curr = head;
	for(int i = 0; i < k-1; i++){
		curr = curr -> next;
		
	}

	cout << curr->data << "\n";
	curr = curr ->next;
	if(curr == 0){
		cout<<"this node points to NULL"<<endl;
	}
	else{
		cout<< "This node points to "<< curr -> data<< "\n";
	}
	cout<< "the head of your list is "<< head -> data<< "\n"; 
}

template<class T>
LinkedList<int> LinkedList<T>::compareLists(LinkedList<bool> b, LinkedList<int> c ){

	int bSize = b.getSize();
	int aSize = getSize();

	/*node *bHead = b.getHead();
	node *bCurr = b.getCurr();*/

	//cout<<"aSize = " <<aSize<<endl; 
	//cout<<"bSize = "<<bSize<<endl;

	curr = head;
	b.curr = b.head;
	int i=0;
	int j=0;

	if(head == NULL || b.head == NULL){
		//cout<<"EMPTY ROW"<<endl;
		c.printList();
		return c;
	}

	//cout<<"your current data is " <<b.curr->data<<endl;
	while(i<aSize && j<bSize /*curr->next != NULL && b.curr ->next != NULL*/){
	//while(!(curr-> col > b.curr ->col)){
		if(curr -> col == b.curr ->col){
			//cout<<"Adding node "<<curr->data<<endl;
			c.addNode(curr->col, curr->data);
		}

		if(curr->next == NULL){
			while(!(b.curr ->col > curr -> col) && b.curr->next != NULL){
				b.curr = b.curr ->next;
				if(curr -> col == b.curr -> col){
					c.addNode(curr -> col, curr -> data);
				}

				//j++;
			}
			c.printList();

			return c;
			//break;
		}


		else if(b.curr -> next == NULL){
			//cout<<"NEXT NODE IS NULL"<<endl;
			while(!(curr->col > b.curr->col) && curr->next != NULL){
				//cout<<"MOVING NODE"<<endl;
				curr = curr ->next;
				
				if(curr -> col == b.curr -> col){
					//cout<<"ADDING NODE: "<<curr -> data <<endl;
					c.addNode(curr -> col, curr -> data);
				}
				
				//cout<<"i == "<<i<<endl;
				c.printList();


			}
			return c;
			//break;
		}

		else{
			curr = curr ->next;
			b.curr = b.curr ->next;
			//cout<<"PRINTING LIST"<<endl;
			c.printList();
			i++;
			j++;
			//cout<<"i = "<<i<<endl;
			//cout<<"j = "<<j<<endl;
		}
	}
	
	//cout<<"exit loop"<<endl;
	c.printList();
	//cout<<"RETURNING LIST"<<endl;
	return c;

}

template<class T>
int LinkedList<T>::getSize(){
	return size;
}





#endif