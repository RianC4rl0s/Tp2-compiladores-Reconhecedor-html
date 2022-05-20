#include "parser.h"
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin;

int main(int argc, char **argv)
{
	//Criando parser
	Parser parser;
	if (argc > 1)//Verificando se tem mais de um argumento na inicialização
	{
		fin.open(argv[1]);//abrinrindo arquivo
		if (!fin.is_open())
		{	//se nao abrir
			cout << "Não foi possivel abrir o arquivo:" << argv[1] << "\n";
			exit(EXIT_FAILURE);
		}
		else
		{
			//se abrir mude a string do lexer
			parser.switchStreams(&fin);
		}
	}
	else
	{
	}
	parser.Start();//iniciando o parser

	fin.close();//fechando o arquivo

	// lexer.yylex();
}
