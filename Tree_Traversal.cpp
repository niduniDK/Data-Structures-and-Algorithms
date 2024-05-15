#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int value;
    struct Node *left;
    struct Node *right;

    Node(int value){
        this->value = value;
        left = NULL;
        right = NULL;
    }

    Node(int value, Node* left, Node* right){
        this->value = value;
        this->left = left;
        this->right = right;
    }

};

struct Tree{
    Node* root;

    Tree(Node* root){this->root=root;}
    Tree(){root = nullptr;}
};

void inorder_traverse(Tree* tree){
    if(!tree->root) return;

    Tree* left = new Tree();
    Tree* right = new Tree();
    left->root = tree->root->left;
    right->root = tree->root->right;

    inorder_traverse(left);
    cout<<tree->root->value<<" ";
    inorder_traverse(right);
}

void preorder_traversal(Tree* tree){
    if(!tree->root) return;

    Tree* left = new Tree();
    Tree* right = new Tree();
    left->root = tree->root->left;
    right->root = tree->root->right;

    cout<<tree->root->value<<" ";
    preorder_traversal(left);
    preorder_traversal(right);
}

void postorder_traversal(Tree* tree){
    if(!tree->root) return;

    Tree* left = new Tree();
    Tree* right = new Tree();
    left->root = tree->root->left;
    right->root = tree->root->right;

    postorder_traversal(left);
    postorder_traversal(right);
    cout<<tree->root->value<<" ";
}

int main()
{
    Node* node3 = new Node(1);
    Node* node4 = new Node(3);
    Node* node5 = new Node(4);
    Node* node7 = new Node(7);
    Node* node1 = new Node(2,node4,node5);
    Node* node6 = new Node(6,node3,node7);
    Node* node2 = new Node(3,node6,nullptr);
    Node* root = new Node(5,node1,node2);

    Tree* tree = new Tree(root);
    cout<<"Inorder Traversal: "<<endl;
    inorder_traverse(tree);
    cout<<'\n'<<endl;

    cout<<"Preorder Traversal: "<<endl;
    preorder_traversal(tree);
    cout<<'\n'<<endl;

    cout<<"Postorder Traversal: "<<endl;
    postorder_traversal(tree);
    cout<<endl;

    return 0;
}
