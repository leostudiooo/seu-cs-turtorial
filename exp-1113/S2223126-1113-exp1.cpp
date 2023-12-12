// 1. Save {'a', 'b', ..., 'z'} into a circular char array sized [26]={}. 
// Starting from [0], count to the m-th blank then fill 'a' into it;
// then fill 'b' into the next m-th blank...
// Until the array is fully filled.
// Then output the array from [0] to [25].

#include<iostream>

using namespace std;

int main() {

	// Variables
	int m;
	char circularArray[26] = {}, currentChar = 'a';

	// Get m, validate and preprocess
	cout << "Input m: ";
	cin >> m;
	if (m == 0) {
		cout << "Invalid input!" << endl;
		return 0;
	}

	// Fill the array
	int currentIndex = -1;
	while (currentChar <= 'z') {
		for (int i = 0; i < m; i++) {
			currentIndex++;
			if (currentIndex > 25)
				currentIndex %= 26;
			if (circularArray[currentIndex])
				i--;
		}
		circularArray[currentIndex] = currentChar;
		currentChar++;
	}

	// Output the array
	for (int i = 0; i < 26; i++)
		cout << circularArray[i] << " ";

	return 0;
}

/*
Input m: 0
Invalid input!
------
Input m: 1
a b c d e f g h i j k l m n o p q r s t u v w x y z
------
Input m: 2
t a n b y c o d u e p f x g q h v i r j z k s l w m
------
Input m: 3
i o a s j b y p c k v d t l e q z f m x g r n h u w
------
Input m: 26
b j c n h d m s o e l v z w f i p k y t g x r u q a
------
Input m: 27
a r b g o c k q t d x s p h e j w u y v f m n l i z
*/
