#include<iostream>
#include<deque>
using namespace std;

class Deque{
	private:
		deque<int> x;
	public:
		void addFront(int item) {x.push_front(item);}
		void addRear(int item) {x.push_back(item);}
		int removeFront(){
			if(x.empty()){
				cerr << "Error: Empty Deque!" << endl;
				return -1;
			}
			int temp = x.front();
			x.pop_front();
			return temp;
		}
		int removeRear(){
			if(x.empty()){
				cerr << "Error: Empty Deque!" << endl;
				return -1;
			}
			int temp = x.back();
			x.pop_back();
			return temp;
		}
		int peekFront() {return x.front();}
		int peekRear() {return x.back();}
		bool isEmpty(){
			return x.empty();
		}
		void print(){
			// Print from left->right (front)
			deque<int> temp = x;
			while(!temp.empty()){
				cout << temp.front()<<' ';
				temp.pop_front();
			}
			cout << endl;
		}
};

int main(){
	int item_rear=0, item_front=0;
	Deque deq;
	deq.removeFront();
	deq.addFront(2); // Deque: [2,]
	deq.print();
	deq.addRear(3); // Deque: [2,3]
	deq.print();
	deq.addFront(1); // Deque: [1,2,3]
	deq.print();
	
	deq.addRear(4);
	deq.addRear(5);
	deq.addRear(6);
	deq.print();
	
	item_rear = deq.removeRear(); // Deque: [1,2,3,4,5] , item_rear= 6;
	deq.print();
	item_front = deq.removeFront(); // Deque: [2,3,4,5], item_front= 1;
	deq.print();
	cout << (deq.isEmpty()? "Emty Deque!": "Not Empty!") << endl;
}
//size()
//push_front()
//push_back()
//pop_front()
//pop_back()
//empty() bool
//front()
//back()
