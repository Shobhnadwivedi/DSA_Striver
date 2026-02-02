#include<iostream>
#include<cmath>
using namespace std;

// Apply Permutation and Combination concept 
// at even positions we can have 5 choices (0,2,4,6,8)
// at odd positions we can have 4 choices (1,3,5,7)


class WrongSolution1 {
public:
    int countGoodNumbers(long long n) {
        long long cnt =0;

        if(n%2 == 0){
            cnt = (int)pow(20, n/2) % 1000000007 ;    // without int = error : cannot do :  "double" % "int"
        }

        else{                                //  pow() uses floating-point math    ;    For large exponents, results are approximate.  ;    Modulo arithmetic requires exact integers

            cnt = (int)pow(20, n/2) * 5 % 1000000007 ;      //  20^(n/2)  → astronomically large   =     must apply modulo at every multiplication, not at the end.
        }

        return cnt  ;
        

    }
};


class Solution {
public:
    string dectobinary(int n){

        if(n==0){
            return "0" ;
        }
        string ans = "" ;
        while(n>0){
            int bit = n%2 ;
            ans = to_string(bit) + ans ;
            n = n/2 ;
        }

        return ans ;
    }



// take 3 parameters : base  ; exp  ; mod 
// convert exp into binary 
// iterate from back to front of binary representation of b
// keep squaring the base and taking mod m and multiply when bit is 1

    int modularpow(long long base, long long exp, long long mod) {
        string bin = dectobinary(exp);

        long long result = 1;
        base = base % mod ;

        for(int i = bin.size() -1 ; i>=0 ; i--){
            if( bin[i] == '1'){
                result = (result * base) % mod ;
            }
            base = ( base * base) % mod ;
        }
        return result ;
    }

    int countGoodNumbers(long long n) {
            long long cnt =0;

            if(n%2 == 0){
                cnt = (int)modularpow(20, n/2,1000000007) % 1000000007 ;    
            }

            else{                               

                cnt = (int)modularpow(20, n/2, 1000000007) * 5 % 1000000007 ;   
            }

            return cnt  ;
        }

};
int main(){
    long long n = 17 ;
    Solution sol ;
    cout<< sol.countGoodNumbers(n) ;

}