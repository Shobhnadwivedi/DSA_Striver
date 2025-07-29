#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
      // Function to perform selection sort on the given array.
    void bubbleSort(vector<int> &arr) {
        int n = arr.size();
        for(int i=0;i<= n-2;i++){
            
            for(int j=0; j<=n-2-i; j++){
                
                if(arr[j]>arr[j+1]){
                    // swap
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;

                }
            }
        }
    }
};

//   Striver's Solution
class Solution2 {
    public:
      // Function to perform selection sort on the given array.
    void bubbleSort(vector<int> &arr) {
        int n = arr.size();
        
        for(int i=n-1;i>= 1;i--){                //  from i = n-1 ....se i=0  and i--      

            int didswap =0;
            
            for(int j=0; j<=i-1; j++){         //  from j=0   se  j=i-1 tak.....1st j=n-2  then n-3....then n-4...
                
                if(arr[j]>arr[j+1]){
                    // swap
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;

                    didswap=1;
                }
            }
            if (didswap==0){break;}
        }
    }
};



int main(){
    vector <int> arr ={9,4,18,6,2,22};
    
    Solution sol;
    sol.bubbleSort(arr);
    int n = arr.size() ;
    for(int i=0;i<n;i++){
        cout<< arr[i]<< " ";
    
    }
    
    }