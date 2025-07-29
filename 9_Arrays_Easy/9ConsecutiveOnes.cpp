#include <iostream>
#include <vector>
#include <algorithm>  // for std::max_element
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> temp;
        int cnt=0;
        for(int i=0; i< nums.size();i++){
            if(nums[i]==1){
                if( nums[i-1]!=1){
                    temp.push_back(cnt);
                    cnt =0;
                }
                cnt++;
                temp.push_back(cnt);
            }
        }


        return *max_element(temp.begin(),temp.end());
    }
};


int main(){
    vector<int> nums = {1,1,0,1,0,1,1,1};
    Solution sol ;
    int res = sol.findMaxConsecutiveOnes(nums);
    cout<< res;
    

}