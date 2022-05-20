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
{brancos}	        ;                                   // nenhuma ação e nenhum retorno 
{eol}               return EOL;                         //fim de linha
{doctype}           return DOCTYPE;                     //doctype
{comment}           return COMMENT;                     //comentario
"<style>"           {BEGIN STYLE; return TAG;}          //ignorar estilo de css
<STYLE>"</style>"   {BEGIN INITIAL; return CLOSETAG;}
<STYLE>{eol}        return EOL;
<STYLE>({text})+    ;         
{tag}               return TAG;                         //tag html
{closetag}          return CLOSETAG;                    //fim tag
{onlyopeningtag}    return ONLYOPENINGTAG;              //tag sem fechamento
{text}              return TEXT;                        //texto
%%
/* 
 OBSERVAÇOES
 
 */

// nenhuma função auxiliar é necessária
