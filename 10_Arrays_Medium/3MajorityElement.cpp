#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
  public:
    int majorityElement(vector<int> &nums){
        int cnt =1, maxcnt= INT_MIN;
        int ans;

        sort(nums.begin(), nums.end());

        for(int i = 1 ; i< nums.size() ; i++){
            if(nums[i] == nums[i-1]){
                cnt++;
            }
            else{
                maxcnt = max(maxcnt, cnt);
                if(maxcnt > nums.size()/2){
                    return nums[i-1];
                }
                
            }
        }

        return 0;
    }
};

int main(){

}
