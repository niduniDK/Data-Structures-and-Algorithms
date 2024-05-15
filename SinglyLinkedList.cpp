#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int value;
    struct Node *next;

    Node(int value){
        this->value = value;
        next = NULL;
    }

    Node(int value, Node* next){
        this->value = value;
        this->next = next;
    }

};

struct SinglyLinkedList{
    Node* head;

    SinglyLinkedList(Node* head){this->head = head;}
    SinglyLinkedList(){head=NULL;}

    int search_data(int key){
        Node* curr = head;
        int index = 0;
        while(curr){
            if(curr->value == key) return index;
            curr = curr->next;
            index++;
        }
        return -1;
    }

    SinglyLinkedList* insert_data(int element, int index=-1){
        Node* node0 = new Node(element);
        Node* curr = head;
        int curr_idx = 0;
        while(curr->next){
            if(curr_idx==index-2 || curr_idx==0){
                if(curr_idx==0 && index==0){
                    node0->next = curr;
                    head = node0;
                    return this;
                }
                else if(curr_idx==index-2){
                    Node* nxt = curr->next;
                    node0->next = nxt;
                    curr->next = node0;
                    return this;
                }
            }
            curr=curr->next;
            curr_idx++;
        }
        Node* nxt = curr->next;
        node0->next = nxt;
        curr->next = node0;
        return this;
    }

    SinglyLinkedList* insert_before(int element, int index){
        index++;
        return insert_data(element,index-1);
    }

    SinglyLinkedList* insert_after(int element, int index){
        return insert_data(element,index+1);
    }

    SinglyLinkedList* delete_data(int element){
        Node* curr = head;
        if(curr->value==element){
            head = curr->next;
            curr->next = nullptr;
            return this;
        }
        else{
            while(curr->next->value!=element){
                curr=curr->next;
            }
            Node* nxt = curr->next->next;
            curr->next->next = nullptr;
            curr->next = nxt;
            return this;
        }
    }

    void traverse(){
        Node* curr = head;
        while(curr && curr->next){
            cout<<curr->value<<" ";
            curr=curr->next;
        }
        cout<<curr->value<<endl;
    }
};


int main()
{
    Node* node7 = new Node(7);
    Node* node6 = new Node(6,node7);
    Node* node5 = new Node(4,node6);
    Node* node4 = new Node(3,node5);
    Node* node3 = new Node(1,node4);
    Node* node2 = new Node(3,node3);
    Node* node1 = new Node(2,node2);
    Node* head = new Node(5,node1);

    SinglyLinkedList* list1 = new SinglyLinkedList(head);

    list1->traverse();
    list1->insert_data(8);
    list1->insert_data(9,5);
    list1->insert_data(10,0);
    list1->traverse();
    list1->delete_data(3);
    list1->traverse();
    cout<<list1->search_data(3)<<endl;
    list1->insert_after(11,4);
    list1->insert_before(12,8);
    list1->insert_before(15,0);
    list1->traverse();

    return 0;
}
