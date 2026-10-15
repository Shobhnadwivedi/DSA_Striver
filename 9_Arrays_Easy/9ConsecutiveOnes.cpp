#include <iostream>
#include <vector>
#include <algorithm>  // for std::max_element
using namespace std;


//. T.C = O(n)  - single pass   , S.C = O(1)  - in place changes
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxim =0, cnt =0;
        for(int i=0; i< nums.size() ; i++){
            if(nums[i]==1){
                cnt++;
                maxim = max(maxim, cnt);
            }
            else{
                cnt=0;
            }
        }

        return maxim ;
    }
};


int main(){
    vector<int> nums = {1,1,0,1,0,1,1,1};
    Solution sol ;
    int res = sol.findMaxConsecutiveOnes(nums);
    cout<< res;
    

}