#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric> // for accumulate
using namespace std;


class Solution {
private:
    int thedays(vector<int>& weights, int days, int mid){
        int count=0;
        int sum=0;
        for(int i=0; i< weights.size(); i++){
            if(sum + weights[i] > mid){
                count++;
                sum = weights[i];
            
            }
            else{ 
                sum += weights[i];
            }
        }
        return count+1; 
    }


public:
    int shipWithinDays(vector<int>& weights, int days) {
        // int low = *min_element(weights.begin(), weights.end())    is wrong bcuz if we take less than maximum no. , to us no. se saarey bade numbers ship nhi ho payenge due to capacity limit.but hume to saare krne h
        
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans =0;
        while(low<=high){
            long long mid = low + (high-low)/2;
            int requiredDays = thedays(weights, days, mid);
            

            if(requiredDays <= days){
                ans= mid ; // try to find a smaller capacity
                high = mid - 1;
            }
            else {
                low = mid + 1; // we need more capacity
            }

        }
        return ans;    
    }
};



int main(){
    vector<int> weights = {1,2,3,1,1};
    int days = 4;
    Solution sol;
    cout << sol.shipWithinDays(weights, days) << endl;


}