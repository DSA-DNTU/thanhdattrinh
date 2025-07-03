#include<iostream>
#include<stack>
using namespace std;

int main(){
	int n, result= 1;
	cin >> n;
	stack<int> st;
	cout << n <<"! = " ;
	if(n == 0){
		cout << result;
	}else{
		// C1:
/*		for(int i=n;i>0;--i){
			st.push(i);
			result *= st.top() ;
			cout << i << " * ";
			st.pop();
		}
		cout << " = " << result;
*/
		// C2
		for(int i=1;i<=n;++i){
			st.push(i);
		}
		while(!st.empty()){
			result *= st.top();
			cout << st.top() << " * ";
			st.pop();
		}
		cout << " = " << result;
	}	
}
