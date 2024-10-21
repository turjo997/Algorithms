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

Node* reverse(Node* head) {
    
    Node *prev_node = NULL , *cur_node = head , *next_node = head;
    
    while(next_node != NULL){
        
        next_node = next_node -> next;
        
        cur_node -> prev = cur_node -> next;
        
        cur_node -> next = prev_node;
        
        prev_node = cur_node;
        
        cur_node = next_node;
    }
    
    head = prev_node;
    
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

     head = reverse(head);

     print_list(head);
}
