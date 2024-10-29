#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;


struct node{
    int data;
    Node *next;
};


Node *create_node(int item , Node *head){

     Node *new_node = (Node *) malloc(sizeof(Node));

     if(new_node == NULL){
        cout << "Can not create new node"<<endl;
     }
     new_node->data = item;

     if(head == NULL){

        new_node ->next = new_node;
        head = new_node;

     }else{

        Node *tmp = head;

        while(tmp -> next != head){
            tmp = tmp -> next;
         }

        tmp -> next =  new_node;
        new_node -> next = head;

    }

     return head;
}



void print_list(Node *head){

    Node *cur_add = head;

    do{
        cout << head -> data << " " << head -> next << " - - - >";
        head = head -> next;
    }while(head != cur_add);

    printf("(head)\n");
}




int main(){

    Node *n1 , *n2 , *n3 , *n4 , *n5;

    n1 = create_node(1 , NULL);

    n2 = create_node(2 , n1);

    n3 = create_node(3 , n2);

    n4 = create_node(4 , n3);

    n5 = create_node(5 , n4);


    print_list(n5);



    return 0;
}
