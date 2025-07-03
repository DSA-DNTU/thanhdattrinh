#include<iostream>
using namespace std;

class CircularQueue{
	private:
	    int* arr;
	    int capacity;
	    int front;
	    int rear;
	    int count;
	public:
		CircularQueue(int size) {
	        capacity = size;
	        arr = new int[capacity];
	        front = 0;
	        rear = -1;
	        count = 0;
    	}
	    ~CircularQueue() {
	        delete[] arr;
	    }
	    void enqueue(int item) {
	        if (isFull()) {
	            cout << "Queue is full!\n";
	            return;
	        }
	        rear = (rear + 1) % capacity;
	        arr[rear] = item;
	        count++;
	    }
	    int dequeue() {
	        if(isEmpty()) {
	            cout << "Queue is empty!\n";
	            return -1;
	        }
	        int item = arr[front];
	        front = (front + 1) % capacity;
	        count--;
	        return item;
	    }
	    int peek() {
	        if(isEmpty()) {
	            cout << "Queue is empty!\n";
	            return -1;
	        }
	        return arr[front];
	    }
	    bool isEmpty() {
	    	return (count == 0);
		}
	    bool isFull(){
	    	return (count == capacity);
		}
	    void printQueue() {
	        cout << "Queue: ";
	        for (int i = 0; i < count; ++i) {
	            int index = (front + i) % capacity;
	            cout << arr[index] << " ";
	        }
	        cout << "\n";
	    }
};
int main(){
	CircularQueue cq(3);

    cq.enqueue(1);  // [1, _, _] f=0 r=0
    cq.enqueue(2);  // [1, 2, _] f=0 r=1
    cq.enqueue(3);  // [1, 2, 3] f=0 r=2 (full)
    
    int item1 = cq.dequeue();  // item1 = 1, f=1, r=2
    cout << "Dequeued item 1: " << item1 << "\n";

    cq.enqueue(4);  // [4, 2, 3], rear return 0

    cq.printQueue();  // Output: 2 3 4

}
