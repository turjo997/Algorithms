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
    cout << "here"<<endl;
}

Node *pre_append(int item , Node *head){
    Node *node = create_node(item , head);
    return node;
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

Node *delete_begin(Node *head){
    Node *current_node = head;
    if(current_node -> next != NULL){
        head = current_node->next;
    }
    return head;
}


Node *delete_end(Node *head){
    Node *cur_node = head , *prev_cur_node;
    while(cur_node -> next != NULL){
        prev_cur_node = cur_node;
        cur_node = cur_node -> next;
    }
    //cout << prev_cur_node ->data << " " << prev_cur_node ->next << endl;
     prev_cur_node ->next = NULL;
     return head;
}


int countNodes(Node *head){
    int cnt = 0 ;

    Node *cur_node  = head;

    while(cur_node != NULL){
        ++cnt;
        cur_node = cur_node -> next;
    }

    return cnt;
}


Node *append_at_location(int len , int item , int location , Node *head){

   if(location == 0){
       Node *node = pre_append(item , head);
       return node;
   }

   if(location > len){
       cout << "Can not perform insert operation. Given location is greater than total length" << endl;
   }

   Node *cur_node = head;
   for(int i = 1 ; i < location ; ++i){
       //cout << "Result inside loop: " << cur_node->data << " " << cur_node->next << endl;
       cur_node = cur_node -> next;
   }

   //cout << "Result : " << cur_node->data << " " << cur_node->next << endl;

   Node *node = create_node(item , cur_node -> next);

   //cout << "New node Result : " << node->data << " " << node->next << endl;

   cur_node ->next = node;
   return head;
}

Node *delete_at_location(int len , int location , Node *head){

   Node *cur_node = head , *prev_node;

   if(location <= 0){
      cout << "Operation can not be performed"<<endl;
      return head;
   }

   if(location == 1){
       if(cur_node -> next != NULL){
         cur_node = cur_node->next;
         return cur_node;
       }
       return head;
   }

   if(location > len){
       cout << "Can not perform insert operation. Given location is greater than total length" << endl;
   }

    for(int i = 1; i < location ; ++i){
        prev_node = cur_node;
        cur_node = cur_node -> next;
    }

    prev_node ->next = cur_node ->next;

    return head;
}



int main(){
    Node *head , *n1 , *n2;

    n2 = create_node(10 , NULL);

    head = delete_begin(n2);
    print_linked_list(head);

    n1 = create_node(20 , n2);
    head = n1;

    print_linked_list(head);

    head = delete_begin(head);
    print_linked_list(head);


    head = pre_append(30 , head);

    print_linked_list(head);

    head = append(70 , head);

    print_linked_list(head);

    head = delete_begin(head);

    print_linked_list(head);


    head = append(100 , head);
    head = append(120 , head);
    head = append(150 , head);

    print_linked_list(head);

    head = delete_end(head);

    print_linked_list(head);

    int len = countNodes(head);

    cout << "Total length is : " << len << endl;


    head  = append_at_location(countNodes(head) , 250 , 0 , head);

    print_linked_list(head);

    head  = delete_at_location(countNodes(head) , 1 , head);

    print_linked_list(head);

    return 0;
}
