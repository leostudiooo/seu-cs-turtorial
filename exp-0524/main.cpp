#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	ifstream fin("main.cpp");
	ofstream fout("main_copy.cpp");

	string temp_line;
	clog << "INFO\tReading from example.cpp..." << endl;

	int line_count = 0;
	int comment_count = 0;
	int comment_line_count = 0;
	int blank_count = 0;

	while (getline(fin, temp_line))
	{
		// Comment
		if (temp_line.find("//") != string::npos || temp_line.find("/*") != string::npos)
		{
			// Judge if the "//" or "/*" is wrapped in quotes
			bool in_quotes = false;
			// Check each character in the line
			for (int i = 0; i < temp_line.size(); i++)
			{
				// If the character is a quote, toggle the in_quotes flag.
				// For example:
				// cout << "Hello, // World!"; // This is a comment
				//         ^quote starts    ^quote ends
				//      in_quotes -> true  in_quotes -> false
				if (temp_line[i] == '"')
				{
					in_quotes = !in_quotes;
				}
				// If the character is a comment, and not in quotes, count it as a comment.
				if (temp_line[i] == '/' && (temp_line[i + 1] == '/' || temp_line[i + 1] == '*') && !in_quotes)
				{
					break;
				}
			}

			// If the comment is wrapped in quotes, output the line as it is.
			if (in_quotes)
			{
				line_count++;
				fout << temp_line << endl;
			}
			else
			{
				line_count++;
				// Inline comment
				if (temp_line.find("//") != string::npos)
				{
					comment_count++;
					comment_line_count++;
					// Remove the inline comment
					temp_line = temp_line.substr(0, temp_line.find("//"));
					fout << temp_line << endl;
				}
				// Inline block comment
				else if (temp_line.find("/*") != string::npos && temp_line.find("*/") != string::npos)
				{
					comment_count++;
					comment_line_count++;
					// Remove the inline block comment
					temp_line = temp_line.substr(0, temp_line.find("/*")) + temp_line.substr(temp_line.find("*/") + 2);
					fout << temp_line << endl;
				}
				// Multi-line block comment
				else if (temp_line.find("/*") != string::npos)
				{
					comment_count++;
					comment_line_count++;
					// Remove the block comment start
					temp_line = temp_line.substr(0, temp_line.find("/*"));
					fout << temp_line << endl;
					// Read along until the block comment ends
					while (getline(fin, temp_line))
					{
						line_count++;
						comment_line_count++;
						// If the block comment ends in this line
						if (temp_line.find("*/") != string::npos)
						{
							// Remove the block comment end
							temp_line = temp_line.substr(temp_line.find("*/") + 2);
							fout << temp_line << endl;
							break;
						}
					}
				}
			}
		}

		else
		{
			line_count /* Stupid inline comment */ ++;
			// Blank line
			if (temp_line.empty())
			{
				blank_count++;
				clog << "INFO\tBlank line found in line " << line_count << endl;
			}
			// Normal line
			fout << temp_line << endl;
		}
	}

	cout << "Total lines: " << line_count << endl;
	cout << "Total comments: " << comment_count << endl;
	cout << "Total comment lines: " << comment_line_count << endl;
	cout << "Total blank lines: " << blank_count << endl;

	// Cleanup
	fin.close();
	fout.close();

	return 0;
}

/*
Console Output:
INFO    Reading from example.cpp...
INFO    Blank line found in line 5
INFO    Blank line found in line 7
INFO    Blank line found in line 12
INFO    Blank line found in line 15
INFO    Blank line found in line 20
INFO    Blank line found in line 40
INFO    Blank line found in line 47
INFO    Blank line found in line 100
INFO    Blank line found in line 114
INFO    Blank line found in line 119
INFO    Blank line found in line 123
Total lines: 149
Total comments: 26
Total comment lines: 62
Total blank lines: 11
*/