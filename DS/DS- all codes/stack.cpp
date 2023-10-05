#include<iostream>
using namespace std;

class Stack{
    private:
        int top;
        int arr[5];
    public:
        Stack(){
            top=-1;
            for(int i=0;i<5;i++){
                arr[i]=0;
            }
        }
        bool isEmpty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }
        bool isFull(){
            if(top==4){
                return true;
            }
            else{
                return false;
            }
        }
        void push(int val){
            if(isFull()){
                cout<<"STACK OVERFLOW"<<endl;
            }
            else{
                top++;
                arr[top]=val;
            }
        }
        int pop(){
            if(isEmpty()){
                cout<<"STACK UNDERFLOW"<<endl;
                return 0;
            }
            else{
                int popValue=arr[top];
                arr[top]=0;
                top--;
                return popValue;
            }
        }

        int count(){
            return (top+1);
        }

        int peek(int pos){
            if(isEmpty()){
                 cout<<"STACK UNDERFLOW"<<endl;
                return 0;
            }
            else{
                return arr[pos];
            }
        }

        void change(int pos,int val){
            arr[pos]=val;
            cout<<"VALUE CHANGED AT POSITION"<<pos<<endl;
        }
        void display(){
            for(int i=4;i>=0;i--){
                cout<<arr[i];
            }
        }

};

int main()
{
    Stack s1;
    int position,value,option;
    do
    {
        cout<<"WHAT OPERATION YPU WANT TO SELECT, SELECT 0 TO EXIT"<<endl;
        cout<<"1--push()"<<endl;
        cout<<"2--pop()"<<endl;
        cout<<"3--isEmpty()"<<endl;
        cout<<"4--isFULL()"<<endl;
        cout<<"5--count()"<<endl;
        cout<<"6--peek()"<<endl;
        cout<<"7--change()"<<endl;
        cout<<"8--display()"<<endl;

        cin>>option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout<<"ENTER ITEM TO PUSH IN THE STACK"<<endl;
            cin>>value;
            s1.push(value);
            break;
        case 2:
            cout<<"POP FUNCTION CALLED"<<s1.pop()<<endl;
            break;
        case 3:
            if(s1.isEmpty()){
                cout<<"THE STACK IS EMPTY"<<endl;
            }
            else{
                cout<<"STACK IS NOT ENPTY"<<endl;
            }
            break;

        case 4:
             if(s1.isFull()){
                cout<<"THE STACK IS FULL"<<endl;
            }
            else{
                cout<<"STACK IS NOT FULL"<<endl;
            }
            break;
        case 5:
            cout<<"ENTER THE POSITION OF VALUE YOU WANT TO PEEK"<<endl;
            cin>>position;
            cout<<"PEEK FUNCTION CALLED - VALUE AT POSITION"<<position <<" is "<<s1.peek(position)<<endl;
            break;

        case 6:
            cout<<"THE NUMBER OF ITEMS IS STACK ARE"<<s1.count()<<endl;
            break;
        
        case 7:
            cout<<"CHANGE FUNCTION CALLED"<<endl;
            cout<<"ENTER THE POSITION OF ITEM YOU WANT TO CHANGE"<<endl;
            cin>>position;
            cout<<"ENTER THE VALUE OF ITEM YOU WANT TO CHANGE"<<endl;
            cin>>value;
            s1.change(position,value);
            break;

        case 8:
            cout<<"DISPLAYING ITEMS"<<endl;
            s1.display();
    
        default:
            cout<<"ENTER PROPPER POSITION NUMBER "<<endl;
        }

    } while (option!=0);
    
    
    return 0;
}