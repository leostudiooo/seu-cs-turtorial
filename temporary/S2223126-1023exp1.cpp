// 1. 设计一个函数，判断一个整数是不是回文数，如果是返回true，反之返回false，回文数是指正序读和反序读都是一样的整数，如12321和45254等）；在主函数main中用两种方式对该函数进行测试，（1）键盘输入整数；（2）随机产生一个整数。

#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int n){
	int n1 = n;
	int n2 = 0;
	while(n1 > 0){
		n2 = n2*10 + n1%10;
		n1 /= 10;
	}
	return n2 == n;
}

int main(){
	int n;
	cout<<"Enter an integer: ";
	cin>>n;
	if(isPalindrome(n)) cout<<n<<" is a palindrome."<<endl;
	else cout<<n<<" is not a palindrome."<<endl;
	srand(time(0));
	n = rand();
	cout<<"Randomly generated integer: "<<n;
	if(isPalindrome(n)) cout<<" is a palindrome."<<endl;
	else cout<<" is not a palindrome."<<endl;
	return 0;
}

/*
Run #1:
(base) PS X:\seu-cs-tutorial> g++ 0f-1023exp1.cpp -o 0f-1023exp1.exe && ./0f-1023exp1.exe
Enter an integer: 123321
123321 is a palindrome.
Randomly generated integer: 23960 is not a palindrome.

Run #2:
(base) PS X:\seu-cs-tutorial> ./0f-1023exp1.exe
Enter an integer: 114514
114514 is not a palindrome.
Randomly generated integer: 24499 is not a palindrome.
*/