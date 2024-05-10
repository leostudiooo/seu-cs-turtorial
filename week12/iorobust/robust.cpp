#include <iostream>
#include <ios>

using namespace std;

int main()
{
	int score;
	do
	{
		// Exception handling for unexpected input, for example, if the user enters a character instead of a number, the program will go into an infinite loop.
		cin.exceptions(ios::failbit);
		try
		{
			cout << "Enter a score: ";
			cin >> score;
		}
		catch (ios::failure &)
		{
			cout << "Invalid input. Please enter a number." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}

	} while (score <= 0 || score > 100);
	
	return 0;
}