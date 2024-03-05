// 3. 设计一个求两个正整数的最小公倍数的函数，在主函数main中进行调用，要求在主函数中能重复输入两个数据并输出最小公倍数这一过程，直至输入0 0 主程序结束。

#include <iostream>

using namespace std;

int gcd(int a, int b){
	if(a < b) swap(a, b);
	if(b == 0) return a;
	return gcd(b, a%b);
}

int lcm(int a, int b){
	return a*b/gcd(a, b);
}

int main(){
	int num1, num2;
	while(1){
		cout<<"Enter num1, num2: "<<endl;
		cin>>num1>>num2;
		if(num1 == 0 && num2 == 0) return 0;
		cout<<lcm(num1, num2)<<endl;
	}
}

/*
(base) PS X:\seu-cs-tutorial> g++ 0f-1023exp3.cpp -o 0f-1023exp3.exe && ./0f-1023exp3.exe
Enter num1, num2: 7 13
91
Enter num1, num2: 10 15
30
Enter num1, num2: 0 0
*/