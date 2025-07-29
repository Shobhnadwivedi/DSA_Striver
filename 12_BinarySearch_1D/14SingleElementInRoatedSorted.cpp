#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solutionwrong {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, h= nums.size()-1;
        int ans;
        while(l<=h){
            int mid = (l+h)/2;

            if(nums[mid]!= nums[mid-1] && nums[mid]!= nums[mid+1] ){
                ans = nums[mid];
                break;
            }

            else if(nums[mid]==nums[mid-1]){

                if((mid-l)%2 == 0){        //  if (mid - low) divisible by 2 h , to left side odd no. of elements hai , mtlb vo single element lies here. 
                    h = mid-1;
                }
                else{
                    l = mid+1;

                }
            }

            else if(nums[mid]== nums[mid+1]){
                if((h-mid)%2 == 0){   //  right hand side odd no. of elements , so that single element lies here.
                    l = mid+1;
                }
                else{
                    h = mid-1;
                }
            }
            

        }
        return ans;
    }
};


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l=1, h= n-2;
        int ans;

        if(n==1){
            ans= nums[0];
        }
        else if(nums[1]!= nums[0]){
            ans = nums[0];
        }
        else if(nums[n-1]!= nums[n-2]){
            ans = nums[n-1];
        }

        while(l<=h){
            int mid = (l+h)/2;
            //  agar mid ke agal bagal wala same nahi to mid is the answer 
            if(nums[mid]!= nums[mid-1]  &&  nums[mid]!= nums[mid+1]){
                ans = nums[mid];
                break;
            }
            else if (nums[mid-1] == nums[mid]){
                if(mid%2 ==0){
                    h= mid-2;
                }
                else{
                    l = mid+1;
                }
            }
            else if (nums[mid+1] == nums[mid]){
                if(mid%2 ==0){
                    l = mid+2;
                }
                else{
                    h = mid-1;
                }
            }
        }
        return ans ;
    }
};


int main(){
    vector<int> arr = {1,1,2,2,3,3,4,5,5,6,6,7,7};
    Solution sol;
    int result = sol.singleNonDuplicate(arr);
    cout << result ;

}