#include "stdio.h"
// Split any input number from [8, 100] into 1s, 2s, and 5s, using for loops, and list every possibility while taking counts of possible combinations.
int main() {
	int input, count, one, two, five;
	while (1)
	{
		printf("Enter a number between 8 and 100: ");
		scanf("%d", &input);
		if (input < 8 || input > 100)
		{
			printf("Invalid input. Please enter a number between 8 and 100.\n");
			break;
		}
		count = 0;
		for (one = 0; one <= input; one++)
		{
			for (two = 0; two <= input; two++)
			{
				for (five = 0; five <= input; five++)
				{
					if (one + 2 * two + 5 * five == input)
					{
						printf("%d = %d * 1 + %d * 2 + %d * 5\n", input, one, two, five);
						count++;
					}
				}
			}
		}
		printf("Total number of combinations: %d\n", count);
	}
}