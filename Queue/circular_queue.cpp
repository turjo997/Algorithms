#include<bits/stdc++.h>
using namespace std;

class CircularQueue{

   private:
   int front, rear , capacity;
   int *arr;

   public:
         CircularQueue(int size){
             capacity = size;
             arr = new int[capacity];
             front = rear = -1;
         }

         ~CircularQueue(){
            delete[]arr;
         }

         void enqueue(int x){
             if(front == -1 && rear == -1){
                front = rear = 0;
                arr[rear] = x;
                cout << x << " enqueued to queue" << endl;
             }
             else if((rear+1) % capacity == front){
                cout << "Queue is full"<<endl;
                return;
             }else{
               rear = (rear+1) % capacity;
               arr[rear] = x;
               cout << x << " enqueued to queue" << endl;
             }

         }

         void dequeue(){

            if(front == -1 && rear == -1){
                cout << "Queue is empty" << endl;
             }
            else if(front == rear){
                //only single element present
                cout << " element is " << arr[front]<<endl;
                front = rear = -1;
            }else{
               cout << " element is " << arr[front]<<endl;

               front = (front+1) % capacity;

            }


         }

         void display(){

            if(front == -1){
                cout << "Queue is empty"<<endl;
                return;
            }


            int i = front;

            while(i != rear){
                cout << arr[i] << " ";
                i = (i + 1) % capacity;
            }
            cout << arr[rear] <<endl;
         }

         void top(){

           cout << arr[front]<<endl;
         }

};



int main(){

    CircularQueue queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.display();
    queue.dequeue();
    queue.display();
    queue.enqueue(4);
    queue.display();
    queue.dequeue();
    queue.enqueue(5);
    queue.display();



   return 0;
}
