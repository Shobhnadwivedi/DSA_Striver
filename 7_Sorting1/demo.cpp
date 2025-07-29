#include <iostream>
#include <vector>
using namespace std;

void insertionsort(vector<int> &arr){
    int n = arr.size();
    for(int i=1;i<=n-1;i++){
        int didswap=0;
        for(int j=i;j>=1;j--){
            if(arr[j]<arr[j-1]){
                //swap them
                int temp= arr[j-1];
                arr[j-1]= arr[j];
                arr[j]= temp;
                
            }
            didswap++;
        }
       if (didswap==0){break;}
    }

}

int main(){
    vector<int> arr = {4,2,22,6,9,18,4,0};
    int n = arr.size();
    insertionsort(arr);
    for(int i=0; i<n; i++ ){
        cout<< arr[i]<< ' ';
    }


}