#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
      // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        int n = arr.size();
        for(int i=0; i<= n-2 ;i++){
            //  finding minimum
            int min =i;
            for(int j=i+1; j<= n-1; j++){
                
                if (arr[j]<arr[min]){
                    min = j;
                }
                
                
            }
            // swap  arr[i] and arr[min]
            int temp= arr[min];
            arr[min] = arr[i];
            arr[i]= temp;

        }
    }
};


int main(){
vector <int> arr ={9,4,18,6,2,22};

Solution sol;
sol.selectionSort(arr);
int n = arr.size() ;
for(int i=0;i<n;i++){
    cout<< arr[i]<< " ";

}

}