#include <FlexLexer.h>
#include <iostream>
#include <fstream>
using namespace std;

class Parser
{
private:
	yyFlexLexer scanner;
	int lookahead;
	int tagCounter = 0;
	int lineCounter = 0;
public:
	void Start();
	inline void switchStreams(ifstream *string)
	{
		scanner.switch_streams(*&string);
	}
};
