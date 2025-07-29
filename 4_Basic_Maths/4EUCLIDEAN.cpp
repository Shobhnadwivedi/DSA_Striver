#include<iostream>
using namespace std;

int gcdByEuclidean(int a,int b){
    // keep modulating jb tak both are greater than zero
    // ek bhi zero hua to = stop
    while(a>0 && b>0){
        // if a is greater = a will be modulated
        if(a>b){
            a = a%b ;
        }
        else{
            b = b%a ;
        }
    }

    // now check konsa zero hua 

    if(a==0){
        return b;
    }
    // else  b==0
    return a;
}


int main(){
    int a,b;
    cin>> a;
    cin>> b;
    
    cout << gcdByEuclidean(a,b);
}
