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
            cnt = (int)pow(20, n/2) % 1000000007 ;    // without int -> error : cannot do :  "double" % "int"
        }

        else{                                //  pow() uses floating-point math    ;    For large exponents, results are approximate.  ;    Modulo arithmetic requires exact integers

            cnt = (int)pow(20, n/2) * 5 % 1000000007 ;      //  20^(n/2)  → astronomically large   =     must apply modulo at every multiplication, not at the end.
        }

        return cnt  ;
        

    }
};

// we can't use normal exponentiation method as     -    O(exponent ) time complexity not feasible for large exponents ;  Numbers become astronomically large
// hence we will use modular exponentiation method
// in most problems we don't even need the actual large number , we just need it modulo m  -    (  a^b mod m  )


// One of the most important properties of modular arithmetic is:    (a×b) mod m = ( (a mod m) × (b mod m) ) mod m      ;   reducing numbers at every step(multiplication) and never let them explode.
// 1. Clculate binary representation of exponent  =  e.g    a^13   ; 13 = 1101 in binary = 8 + 4 + 0 + 1
// And we can compute    a^1  ,  a^2  ,   a^3 ... very easily by squaring previous result   ;   T.C : O(log exp) steps




class Solution2 {
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
// convert exp into binary string using dectobinary function
// iterate from back to front of binary representation of exp 
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
                cnt = (long long )modularpow(20, n/2,1000000007) % (long long )1000000007 ;    
            }

            else{                               

                cnt = (long long )modularpow(20, n/2, 1000000007) * 5 % (long long )1000000007 ;   
            }

            return cnt  ;
        }

};
int main(){
    long long n = 17 ;
    Solution2 sol ;
    cout<< sol.countGoodNumbers(n) ;

}