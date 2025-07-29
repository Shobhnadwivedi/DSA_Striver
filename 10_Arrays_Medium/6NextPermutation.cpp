#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.
*/


//  BRUTE SOLUTION 1 =  T.C = 
class Solution {
private : 
    void recurPermute(vector<int>& nums, vector<vector<int>>& ans, vector<int>& freq, vector<int>& ds ){      // pass by reference 
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<nums.size();i++){
            if(freq[i]==0){
                ds.push_back(nums[i]);
                freq[i]=1;
                recurPermute(nums, ans, freq, ds);
                ds.pop_back();
                freq[i]=0;
            }
        }

    }

public:
    vector<vector<int>> permute(vector<int>& nums){   // pass by reference  = use & 
        vector<vector<int>> ans;  
        vector<int> freq(nums.size(),0);
        vector<int> ds;
        recurPermute(nums,ans, freq, ds );
        return ans;

    }

};

class Solution2{
private:
    void recurPermute(vector<int>& nums, int l ){
        
        if(l>nums.size()-1){
            for(int i=0; i<nums.size();i++){
            cout<< nums[i]<< " ";
        }
            return ;
        }
        for(int i=l; i<nums.size();i++){
            swap(nums[i],nums[l]);
            recurPermute(nums, l+1);
            // backtracking dont forget or restrore previous numss after returning.
            swap(nums[i],nums[l]);         
        }
        
        cout<< endl;
    }

public:
    void permute(vector<int>& nums){
        int l=0;
        recurPermute(nums, l);
        
    }
};

class Solution3{
public:
    vector<int> permute(vector<int>& nums){
        int i= nums.size()-1;

        
        while(i>1){
            if(nums[i-1]< nums[i]){
                for(int j=nums.size(); j>=i;j--){
                    if(nums[j]>nums[i-1]){
                        swap(nums[j],nums[i-1]);
                        sort( nums.begin() + i , nums.end());
                        break;
                    }
                    
                }
                
                break;
            }
            
            i--;
        }
        return nums;
    }
};


class Solution4 {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index = -1;
        for(int i=n-1;i>0;i--){
            if(nums[i-1] < nums[i]){ 
                index = i-1 ;
                break;
            }
        }

        if(index==-1){
            reverse(nums.begin(),nums.end());  
        }
        else{
            for(int j= n-1; j>= index +1; j--){
                if(nums[j] > nums[index]){
                    swap(nums[j], nums[index]);
                    break;
                }
            }
            reverse( nums.begin()+ index+1, nums.end());
        }
    }       
};


int main(){
    Solution4 sol;
    vector<int> nums = {2,1,5,4,3,0,0};
    sol.nextPermutation(nums);
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << ' ';
    }


}