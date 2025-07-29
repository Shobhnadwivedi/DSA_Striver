#include <iostream>
#include <vector>
#include <map>

using namespace std;



// OPTIMAL SOLUTION  =  3 POINTER =   T.C = O(N)   ;  S.C = O(1)
//    DUTCH NATIONAL FLAG ALGORITHM
class Solution{
public:
    void sortColors(vector<int>& nums){
        int n = nums.size();
        int low=0, mid=0, high = n-1;

        while(mid<=high){
            if(nums[mid]==0){
                // swap mid and low 
                int temp1 = nums[mid];
                nums[mid]=nums[low];
                nums[low]= temp1;

                low++;
                mid++;
            }
            else if(nums[mid]==1){
                // do nothing just move forward
                mid++;
            }
            else {
                // swap mid and high
                int temp2=nums[mid];
                nums[mid]= nums[high];
                nums[high]= temp2;

                high--;
            }
        }

    }
};

int main(){
    vector<int> nums= {2,0,1,2,2,0,0,1,0,2,1,1};
    Solution sol;
    sol.sortColors(nums);
    for(int i=0;i<nums.size();i++){
        cout<< nums[i] << " ";
    }

}