#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;

struct node{
   int data;
   Node *next;
};

Node *create_node(int item , Node *head){

     Node *new_node = (Node *) malloc(sizeof(Node));
     new_node->data = item;

     if(head == NULL){
        new_node->next = NULL;
        head = new_node;
     }else{
         Node *tmp = head;
         while(tmp -> next != NULL){
            tmp = tmp -> next;
         }
        tmp -> next = new_node;
        new_node -> next = NULL;
     }
     return head;
}

void print_linked_list(Node *head){
    Node *current_node = head;
    while(current_node != NULL){
        cout << current_node -> data << " " << current_node -> next << endl;
        current_node = current_node -> next;
    }
}

int countNodes(Node *head){
        Node *tmp = head;
        int cnt = 0;
        while(tmp != NULL){
           ++cnt;
           tmp = tmp -> next;
        }
        return cnt;
}

Node* delete_node(int data, Node* head){

        Node *cur = head , *prev = 0;

        while(cur != NULL ){
            if(cur -> data == data){
                 if(prev == 0){
                    int x = cur -> data ;
                       while(cur -> next!= NULL && x == cur -> data){
                            cur = cur -> next ;
                       }
                       head = cur;
                  }else{

                    int x = cur -> data ;

                    while(cur -> next != NULL && x == cur -> data){
                        cur = cur -> next;
                    }
                    prev -> next = cur;
                    cur = cur -> next;
                    prev = prev -> next;
                  }
            }
            else{
                prev = cur;
                cur = cur -> next;
            }
        }

        //print_linked_list(head);

        prev = head, cur = head;

        while(cur -> next!= NULL){
            prev = cur;
            cur = cur -> next;
        }

        if(cur -> data == data){
            prev -> next = cur -> next;
        }

       //  cout << "prev   " << prev << " cur    " << cur << endl;


        return head;
}


int main(){
    Node *head = NULL;

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; ++i){
        int x ; cin >> x;
        head = create_node(x , head);
    }


    print_linked_list(head);

     int n1;
     cin >> n1;

     vector<int> nums(n1);

     for(int i = 0 ; i < n1 ; ++i){
        cin >> nums[i];
     }

    for(int i = 0 ; i < nums.size() ; ++i){
        head = delete_node(nums[i] , head);
    }

     print_linked_list(head);


    return 0;
}


