#include <iostream>
using namespace std;

int main(){
    int q;
    cout<< "Array size? ";
    cin>> q;
    int arr[]={} ;
    

    for(int i=0; i<q;i++){
        int query;
        cin >> query;
        int cnt=0;
        for (int j=0;j< (sizeof(arr) / sizeof(arr[0]));j++){
            
            if (query==arr[j]){
                cnt++;
            }
        }
        cout<< "cnt = "<< cnt;

    }


}

