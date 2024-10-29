#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;

struct node{
   int data;
   Node *next;
};

Node *create_node(int item , Node *address){

     Node *new_node = (Node *) malloc(sizeof(Node));

     if(new_node == NULL){
        cout << "Can not create new node"<<endl;
     }

     new_node->data = item;
     new_node->next = address;

     return new_node;
}

void print_linked_list(Node *head){
    Node *current_node = head;
    while(current_node != NULL){
        cout << current_node -> data << " " << current_node -> next << endl;
        current_node = current_node -> next;
    }
    cout <<endl;
}

Node *merge_two_sorted_ll(Node *head1 , Node *head2){

    Node *cur1 = head1 , *cur2 = head2;

    Node *dummy = create_node(-1 , NULL);
    Node *p = dummy;

    while(cur1 != NULL && cur2 != NULL){
        if(cur1->data <= cur2->data){
           p->next = cur1;
           cur1 = cur1->next;
        }else{
           p->next = cur2;
           cur2 = cur2->next;
        }
        p = p->next;
    }

    if(cur1 == NULL){
       while(cur2 != NULL){
             p->next = cur2;
             cur2 = cur2->next;
             p = p->next;
        }
    }else{
           while(cur1 != NULL){
             p->next = cur1;
             cur1 = cur1->next;
             p = p->next;
        }
    }

    p->next = NULL;


   return dummy->next;
}


int main(){

    Node *head , *n1 , *n2 , *n3 , *n4 , *n5 , *n6 , *n7 , *n8 , *n9 , *n10;
   // n10 = create_node(7 , NULL);
    n9 = create_node(3 , NULL);
    n8 = create_node(1 , n9);


    print_linked_list(n8);
    cout << endl;

    n10 = create_node(3 , NULL);
    n7 = create_node(2 , n10);
    n6 = create_node(1 , n7);

    print_linked_list(n6);

    cout << endl;

    head = merge_two_sorted_ll(n8 , n6);
    print_linked_list(head);

    return 0;
}

