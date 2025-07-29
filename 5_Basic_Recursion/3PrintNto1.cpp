/*  Q.)
Print numbers from N to 1 (space separated) without the help of loops.
    Example 1:
        Input:   N = 10
        Output: 10 9 8 7 6 5 4 3 2 1
*/

//{ Driver Code Starts
#include <iostream>
using namespace std;


class Solution {
  public:
    void printNos(int N) {
        if (N==0){
            return ;
        }
        cout << N << ' ';
        N--;
        printNos(N);

    }
};


int main(){

    Solution sol;
    sol.printNos(6) ;
}