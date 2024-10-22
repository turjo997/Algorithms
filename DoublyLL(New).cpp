#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;


struct node{
    int data;
    Node *prev;
    Node *next;
};


Node *create_node(int item , Node *head , Node *tail){

     Node *new_node = (Node *) malloc(sizeof(Node));

     if(new_node == NULL){
        cout << "Can not create new node"<<endl;
     }
     new_node->data = item;

     if(head == NULL){

        new_node ->prev = head;
        new_node ->next = tail;

        head = new_node;

     }else{

        Node *tmp = head;

        while(tmp -> next != NULL){
            tmp = tmp -> next;
        }

        tmp -> next = new_node;

        new_node -> prev = tmp;
        new_node -> next = tail;

    }

     return head;
}



Node *insert_beginning(int data , Node *head){

    Node *new_node = (Node *) malloc(sizeof(Node));

    new_node -> data = data;
    new_node -> prev = NULL;
    new_node -> next = head;

    head -> prev = new_node;

    head = new_node;

    return head;
}


Node *insert_end(int data , Node *head){

    Node *new_node = (Node *) malloc(sizeof(Node));

    Node *cur_node = head;

    while(cur_node -> next != NULL){
        cur_node = cur_node -> next;
    }

     new_node -> data = data;
     new_node -> prev = cur_node;
     new_node -> next = NULL;


     cur_node -> next = new_node;

     return head;
}


void print_list(Node *head){

    Node *cur_node = head;

    while(cur_node != NULL){

        cout << cur_node -> prev << " "<< cur_node -> data << " " << cur_node -> next << endl;

        cur_node = cur_node -> next;
    }
}




int main(){

     Node *n1 , *n2 , *n3 , *n4 , *head;

     head = create_node(1 , NULL , NULL);

     head = create_node(2 , head , NULL);

     head = create_node(3 , head , NULL);


     head = insert_beginning(4 , head);

     head = insert_beginning(5 , head);

     head = insert_end(6 , head);


     print_list(head);




    return 0;
}

