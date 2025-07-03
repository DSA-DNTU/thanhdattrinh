#include<iostream>
#include<stdexcept>
#include<stack>
#include<string>
#include<sstream>

using namespace std;

int main(){
	stack<int> st ;
	string exp;
	string token;
	getline(cin, exp);
	stringstream ss(exp);
	// Split value in string , skip ' '
	while(ss >> token){
		// Expected error: Invalid Argument (ex: a,B,+,-,*,/, not a number...)
		try{
			int x = stoi(token); // Convert string number back to int
			st.push(x);
		}catch(const invalid_argument& e){
			if (token == "+" || token == "-" || token == "*" || token == "/"){
				// Check if valid expression (>=2 operand)
				if(st.size()<2){
					cerr << "Error: Invalid Expression!";
					return 1;
				}
				int b = st.top(); st.pop(); // Take 1st value and pop
				int a = st.top(); st.pop(); // Take 2nd value and pop
				int result = 0;
				
				if(token == "+") result = a + b;
				else if(token == "-") result = a - b;
				else if(token == "*") result = a * b;
				else if(token == "/") result = a / b;
				st.push(result);
			}
			else{
				cerr << "Error: Invalid Argument!";
				return 1;
			}
		}
	}
	// Handle case if stack have more than 1 element
	if(st.size() > 1) cerr << "Error: Invalid Expression!";
	else cout << "Ans: " << st.top();
}
/*
	Input 1: 2 10 4 * / 6 + 
	Output 1: 26

	Input 2: 10 2 / 5 * 7 +
	Output 2:
	
	Input 3: "-1 2 + 3 4 *"
	Output 3: Error
	
	Input 3: "2 20 / 3 * +"
	Output 3: Error	
*/
/*
	result = st.top(); st.pop(); // Take 1st value and pop
	// Take 2nd value, cal and pop
	if(token == "+") {
		result = st.top() + result; st.pop();
	} 
	else if(token == "-"){
		result = st.top() - result; st.pop(); 
	} 
	else if(token == "*"){
		result = st.top() * result; st.pop();
	} 
	else if(token == "/"){
		result = st.top() / result; st.pop();
	}
	st.push(result);
*/
