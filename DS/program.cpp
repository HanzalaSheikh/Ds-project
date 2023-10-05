#include <bits/stdc++.h>
// #include <
using namespace std;

// int main() {
    // cout << "HELLO WORLD!\n";

// Program To print Rectangular pattern
    // int n,m;
    // cout << "Rows:\n";
    // cin >> n;
    // cout << "Columns:\n"; 
    // cin >> m;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         cout << '*';    
    //     }
    //     cout << endl;
    // }

// Program To print Hollow Rectangular pattern
    // int n,m;
    // cout << "Rows:\n";
    // cin >> n;
    // cout << "Columns:\n"; 
    // cin >> m;
    // for(int i=1; i<=n; i++){
    //     for (int j= 1; j <=m; j++){        
    //         if( i==1 || i==n){
    //             cout << "*";
    //         }
    //         else if (j==1 || j ==m){
    //             cout << "*";
    //         }
    //         else{
    //             cout << " ";
    //         }
    //     }
    //     cout << endl;
    // }

// Program to print Inverted Pyramid
    // int n;
    // cin>>n;
    // int k = n; // initializing k to the value n so we can decrement the value of n without changing input number.
    // for (int i = 1; i <= n; i++)
    // {   
    //     for (int j = k; j > 0; j--){
    //             cout << "*";
    //     }
    //     k--;
    //     cout << endl;
    // }

// Program to print Inverted Pyramid
    // int n;
    // cin>>n;
    // for (int i = n; i >=1; i--)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout<<"*";
    //     }
    //     cout<< endl;
    // }
    
// Program to print Inverted Pyramid 180

    // int n;
    // cin>>n;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <=n ; j++)
    //     {
    //         if (j<=n-i)
    //         {
    //             cout<<" ";
    //         }
    //         else{
    //             cout<<"*";
    //         }
    //     }
    //     cout<< endl;
    // }

// Program to print Inverted Number Triangle


    // int n;
    // cin>> n;
    // for (int i = 1; i <= n ; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout<<i;
    //     }
    //     cout << endl;
    // }

// Program to print floyd Triangle

    // int n;
    // cin>> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout<<j;

    //     }
    //     cout<< endl;
    // }
    
// Program to print a butterfly Pattern

// int n;
// cin>>n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout<<"*";
//         }
//         int space = 2*n-2*i;
//         for (int j = 1; j <=space; j++)
//         {
//             cout<< " ";
//         }
//         for (int j = 1; j <= i; j++)
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     for (int i = n; i >= 1; i--)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout<<"*";
//         }
//         int space = 2*n-2*i;
//         for (int j = 1; j <=space; j++)
//         {
//             cout<< " ";
//         }
//         for (int j = 1; j <= i; j++)
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }

// ADVAMCED 

// inverted pattern numbers

    // int n;
    // cin>>n;
    // for (int i = n; i >= 1; i--)
    // {
    //     for (int j=1; j<=i ; j++)
    //     {
    //         cout<<j;
    //     }
    //     cout<<endl;
    // }
    

    // 0-1 patterm

//     int n;
//     cin>>n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             if ((i+j)%2==0)
//             {
//                 cout<<"1";
//             }
//             else{
//                 cout<<"0";
//             }
//         }
//         cout<< endl;
//    }
    

// Program to reverse a number;

    // int n;
    // cin>> n;
    // int remainder;
    // int quotient;
    // // for (int i = 1; i < n; i++)
    // // {
    // //     /* code */
    // // }
    // while (n>0)
    // {
    //     remainder = n%10;
    //     quotient = n/10;
    //     cout<< remainder;   
    //     n = quotient;     
    // }
    

// Program for armstrong number;

    // int n;
    // cin>> n;
    // int remainder;

// Program for SubARRAY

    // int n;
    // cin>> n;
    // int a[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin>> a[i];
    // }
    // // int sum = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         sum+= a[j];
    //         cout<<sum<< endl;
    //     }
    //     cout<< endl;
    // }
    
    
// Program of Google KickStart
// SubArray

// int count;
// cin>> count;
// cout<< count;

// Function of NCR

// int fact(int x){
//     int fac=1;
//     if (x==fac)
//     {
//         return fac;
//     }
//     else{    
//     for (int i = x; i >= 2; i--)
//     {
//         fac*=i;
//     }
//     }
//     return fac;
// }
// int nCr(int n,int r) {
//     // Program for NCR

//         // int n,r,f;
//         // cin>>n>>r;
//         int f = n-r;

//     // N R F Factorials    
//         int Nfac = fact(n);
//         // cout<< " N Fac: " << Nfac;
//         int Rfac = fact(r);
//         // cout<< " r Fac: " << Rfac;
//         int Ffac = fact(f);
//         // cout<< " N-r Fac: " << Ffac;

//         int NCR = Nfac/(Ffac*Rfac);
//         // cout<< " NCR: ";
//         return NCR; 
// }
    
// function of Ispythagorean
// bool Ispythagorean(int x, int y, int z){
//     int a = max(x, max (y,z));
//     int b,c;
//     if (a==x)
//     {
//         b = y;
//         c = z;
//     }
//     else if (a==y)
//     {
//         b = x;
//         c = z;
//     }
//     else{
//         b = x;
//         c = y;
//     }

//     if (a*a == b*b + c*c)
//         return true;
//     else
//         return false;

// }


// void SieveOFEratosthenes(int n){
//     int prime[100] = {0};
//     for (int i=2; i<=n; i++){
//         if(prime[i]==0){
//             for(int j=i*i; j<=n; j+=i){
//                 prime[j]=1;
//             }
//         }
//     }
//     for (int i=2; i<=n; i++){
//         if(prime[i]==0){
//             cout<<i<<" ";
//         }
//         // cout<<endl;
//     } 
// }


int main() {


// Febonacci Number

    // int n;
    // cin>> n;
    // int t1 = 0;
    // cout<<t1<<endl;
    // cout<<t1+1<<endl;
    // int newTerm;
    // for (int i = 1; i < n-1; i++)
    // {

    //     newTerm = t1 + i;
    //     cout<<newTerm<<endl;
    //     t1=newTerm;
    // }


// Program to print pascal triangle
// using NCR
    // int count;
    // cin>> count;

    

    // for (int i = 0; i < count; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout<< nCr(i,j);
    //     }
    //     cout<<endl;
        
    // }
    


// program ro check wether pythagorian triplet or not

// int x,y,z;
// cin>>x,y,z;

// if (Ispythagorean(x,y,z))
// {
//     cout<< "IT is a pythagorean triplet";
// }
// else{
//     cout<< "Not";
// }


    int n;
    cin>> n;
//     sieveOfEratosthenes(n);

    // // number of trailing zeros
    // int result = 0;
    // for (int i = 5; i <= n; i*=5)
    // {
    //     result= result + n/i;
    // }
    // cout<< result;

    // Palindrone number 121 ---> 121
    
    // int numnew,m;
    // for (int i = n; i > 0; i--)
    // {
    //     m = n%10;
    //     numnew = (m*10)    
    // }
    
// Reccursion Q 


















   
    
    return 0;
}
//  judge Results window control Alt B