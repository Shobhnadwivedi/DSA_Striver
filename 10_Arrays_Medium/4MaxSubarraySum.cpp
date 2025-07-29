#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// BRUTE   = T.C = O(N^3)  = 3 nested loops
class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int n=nums.size();
        int maxx= nums[0];                   //      = when maxx what initialized maxx = 0 , the answer was coming wrong for nums[-1] , bcuz  while computing maximum between -1 & 0 =>  0 is maximum , to negative answer kbhi ho hi nhi skta 

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum+=nums[k];

                }
                maxx = max(maxx,sum);
            }
        }
        return maxx;
    }
};


// BETTER = 
class Solution2{
public:
    int maxSubArray(vector<int>& nums){
        int n=nums.size();
        int maxx=nums[0];
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i; j<n;j++){
                sum+=nums[j];
                maxx = max(sum,maxx);
            }
        }
        return maxx;

    }

};


// OPTIMAL  = T.C = O()
class Solution3{
public:
    int maxSubArray(vector<int>& nums){
        int maxx = INT_MIN;
        int sum=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxx = max(maxx,sum);
            if(sum<0){
                sum=0;
            }

        }
        return maxx;

    }

};

int main(){
    vector<int> nums = {-2};
    Solution3 sol;
    cout<< sol.maxSubArray(nums);
}