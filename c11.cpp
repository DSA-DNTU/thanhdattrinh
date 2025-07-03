#include<iostream>
#include<string>
using namespace std;

class PriorityQueue{
	private:
		int* priorities; // Priority array
		string* tasks; // Task array
		int capacity; // Capacity
		int current; // Current size
		bool ascend = true;
	public:
		PriorityQueue(int cap, bool asc){
			capacity = cap;
			current = 0;
			ascend = asc;
			priorities = new int[capacity];
			tasks = new string[capacity];
		}
		~PriorityQueue(){
			delete[] priorities;
			delete[] tasks;
		}	
		void enqueue(string taskName, int priority){
			if(current >= capacity){
				cout << "Queue Full!" << endl;
				return;
			}
			priorities[current] = priority; // Add priority number
			tasks[current] = taskName; // Add task name
			++current;
		}
		string dequeue(){
			if(current == 0) return "Empty";
			
			int top = 0; // Top Priority Position
			string result;
			if(ascend){
				// Take the ascending priority position in array (L2H)
				for(int i = 0; i < current; ++i){
					if(priorities[top] > priorities[i]){
						top = i;
					}
				}
				result = tasks[top];
			}
			else{
				// Take the descending priority position in array (H2L)
				for(int i = 0; i < current; ++i){
					if(priorities[top] < priorities[i]){
						top = i;
					}
				}
				result = tasks[top];
			}
			// Pop the current tasks by replacing and shrinking array from element after "top"
			for(int i=top; i<current-1; ++i){
				priorities[i] = priorities[i+1];
				tasks[i] = tasks[i+1];
			}
			--current; // Decrease size
			return result;
		}
};
int main(){
	PriorityQueue pq1(5, true);
	PriorityQueue pq2(5, false);
	
	cout << pq1.dequeue() << endl;
	cout << pq2.dequeue() << endl;
	
	cout << "Test Case 1: Lowest to Highest - L2H" << endl;
	pq1.enqueue("Task A", 3);
	pq1.enqueue("Task B", 4);
	pq1.enqueue("Task C", 2);
	pq1.enqueue("Task D", 1);
	pq1.enqueue("Task E", 5);
	pq1.enqueue("Task F", 6); // Error
	cout << pq1.dequeue() << endl; // Task D, array size = 4
	cout << pq1.dequeue() << endl; // Task C, array size = 3
	cout << pq1.dequeue() << endl; // Task A, array size = 2
	cout << pq1.dequeue() << endl; // Task B, array size = 1
	cout << pq1.dequeue() << endl; // Task E, array size = 0
	
	cout << "Test Case 2: Highest to Lowest - H2L" << endl;
	pq2.enqueue("Task A", 3);
	pq2.enqueue("Task B", 4);
	pq2.enqueue("Task C", 2);
	pq2.enqueue("Task D", 1);
	pq2.enqueue("Task E", 5);
	pq2.enqueue("Task F", 6); // Error
	cout << pq2.dequeue() << endl; // Task E, array size = 4
	cout << pq2.dequeue() << endl; // Task B, array size = 3
	cout << pq2.dequeue() << endl; // Task A, array size = 2
	cout << pq2.dequeue() << endl; // Task C, array size = 1
	cout << pq2.dequeue() << endl; // Task D, array size = 0
}
