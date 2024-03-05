/*
Original code:

#include<iostream>
using namespace std;
int main(){
	int ch;
	int nline=0, nword=0, nch=0;
	int isword =0;
	cout<<"Enter text: (without empty line)";
	do{
		ch = cin.get();
		if(ch == '\n') nline++;
		if(ch != ' ' && ch != '\n' && ch != '\t' && ch != EOF){
			nch++;
			if(isword == 0){
				isword = 1;
				nword++;
			}
		}
		else isword = 0;
	} while(ch != EOF);
	cout<<"Number of lines: "<<nline<<endl;
	cout<<"Number of words: "<<nword<<endl;
	cout<<"Number of characters: "<<nch<<endl;
	return 0;
}
*/

// read a text from file 0e-2.18.inputtext, and output the number of lines, words, and characters to 0e-2.18.outputtext

#include <fstream>

using namespace std;

int main(){
	ifstream fin("0e-2.18.inputtext");
	ofstream fout("0e-2.18.outputtext");
	int ch;
	int nline=0, nword=0, nch=0;
	int isword =0;
	do{
		ch = fin.get();
		if(ch == '\n') nline++;
		if(ch != ' ' && ch != '\n' && ch != '\t' && ch != EOF){
			nch++;
			if(isword == 0){
				isword = 1;
				nword++;
			}
		}
		else isword = 0;
	} while(ch != EOF);
	fout<<"Number of lines: "<<nline<<endl;
	fout<<"Number of words: "<<nword<<endl;
	fout<<"Number of characters: "<<nch<<endl;
	return 0;
}