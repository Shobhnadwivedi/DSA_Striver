#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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


class Solution2{
public:
    int singleNumber(vector<int>& nums){
        int xor = 0;
        for(int i=0; i< nums.size(); i++){
            xor = xor ^ nums[i];
        }
        return xor;
    }

};