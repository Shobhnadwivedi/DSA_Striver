#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int maxim=0;
        for(int i=0;i<n;i++){

            for(int j=i;j<n;j++){
                int sum=0;
                for(int m=i;m<=j;m++){
                    sum+=arr[m];

                }
                if(sum==k){
                    maxim = max(maxim, j-i+1);
                }
            }
        }
        return maxim;
    }

};


class Solution2{       //   t.c =o(n^2)
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int maxim=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+= arr[j];
                
                if(sum==k){
                    maxim = max(maxim, j-i+1);
                }
            }
        }
        return maxim;
    }

};


class Solution3{
public:
    int longestSubarray(vector<int>& arr, int k){
        int psum=0, len=0;
        int n = arr.size();
        unordered_map<int,int> h_mp ;
        for(int i=0; i<n; i++){
            psum+= arr[i];
            h_mp[psum] =i;
            if(psum==k && (i+1)>len){
                len+= i+1;
            }
            if((h_mp[psum]-h_mp[psum-k]) > len ){
                len +=  (h_mp[psum]-h_mp[psum-k]);
            }
        }
        return len;
    }
};


int main(){
    vector<int> nums={1,2,3,1,1,1,4,2,3};
    Solution3 sol;
    int res = sol.longestSubarray(nums,3);
    cout<< res ;
}