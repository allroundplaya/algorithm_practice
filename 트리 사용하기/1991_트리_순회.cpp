#include <iostream>

using namespace std;

class treeNode{
    public:
    char data;
    treeNode* left;
    treeNode* right;
    
    treeNode(char p, treeNode* left=NULL, treeNode* right=NULL){
        this->data = p;
        this->left = left;
        this->right = right;
    }
};

class Tree{
    public:
    treeNode* root;
    
    Tree(){
        this->root = new treeNode('A');
    }
    
    void insert(treeNode* cur, char p, char l, char r){
        if(!cur) return;
        if(cur->data == p ) {
            if( l == '.') cur->left = NULL;
            else cur->left = new treeNode(l);
            if( r == '.') cur->right = NULL;
            else cur->right = new treeNode(r);
        }
        else{
            insert(cur->left, p, l, r);
            insert(cur->right, p, l, r);
        }
    }
    
    void preorder(treeNode* cur){
        if(!cur) return;
        cout << cur->data;
        preorder(cur->left);
        preorder(cur->right);
    }
    
    void inorder(treeNode* cur){
        if(!cur) return;
        inorder(cur->left);
        cout << cur->data;
        inorder(cur->right);
    }
    
    void postorder(treeNode* cur){
        if(!cur) return;
        postorder(cur->left);
        postorder(cur->right);
        cout << cur->data;
    }
};

int main(){
    int n;
    cin >> n;
    
    Tree tree;
        
    char p, l, r;
    while (n--){
        cin >> p >> l >> r;
        tree.insert(tree.root, p, l, r);
    }
    
    tree.preorder(tree.root);
    cout << '\n';
    tree.inorder(tree.root);
    cout << '\n';
    tree.postorder(tree.root);
    
    return 0;
}
