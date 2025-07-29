#include <iostream>
using namespace std; 

/*  Fctorial of N  =  1*2*3...*N    

1.  PARAMETERIZED WAY =   */


void fac(int n, int prod =1){ 
  
    if (n<1){
       cout << prod ;
       return; 
    }
    prod *= n;
    n--;
    fac(n,prod);
}

/* 2.  FUNCTIONAL WAY =    */
int factorial(int n){
    if(n==0){
        return 1;
    }
    return n* factorial(n-1);

}



int main(){
    int n;
    cin >> n;
    cout << factorial(n);
}