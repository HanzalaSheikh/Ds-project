#include<iostream>
using namespace std;

class CircularQueue{
    private:
        int front;
        int rear;
        int arr[5];
        int itemCount;
    public:
        CircularQueue(){
            front=-1;
            rear=-1;
            for(int i=0;i<5;i++){
                arr[i]=0;
            }
        }
        bool isEmpty(){
            if(front ==-1 && rear==-1){
                return true;
            }
            else{
                return false;
            }
        }
        bool isFull(){
            if((rear+1)%5 == front){
                return true;
            }
            else{
                return false;

            }
        }
        void enQueue(int value){
            if(isFull()){
                cout<<"THE QUEUE IS FULL "<<endl;
            }
            else if(isEmpty()){
                front=0;
                rear=0;
            }
            else{
                rear=(rear+1)%5 ;
            }
            arr[rear]=value;
            itemCount++;
        }

        int deQueue(){
            int x;
            if(isEmpty()){
                cout<<"THE QUEUE IS EMPTY "<<endl;
            }
            else if(front == rear){
                x=arr[front];
                arr[front]=0;
                front=-1;
                rear=-1;
                itemCount--;
                return x;
            }
            else{
                x=arr[front];
                arr[front]=0;
                front=(front+1)%5;
                itemCount--;
                return x;

            }
            
        }

        int count(){
            return (itemCount);
        }
};

int main()
{
    int option,value;
    CircularQueue q;

    do
    {
        cout<<"WHAT OPERATION YOU WANT TO PERDORM SELECT NUMBER, ENTER 0 TO EXIT"<<endl;
        cout<<"1-- enQueue()"<<endl;
        cout<<"2--deQueue()"<<endl;
        cout<<"3--isEmpty()"<<endl;
        cout<<"4--isFull()"<<endl;
        cout<<"5--count()"<<endl;
        
        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"enQue operation \nEnter an item to enqueue  "<<endl;
            cin>>value;
            q.enQueue(value);
            break;
        
        case 2:
            cout<<"deQueue operation \n"<<q.deQueue()<<endl;
            break;
        case 3:
            if(q.isEmpty()){
                cout<<"Queue is full  "<<endl;

            }
            else{
                cout<<"queuse is not full"<<endl;
            }
            break;
        case 4:
            if(q.isFull()){
                cout<<"the queue is full "<<endl;

            }
            else{
                cout<<"the queue is not full"<<endl;
            }
            break;
        case 5:
            cout<<q.count()<<endl;
            break;
        default:
            cout<<"enter proper option number"<<endl;
            break;
        }
    } while (option!=0);
    
    
    return 0;
}