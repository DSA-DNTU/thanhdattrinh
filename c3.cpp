#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
//	Node(int value){
//		data = value;
//		next = nullptr; 
//	}
	Node(int value): data(value), next(nullptr){}; // Alternative way
};
typedef Node* nodePtr;

// Create node function
nodePtr createNode(int data){
	nodePtr newNode = new Node(data);
	return newNode;
}

// Add new node from the beginning
nodePtr addHead(nodePtr &head, int data){
//	nodePtr temp = createNode(data);
	nodePtr temp = new Node(data);
	if(head == nullptr){
		head = temp;
	}else{
		temp->next = head; // Add the current 1st address to the new node
		head = temp; // Redirect head pointer to the new node, turning the previous node to 2nd node
	}
}

// Add new node from the end
nodePtr addTail(nodePtr &head, int data){
//	nodePtr temp = createNode(data);
	nodePtr temp = new Node(data);
	if(head == nullptr){
		head = temp;
	}
	else{
		nodePtr tail = head;
		// loop to the last node before NULL
		while(tail->next != nullptr){
			tail = tail->next;
		}
		tail->next = temp;
	}

}

// Check empty list
bool checkEmpty(nodePtr head){
	return head == NULL;
}

// Print linked list
nodePtr printNode(nodePtr head){
	nodePtr temp = head;
	while(temp != nullptr){
		cout<<temp->data<<' ';
		temp = temp->next;
	}	
	cout<<endl;
}
// Delete list
void deleteList(nodePtr &head){
	while(head != nullptr){
		nodePtr temp = head;
		head = head->next; // Moving head address to the next node
		delete temp; // Delete the current node
	}
}


int main(){
	nodePtr head = nullptr ;
//	addHead(head,3);
//	addHead(head,2);
	addTail(head,1);
	printNode(head);
	cout<<(checkEmpty(head)? "Empty":"Not Empty")<<endl;
	deleteList(head);
	cout<<(checkEmpty(head)? "Empty":"Not Empty")<<endl;
}
