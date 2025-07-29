#include <iostream>
#include <vector>
#include <algorithm>  // For sort function
using namespace std;



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        for(int i =0 ; i< n;i++){
            int sum = nums[i];
            for(int j=i+1; j<n ;j++){
                if((sum + nums[j]) == target){
                    result.push_back(i);
                    result.push_back(j);
                }
            } 
        }
        
        return result;

    }
};


class Solution2{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        
        int l=0, r = nums.size()-1;
        vector<int> ans;
        while(l<= r){
            if((nums[l]+nums[r]) < target ){
                l++;
            }
            else if((nums[l]+nums[r]) > target ){
                r--;
            }
            else{
                ans.push_back(l);
                ans.push_back(r);
                break;
            }
        }

        for(int i=0;i< ans.size(); i++){
            cout<< ans[i] <<" " ;
        }
        return ans;
    }
};



int main(){
    vector<int> nums = {3,0,5,1,2};
    Solution2 sol ;
    sol.twoSum(nums,8);

    
    

}