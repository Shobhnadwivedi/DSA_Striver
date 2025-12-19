#include<iostream>
#include<string>
using namespace std;

/*  Q.1) 
Print GFG n times without the loop.

Example:
    Input:
    5
    Output:
    GFG GFG GFG GFG GFG
*/

class Solution {
    public:
    int cnt=0;
    void name(int N){
        if(cnt==N){
            return;
        }
        cout << "GFG " ;
        cnt++ ;
        name(N) ;
    }
};


class Solution2 {
    public:
    void name(int N){
        if(N==0){
            return;
        }
        cout << "GFG " ;
        name(N-1) ;
    }
};



int main(){
    Solution2 nameprinter;
    nameprinter.name(5);
}