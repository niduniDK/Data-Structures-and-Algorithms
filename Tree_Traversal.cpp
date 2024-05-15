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

    void inorder_traverse(){
        if(!this->root) return;

        Tree* left = new Tree();
        Tree* right = new Tree();
        left->root = this->root->left;
        right->root = this->root->right;

        left->inorder_traverse();
        cout<<this->root->value<<" ";
        right->inorder_traverse();
    }

    void preorder_traversal(){
        if(!this->root) return;

        Tree* left = new Tree();
        Tree* right = new Tree();
        left->root = this->root->left;
        right->root = this->root->right;

        cout<<this->root->value<<" ";
        left->preorder_traversal();
        right->preorder_traversal();
    }

    void postorder_traversal(){
        if(!this->root) return;

        Tree* left = new Tree();
        Tree* right = new Tree();
        left->root = this->root->left;
        right->root = this->root->right;

        left->postorder_traversal();
        right->postorder_traversal();
        cout<<this->root->value<<" ";
    }
};



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
    tree->inorder_traverse();
    cout<<'\n'<<endl;

    cout<<"Preorder Traversal: "<<endl;
    tree->preorder_traversal();
    cout<<'\n'<<endl;

    cout<<"Postorder Traversal: "<<endl;
    tree->postorder_traversal();
    cout<<endl;

    return 0;
}
