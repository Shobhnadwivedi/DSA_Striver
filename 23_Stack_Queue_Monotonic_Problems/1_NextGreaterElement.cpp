#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums2.size(), -1);
        stack<int> st;

        for(int i=0; i<nums2.size(); i++){
            while(! st.empty() && nums2[st.top()]< nums2[i]){
                int idx = i - st.top();
                result[st.top()] = idx;
                st.pop();
            }
            st.push(i);
        }

        vector<int> ans ;
        /* 
        for(int i=0; i<nums1.size(); i++){
            int val = nums1[i];
            //finding index of val in nums2
            for(int j=0 ; j< nums2.size(); j++){
                if(nums2[j] == val){
                    ans.push_back(result[j]);
                    break;
                }
            }
        }
         */

        unordered_map<int,int> mp;
        for(int i=0 ; i< nums2.size(); i++){
            mp[nums2[i]] = result[i];
        }

        for(int i=0; i<nums1.size(); i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};