#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPH 26
typedef struct TrieNode{ struct TrieNode* child[ALPH]; int isEnd; } TrieNode;
TrieNode* getNode(){ TrieNode* p = malloc(sizeof(TrieNode)); p->isEnd=0; for(int i=0;i<ALPH;i++) p->child[i]=NULL; return p; }
void insertTrie(TrieNode* root, char *key){
    TrieNode* p=root;
    for(int i=0;i<strlen(key);i++){
        int idx = key[i]-'a';
        if(!p->child[idx]) p->child[idx]=getNode();
        p = p->child[idx];
    }
    p->isEnd = 1;
}
int searchTrie(TrieNode* root, char *key){
    TrieNode* p=root;
    for(int i=0;i<strlen(key);i++){
        int idx = key[i]-'a';
        if(!p->child[idx]) return 0;
        p = p->child[idx];
    }
    return p!=NULL && p->isEnd;
}
int main(){
    TrieNode* root = getNode();
    insertTrie(root, "hello"); insertTrie(root, "world");
    printf("%d %d\n", searchTrie(root,"hello"), searchTrie(root,"hi"));
    return 0;
}
