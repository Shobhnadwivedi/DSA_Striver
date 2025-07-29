#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
      // Function to sort an array using quick sort algorithm.
      void quickSort(vector<int>& arr, int low, int high) {
        if(low<=high) return;                                     // mistake =  if (low==high)

        int part_index = partition(arr,low,high);

        quickSort(arr, low,part_index-1);
        quickSort(arr,part_index+1,high);
      }
  
    public:
      // Function that takes last element as pivot, places the pivot element at
      // its correct position in sorted array, and places all smaller elements
      // to left of pivot and all greater elements to right of pivot.
      int partition(vector<int>& arr, int low, int high) {
        int pivot=arr[low];
        int i =low;
        int j =high;

        while(i<j){
            while(arr[i]<=pivot && i<=high-1){
                i++;
            }

            while(arr[j]>pivot && j>=low+1){
                j--;
            }
            
            if(i<j){ 
                //swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        //swap arr[j] and arr[low]       mistake = don't use pivot bcuz it is a local variable
        int temp2 = arr[low];
        arr[low]= arr[j];
        arr[j]= temp2;

        return j;
        


      }
  };

  class Solution2 {
    public:
      // Function to sort an array using quick sort algorithm.
      void quickSort(vector<int>& arr, int low, int high) {
          if(low>=high){
              return;
          } 
  
          int part_index = partition(arr,low,high);
  
          quickSort(arr, low,part_index-1);
          quickSort(arr,part_index+1,high);
      }
  
    public:
      // Function that takes last element as pivot, places the pivot element at
      // its correct position in sorted array, and places all smaller elements
      // to left of pivot and all greater elements to right of pivot.
      int partition(vector<int>& arr, int low, int high) {
          int pivot=arr[low];
          int i =low;
          int j =high;
  
          while(i<j){
              while(arr[i]<=pivot && i<=high-1){
                  i++;
              }
  
              while(arr[j]>pivot && j>=low+1){
                  j--;
              }
              
              if(i<j){
                  //swap arr[i] and arr[j]
              int temp = arr[i];
              arr[i] = arr[j];
              arr[j] = temp;
              }
          }
          
         
          //swap arr[j] and pivot
          int temp2 = arr[low];
          arr[low]= arr[j];
          arr[j]= temp2;
       
  
          return j;
}
  };
  


int main(){
    vector<int> arr={3,1,2,4,1,5,6,2,4} ;
    int l=0;
    int r = arr.size()-1 ;
    Solution2 sol;
    sol.quickSort( arr, l, r);

    for(int i=l; i<=r;i++){
        cout<<arr[i] << " ";
    }
}