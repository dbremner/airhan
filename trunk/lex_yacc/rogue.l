%{
/*
* Kosmos - michael, why you are fighting such a war that doomed to fail?
* Michael - without fighting you will never realize how powerful you are.
* Kosmos - understand. system power up, stand by, level 1 defense canon up.
*
*/
%}

%%

[\t ]+ ;

is |
am |
are |
were |
was |
be |
being |
been |
do |
does |
did |
should |
can |
could |
has |
have |
had |
go {printf("%s: is a verb\n", yytext);}

[a-zA-Z]+ {printf("%s: is no a verb\n", yytext);}

.I\n {ECHO; /*default anyways*/}

%%

main()
{
	yylex();
}
