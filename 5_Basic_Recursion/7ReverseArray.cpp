/*      Reverse a given array using   -    RECURSION       */

/*   1. using 2 pointers/variables  */
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr= {2,4,2,6,9,7};
class Solution {
  public:

    void reverseArray(int l, int r) {
        if(l>=r){
            return;
        }
        swap(arr[l],arr[r]) ;
        reverseArray(l+1,r-1);

    }
};

int main(){

Solution ob;
ob.reverseArray(0,arr.size()-1);
for (int i=0;i<=arr.size()-1; i++){
    cout << arr[i] << ' ';
}
}