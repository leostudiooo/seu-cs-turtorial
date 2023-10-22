// break 100 into a combination of 10s, 5s, and 1s, and output all possible combinations

#include <iostream>

using namespace std;

int main(){
	int n=100, count=0;
	for (int i=0; i<=n/10; i++){
		for (int j=0; j<=(n-i*10)/5; j++){
			for (int k=0; k<=(n-i*10-j*5); k++){
				if (i*10+j*5+k==n){
					cout << i << " " << j << " " << k << endl;
					count++;
				}
			}
		}
	}
	cout << "Total: " << count << endl;
}