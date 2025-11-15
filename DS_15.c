void printRange(Node* root, int low, int high){
    if(!root) return;
    if(root->data > low) printRange(root->l, low, high);
    if(root->data >= low && root->data <= high) printf("%d ", root->data);
    if(root->data < high) printRange(root->r, low, high);
}
