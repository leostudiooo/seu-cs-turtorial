#include <iostream>
using namespace std;

char convert(char ch){
	if(ch>='A' && ch<='Z'){
		return ch+32;
	}
	else if(ch>='a' && ch<='z'){
		return ch-32;
	}
	else{
		return ch;
	}
}

int main(){
	char ch;
	cin>>ch;
	cout<<convert(ch)<<endl;
	return 0;
}