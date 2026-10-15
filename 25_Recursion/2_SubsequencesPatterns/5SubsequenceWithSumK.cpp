#include<iostream>
#include<vector>
using namespace std;

// 2. PRINT ALL POSSIBLE SUBSEQUENCES WITH SUM K 
class Solution{
  public:
    
    void printF(int i, vector<int> &ds, vector<int> arr, int n, int sum, int k){

        // 1. BASE CASE
        if(i>=n){
            // agar sum == 2 -> print the array
            if( sum == k ){
                for( auto it : ds){
                    cout << it << " ";
                }
                cout<< endl;
                return;
            }
            // varna return back withount printing
            return;
        }

        // 2. Take & update sum = sum + arr[i];
        ds.push_back(arr[i]);
        printF(i+1, ds, arr, n , sum+arr[i], k);

        // 3. Don't Take & since we didn't include arr[i]....sum remains sum
        ds.pop_back();
        printF(i+1, ds , arr, n, sum, k);


    }
};

// 3. PRINT ONLY 1 SUBSEQUENCE WITH SUM = K       -->>      function will be int type
class Solution2{
  public:
    
    bool print1(int i, vector<int> &ds , int n, int k, int sum, vector<int> arr ){

        // BASE CASE 
        // In cas of scrictly positive array, we can add a case -> 
        // if (sum > k) return false; 

        if(i==n){

            if(sum == k){
                for(auto it : ds){
                    cout << it << " ";
                }
                return true;
            }

            else return false; 
        }

        ds.push_back(arr[i]);

        if( print1( i+1 , ds, n , k , sum + arr[i] , arr )== true){
            return true ;
        }

        ds.pop_back();

        if( print1( i+1 , ds, n , k , sum , arr )== true){
            return true ;
        }
    
        return false ;
    }
};



// 3. PRINT ONLY 1 SUBSEQUENCE WITH SUM = K    ->>     function will be int type
class Solution3{
  public:
    
    int printCnt(int i, vector<int> &ds , int n, int k, int sum,  vector<int> arr ){

        if(i >= n){
            if(sum ==k){
                return 1;
            }
            else return 0;
        }

        ds.push_back(arr[i]);

        int l = printCnt(i+1, ds, n, k, sum + arr[i] , arr);

        ds.pop_back();

        int r = printCnt(i+1, ds, n, k, sum , arr);

        return l+r ; 
    }


};


int main(){
    cout<< "Enter length of array: ";
    int n ;
    cin >> n;

    cout << "Enter array elements: ";
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout<< "Enter k : ";

    int k ;
    cin >> k;

    vector<int> ds;
    int sum =0;
    Solution3 sol ;

    cout << sol.printCnt(0,ds , n, k,  sum, arr) ;
    

}