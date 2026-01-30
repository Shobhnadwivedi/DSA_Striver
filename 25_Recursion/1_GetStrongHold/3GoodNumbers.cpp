#include<iostream>
using namespace std;

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long cnt =0;

        if(n%2 == 0){
            cnt = (int)pow(20, n/2) % 1000000007 ;
        }
        else{
            cnt = (int)pow(20, n/2) * 5 % 1000000007 ;
        }

        return cnt  ;
        

    }
};