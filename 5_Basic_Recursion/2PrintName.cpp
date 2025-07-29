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

int main(){
    Solution nameprinter;
    nameprinter.name(5);
}