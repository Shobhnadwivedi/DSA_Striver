#include <iostream>
#include <vector>
using namespace std;


void merge( int arr[], int l , int mid , int r){
 
    vector<int> temp;

    int n1 = l;
    int n2 = mid +1;
    while( n1 <= mid && n2 <=r){
        if( arr[n1]<= arr[n2]){
            temp.push_back(arr[n1]);
            n1++;
        }
        else{
            temp.push_back(arr[n2]);
            n2++;
        }
    }

    if( n1 > mid){
        while(n2 <=r){
            temp.push_back(arr[n2]);
            n2++;
        }
    }

    if( n2 > r){
        while(n1 <= mid){
            temp.push_back(arr[n1]);
            n1++;
        }
    }
    // copy back to original array //

    for(int i=l; i<=r; i++){
        arr[i] = temp[i-l];
    }

}



void mergeSort( int arr[],int l, int r){

    if(l>=r){
        return;
    }

    int mid = l+ (r-l)/2 ;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);

    merge(arr, l, mid , r);

    
}


int main(){

    int arr[] = {5,4,3,2,3,1};
    int n = sizeof(arr)/ sizeof(arr[0]);

    mergeSort(arr, 0, n-1);

    for( int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

}