#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Brute Force Approach = O(n*m) time and O(1) space complexity.
class BruteSolution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {    
        int n = arr.size();
        int m = arr[0].size();
        int cnt_max = 0;
        int index= -1;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<m; j++){
                count += arr[i][j];
            }
            if (count > cnt_max){
                cnt_max = count;
                index = i;
            }

        }
        return index;
        
    }
};

// Optimal Approach= Binary Search = O(n * log2 m) time and O(1) space complexity.
// Since each row is sorted , so sizeofrow = m - first_occurence_of_1   will give the count of 1's in that row.
// we can use lower_bound(1) or upper_bound(0) or first_occurrence_of_1 to find the first occurence of 1 in that row.

class Solution {
  private:
    int lower_bound(vector<int>& row) {
        int left = 0, right = row.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (row[mid] == 1) {
                right = mid - 1; // move left to find first occurrence
            } else {
                left = mid + 1; // move right
            }
        }
        return left; 
    }
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int index = -1;
        int max_count = 0;  

        
        for(int i=0; i< arr.size(); i++) {
            int cnt = 0;
            cnt = arr[i].size() - lower_bound(arr[i]);
            if(cnt > max_count) {
                max_count = cnt;
                index =i;

            }
            
        }
        return index;
        
    }
};