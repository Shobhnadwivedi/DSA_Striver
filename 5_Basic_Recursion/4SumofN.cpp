/*
Given an integer n, calculate the sum of series 1^3 + 2^3 + 3^3 + 4^3 + … till n-th term.
    Examples:
        Input: n = 5
        Output: 225
*/

#include<iostream>
using namespace std ;

class Solution{
    public:
    
    int sumOFSeries(int n){
        if (n==0){
            return 0 ;
        }
        
        return  (n*n*n) + sumOFSeries(n-1);

    }

};


int main(){
    Solution sol;
    cout << sol.sumOFSeries(5) ;
}