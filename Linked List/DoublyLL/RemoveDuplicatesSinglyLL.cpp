# Remove duplicates from a sorted singly linked list

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

Node *remove_duplicates(Node *head){

    Node *cur = head;

    while(cur != NULL){
        int x = cur->data;
        Node *tmp = cur->next;

        while(tmp != NULL && tmp->data == x){
            cout << "duplicate data " << tmp->data << endl;
            tmp = tmp -> next;
            cur->next = tmp;
        }

        //cout << tmp ->next << endl;
        cur = tmp;

    }

   return head;
}


int main(){
    // 1 , 2  , 2 , 3 , 3 , 3 , 4 , 5 , 5 , 6
    Node *head , *n1 , *n2 , *n3 , *n4 , *n5 , *n6 , *n7 , *n8 , *n9 , *n10;
    n10 = create_node(6 , NULL);
    n9 = create_node(5 , n10);
    n8 = create_node(5 , n9);
    n7 = create_node(4 , n8);
    n6 = create_node(3 , n7);
    n5 = create_node(3 , n6);
    n4 = create_node(3 , n5);
    n3 = create_node(2 , n4);
    n2 = create_node(2 , n3);
    n1 = create_node(1 , n2);
  
    head = create_node(1 , n1);
    print_linked_list(head);
  
    cout << endl;
    
    head = remove_duplicates(head);
    print_linked_list(head);


    return 0;
}

    /*
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0 ; i < n ; ++i){
        cin >> v[i];
    }

    for(int i = 0 ; i < n ; ++i){
        int x = v[i];
        //int j = i + 1;
        while(i < n && v[i+1] == x){
            ++i;
        }
        cout << v[i];
    }

    */
