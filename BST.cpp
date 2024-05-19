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
};

struct BST{
    Node* root;

    BST(Node* root){this->root=root;}
    BST(){root = nullptr;}

    void insert_data(int element){
        Node* curr = root;
        Node* node0 = new Node(element);
        if(!curr) {
            root = node0;
            this->root = root;
            return;
        }
        while(curr){
            if(curr->value < element){
                if(!curr->right) {
                    curr->right = node0;
                    this->root = root;
                    break;
                }
                curr = curr->right;
            }
            else if(curr->value > element){
                if(!curr->left) {
                    curr->left = node0;
                    this->root = root;
                    return;
                }
                curr = curr->left;
            }
            else break;
        }
    }

    Node* get_max_child(Node* curr){
        Node* temp = curr;
        if(!curr) return curr;
        else if(!temp->left){
            if(!temp->right) return curr;
            temp = temp->right;
            while(temp->left){
                temp = temp->left;
            }
        }
        else{
            temp = temp->left;
            while(temp->right){
                temp = temp->right;
            }
        }
        Node* node = temp;
        return node;
    }

    void delete_data(int element){
        Node* curr = root;
        Node* prev = root;
        if(!curr) return;
        while(curr->value != element){
            prev = curr;
            if(curr->value < element) {curr = curr->right;}
            else if(curr->value > element) {curr = curr->left;}
        }
        if(!curr->left && !curr->right){
            if(prev->value < curr->value) {prev->right = nullptr; return;}
            else if(prev->value > curr->value) {prev->left = nullptr; return;}
        }
        else if(!curr->left && curr->right){
            if(prev->value < curr->value) {prev->right = curr->right; return;}
            else if(prev->value > curr->value) {prev->left = curr->right; return;}
        }
        else if(curr->left && !curr->right){
            if(prev->value < curr->value) {prev->right = curr->left; return;}
            else if(prev->value < curr->value) {prev->left = curr->left; return;}
        }
        else{
            Node* max_child = get_max_child(curr);
            curr->value = max_child->value;
            delete_data(max_child->value);
        }
        return;
    }

    bool check_BST(){
        if(!root) return true;
        if(root->left && !root->right){
            if(root->value < root->left->value) return false;
            BST* left = new BST(root->left);
            left->check_BST();
        }
        else if(!root->left && root->right){
            if(root->value > root->right->value) return false;
            BST* right = new BST(root->right);
            right->check_BST();
        }
        else if(root->left && root->right){
            if((root->value < root->left->value) || (root->value > root->right->value)) return false;
            BST* right = new BST(root->right);
            right->check_BST();
            BST* left = new BST(root->left);
            left->check_BST();
        }
        return true;
    }

    int max_ele(){
        Node* curr = root;
        if(!curr) return curr->value;
        while(curr->right){
            curr = curr->right;
        }
        return curr->value;
    }

    int min_ele(){
        Node* curr = root;
        if(!curr) return curr->value;
        while(curr->left){
            curr = curr->left;
        }
        return curr->value;
    }

    bool check_empty(){
        if(!root) return true;
        return false;
    }

    int get_successor(int element){
        Node* curr = root;
        while(curr->value != element){
            if(curr->value < element) curr = curr->right;
            else curr = curr->left;
        }
        return get_max_child(curr)->value;
    }

    int get_predecessor(int element){
        Node* curr = root;
        if(curr->value == element) return -1;
        while(curr->left && curr->right && (curr->left->value != element) && curr->right->value != element){
            if(curr->value < element) curr = curr->right;
            else curr = curr->left;
        }
        return curr->value;
    }

    void inorder_traverse(){
        if(!this->root) return;

        BST* left = new BST();
        BST* right = new BST();
        left->root = this->root->left;
        right->root = this->root->right;

        left->inorder_traverse();
        cout<<this->root->value<<" ";
        right->inorder_traverse();
    }

    void preorder_traversal(){
        if(!this->root) return;

        BST* left = new BST();
        BST* right = new BST();
        left->root = this->root->left;
        right->root = this->root->right;

        cout<<this->root->value<<" ";
        left->preorder_traversal();
        right->preorder_traversal();
    }

    void postorder_traversal(){
        if(!this->root) return;

        BST* left = new BST();
        BST* right = new BST();
        left->root = this->root->left;
        right->root = this->root->right;

        left->postorder_traversal();
        right->postorder_traversal();
        cout<<this->root->value<<" ";
    }
};

int main()
{
    Node* root = new Node(6);
    BST* bst = new BST(root);

    bst->insert_data(4);
    bst->insert_data(7);
    bst->insert_data(1);
    bst->insert_data(10);
    bst->insert_data(3);
    bst->insert_data(14);
    bst->insert_data(20);
    bst->insert_data(2);
    bst->insert_data(4);

    cout<<"Inorder Traversal: "<<endl;
    bst->inorder_traverse();
    cout<<endl;

    cout<<"Preorder Traversal: "<<endl;
    bst->preorder_traversal();
    cout<<endl;

    cout<<"Postorder Traversal: "<<endl;
    bst->postorder_traversal();
    cout<<endl;

    cout<<"This is a BST: "<<bst->check_BST()<<endl;
    cout<<"Predecessor of 10: "<<bst->get_predecessor(10)<<endl;
    cout<<"Successor of 10: "<<bst->get_successor(10)<<endl;

    bst->delete_data(10);

    cout<<"Maximum element: "<<bst->max_ele()<<endl;
    cout<<"Minimum element: "<<bst->min_ele()<<endl;

    bst->delete_data(1);

    cout<<"Inorder Traversal: "<<endl;
    bst->inorder_traverse();
    cout<<endl;

    cout<<"Preorder Traversal: "<<endl;
    bst->preorder_traversal();
    cout<<endl;

    cout<<"Postorder Traversal: "<<endl;
    bst->postorder_traversal();
    cout<<endl;

    return 0;
}
