// Hashing [Separate Chaining]

#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node * next;
        Node(){
            
        }
        Node(int value){
            data=value;
            next=NULL;
        }
};

void insertNode(Node* &head,int val){
    Node* n=new Node(val);
    if (head==NULL){
        head=n;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    
}

void searchNode(Node* head,int val){
    Node* temp=head;
    while (temp!=NULL){
        if (temp->data==val){
            cout<<val<<" Found :)\n";
            return;
        }
        temp=temp->next;
    }
    cout<<val<<" Not Found :(\n";
    return;
}

void showNode(Node* head){
    Node* temp=head;
    while (temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

void deleteNodefromHead(Node* &head){
    Node* toDelete=head;
    head=head->next;
    delete toDelete;
}


void deleteNode(Node* &head,int val){
  if (head==NULL)return;
  if (head->next==NULL){
     deleteNodefromHead(head);
     return;
  }
  if (head->data==val){
    deleteNodefromHead(head);
    return;
  }
    Node* temp=head;
    while (temp->next->data != val){
        temp=temp->next;
    }
    Node* toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
}



// Hash Function
int iHash(int Key,int TotalElements){
    return Key%TotalElements;
}

// Show,Insertion,Search,Deletion
class Hash{
    public:
    int TotalElements=10;
    Node** HashArray= new Node*[TotalElements];
    
    Hash(){
        for(int i=0;i<TotalElements;i++){ 
            HashArray[i]=0;
            
        }
    }
    
    void Show(){
        cout<<"HashArray --> [ ";
        cout<<"\n";
        for(int i=0;i<TotalElements;i++) {
            cout<<"index = "<<i<<" | ";
            showNode(HashArray[i]);
        }
        cout<<" ] ";
        cout<<"\n";
    }
        
    
    void Insert(int Key){
        int H=iHash(Key,TotalElements);
        insertNode(HashArray[H],Key);
    }
    
    void Search(int Key){
        int H=iHash(Key,TotalElements);
        searchNode(HashArray[H],Key);
        }
    
    void Delete(int Key){
        int H=iHash(Key,TotalElements);
        deleteNode(HashArray[H],Key);
        }
            
};


int main() {
        
    Hash* H=new Hash();
    H->Insert(11);
    H->Insert(21);
    H->Insert(31);
    H->Insert(41);
    
    H->Insert(12);
    H->Insert(22);
    H->Insert(32);
    H->Insert(42);
    
    H->Insert(13);
    H->Insert(23);
    H->Insert(33);
    H->Insert(43);
    
    H->Insert(14);
    H->Insert(24);
    H->Insert(34);
    H->Insert(44);
    
    H->Insert(15);
    H->Insert(25);
    H->Insert(35);
    H->Insert(45);
    
    H->Insert(16);
    H->Insert(26);
    H->Insert(36);
    H->Insert(46);
    
    H->Insert(17);
    H->Insert(27);
    H->Insert(37);
    H->Insert(47);
    
    H->Insert(18);
    H->Insert(28);
    H->Insert(38);
    H->Insert(48);
    
    H->Insert(19);
    H->Insert(29);
    H->Insert(39);
    H->Insert(49);
    
    H->Show();
    H->Search(32);
    H->Search(1000);
    H->Delete(37);
    H->Show();
    return 0;
}
