%{
 
#include <stdlib.h>

#define NOUN 257
#define PRONOUN 258
#define VERB 259
#define ADVERB 260
#define ADJECTIVE 261
#define PREPOSITION 262
#define CONJUNCTION 263

#define LOOKUP 0

int state;

int add_word(int type, char* word);
int lookup_word(char* word);

%}

%%

 /* end of line, return to default state */
\n { state = LOOKUP; }

\.\n { state = LOOKUP; return 0; }

 /* line starts with a reserved part (keyword) change state to define */
^verb { state = VERB; }
^adj { state = ADJECTIVE; }
^adv { state = ADVERB; }
^noun { state = NOUN; }
^prep { state = PREPOSITION; }
^pron { state = PRONOUN; }
^conj { state = CONJUNCTION; }

[a-zA-Z]+ {
if (state != LOOKUP)
{
 add_word(state, yytext);
}
else
{
 switch (lookup_word(yytext))
 {
  case VERB: return (VERB);
  case ADJECTIVE: return (ADJECTIVE);
  case ADVERB: return (ADVERB);
  case NOUN: return (NOUN);
  case PREPOSITION: return (PREPOSITION);
  case CONJUNCTION: return (CONJUNCTION);
  default:
    printf("%s: don't know\n", yytext);
     /* don't know, just ignore */
 }
}
}

 /* ignore everything else */;

%%

struct word
{
 char* word_name;
 int word_type;
 struct word* next;
}* word_list;

int add_word(int type, char* word)
{
 struct word* wp;
 
 if (lookup_word(word) != LOOKUP)
 {
  printf("warning : word %s already defined \n", word);
  return 0;
 }
 
 wp = (struct word*)malloc(sizeof(struct word));
 wp->next = word_list;
 wp->word_name = (char*)malloc(strlen(word)+1);
 strcpy(wp->word_name, word);
 wp->word_type = type;
 word_list = wp;
 return 1;
 /* it worked ! */
}

int lookup_word(char* word)
{
 struct word* wp = word_list;
 
 for (; wp; wp = wp->next)
 {
  if (strcmp(wp->word_name, word) == 0) return wp->word_type;
 }

 return LOOKUP;
}
