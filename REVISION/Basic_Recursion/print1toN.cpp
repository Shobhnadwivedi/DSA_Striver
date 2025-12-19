#include <iostream>
using namespace std;

void print1toN( int n , int cnt){
    
    if( cnt==n){
        return ;
    }
    
    cout << cnt +1 << " ";
    cnt++;
    return print1toN(n, cnt);

}


void print1toNbacktracking( int n ){
    if(n==0){
        return;
    }

    return print1toNbacktracking(n-1);
    
    cout << n << " ";
}


int main(){
    int n; 
    cin >> n;
    int cnt =0 ;
    print1toNbacktracking(n);
}