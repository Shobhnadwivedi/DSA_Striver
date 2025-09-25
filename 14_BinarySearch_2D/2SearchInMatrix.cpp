#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach = O(n*m) time complexity and O(1) space complexity
class BruteForceSolution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool isthere = false;
        for(int i=0; i< matrix.size(); i++){
            for(int j=0; j< matrix[0].size(); j++){
                if(matrix[i][j]== target){
                    isthere = true;
                    
                }

            }
        }
        return isthere;
    }
};

// Better Approach = O (N* log M) time complexity and O(1) space complexity
class Solution {
private:
    bool binarySearch(vector<int> &row, int target){
        int low = 0, high= row.size()-1;
        while(low<=high){
            int mid = (low + high)/2;

            if(row[mid]== target){
                return true;
            }
            else if(row[mid]< target){
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i< matrix.size(); i++){
            if(binarySearch(matrix[i], target)){
                return true;
            }
        }
        return false;

    }
};

//  2nd Better Approach = pehle we were searching in all the rows but now we will search in only those rows which can contain the target element
// T.C = O(n) + O(log m)   ,    SC = O(1)
class Solution2 {
private:
    bool binarySearch(vector<int> &row, int target){
        int low = 0, high= row.size()-1;
        while(low<=high){
            int mid = (low + high)/2;

            if(row[mid]== target){
                return true;
            }
            else if(row[mid]< target){
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i< matrix.size(); i++){
            if(matrix[i][0]<= target && matrix[i][matrix[0].size()-1]>= target){
                if(binarySearch(matrix[i], target)){
                    return true;
                }
            }
        }
        return false;
        
    }
};

// Optimal Approach =  Imagine the 2D matrix as a 1D sorted array and apply binary search on it
// T.C = O(log (n*m)) , SC = O(1)

class  OptimalSolution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = (n*m)-1;

        while(low<= high){
            int mid = low + (high - low)/2;
            int row = mid / m;
            int col = mid % m;

            if(matrix[row][col]== target){
                return true;
            }
            else if(matrix[row][col]< target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }

        }
        return false;

    }

};


int main(){
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    OptimalSolution sol;
    bool result = sol.searchMatrix(matrix, target);
    cout << result << endl; // Output: true
    
}
