#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>> n;
    vector<int> arr(n);

    for(int i=0; i<n;i++){
        cin >> arr[i];
        int cnt=0;
    }

    int max_val = *max_element(arr.begin(), arr.end());
    vector<int> h_arr(max_val + 1, 0);

    for(int i=0;i<n;i++){
        h_arr[arr[i]]++;
    }

    int q;
    cin>> q;
    vector<int> q_arr(q);
    for(int j=0;j<q;j++){
        cin>> q_arr[j];
        cout<< "count = "<<h_arr[q_arr[j]];
    }
    

}