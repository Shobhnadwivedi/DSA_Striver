#include <iostream>
#include <vector>

using namespace std;

/*             268 LEETCODE - > https://leetcode.com/problems/missing-number/description/ 

BEST sol is of  "sum of n numbers" or "xor" -

1.                                                        xor properties :             

XOR gives 1 only when the bits are different.
If yes -> 1          if no -> 0
E.g:           5 ^ 3 =   0101  ^ 0011  =  0110 = 6

2.  same numbers xor gives zero ALWAYS   ->         2 ^ 2 = 0010 ^ 0010 = 0000

3. xor of a number with zero is the number itself ALWAYS  ->       6 ^ 0 =  0110 ^ 0000 = 0110 = 6 

SOLUTION->    when we do xor of all numbers from 0 to n    
        ->    then we do xor of all elements of array 
        ->    then we xor these both      
        ->    the same numbers get cancelled to 0 and only 1 is left that is missing bcuz uska pair nhi ban paya . so the answer is the missing number.


*/

class SolutionXOR {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_all=0, xor_array=0;
        for(int i = 0; i<n +1 ; i++){
            xor_all = xor_all ^ i;
        }

        for(int i = 0; i<n ; i++){
            xor_array = xor_array ^ nums[i];
        }

        return xor_all ^ xor_array;
    }
};



//      SUM OF N NUMBERS METHOD  - T.C = O(n)  S.C = O(1)   -  SUM OF N NUMBERS = n*(n+1)/2

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total_sum =  n*(n+1)/2;              
        int arr_sum=0;
        for(int i =0; i<n; i++){
            arr_sum += nums[i];
        }

        return total_sum - arr_sum;
    }
};





int main(){
    vector<int> nums = {3,0,5,1,2};
    Solution sol ;
    int res = sol.missingNumber(nums);
    cout<< res;
    
    

}