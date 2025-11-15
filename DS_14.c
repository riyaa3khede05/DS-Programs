#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int data; struct Node *l,*r,*p; } Node;
Node* newNode(int x){ Node* n=malloc(sizeof(Node)); n->data=x; n->l=n->r=n->p=NULL; return n; }
Node* insert(Node* root,int x){
    if(!root) return newNode(x);
    if(x < root->data){ Node* t = insert(root->l,x); root->l = t; if(t) t->p = root; }
    else { Node* t = insert(root->r,x); root->r = t; if(t) t->p = root; }
    return root;
}
void inorder(Node* r){ if(!r) return; inorder(r->l); printf("%d ", r->data); inorder(r->r); }
void preorder(Node* r){ if(!r) return; printf("%d ", r->data); preorder(r->l); preorder(r->r); }
void postorder(Node* r){ if(!r) return; postorder(r->l); postorder(r->r); printf("%d ", r->data); }
void mirror(Node* r){ if(!r) return; Node* t=r->l; r->l=r->r; r->r=t; mirror(r->l); mirror(r->r); }

Node* find(Node* root,int x){ if(!root) return NULL; if(root->data==x) return root; if(x<root->data) return find(root->l,x); return find(root->r,x); }
Node* parent(Node* node){ return node ? node->p : NULL; }
Node* sibling(Node* node){ Node* p = parent(node); if(!p) return NULL; if(p->l==node) return p->r; return p->l; }
Node* grandparent(Node* node){ Node* p = parent(node); return p ? parent(p) : NULL; }
Node* uncle(Node* node){ Node* g = grandparent(node); if(!g) return NULL; if(g->l==parent(node)) return g->r; return g->l; }

int main(){
    Node* root = NULL;
    int vals[] = {20,10,30,5,15,25,35};
    for(int i=0;i<7;i++) root = insert(root, vals[i]);
    printf("Inorder: "); inorder(root); printf("\n");
    Node* nd = find(root,15);
    printf("Parent of 15 = %d\n", parent(nd)->data);
    printf("Uncle of 15 = %d\n", uncle(nd)->data);
    return 0;
}
