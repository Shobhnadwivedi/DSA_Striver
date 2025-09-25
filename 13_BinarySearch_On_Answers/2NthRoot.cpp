#include<iostream>
#include<algorithm>
#include<cmath> // for pow function
using namespace std;


//    GFG  =    https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

class Solution {
  public:
    int nthRoot(int n, int m) {
        
        int l=0, h= m;
        int ans = -1; // Initialize ans to -1 to indicate no root found

        while(l<=h){
            // Use long long to prevent overflow of mid^n  and this formula to prevent overflow in case where (l+h) could overflow.
            long long mid = l +(h-l)/2; 
            long long val = pow(mid, n);    // Calculate mid raised to the power of n

            if(val == m){
                ans = mid;
                break;
            }
            else if(val < m){
                l = mid+1;
            }
            else{
                h= mid-1;
            }

        }
        return ans;
    }
};

int main(){
    Solution sol;
    int n = 3; // Example: Find the 3rd root
    int m = 27; // Example: of 27
    cout << sol.nthRoot(n, m) << endl; // Output should be 3 since 3^3 = 27

}