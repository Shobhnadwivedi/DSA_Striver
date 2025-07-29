#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;    

class Solution {
private:
    bool canMakeBouquets(vector<int>& bloomDay, int m ,int k, int mid){
        bool canMake = false;
        int cnt = 0 , n = bloomDay.size(), noOfBouquets = 0;
        for(int i=0; i<n; i++){
            if(bloomDay[i]<= mid){
                cnt++;
                if(cnt == k){
                    noOfBouquets++;
                    cnt=0; // Reset count after making a bouquet
                }
            }
            else{
                cnt =0;  // Reset count if we can't make a bouquet
            }
            
            
        }
        if(noOfBouquets >= m) {
            canMake = true;
        }
        return canMake;
        
    }


public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m*k >n){
            return -1; // Not enough flowers to make m bouquets
        }
        // instead of low =1 , use low = min_element
        int l = *min_element(bloomDay.begin(), bloomDay.end()) , h = *max_element(bloomDay.begin(), bloomDay.end()); 

        while(l<=h){
            long long mid = l +(h-l)/2 ;

            if(canMakeBouquets(bloomDay, m, k, mid)){
                h = mid - 1; // Try to find a smaller day
            }
            else{
                l = mid + 1; // Increase the day count
            }
  
        }
        return l;
    }
};

int main(){
    Solution sol;
    vector<int> bloomDay1 = {1,10,3,10,2};
    cout << sol.minDays(bloomDay1, 3, 1) << endl; // Output: 3

    vector<int> bloomDay2 = {1,10,3,10,2};
    cout << sol.minDays(bloomDay2, 3, 2) << endl; // Output: -1

    vector<int> bloomDay3 = {7,7,7,7,12,7,7};
    cout << sol.minDays(bloomDay3, 2, 3) << endl; // Output: 12
}