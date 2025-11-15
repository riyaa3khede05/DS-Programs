#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseStr(char *s){ int i=0,j=strlen(s)-1; while(i<j){ char t=s[i]; s[i]=s[j]; s[j]=t; i++; j--; } }
void swapParen(char *s){ for(int i=0;i<strlen(s);i++){ if(s[i]=='(') s[i]=')'; else if(s[i]==')') s[i]='('; } }
int main(){
    char in[500], tmp[500], out[500];
    fgets(in,500,stdin);
    if(in[strlen(in)-1]=='\n') in[strlen(in)-1]=0;
    strcpy(tmp, in);
    reverseStr(tmp);
    swapParen(tmp);
    extern void infixToPostfix(char*, char*);
    infixToPostfix(tmp, out);
    reverseStr(out);
    printf("%s\n", out);
}
