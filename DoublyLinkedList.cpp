#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int value;
    struct Node *next;
    struct Node *prev;

    Node(){
        value = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int value){
        this->value = value;
        next = NULL;
        prev = NULL;
    }

    Node(int value, Node* prev){
        this->value = value;
        next = NULL;
        this->prev = prev;
    }


    Node(int value, Node* next, Node* prev){
        this->value = value;
        this->next = next;
        this->prev = prev;
    }

};


struct DoublyLinkedList{
    Node* head;

    DoublyLinkedList(Node* head) {this->head=head;}

    int search_data(int key){
        int index = 0;
        Node* curr = head;
        while(curr){
            if(curr->value==key) return index;
            curr=curr->next;
            index++;
        }
        return -1;
    }

    DoublyLinkedList* insert_data(int element, int index=-1){
        Node* node0 = new Node(element);
        Node* curr = head;
        int curr_idx = 0;
        while(curr->next){
            if(curr_idx==index-1 || curr_idx==0){
                if(curr_idx==0 && index==0){
                    node0->next = curr;
                    curr->prev = node0;
                    head = node0;
                    return this;
                }
                else if(curr_idx==index-1){
                    Node* nxt = curr->next;
                    node0->next = nxt;
                    nxt->prev = node0;
                    curr->next = node0;
                    node0->prev = curr;
                    return this;
                }
            }
            curr=curr->next;
            curr_idx++;
        }


        curr->next = node0;
        node0->prev = curr;
        return this;
    }

    DoublyLinkedList* insert_before(int element, int index){
        index++;
        return insert_data(element,index-1);
    }

    DoublyLinkedList* insert_after(int element, int index){
        return insert_data(element,index+1);
    }

    DoublyLinkedList* delete_data(int element){
        Node* curr = head;
        if(curr->value==element){
            head = curr->next;
            head->prev = nullptr;
            curr->next = nullptr;
            return this;
        }
        else{
            while(curr->next->value!=element){
                curr=curr->next;
            }
            Node* nxt = curr->next->next;
            curr->next->next = nullptr;
            curr->next->prev = nullptr;
            nxt->prev = curr;
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
    Node* node7;Node* node6;Node*node5;Node* node4;Node* node3;Node* node2;Node* node1;Node* head;
    node7 = new Node(7,node6);
    node6 = new Node(6,node7,node5);
    node5 = new Node(4,node6,node4);
    node4 = new Node(3,node5,node3);
    node3 = new Node(1,node4,node2);
    node2 = new Node(3,node3,node1);
    node1 = new Node(2,node2,head);
    head = new Node(5,node1,NULL);

    DoublyLinkedList* list1 = new DoublyLinkedList(head);

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
    list1->traverse();

    return 0;
}
