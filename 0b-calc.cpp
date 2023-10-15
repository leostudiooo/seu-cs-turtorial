#include <iostream>
using namespace std;
int main(){
	double a, b;
	char oper;
	cout << "Enter a expression: ";
	cin >> a >> oper >> b;
	bool valid = true;
	double result;
	switch(oper){
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			if(b == 0){
				valid = false;
			}else{
				result = a / b;
			}
			break;
		default:
			valid = false;
	}
	if(valid)
		cout << "Result: " << result << endl;
	else
		cout << "Invalid expression" << endl;
}