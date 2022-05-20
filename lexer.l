%{
// Reconhecedor de uma linguagem simplificada
#include <iostream>
#include "tokens.h"
using std::cout;
%}

%option noyywrap
delim	[ \t]
eol [\n]
brancos {delim}+
letter	[A-Za-záàâãéèêíïóôõöúçñÁÀÂÃÉÈÍÏÓÔÕÖÚÇÑ ]
digit	[0-9]
special [,.:\-;%\"+&)(\!\?\/_]
text    ({letter}|{digit}|{special}|{delim})+
doctype <!DOCTYPE([ ]+{letter}*)>
comment <!--({text}*|[ \n]*)\-\-> 
tagName html|head|style|title|body|h[1-6]|p|b|i|table|tr|td|th|ul|li|a
attr    [ ]+[a-zA-Z]+=\"({text}|{special})\"
tag     <{tagName}{attr}*>
closetag <\/{tagName}>
onlyopeningtag <(img|br){attr}*[ ]*\/?>
styleCss    [\t ][A-Za-z0-9\-]*[ ]\{[.\n ]*\}


%%
{brancos}	; // nenhuma ação e nenhum retorno 
{eol} return EOL;
{doctype}     return DOCTYPE;
{comment}     return COMMENT;
{tag}         return TAG;
{closetag}    return CLOSETAG;
{onlyopeningtag} return ONLYOPENINGTAG;
{styleCss} return ONPENSTYLE;
{text}        return TEXT;
%%
/* 

{attr}        return TEXT;
{tagName}     return TAGNAME; */
/* .           cout << YYText() << " é um token inválido!\n";  */

// nenhuma função auxiliar é necessária
