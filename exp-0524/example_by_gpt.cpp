#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool isWhitespaceOnly(const string& line) {
    for (char ch : line) {
        if (!isspace(ch)) {
            return false;
        }
    }
    return true;
}

string removeComments(const string& line, bool& inMultiLineComment) {
    string result;
    bool inString = false;
    bool singleLineComment = false;

    for (size_t i = 0; i < line.length(); ++i) {
        if (singleLineComment) {
            break; // Ignore the rest of the line
        }

        if (inMultiLineComment) {
            if (i + 1 < line.length() && line[i] == '*' && line[i + 1] == '/') {
                inMultiLineComment = false;
                i++; // Skip the '/'
            }
        } else if (inString) {
            if (line[i] == '\\' && i + 1 < line.length() && (line[i + 1] == '"' || line[i + 1] == '\'')) {
                result += line[i];
                result += line[i + 1];
                i++; // Skip the next character too
            } else if (line[i] == inString) {
                inString = false;
                result += line[i];
            } else {
                result += line[i];
            }
        } else {
            if (i + 1 < line.length() && line[i] == '/' && line[i + 1] == '/') {
                singleLineComment = true;
                i++; // Skip the next character too
            } else if (i + 1 < line.length() && line[i] == '/' && line[i + 1] == '*') {
                inMultiLineComment = true;
                i++; // Skip the next character too
            } else if (line[i] == '"' || line[i] == '\'') {
                inString = line[i];
                result += line[i];
            } else {
                result += line[i];
            }
        }
    }

    return result;
}

int main() {
    string inputFileName;
    string outputFileName = "output.cpp";
    cout << "Enter the name of the C++ source file: ";
    cin >> inputFileName;

    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << inputFileName << endl;
        return 1;
    }

    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error opening file: " << outputFileName << endl;
        return 1;
    }

    string line;
    bool inMultiLineComment = false;
    int totalLines = 0;
    int commentLines = 0;
    int blankLines = 0;

    while (getline(inputFile, line)) {
        totalLines++;
        string trimmedLine = removeComments(line, inMultiLineComment);
        
        if (isWhitespaceOnly(line)) {
            blankLines++;
            clog << "INFO\tBlank line found in line " << totalLines << endl;
        }
        
        if (line.find("//") != string::npos || line.find("/*") != string::npos || line.find("*/") != string::npos) {
            commentLines++;
            clog << "INFO\tComment found in line " << totalLines << endl;
        }

        outputFile << trimmedLine << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Total lines: " << totalLines << endl;
    cout << "Total comments: " << commentLines << endl;
    cout << "Total blank lines: " << blankLines << endl;

    return 0;
}
/*
Console output:
Enter the name of the C++ source file: main.cpp
INFO    Blank line found in line 5
INFO    Blank line found in line 7
INFO    Blank line found in line 12
INFO    Blank line found in line 15
INFO    Blank line found in line 20
INFO    Comment found in line 23
INFO    Comment found in line 24
INFO    Comment found in line 26
INFO    Comment found in line 29
INFO    Comment found in line 32
INFO    Comment found in line 33
INFO    Comment found in line 34
INFO    Comment found in line 35
INFO    Comment found in line 36
INFO    Blank line found in line 41
INFO    Comment found in line 42
INFO    Blank line found in line 49
INFO    Comment found in line 50
INFO    Comment found in line 58
INFO    Comment found in line 59
INFO    Blank line found in line 60
INFO    Comment found in line 61
INFO    Blank line found in line 71
INFO    Comment found in line 72
INFO    Comment found in line 79
INFO    Blank line found in line 82
INFO    Comment found in line 83
INFO    Comment found in line 94
INFO    Blank line found in line 103
INFO    Comment found in line 107
INFO    Comment found in line 113
INFO    Blank line found in line 117
INFO    Blank line found in line 122
INFO    Comment found in line 123
INFO    Blank line found in line 126
INFO    Blank line found in line 129
INFO    Comment found in line 130
INFO    Comment found in line 155
Total lines: 155
Total comments: 23
Total blank lines: 15
*/