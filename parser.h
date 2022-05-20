#include <FlexLexer.h>
#include <iostream>
#include <fstream>
using namespace std;

class Parser
{
private:
	yyFlexLexer scanner;
	int lookahead;
	int tagCounter = 0;//contador de tags
	int lineCounter = 0;//contador de linhas
public:
	void Start();
	inline void switchStreams(ifstream *string)//Mudando a cadeia do lexer
	{
		scanner.switch_streams(*&string);
	}
};
