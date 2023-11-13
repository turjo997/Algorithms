#include<bits/stdc++.h>
using namespace std;

#define N 6

int queue_ar[N];
int front = -1;
int rear = -1;

bool isEmpty(){
   if(front == -1 && rear == -1){
    return true;
   }
   return false;
}

bool isFull(){
  if(rear == N-1){
    return true;
   }
   return false;
}

int top_elem(){
   if(front == -1 && rear == -1){
     return -1;
   }
   return queue_ar[front];
}
void enqueue(int x){

  if(rear == N-1){
    cout << "Queue is full"<<endl;
  }else if(front == -1 && rear == -1){
    front = rear = 0;
    queue_ar[rear] = x;
    cout << "enqued element is : " << x << endl;
  }else{
    ++rear;
    queue_ar[rear] = x;
    cout << "enqued element is : " << x << endl;
  }
}

void dequeue(){
    if(front == -1 && rear == -1){
        cout << "Queue is empty"<<endl;
    }else if(front == rear){
        cout << "popped element is : " << queue_ar[front] << endl;
        front = rear = -1;
    }
    else{
        cout << "popped element is : " << queue_ar[front] << endl;
         ++front;
    }
}

void display(){

   if(front == -1 && rear == -1){
    cout << "Queue is empty"<<endl;
   }else{

     for(int i = front ; i <= rear ; ++i){
        cout << "element is : " << queue_ar[i] << endl;
     }

   }

}

int main(){

    display();
    dequeue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display();
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    dequeue();
    display();


   return 0;
}

