#include<iostream>
using namespace std;

bool prime(int n){

    if(n<=1){ return false;}
    for(int i=2; i*i<n ; i++){
        if(n%i==0){
            return false;
        }
       
    }
    return true;
}

int noOfprime(int n){
    int k=n;
    int cnt=0;
    for(k=2; k<n;k++){
        bool prime = true;
        for(int i=2; i*i<k ; i++){
            if(k%i==0){
                prime=false;
            }
            
        }
        
        if(prime){cnt++;}

    }
    
    return cnt;
}

int main(){
    int n;
    cin>> n;
    cout<< noOfprime(n);
    
}
