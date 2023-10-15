#include<iostream>
int main(){
	int a, b;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < i; j++)
		{
			std::cout << j*i <<std::endl;
		}
		
	}
	return 0;	
}