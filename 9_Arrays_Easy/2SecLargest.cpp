/*               https://www.geeksforgeeks.org/problems/second-largest3735/1
Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
*/


#include <iostream>
#include <vector>
using namespace std;

int part_index(vector<int> &arr, int l, int h){
    int pivot = arr[l];
    int i= l;
    int j = h;
    while(i<j){
        while(arr[i]<= pivot && i<=h-1){
            i++;
        }

        while(arr[j]> pivot && j>=l+1){
            j--;
        }
        if(i<j){
            int temp1 = arr[j];
            arr[j] = arr[i];
            arr[i] = temp1;
        }  
    }

    // swap arr[l] and pivot 
    int temp2 = arr[l];
    arr[l] = arr[j];
    arr[j] = temp2;

    return j;
}

void quickSort(vector<int> &arr, int l, int h){
    if(l>=h){
        return ;
    }
    int partindex = part_index(arr,l,h);
    quickSort(arr,l,partindex-1);
    quickSort(arr, partindex+1, h);

}

// BRUTE FORCE  =  T.C = O(N lOG N)[quicksort] + O(N)[loop]    =  array ko sort krke , take last elem=largest for comparison, start form 2nd last index , 
//              =  S.C = O(1)                                  =  if not equal then it is the second largest element, return it , break the loop 
//                                                             =  else agr saare equal to largest h , means second larg doesn't exist , return -1
int getSecondLargest1(vector<int> &arr) {
    int l =0;
    int h= arr.size()-1;
    quickSort(arr,l,h);    // arr has been sorted now

     
    for(int i=h-1; i>=0; i++){
        if(arr[i] != arr[h]){
            int sec_larg = arr[i];
            return sec_larg;
            break;
        }
        else return -1;
    }                                               
    
}
    

// BETTER  =  T.C = O(2N) [one pass to find largest, other to find sec larg -> (check every elem i it is less than(not equal to ) largest, greater than previous sec largest , update it to sec larg )]
//         =  S.C = O(1)
int getSecondLargest2(vector<int> &arr) {
    int n = arr.size();
    if(n==0 || n==1){ 
        cout<< -1 <<" "<<endl;                // edge case when only one element is present in array
    }                             
    int largest = arr[0];
    int sec_larg;
    // 1st pass for largest element   = O( N )
    for(int i=0;i<arr.size();i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    // 2nd pass for second largest element  = O( N )
    for(int i=0;i<arr.size();i++){
        if(arr[i]<largest && arr[i]!=largest){
            sec_larg = arr[i];
        }
    }
    return sec_larg;

}


// OPTIMAL  =  T.C = O(N)  [single traversal ]    =  take 
int getSecondLargest3(vector<int> &arr) {
    int min = -1;
    int larg = arr[0];

    for(int i =0;i<arr.size(); i++){
        if(arr[i]> larg){
            if(larg>min && arr[i]!=larg){
                min=larg;
            }
            larg=arr[i];
        }
        if(arr[i]> min && arr[i]!=larg){
            min = arr[i];
        }

    }
    return min;
}


int main(){
    vector<int> arr = {5,9,6,10,10};
    int l =0;
    int h= arr.size()-1;
    quickSort(arr,l,h);    // arr has been sorted now

    int sec_largest = getSecondLargest2(arr);
    cout<< sec_largest<< " ";

    

}