#include <iostream>
#include <vector>

using namespace std;


class Solution1 {
    public:
      // Function to perform selection sort on the given array.
    void insertSort(vector<int> &arr) { 
        int n = arr.size();
        
        for(int i=0; i<= n-2 ; i++){

            for(int j=i+1; j>=1; j--){           // ( j=0  se j = i+1)      j>=1 islye kyuni fir 1st index ke saaath 0th wala compare hoga 
                if (arr[j]<arr[j-1]){            //  but if 0 bhi count krle to uske saath compare krne wala koi nhi
                    //  swap
                    int temp = arr[j];
                    arr[j]  = arr[j-1];
                    arr[j-1] = temp;
                    
                }
            }
        }
    }
};


class Solution2 {    //     for ki jagah WHILE loop
    public:
      // Function to perform selection sort on the given array.
    void insertSort(vector<int> &arr) { 
        int n = arr.size();
        
        for(int i=0; i<= n-1 ; i++){
            int j=i;
            while(j>0 && arr[j]<arr[j-1]){ 
                    //swap
                    int temp = arr[j];
                    arr[j]  = arr[j-1];
                    arr[j-1] = temp;
                    
                    j--;
                }
                
            
        }
    }
};


// to calculate best case alag se 
class Solution {    //     for ki jagah WHILE loop
    public:
      // Function to perform selection sort on the given array.
    void insertSort(vector<int> &arr) { 
        int n = arr.size();
        
        for(int i=0; i<= n-2 ; i++){
            int didswap=0;
            int j=i+1;
            while(j>0 && arr[j]<arr[j-1]){ 
                    //swap
                    int temp = arr[j];
                    arr[j]  = arr[j-1];
                    arr[j-1] = temp;
                   
                    j--;
            }
            didswap=1;
            if(didswap==0){
                
                break;
            }  
        } 
           

    }
};



int main(){
    vector <int> arr ={4,1,3,9,7};
    
    Solution sol;
    sol.insertSort(arr);
    int n = arr.size() ;
    for(int i=0;i<n;i++){
        cout<< arr[i]<< " ";
    
    }
    
    }