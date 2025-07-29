#include<iostream>
#include<vector>
using namespace std;

// GFG -  https://www.geeksforgeeks.org/problems/square-root/1


//  Linear search =  T.C = O(sqrt(n)), S.C = O(1)
class BruteForceSolution {
  public:
    int floorSqrt(int n) {
        int i=1;
        while(i*i <=n){
            i++;
        }
        return i-1;
        
    }
};


//  Binary search =  T.C = O(log(n)), S.C = O(1)
class Solution {
  public:
    int floorSqrt(int n) {
        int low = 1, high = n ;
        int ans = 0 ;   //  important to initialize ans to 0, as in leetcode it gives some garbage value if not initialized

        while(low<= high){
            // use long long to avoid overflow for large n , mid*mid will not come under " int "
            // even if we put long long mid = (low+high)/2; it will  overflow ( in case of n = INT_MAX (2^31 - 1) )  =  because before calculating mid , we calculate = low + high = 1+ INT_MAX 
            //  so we use  long long mid = low + (high - low) / 2;
            //  this will not overflow as we are not adding low and high directly
            long long mid =low + (high - low)/2;      
            long long val = mid*mid;
            if(val <= n){
                ans = mid; 
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans ;
        
    }
};

int main(){
    Solution sol ;
    cout << sol.floorSqrt(0); 
    
}