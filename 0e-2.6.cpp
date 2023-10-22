// Output the graph below, with the character of the line in the middle input by user.
//       A
//     B B B
//   C C C C C
// D D D D D D D
//   C C C C C
//     B B B
//       A

#include <iostream>
#include <string>

int main() {
    char c;
    std::cout << "Enter a character: ";
    std::cin >> c;

    int n = c - 'A' + 1;

    // Print the upper half of the pattern
    for (int i = 1; i <= n; i++) {
        // Print the spaces before the characters
        for (int j = 1; j <= n - i; j++) {
            std::cout << "  ";
        }
        // Print the characters
        for (int j = 1; j <= 2 * i - 1; j++) {
            std::cout << char('A' - 1 + i) << " ";
        }
        std::cout << std::endl;
    }

    // Print the lower half of the pattern
    for (int i = n - 1; i >= 1; i--) {
        // Print the spaces before the characters
        for (int j = 1; j <= n - i; j++) {
            std::cout << "  ";
        }
        // Print the characters
        for (int j = 1; j <= 2 * i - 1; j++) {
            std::cout << char('A' - 1 + i) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}