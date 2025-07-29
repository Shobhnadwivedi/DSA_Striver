#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution1{
    public:
    vector<int> findunion(vector<int> &arr1, vector<int> &arr2){
        map<int,int> temp;
        vector<int> Union ;
        for(int i=0;i<arr1.size();i++){
            temp[arr1[i]] ++ ;
        }

        for(int i=0;i<arr2.size();i++){
            temp[arr2[i]] ++ ;
        }

        for (auto& pair : temp) {
           Union.push_back(pair.first);
            
        }
        for(int i=0; i< Union.size(); i++){
            cout<< Union[i] << " ";
        }
        return Union;

    }
};


class Solution2{
    public:
    vector<int> findunion(vector<int>& arr1, vector<int>& arr2){
        set<int> s ;
        
        for(int i=0;i< arr1.size();i++){
            s.insert(arr1[i]);
        }
        for(int i=0;i< arr2.size();i++){
            s.insert(arr2[i]);
        }
        vector<int> v1(s.begin(), s.end());
        for(int i=0; i< v1.size(); i++){
            cout<< v1[i] << " ";
        }
        return v1;
    }
    
};

//  using 2 pointer
class Solution3{
    public:
    vector<int> findunion(vector<int>& a, vector<int>& b){
        vector<int> Union;
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                if(a[i-1] != a[i]) {Union.push_back(a[i]);}
                i++;
                j++;
            }
            else if(a[i] < b[j]){
                if(a[i-1] != a[i]) {Union.push_back(a[i]);}
                i++;
            }
            else{
                if( b[j-1] !=b[j]) {Union.push_back(b[j]);}
                j++;
            }
        }
        while(i< a.size()){
            if(a[i-1] != a[i]) {Union.push_back(a[i]);}
            i++;
        }
        while(j< b.size()) {
            if( b[j-1] !=b[j]) {Union.push_back(b[j]);}
            j++;
        }
        for(int k=0; k< Union.size(); k++){
            cout<< Union[k] << " ";
        }
        return Union;
    }
};

//  Intersection of 2 sorted arrays = 

class Solution4 {
  public:
    // Function to return a list containing the intersection of two arrays.
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        vector<int> inter;
        int i=0, j=0;

        while(i<n1 && j<n2){
            if( arr1[i]== arr2[j]){
                if(inter.size()==0 || inter.back()!=arr1[i]){
                    inter.push_back(arr1[i]);
                }
                i++;
                j++;
            }

            else if( arr1[i] < arr2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        for(int k=0; k< inter.size(); k++){
            cout<< inter[k] << " ";
        }
        return inter;
        
    }
};


int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};

    Solution4 res ;
    res.intersection(arr1, arr2);
    
    

}