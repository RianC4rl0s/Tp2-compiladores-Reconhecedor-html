#include "parser.h"
#include "tokens.h"
#include <iostream>
using std::cout;

void Parser::Start()
{
    //Contador de carcteres
    int textChar = 0;
    //Contador de espaços(usando para tabulação)
    int spaces = 0;
    while ((lookahead = scanner.yylex()) != 0)
    {
        // trata o token recebido do analisador léxico
        switch (lookahead)
        {
        case TEXT:
            // se spaces > 0 coloque | + tabulação numero de vezes de space
            if (spaces > 0)
            {
                for (int i = 0; i < spaces; i++)
                {
                    cout << "|\t";
                }
              
            }
            cout << "+--Texto[" << scanner.YYLeng() << "]\n";
            textChar+=scanner.YYLeng();
            break;
        case DOCTYPE:
            // se doctype n faça nada
            ;
            break;
        case TAGNAME:
            // se nome de tag n faça nada
            ;
            break;
        case COMMENT:
            // se comentario ignore
            ;
            break;
        case TAG:
            // se spaces > 0 
            if (spaces > 0)
            {
                // para cada space coloque | \p
                for (int i = 0; i < spaces; i++)
                {
            
                    cout << "|\t";
                }
               
            }
            cout << "+--" << scanner.YYText() << "\n";
            //conte linha
            tagCounter += 1;
            //conte space
            spaces += 1;
            break;
        case CLOSETAG:
            spaces -= 1;//diminua o tamanho de spaces antes de realiza o for
            if (spaces > 0)//mesmo for que acontece quando abre tag
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
            if (spaces > 0)//mesmo for que acontece quando abre tag ou fecha
            {
                for (int i = 0; i < spaces; i++)
                {

                    cout << "|\t";
                }
            }
            cout << "+--" << scanner.YYText() << "\n";
            tagCounter += 1;//conta tag
            // spaces não incrementa pois essa tag não criou um novo escopo 
            break;
        case EOL:
            lineCounter++;//Contalinha
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
