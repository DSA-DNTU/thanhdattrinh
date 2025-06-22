#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
	Node(int value): data(value), next(nullptr), prev(nullptr){};
};
typedef Node* node;
int size(node head){
	int count=0;
	while(head != nullptr){
		++count;
		head = head->next;	
	}
	return count;
}

node insertAfter(node &head, int value, int position) {
	int s = size(head);
	if (position < 0 || position > s) {
		cerr << "Invalid Position!" << endl;
		return head;
	}

	node temp = new Node(value);
	// If empty
	if (head == nullptr) {
		head = temp;
		return head;
	}
	else if(position == 0){
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else if(position == s){
		node last = head;
		while(last->next != nullptr){
			last = last->next;
		}
		last->next = temp;
		temp->prev = last;
		return head;
	}
	else {
		// Traverse to the node before the selected position
		node prevNode = head;
		for (int i = 0; i < position-1; ++i) {
			prevNode = prevNode->next;
		}
		// Redirect
		temp->next = prevNode->next;
		temp->prev = prevNode;
	
		if (prevNode->next != nullptr) {
			prevNode->next->prev = temp;
		}
		prevNode->next = temp;
		
		return head;
	}
}
void printList(node head){
	if(head == nullptr) cout << "Empty!" << endl;
	else{
		while(head != nullptr){
			cout<< head->data << " ";
			head = head->next;
		}
		cout << endl;
	}
}
void deleteNode(node head){
	while(head != nullptr){
		node temp = head;
		head = head->next;
		delete temp;
	}
}

int main(){
	node head = new Node(10);
	int pos = 1;
	cout << "Size before: " << size(head) << endl;
	insertAfter(head, 20, pos);
	printList(head);
	insertAfter(head, 30, 1);
	printList(head);
	insertAfter(head, 40, 2);
	printList(head);
	cout << "Size after: " << size(head) << endl;
	deleteNode(head);
}
