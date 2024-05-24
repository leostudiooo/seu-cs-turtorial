/*
本来以为这个题挺简单的，然后用主程序本身作为输入，结果发现怎么 debug 都不对，在遇到字符串内包裹双斜杠这种情况的时候总是不能按照预期运行，直接从双斜杠就把那一整行都删掉了。然后又想到了行末注释，还有各种直接用字符串操作不好处理（但是编辑器基于状态机/正则匹配的语法高亮就能做）的 edge case，比如行内的块注释（见 ln 101）。光是今天这个作业我就新建了三个 branch，即使是最简单的不考虑括号包裹等各种问题的版本也会出问题。但是我认为这一版的设计思路是比较完善的。
然后让 GPT-4o 生成了一个版本 (attached: example_by_gpt.cpp)，那个能正常跑 (输出文件：output.cpp)。看了一下，是一个基于状态机的解法，但是状态机也太超纲了。反正这个原始版本就先留着，实在是调不动了。
另外还看了一下 Prism.js（一个用 JavaScript 写的代码高亮库）处理 C++ 代码片段的源码，那个是用正则表达式写的，关于字符串包裹之类的这种情况估计是通过不同高亮类型的优先级来解决的。然而正则表达式的可读性奇差，用 C++ 也不容易实现，况且这个题目也只要求了关于注释的处理，所以这种方法也不太适用。
总之这个题乍一看好像很简单的，但是一旦上手之后就会发现有各种难处理的 edge case。文件读写本身其实是最简单的，但是考虑各种各样的注释规则就会变得非常非常非常麻烦。我这里也都还是用了 C/C++ 提供的字符串操作函数，如果不用这些函数的话还会更麻烦。
*/

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
			size_t position = 0;
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
				else if (temp_line[i] == '/' && (temp_line[i + 1] == '/' || temp_line[i + 1] == '*') && !in_quotes)
				{
					position = i;
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
				// Read position of comment, judge if it is an inline/single-line comment or a block comment
				// Then remove the comment, and output the line

				// Single-line comment
				if (temp_line[position + 1] == '/')
				{
					line_count++;
					comment_count++;
					comment_line_count++;
					clog << "INFO\tComment found in line " << line_count + 1 << endl;
					temp_line = temp_line.substr(0, position);
					fout << temp_line << endl;
				}

				// Inline block comment
				else if (temp_line[position + 1] == '*')
				{
					line_count++;
					comment_count++;
					comment_line_count++;
					clog << "INFO\tComment found in line " << line_count + 1 << endl;
					temp_line = temp_line.substr(0, position) + temp_line.substr(temp_line.find("*/") + 2);
					fout << temp_line << endl;
				}

				// Multi-line block comment
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
Console output:
INFO	Reading from example.cpp...
INFO	Blank line found in line 5
INFO	Blank line found in line 7
INFO	Blank line found in line 12
INFO	Blank line found in line 15
INFO	Blank line found in line 20
INFO	Comment found in line 24
INFO	Comment found in line 25
INFO	Blank line found in line 82
INFO	Comment found in line 84
INFO	Blank line found in line 103
INFO	Comment found in line 108
INFO	Comment found in line 114
INFO	Blank line found in line 117
INFO	Blank line found in line 122
INFO	Comment found in line 124
INFO	Blank line found in line 126
INFO	Blank line found in line 129
INFO	Comment found in line 131
Total lines: 155
Total comments: 7
Total comment lines: 63
Total blank lines: 11
*/