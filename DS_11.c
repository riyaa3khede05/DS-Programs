#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int evalPostfix(char *s){
    int stack[1000], top=-1;
    for(int i=0;i<strlen(s);i++){
        char c = s[i];
        if(isspace(c)) continue;
        if(isdigit(c)){
            int val=0;
            while(i<strlen(s) && isdigit(s[i])) { val=val*10 + (s[i]-'0'); i++; }
            i--;
            stack[++top]=val;
        } else {
            int b = stack[top--], a = stack[top--], res=0;
            if(c=='+') res=a+b;
            else if(c=='-') res=a-b;
            else if(c=='*') res=a*b;
            else if(c=='/') res=a/b;
            stack[++top]=res;
        }
    }
    return stack[top];
}
int main(){
    char s[500]; fgets(s,500,stdin);
    printf("%d\n", evalPostfix(s));
}
