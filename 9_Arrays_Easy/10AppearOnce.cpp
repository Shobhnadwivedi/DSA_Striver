#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


//  BRUTE FORCE SOLUTION = T.C = O(n) same as optimal , but   S.C = O(n)
class Solution{
public:
    int singleNumber(vector<int>& nums){
        unordered_map<int,int> mpp;
        for(int i=0; i< nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(auto it: mpp){
            if(it.second ==1){
                return  it.first;
            }
        }
    }

};

// OPTIMAL SOLUTION = T.C = O(n)  S.C = O(1)

// Take xor of all the elements in the array. The same numbers will cancel each other out and only the number that appears once will remain.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xxor = 0;
        for(int i=0; i< nums.size(); i++){
            xxor = xxor ^ nums[i];
        }
        return xxor;
    }
    
};