%{
// Reconhecedor de uma linguagem simplificada
#include <iostream>
#include "tokens.h"
using std::cout;
%}

%option noyywrap
%x STYLE
delim           [ \t]
eol             [\n]
brancos         {delim}+
letter	        [A-Za-záàâãéèêíïóôõöúçñÁÀÂÃÉÈÍÏÓÔÕÖÚÇÑ ]
digit	        [0-9]
special         [,.:\-;%\"+&)(\!\?\/_{}]
text            ({letter}|{digit}|{special}|{delim})+
doctype         <!DOCTYPE([ ]+{letter}*)>
comment         <!--({text}*|[ \n]*)\-\-> 
tagName         html|head|style|title|body|h[1-6]|p|b|i|table|tr|td|th|ul|li|a
attr            [ ]+[a-zA-Z]+=\"({text}|{special})\"
tag             <{tagName}{attr}*>
closetag        <\/{tagName}>
onlyopeningtag  <(img|br){attr}*[ ]*\/?>


%%
{brancos}	        ; // nenhuma ação e nenhum retorno 
{eol}               return EOL;
{doctype}           return DOCTYPE;
{comment}           return COMMENT;
"<style>"           {BEGIN STYLE; return TAG;}
<STYLE>"</style>"   {BEGIN INITIAL; return CLOSETAG;}
<STYLE>{eol}        return EOL;
<STYLE>({text})+    ;         
{tag}               return TAG;
{closetag}          return CLOSETAG;
{onlyopeningtag}    return ONLYOPENINGTAG;
{text}              return TEXT;
%%
/* 
{styleCss} return ONPENSTYLE;
styleCss    [\t ][A-Za-z0-9\-]*[ ]\{[.\n ]*\}

{attr}        return TEXT;
{tagName}     return TAGNAME; */
/* .           cout << YYText() << " é um token inválido!\n";  */

// nenhuma função auxiliar é necessária
