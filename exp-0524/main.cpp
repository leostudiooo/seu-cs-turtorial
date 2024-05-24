/*
一、实验目的：练习文本文件的读写
二、实验内容：
1、根据从键盘输入的文件名，读取一个C++源代码文件，并进行以下处理：
(1) 将该文件中各行的注释删除掉，并将删除掉注释后的程序行写到相应的另一个文件中；
(2) 统计输入文件中的带注释的行数；
(3) 统计输入文件中的空白行数；
(4) 统计输入文件中的总行数；
2、在屏幕上输出 (2), (3), (4) 的统计结果。
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	string filename = "main.cpp";
	ifstream fin(filename);
	ofstream fout("output.cpp");

	if (!fin)
	{
		cerr << "Cannot open " << filename << endl;
		exit(1);
	}

	string line;
	int line_count = 0, comment_line_count = 0, blank_line_count = 0;
	bool in_comment = false;

	while (getline(fin, line))
	{
		line_count++;
		if (line.empty())
		{
			blank_line_count++;
			continue;
		}

		size_t pos = line.find("//");
		if (pos != string::npos)
		{
			line = line.substr(0, pos);
		}

		if (!in_comment)
		{
			pos = line.find("/*");
			if (pos != string::npos)
			{
				in_comment = true;
				line = line.substr(0, pos);
			}
		}

		if (in_comment)
		{
			pos = line.find("*/");
			if (pos != string::npos)
			{
				in_comment = false;
				line = line.substr(pos + 2);
			}
			else
			{
				comment_line_count++;
				continue;
			}
		}

		fout << line << endl;
	}

	cout << "Comment lines: " << comment_line_count << endl;
	cout << "Blank lines: " << blank_line_count << endl;
	cout << "Total lines: " << line_count << endl;

	fin.close();
	fout.close();

	return 0;
}