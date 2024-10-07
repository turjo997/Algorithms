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

   new_node ->data = item;
   new_node ->next = address;
   return new_node;
}

void print_linked_list(Node *head){
    Node *current_node = head;
    while(current_node != NULL){
        cout << current_node -> data << " " << current_node -> next << endl;
        current_node = current_node -> next;
    }
    cout<<endl;
}

Node *append(int item , Node *head){
    Node *new_node = create_node(item , NULL);
    if(head == NULL){
      return new_node;
   }
    Node *cur_node = head;
    while(cur_node->next != NULL){
        cur_node = cur_node->next;
    }
    cur_node->next = new_node;

    return head;
}


Node *reverse_with_stack(Node *head){

    stack<int> st;
    Node *cur_node = head;
    while(cur_node != NULL){
         st.push(cur_node->data);
         cur_node = cur_node -> next;
    }

    cur_node = head;

    while(cur_node != NULL){
         cur_node ->data = st.top();
         st.pop();
         cur_node = cur_node -> next;
    }

    return head;
}


Node *reverse_aproach_2(Node *head){

   Node *prev = NULL , *cur_node = head , *nxt_node = head;

   while(nxt_node != NULL){
        nxt_node = nxt_node -> next;
        cur_node->next = prev;
        prev = cur_node;
        cur_node = nxt_node;
   }

   head = prev;

   return head;
}


int main(){

    Node *head , *n1 , *n2;
    n2 = create_node(10 , NULL);
    n1 = create_node(20 , n2);
    head = n1;
    append(30 , head);
    append(40 , head);
    append(50 , head);
    print_linked_list(head);

    head = reverse_aproach_2(head);
    print_linked_list(head);

   return 0;
}
