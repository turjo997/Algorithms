#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;

struct node{
     int data;
     Node *prev;
     Node *next;
};

Node *head;


void print_list(Node *head){

    Node *cur_node = head;

    while(cur_node != NULL){

        cout << cur_node -> prev << " "<< cur_node -> data << " " << cur_node -> next << endl;

        cur_node = cur_node -> next;
    }
}



Node *insert_beginning(int data , Node *head){
    Node *new_node = (Node*) (malloc(sizeof(Node)));
    new_node -> data = data;

    if(head == NULL){
        new_node -> prev = NULL;
        new_node -> next = NULL;
    }else{
        new_node -> prev = NULL;
        new_node -> next = head;
        head -> prev = new_node;
    }

    return new_node;
}

Node *insert_pos(int data , Node *head){

    Node *new_node = (Node*) (malloc(sizeof(Node)));


    Node *cur = head , *after = head;


    if(data < head ->data){
        new_node -> data = data;
        new_node -> prev = NULL;
        new_node -> next = head;
        head -> prev = new_node;

        return new_node;
    }
    while(after ->next != NULL){

        cur = after;
        after = after -> next;

        if(after->data >= data){
            break;
        }

    }

  //  cout << "Cur : " << cur << " After " << after << endl;

    if(data > after->data){

        new_node -> data = data;
        new_node -> prev = after;
        new_node -> next = NULL;

        after ->next = new_node;

        return head;
    }

    new_node -> data = data;
    new_node -> prev = cur;
    new_node -> next = after;

    cur->next = new_node;
    after -> prev = new_node;

    return head;
}

int main(){

     Node *n1 , *n2 , *n3 , *n4 , *n5;

     int n; cin >> n;

     head = NULL;
     n1 = NULL;
     for(int i = 0 ; i < n ; ++i){
        int x ; cin >> x;
        head = insert_beginning(x  , head);
     }

     print_list(head);

     cout << endl;

     head = insert_pos(1, head);

     print_list(head);
}
