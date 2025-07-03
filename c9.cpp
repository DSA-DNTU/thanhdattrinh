#include<iostream>
#include<queue>
#include<stdexcept>
using namespace std;

class Queue{
	private:
		queue<int> x;
	public:
		void enqueue(int item){
			x.push(item);	
		}
		int dequeue(){
			if(!x.empty()){
				int temp = x.front();
				x.pop();
				return temp;
			}
			throw runtime_error("Error: Queue is empty!");
		}
		int peek(){
			if(!x.empty()) return x.front();
			throw runtime_error("Error: Queue is empty!");
		}
		bool isEmpty(){
			return x.empty();
		}
};
void print(Queue x){
	Queue temp = x;
	while(!temp.isEmpty()){
		cout << temp.dequeue() << ' ';
	}
	cout << endl;
}
int main(){
	Queue q;
	int first_item, next_item;
	q.enqueue(10);
	print(q);
	q.enqueue(20);
	print(q);
	try{
			first_item = q.dequeue();
	}catch(const runtime_error& e){
		cerr << e.what();
	}
	print(q);
	q.enqueue(30);
	try{
		next_item = q.peek();
	}catch(const runtime_error& e){
		cerr << e.what();
	}
	print(q);
	cout << (q.isEmpty() ? "Empty!" : "Queue Not Empty!" );
}
