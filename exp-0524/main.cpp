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
		// Single-line comment: find the first occurrence of "//", with leading characters only whitespace
		if (
			temp_line.find("//") != string::npos &&
			(
				temp_line.find("//") == temp_line.find_first_not_of(" \t") ||
				temp_line.find("") == temp_line.find_first_not_of(" ")
			)
		)
		{
			line_count++;
			comment_count++;
			comment_line_count++;
			clog << "INFO\tSingle-line comment found in line " << line_count << endl;
		}

		// Multi-line comment: find the first occurrence of "/*", then read along until "*/"
		else if (temp_line.find("/*") != string::npos)
		{
			line_count++;
			comment_count++;
			comment_line_count++;

			clog << "INFO\tMulti-line comment found in line " << line_count << endl;

			// Read until "*/"
			while (temp_line.find("*/") == string::npos)
			{
				getline(fin, temp_line);
				comment_line_count++;
				line_count++;
			}
		}

		else
		{
			line_count++;
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
	cout << "Total blank lines: " << blank_count << endl;

	// Cleanup
	fin.close();
	fout.close();

	return 0;
}
/*
Console Output:
INFO    Reading from example.cpp...
INFO    Blank line found in line 4
INFO    Blank line found in line 6
INFO    Blank line found in line 11
INFO    Blank line found in line 14
INFO    Blank line found in line 18
INFO    Comment found in line 21
INFO    Comment found in line 23
INFO    Comment found in line 25
INFO    Comment found in line 34
INFO    Comment found in line 35
INFO    Blank line found in line 48
INFO    Comment found in line 52
INFO    Comment found in line 58
INFO    Blank line found in line 62
INFO    Blank line found in line 66
INFO    Comment found in line 67
INFO    Blank line found in line 70
Total lines: 72
Total comments: 8
Total blank lines: 9
*/