#include "parser.h"
#include "tokens.h"
#include <iostream>
using std::cout;

void Parser::Start()
{
    int textChar = 0;
    int spaces = 0;
    while ((lookahead = scanner.yylex()) != 0)
    {
        // trata o token recebido do analisador léxico
        switch (lookahead)
        {
        case TEXT:
            // cout << "TEXT: " << scanner.YYText() << "\n";
            if (spaces > 0)
            {
                // cout << "|";
                for (int i = 0; i < spaces; i++)
                {
                    cout << "|\t";
                }
              
            }
            cout << "+--Texto[" << scanner.YYLeng() << "]\n";
            textChar+=scanner.YYLeng();
            break;
        case DOCTYPE:
            // cout << "DOCTYPE: " << scanner.YYText() << "\n";
            ;
            break;
        case TAGNAME:
            // cout << "TAGNAME: " << scanner.YYText() << "\n";
            ;
            break;
        case COMMENT:
            // cout << "COMMENT: " << scanner.YYText() << "\n";
            ;
            break;
        case TAG:
            if (spaces > 0)
            {
                // cout << "|";
                for (int i = 0; i < spaces; i++)
                {
                    // cout << " ";
                    cout << "|\t";
                }
               
            }
            cout << "+--" << scanner.YYText() << "\n";
            tagCounter += 1;
            spaces += 1;
            break;
        case CLOSETAG:
            spaces -= 1;
            if (spaces > 0)
            {
                // cout << "|";
                for (int i = 0; i < spaces; i++)
                {
                    // cout << " ";
                    cout << "|\t";
                }
            }

            cout << "+--" << scanner.YYText() << "\n";
            ;
            break;
        case ONLYOPENINGTAG:
            if (spaces > 0)
            {
                // cout << "|";
                for (int i = 0; i < spaces; i++)
                {
                    // cout << " ";
                    cout << "|\t";
                }
            }
            cout << "+--" << scanner.YYText() << "\n";
            tagCounter += 1;
            // lineCounter++;
            break;
        case EOL:
            lineCounter++;
            break;
        case ONPENSTYLE:
        break;
        }
    }

    cout << endl;
    cout << "==============================\n";
    cout << "Número de Tags: " << tagCounter << "\n";
    cout << "Número de Caracteres de texto: " << textChar << "\n";
    cout << "Número de Linhas: " << lineCounter << "\n";
    cout << "==============================\n";
}
