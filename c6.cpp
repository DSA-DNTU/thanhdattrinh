#include<iostream>
#include<string>
#include<stack>
using namespace std;
/*
void printStack(stack<char> st){
	while(!st.empty()){
		cout << st.top() << ' ';
		st.pop();
	}
	cout<<endl;
}*/
int main(){
	string s;
	getline(cin,s);
	stack<char> st;
	
	for(char x:s){
		if(x=='(' || x=='[' || x=='{'){
			st.push(x);
		}
		if(x==')' || x==']' || x=='}'){
			if(st.empty()){
				cout << "INVALID!" ;
				return 0;
			}
			else{
				if ((x == '}' && st.top() == '{') ||
				    (x == ']' && st.top() == '[') ||
				    (x == ')' && st.top() == '(')) {
				    st.pop();
				}
			}
		}
 	}	
 	
	if(st.empty()) cout << "VALID!";
	else cout << "INVALID!";
}
/*
	Input 1: (a+b*[c-{d/e}])
	Output 1: VALID!
	
	Input 2: a*(b+c)-[c+d]
	Output:  VALID!
	
	Input 3: ([{})]
	Output: INVALID!
	
	Input 4: (a/b*{[c+d}])
*/	
