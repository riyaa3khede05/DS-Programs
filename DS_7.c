#include <stdio.h>
#include <string.h>
#include <ctype.h>

int prec(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}
void infixToPostfix(char *in, char *out){
    char st[500]; int top=-1, k=0;
    for(int i=0;i<strlen(in);i++){
        char c=in[i];
        if(isspace(c)) continue;
        if(isalnum(c)) out[k++]=c;
        else if(c=='(') st[++top]=c;
        else if(c==')'){
            while(top!=-1 && st[top]!='(') out[k++]=st[top--];
            if(top!=-1) top--;
        } else { // operator
            while(top!=-1 && ((prec(st[top])>prec(c)) || (prec(st[top])==prec(c) && c!='^')) && st[top]!='(')
                out[k++]=st[top--];
            st[++top]=c;
        }
    }
    while(top!=-1) out[k++]=st[top--];
    out[k]='\0';
}
int main(){
    char in[500], out[500];
    fgets(in, 500, stdin);
    infixToPostfix(in, out);
    printf("%s\n", out);
}
