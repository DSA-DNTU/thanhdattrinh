#include<iostream>

using namespace std;
void addValue(int arr[],int &length,int size ,int x, int pos){
	if(length>=size) cout<<"Not Enough Space!";
	else if(pos>length) cout<<"Invalid Position!";
	else{
		for(int i=length;i>=pos;--i){
			arr[i]=arr[i-1];
		}
		arr[pos]=x;
		++length;
		for(int i=0;i<size;++i){
			cout<<arr[i]<<' ';
		}
		cout<<endl;
	}
}

int main(){
	int size,length,x,pos;
	do{
		cout<<"Insert array capacity: ";cin>>size;
	}while(size<=0);

	int arr[size];
	
	do{
		cout<<"How many value? : ";cin>>length;
	}while(length<=0);
	
	cout<<"Insert array value: ";
	for(int i=0;i<length;i++) cin>>arr[i];
	// Fill with 0
	for(int i=length;i<size;i++) arr[i]=0;
	// Test
	for(int x:arr) cout<<x<<' ';
	cout<<endl;
	do{
		cout<<"Insert position to add: ";cin>>pos;
	}while(pos<0);
	
	cout<<"Insert extra value: ";cin>>x;
	addValue(arr,length,size,x,pos);
}
