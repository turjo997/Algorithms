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

Node *reorder_even_odd(Node *head){

     Node *odd = head , *even = head -> next;

     if(head == NULL){
        return head;
     }

     head = odd;

     Node *tmp = even;

     while(even != NULL && even -> next != NULL){
        odd -> next =  odd -> next -> next;
        odd = odd -> next;
        even -> next =  even -> next -> next;
        even = even -> next;
     }

     odd -> next = tmp;


     print_linked_list(head);
}


int pairSum(Node* head) {
   vector <int> v;

   while(head != NULL){
      v.push_back(head->data);
      head = head -> next;
   }

   int mx = 0;

   for(int i = 0 , j = v.size() - 1; i < ( v.size() / 2 ); ++i , --j){
      mx = max(mx , v[i] + v[j]);
   }

   return mx;
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

vector<Node*> splitListToParts(Node* head, int k) {
         Node *cur = head;
        int len = countNodes(head);

      //  cout << "Total node is : " << len << endl;

        vector<Node*> result;

        if(len < k){

            for(int i = 0 ; i < k ; ++i){

                   while(cur != NULL && i < k){

                        cout << "inside"<<endl;
                        Node *tmp = cur;
                        Node *nextPart = tmp->next;
                        tmp ->next = 0;

                        cout <<cur ->data << " " << cur ->next << endl;
                        result.push_back(tmp);
                        cur = nextPart;   // Move to the next part

                       // cur = cur -> next;
                        ++i;
                   }
                   //cout << i << endl;
                  result.push_back(NULL);
            }
        }

        return result;
}


Node* delete_node(int data, Node* head){

        Node *cur = head , *prev = cur;

        while(cur != NULL ){
            if(cur -> data == data){
                 break;
            }
            prev = cur;
            cur = cur -> next;
        }

        //cout << prev << " " << cur << endl;

        if(cur == 0){
            // data not exist
            return head;
        }

        if(prev == cur){
             // starting node
             head = prev -> next;
        }else{
             prev -> next = cur -> next;
        }

        return head;

}


Node* delete_node3(vector<int>& nums, Node* head){

        set<int> s;
        for(int i = 0 ; i < nums.size() ; ++i){
            s.insert(nums[i]);
        }

        Node *dummy = create_node(-1 , NULL);

        Node *tmp = dummy , *cur = head;

        //dummy -> next = tmp;

        while(cur != NULL){
            if(s.count(cur -> data)){
                cur = cur -> next;
            }else{
                tmp -> next = cur;
                tmp = tmp-> next;
                cur = cur -> next;
            }
        }

        //cout << tmp << endl;
        tmp -> next = 0;
        return dummy -> next;
}

Node* swapPairs(Node* head) {

        Node *cur = head , *prev = head;

        if(head == NULL){
            return head;
        }
        int len = countNodes(head);
        while(cur -> next -> next  != NULL){
             int x = cur -> data;
             int y = cur -> next -> data;
             cur -> data = y;
             cur = cur -> next;
             cur -> data = x;
             if(cur -> next -> next != NULL){
                cur = cur -> next;
             }
        }

        //cout << cur << endl;

        if(len % 2 != 0){
            return head;
        }

        int x = cur -> data;
        cur -> data = cur -> next -> data;
        cur = cur -> next;
        cur -> data = x;

        return head;

}


Node *addNumbers(Node *head1 , Node *head2){
    Node *cur1 = head1 , *cur2 = head2;
    Node *dummy = create_node(-1 , NULL);
    Node *p = dummy;


    int carry = 0;

    while(cur1  != NULL && cur2 != NULL){
        int x = cur1 -> data;
        int y = cur2 -> data;
        int sum = x + y + carry;
        carry = sum / 10;
        int add = sum % 10;
        //cout << add << endl;
        p -> next = cur1;
        p = p -> next;
        p -> data = add;

        cur1 = cur1 -> next;
        cur2 = cur2 -> next;
    }
    Node *p2 = cur2 == NULL ? cur1 : cur2;

        while(p2  != NULL){
                int x = p2 -> data;
                int sum = x + carry;
                carry = sum / 10;
                int add = sum % 10;

                p -> next = p2;
                p = p -> next;
                p -> data = add;
                p2 = p2 -> next;
        }


    if(carry > 0){
         p -> next = create_node(carry , NULL);
    }


    return dummy -> next;

}

Node *rotate_LL(Node *head , int k){

    int len = countNodes(head);

    if(k > len){
        k = k % len;
    }

    if(k == len){
        return head;
    }

    k = len - k;
    Node *cur = head;

    int i = 1;

    Node *dummy = create_node(-1,0);
    Node *p = dummy;

    while(i < k && cur != NULL){
        cur = cur -> next;
        ++i;
    }

   // cout << cur << endl<<endl;

    p -> next = cur -> next;
    while(p -> next != NULL){
        p = p -> next;
    }

    cout << cur << endl;

    cur -> next = 0;
    p -> next = head;

    return dummy -> next;
}

int main(){
    Node *head = NULL;
    Node *head1 = NULL , *head2 = NULL;

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; ++i){
        int x ; cin >> x;
        head1 = create_node(x , head1);
    }

    print_linked_list(head1);

    int m;
    //cin >> m;

    //for(int i = 0 ; i < m ; ++i){
        //int x ; cin >> x;
       // head2 = create_node(x , head2);
    //}

     //head = addNumbers(head1 , head2);
     //print_linked_list(head);

     //int n1;
    // cin >> n1;

     //vector<int> nums(n1);

     //for(int i = 0 ; i < n1 ; ++i){
      //  cin >> nums[i];
     //}

    //for(int i = 0 ; i < nums.size() ; ++i){
       // head = delete_node2(nums[i] , head);
    //}

   // head = delete_node3(nums , head);


    // head = swapPairs(head);


  //  delete_node(4, head);

    // print_linked_list(head);

   // int k = 5;

   head1 = rotate_LL(head1 , 2);
   print_linked_list(head1);

   // vector<Node*> res = splitListToParts(head , k);

  //  cout << "Size is : " << res.size() << endl;


   // for(int i = 0 ; i  < k ; ++i){
       //  print_linked_list(res[i]);
       //  cout << endl;
  //  }



   // reorder_even_odd(head);

    return 0;
}


/*
class Solution {
public:
    int countNodes(ListNode *head){
        ListNode *tmp = head;
        int cnt = 0;
        while(tmp != NULL){
           ++cnt;
           tmp = tmp -> next;
        }
        return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {

    int len = countNodes(head);

        if(k > len){
            k = k % len;
        }

        if(k == len){
            return head;
        }

        k = len - k;
        ListNode *cur = head;

        int i = 1;

        ListNode *dummy = new ListNode(-1,0);
        ListNode *p = dummy;

        while(i < k && cur != NULL){
            cur = cur -> next;
            ++i;
        }


        p -> next = cur -> next;
        while(p -> next != NULL){
            p = p -> next;
        }

        cur -> next = 0;
        p -> next = head;

        return dummy -> next;
    }
};
*/
