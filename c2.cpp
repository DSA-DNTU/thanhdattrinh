#include<iostream>
#include<cstdlib>
using namespace std;
class DynamicArray{
	private:
		int capacity = 2, length=0;
		int* arr;
	public:
		DynamicArray();
		DynamicArray(int);
		~DynamicArray();
		void add(int);
		void get(int);
		void resize();
		void size(); 
		void info();
};
// Constructor
DynamicArray::DynamicArray(){
	arr= new int[capacity];
	cout << "A default dynamic array has been created with capacity of 2." << endl;
}
DynamicArray::DynamicArray(int capacity){
	if(capacity <= 0){
		cerr << "Invalid Capacity!";
		exit(1);
	}
	this->capacity = capacity;
	this->arr = new int[capacity];
	cout << "A dynamic array has been created with capacity of " <<capacity<< "." << endl;
}
// Destructor
DynamicArray::~DynamicArray(){
	delete[] arr;
}
// Basic Function
// Add Value
void DynamicArray::add(int element){
	if(length >= capacity){
		resize();
	}
	arr[length] = element;
	++length;	
// Fill zero
	/*
	if(length<capacity){
		for(int i=length;i<=capacity;++i){
			arr[i]=0;
		}
	} */
};
// Find Value
void DynamicArray::get(int index){
	if(index < 0 || index >= length) cerr << "Invalid index!" << endl;
	else cout <<"Value at index " << index << ": "<< arr[index]<<endl;
};
// Resize Array
void DynamicArray::resize(){
	int newCapacity = capacity * 2;
	int *newArr = new int[newCapacity];
	
	for(int i=0;i<capacity;i++){
		newArr[i] = arr[i];
	}
	
	delete[] this->arr;
	this->arr = newArr;
	this->capacity = newCapacity;
};
// Check Current size
void DynamicArray::size(){
	cout<<"Size: "<<capacity;
};
void DynamicArray::info(){
	cout << "Current cap: " << capacity << endl;
	cout << "Current length: " << length << endl;
	for(int i=0;i<length;++i){
		cout << arr[i] <<" ";
	}
	cout<<endl;
}
int main(){
	DynamicArray x(3);
	x.add(1);
	x.add(2);
	x.add(3);
	x.add(4);
	x.add(5);
	x.add(6);
//	x.add(7);
	x.info();
	x.get(4); 
	x.size(); 
}
