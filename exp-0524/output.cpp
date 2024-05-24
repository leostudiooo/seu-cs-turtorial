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
		
		if (temp_line.find("//") != string::npos || temp_line.find("/*") != string::npos)
		{
			
			bool in_quotes = false;
			size_t position = 0;
			
			for (int i = 0; i < temp_line.size(); i++)
			{
				
				
				
				
				
				if (temp_line[i] == '"')
				{
					in_quotes = !in_quotes;
				}

				
				else if (temp_line[i] == '/' && (temp_line[i + 1] == '/' || temp_line[i + 1] == '*') && !in_quotes)
				{
					position = i;
					break;
				}
			}

			
			if (in_quotes)
			{
				line_count++;
				fout << temp_line << endl;
			}
			else
			{
				
				

				
				if (temp_line[position + 1] == '/')
				{
					line_count++;
					comment_count++;
					comment_line_count++;
					clog << "INFO\tComment found in line " << line_count + 1 << endl;
					temp_line = temp_line.substr(0, position);
					fout << temp_line << endl;
				}

				
				else if (temp_line[position + 1] == '*')
				{
					line_count++;
					comment_count++;
					comment_line_count++;
					clog << "INFO\tComment found in line " << line_count + 1 << endl;
					temp_line = temp_line.substr(0, position) + temp_line.substr(temp_line.find("*/") + 2);
					fout << temp_line << endl;
				}

				
				else
				{
					line_count++;
					comment_count++;
					comment_line_count++;
					clog << "INFO\tComment found in line " << line_count + 1 << endl;
					while (getline(fin, temp_line))
					{
						line_count++;
						comment_line_count++;
						if (temp_line.find("*/") /* Some stupid inline comment */ != string::npos)
						{
							comment_line_count++;
							break;
						}
					}
				}
			}
		}

		else
		{
			line_count++;
			
			if (temp_line.empty())
			{
				blank_count++;
				clog << "INFO\tBlank line found in line " << line_count << endl;
			}
			
			fout << temp_line << endl;
		}
	}

	cout << "Total lines: " << line_count << endl;
	cout << "Total comments: " << comment_count << endl;
	cout << "Total comment lines: " << comment_line_count << endl;
	cout << "Total blank lines: " << blank_count << endl;

	
	fin.close();
	fout.close();

	return 0;
}



























