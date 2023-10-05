// Hashing [Quadratic Probing]
// Formula [(H+i*i)%N]

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
            if ( HashArray[(H+i*i)%TotalElements] == 0 ) break;
            else if(i>TotalElements-1){
                FULL = 1;
                break;
                }
            i++;
        }
        if (FULL == 1){
            cout<<"Hash Array is FULL or Key Cannot be inserted:(\n";
            Show();
            
        }
        else{
            HashArray[(H+i*i)%TotalElements]=Key;
            cout<<"Key = "<< Key << " inserted at index = " << (H+i*i)%TotalElements <<":)\n";
            Show();
            
        }
        
    }
    
    void Search(int Key){
        int H=iHash(Key,TotalElements);
        int i=0;
        while(HashArray[(H+i*i)%TotalElements] != 0 && i<TotalElements){
            if ( HashArray[(H+i*i)%TotalElements] == Key ) {
                cout<<"Key = "<< Key << " Found at index = " << (H+i*i)%TotalElements <<":)\n";
                return;}
                i++;}
        cout<<"Key = "<< Key <<  " not Found !!! :(\n";
        return;
            
    }

    void Delete(int Key){
        int H=iHash(Key,TotalElements);
        int i=0;
        while(HashArray[(H+i*i)%TotalElements] != 0 && i<TotalElements){
            if ( HashArray[(H+i*i)%TotalElements] == Key ) {
                
                HashArray[(H+i*i)%TotalElements]=0; //Only Change
                cout<<"Key = "<< Key << " Deleted at index = " << (H+i*i)%TotalElements <<":)\n";
                return;}
            i++;
        }
            
            cout<<"Key = "<< Key <<  " not Found !!! :(\n";
            return;
    }
            
};


int main() {
    
    
    Hash* H=new Hash();
    H->Insert(22);
    H->Insert(32);
    H->Insert(42);
    H->Insert(52);
    H->Insert(62);
    H->Insert(72);
    H->Insert(82);
    H->Insert(92);
 
    H->Insert(1000);
    H->Search(32);
    H->Search(1000);
    H->Delete(1000);
    H->Show();

    return 0;
}
