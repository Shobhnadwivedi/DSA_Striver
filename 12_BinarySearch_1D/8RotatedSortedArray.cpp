#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




class Solution{

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0, h= n-1;
        int ans = -1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]== target){
                ans= mid;
            }
            // else if lagayenge to loop keeps running . why???
            if(nums[l]<= nums[mid]){     // idhar agar else if lagaya to loop keeps running, kyunki jab nums[mid]== target hoga , to pehli if wali condition satisfy hogi , isiliye else if wali condition check hi nhi hogi, aur ' l' and 'h' usme hi update ho rahe h, yo vo update hi nhi honge.
                if(nums[l]<= target  && target <= nums[mid] ){
                    h= mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if(nums[mid]<= target && target <= nums[h]){
                    l= mid+1;
                }
                else{
                    h = mid-1;
                }

            }
        }
        return ans;

        
    }

};

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    Solution sol;
    int result = sol.search(arr, 0);
    cout << result ;

}