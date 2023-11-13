#include<bits/stdc++.h>
using namespace std;

#define N 6

int stack_ar[N];
int top = -1;

bool isEmpty(){
   if(top == -1){
    return true;
   }
   return false;
}

bool isFull(){
  if(top == N-1){
    return true;
   }
   return false;
}

int top_elem(){
    if(top == -1){
        return -1;
    }
   return stack_ar[top];
}
void push(int x){

  if(top == N-1){
    cout << "Stack is full"<<endl;
  }else{
    ++top;
    stack_ar[top] = x;
    cout << "pushed element is : " << x << endl;
  }
}

void pop(){
    if(top == -1){
        cout << "Stack is empty"<<endl;
    }else{
        cout << "popped element is : " << stack_ar[top] << endl;
         --top;
    }
}

void display(){

   if(top == -1){
    cout << "Stack is empty"<<endl;
   }else{

     for(int i = top ; i >= 0 ; --i){
        cout << "element is : " << stack_ar[i] << endl;
     }

   }

}

int main(){

    display();
    pop();
    push(1);
    push(2);
    push(3);
    display();
    pop();
    display();
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    pop();
    display();


   return 0;
}
