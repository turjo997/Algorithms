#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;

struct node{
     int data;
     Node *prev;
     Node *next;
};

Node *head;

Node *create_node(int item , Node *left , Node *right){
   Node *new_node = (Node*) (malloc(sizeof(Node)));

   if(new_node == NULL){
       cout << "Can not create new node"<<endl;
   }

   new_node -> data = item;
   new_node -> next = right;
   new_node -> prev = left;

   if(head == NULL){
     head = new_node;
   }else{
     head -> prev = new_node;
     head = new_node;
   }

   return new_node;
}

Node *create_node2(int item , Node *left , Node *right){
   Node *new_node = (Node*) (malloc(sizeof(Node)));

   if(new_node == NULL){
       cout << "Can not create new node"<<endl;
   }

   new_node -> data = item;
   new_node -> next = right;
   new_node -> prev = left;

   return new_node;
}

int countNodes(Node *head){
   int cnt = 0;

   while(head != NULL){
      ++cnt;
      head = head ->next;
   }

   return cnt;
}

Node *insert_beginning(int data , Node *head){
    Node *new_node = create_node2(data , NULL , head);
    head -> prev = new_node;
    return new_node;
}

Node *insert_end(int data , Node *head){
    Node *cur_node = head;

    while(cur_node -> next != NULL){
        cur_node = cur_node -> next;
    }

     Node *new_node = create_node(data , cur_node , NULL);
     cur_node -> next = new_node;
     head -> prev = NULL;

     return head;
}


Node *insert_from_pos(int data , int pos , Node *head){

    Node *cur = head , *previous = head;

    int len  = countNodes(head);

    if(pos == 0){
        head = insert_beginning(data , head);
        return head;
    }
    if(pos >= len){
        head = insert_end(data , head);
        return head;
    }

    int i = 0;
    while(i< pos && cur != NULL){
        previous = cur;
        cur = cur -> next;
        ++i;
    }

    //cout << previous << " " << cur << endl;

    Node *new_node = create_node(data , previous , cur);

    previous -> next = new_node;
    cur -> prev = new_node;

    return head;
}

Node *delete_begin(Node *head){
    Node *cur = head;

    if(cur ->next == NULL){
        cout <<  "can't perform delete operation"<<endl;
       // cur = NULL ;   //optional if we want to really delete the beginning node
        return cur;
    }
    cur = cur ->next;
    cur ->prev = NULL;
    return cur;
}

Node *delete_end(Node *head){
    Node *cur = head , *prev = head;

    while(cur ->next != NULL){
        prev = cur;
        cur = cur ->next;
    }

    prev ->next = NULL;
    return head;
}

Node *delete_from_pos(int pos , Node *head){
    Node *cur = head , *prev = head;

    int len = countNodes(head);

    if(pos >= len){
        cout << "Delete operation can not be performed"<< endl;
        return head;
    }

    if(pos == 0){
        head = delete_begin(head);
        return head;
    }

    int i = 0;
    while(i < pos && cur != NULL){
        prev = cur;
        cur = cur -> next;
        ++i;
    }

   // cout << prev << " " << cur << endl;

    prev->next = cur->next;
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

     Node *n1 , *n2 , *n3 , *n4 , *n5;

     n1 = create_node(30 , NULL , NULL);

     //n1 = delete_begin(n1);

     //print_list(n1);

     n2 = create_node(50 , NULL , n1);

     n3 = create_node(70 , NULL , n2);

     cout << n3 << endl;
     print_list(n3);

     cout << endl << endl;

     n4 = insert_beginning(100 , n3);

     print_list(n4);

     cout << endl << endl;

     n5 = insert_end(150 , n4);

     print_list(n5);

     cout << endl;

     Node *head = delete_begin(n5);

     print_list(head);

     cout << endl;

    // head  = delete_end(head);

     //print_list(head);

     //cout << endl;


     //head = delete_from_pos(0 , head);
     //print_list(head);


      head = insert_beginning(100 , head);
      print_list(head);

      cout << endl;


      head = insert_from_pos(230, 0 , head);
      print_list(head);
}
