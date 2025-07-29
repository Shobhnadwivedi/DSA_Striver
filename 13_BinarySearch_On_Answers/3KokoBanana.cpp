#include<iostream>
#include<cmath>  // for ceil function = cel(x) = gives the smallest integer >= x
#include<vector>
#include<algorithm> // for max_element
using namespace std;


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        //  Binary search =  T.C = O(n*log(max(piles))), S.C = O(1)

        //  high = *max_element(piles, piles + n);          t.c of this stl = o(n)
        int low=1 , high = *max_element(piles.begin(), piles.end());    // max_element returns an iterator to the maximum element in the range

        while(low<=high){
            long long mid = low + (high - low) / 2; // Calculate mid to avoid overflow
            long long val = 0;
            for(int i=0; i<n; i++){
                // safer than ceil((double)piles[i]/mid)
                val += (piles[i] + mid - 1) / mid;
            }

            if(val<=h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            

        }
        return low;

    }
};



int main(){
    Solution sol;
    vector<int> piles = {30,11,23,4,20}; // Example piles of bananas
    int h = 6; // Example hours available to eat
    cout << sol.minEatingSpeed(piles, h) << endl; 
}