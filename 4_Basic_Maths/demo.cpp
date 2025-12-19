#include <iostream>
#include <vector>
using namespace std;

/*
a function to print n numbers .
*/

void printn(int n, int i){
    if(n==0){
        return ;
    }
    cout << i << " " ;
    printn(n-1, i++);

}

int main(){
    int i=1;
    printn(5,i);
}

