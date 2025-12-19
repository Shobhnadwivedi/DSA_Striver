/*  Q.1) A Function to print N numbers . let n= 3.         */


#include <iostream>
using namespace std;



void printNtimes(int n){
    if(n==0){
        return;
    }

    cout << "Shobhna " ;
    return printNtimes(n-1);

}


int main(){
    int n;
    cin >> n;

    printNtimes(n);
}