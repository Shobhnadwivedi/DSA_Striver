#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int l, int mid, int r) {
    vector<int> temp; // temporary array
    int left = l;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= r) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++; 
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    if(right>r) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    if (left>mid){
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = l; i <= r; i++) {
        arr[i] = temp[i - l];                   // why (i-l) and not simply temp[l]  ????
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2 ;
    mergeSort(arr, l, mid);  // left half
    mergeSort(arr, mid + 1, r); // right half
    merge(arr, l, mid, r);  // merging sorted halves
}


int main(){
    vector<int> arr={3,1,2,4,1,5,6,2,4} ;
    int l=0;
    int r = arr.size()-1 ;
    mergeSort( arr, l, r);

    for(int i=l; i<=r;i++){
        cout<<arr[i] << " ";
    }
}