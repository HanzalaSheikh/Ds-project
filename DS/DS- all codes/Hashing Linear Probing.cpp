// Hashing [Linear Probing]
// Formula [(H+i)%N]

#include <iostream>

using namespace std;

// Hash Function
int iHash(int Key,int TotalElements){
    return Key%TotalElements;
}

// Show,Insertion,Search,Deletion
class Hash{
    public:
    int TotalElements=10;
    int* HashArray= new int[TotalElements];
    int FULL = 0;
    
    Hash(){
        for(int i=0;i<TotalElements;i++) HashArray[i]=0;
    }
    
    void Show(){
        cout<<"HashArray --> [ ";
        for(int i=0;i<TotalElements;i++) cout<<HashArray[i]<<" ";
        cout<<" ] \n";
    }
        
    
    void Insert(int Key){
        int H=iHash(Key,TotalElements);
        int i=0;
        while(1){
            if ( HashArray[(H+i)%TotalElements] == 0 ) break;
            else if(i>TotalElements-1){
                FULL = 1;
                break;
                }
            i++;
        }
        if (FULL == 1){
            cout<<"Hash Array is FULL :(\n";
            Show();
            
        }
        else{
            HashArray[(H+i)%TotalElements]=Key;
            cout<<"Key = "<< Key << " inserted at index = " << (H+i)%TotalElements <<":)\n";
            Show();
            
        }
        
    }
    
    void Search(int Key){
        int H=iHash(Key,TotalElements);
        int i=0;
        while(HashArray[(H+i)%TotalElements] != 0 && i<TotalElements){
            if ( HashArray[(H+i)%TotalElements] == Key ) {
                cout<<"Key = "<< Key << " Found at index = " << (H+i)%TotalElements <<":)\n";
                return;}
                i++;}
        cout<<"Key = "<< Key <<  " not Found !!! :(\n";
        return;
            
    }

    void Delete(int Key){
        int H=iHash(Key,TotalElements);
        int i=0;
        while(HashArray[(H+i)%TotalElements] != 0 && i<TotalElements){
            if ( HashArray[(H+i)%TotalElements] == Key ) {
                
                HashArray[(H+i)%TotalElements]=0; //Only Change
                cout<<"Key = "<< Key << " Deleted at index = " << (H+i)%TotalElements <<":)\n";
                return;}
            i++;
        }
            
            cout<<"Key = "<< Key <<  " not Found !!! :(\n";
            return;
    }
            
};


int main() {
    
    
    Hash* H=new Hash();
    H->Insert(11);
    H->Insert(22);
    H->Insert(33);
    H->Insert(44);
    H->Insert(55);
    H->Insert(66);
    H->Insert(77);
    H->Insert(88);
    H->Insert(99);
    H->Insert(1000);
    H->Search(89);
    H->Search(99);
    H->Search(1000);
    H->Delete(99);
    H->Show();

    return 0;
}
