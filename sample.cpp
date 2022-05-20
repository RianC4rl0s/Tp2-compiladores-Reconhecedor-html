#include "parser.h"
#include <iostream>
#include <fstream>
using namespace std;

char **fileList;
unsigned nFiles;
unsigned currentFile = 0;
bool openFile = false;
unsigned long charCount = 0, wordCount = 0, lineCount = 0;
unsigned long totalCC = 0, totalWC = 0, totalLC = 0;
ifstream fin;

int main(int argc, char **argv)
{
	//yyFlexLexer lexer;
	Parser parser;
	if (argc > 1)
	{
		fin.open(argv[1]);
		if (!fin.is_open())
		{
			cout << "Não foi possivel abrir o arquivo:" << argv[1] << "\n"; 
			exit(EXIT_FAILURE);
		}else{
			// lexer.switch_streams(&fin);
			parser.switchStreams(&fin);
		}
	}
	else
	{
	}
	parser.Start();

	fin.close();

	// lexer.yylex();
}
