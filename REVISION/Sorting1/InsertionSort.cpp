#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1 ; i<=n-1 ; i++){

        for(int j= i ; j>0  ; j--){
            if(arr[j-1]> arr[j]){
                swap(arr[j-1], arr[j]);
            }
            else{
                break;
            }
        }

    }
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);


    cout << "Sorted array: \n";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}