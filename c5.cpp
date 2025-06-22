#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int value): data(value), next(nullptr){};		
};
typedef Node* node;
int count=0;
node addForwardNode(node& head, int value){
	node temp = new Node(value);
	if(head == nullptr){
		temp->next = temp;
		head = temp;
	}
	else{
		node current = head;
		temp->next = head;
		while(current->next != head){
			current = current->next;
		} // Traverse to the end of the list
		current->next = temp;
	}
	++count;
}
void setHead(node& head, int position){
	if (head == nullptr || position < 1 || position > count){
		cerr << "Invalid position (1-based)!" << endl;
		return;
	}
	for (int i = 1; i < position; ++i){
		head = head->next;
	}
}
void traverseCircularList(node head){
	node temp = head;
	if(head == nullptr){
		cerr << "Empty list, cannot print!" <<endl;
		return;
	}
	do{
		cout << temp->data << (temp->next == head?"":"->") ;
		temp = temp->next;
	}while(temp != head); // Stop when meets head
	cout << endl;
} 


int main(){
	node head = nullptr;
	addForwardNode(head, 1);
	addForwardNode(head, 2);
	addForwardNode(head, 3);
	setHead(head,2);
	cout << "Total node:" << count << endl;
	traverseCircularList(head);
}
