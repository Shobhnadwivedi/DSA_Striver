#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=0 , h=n-1;
        int minim= nums [(l+h)/2] ;

        while(l<=h){
            int mid = (l+h)/2 ;
            
            if(nums[l]<= nums[h]){
                // minim = min( minim, nums[l]);
                if(nums[l] <= minim){
                    minim = nums[l];
                }

                break;
            }
            // if left is sorted sbse chota hoga nums[low]
            if(nums[l]<= nums[mid]){
                // minim = min( minim, nums[l]);
                if(nums[l] <= minim){
                    minim = nums[l];
                }
                l= mid+1;
            }
            else{
                // minim = min(minim , nums[mid]);
                if(nums[mid]<= minim){
                    minim = nums[mid];
                }
                h = mid -1;

            }
        }
        return minim ;
    }
};


int main(){
    vector<int> arr = {5, 6, 1, 2, 3, 4};
    Solution sol;
    int result = sol.findMin(arr);
    cout << result ;

}