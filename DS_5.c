#include <stdio.h>
#include <string.h>

int isMatching(char a, char b){
    return (a=='(' && b==')')||(a=='{'&&b=='}')||(a=='['&&b==']');
}

int isBalanced(char *s){
    char st[1000]; int top=-1;
    for(int i=0;i<strlen(s);i++){
        char c=s[i];
        if(c=='('||c=='['||c=='{') st[++top]=c;
        else if(c==')'||c==']'||c=='}'){
            if(top==-1 || !isMatching(st[top--], c)) return 0;
        }
    }
    return top==-1;
}
int main(){
    char s[500]; scanf("%[^\n]", s);
    printf(isBalanced(s) ? "Balanced\n":"Not Balanced\n");
}
