#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//   T.C = O(N^3)- 3 loops of size nearly n     -    TIME LIMIT EXCEEDED
//   S.C = O(1)    - given array me hi changes
class Solution1 {
    public:

    void moveZeroes1(vector<int>& nums) {
        int n = nums.size();
        for(int k=0 ; k<n ; k++){ 
            for(int i=0;i<n; i++){
                if(nums[i]==0){
                    for(int j =i;j<n-1; j++){

                        int temp = nums[j];
                        nums[j] = nums[j+1];
                        nums[j+1] = temp;
                    }
                }  
            }
        }       
    }
};

// T.C =  O(N )   - while loop runs n times    and insert() function takes O(cnt)
// S.C =  O(1 )
class Solution2 {
    public:
        void moveZeroes(vector<int>& nums) {
            int i=0;
            int cnt =0;
            while( i < nums.size()){
                if(nums[i]==0){
                    nums.erase(nums.begin()+i);
                    cnt++;
                }
                else{
                    i++;
                }
            }
            nums.insert(nums.end(),cnt,0);
        }
    };

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int i;
            for(int k=0 ; k<nums.size(); k++){
                if(nums[k]==0){
                    i=k;
                    break;
                }
                
            }

            int j=i+1;

            while(j<nums.size()){
                if(nums[j]!=0){
                    //swap
                    int temp = nums[i];
                    nums[i]=nums[j];
                    nums[j]=temp ;

                    i++;
                    j++;

                }
                else{
                    j++;
                }
            }    
        }
};

int main(){
    vector<int> nums = {5,0,4,0,6,1};;
    Solution sol ;
    sol.moveZeroes(nums);
    
    for (int i=0;i< nums.size() ;i++){
        cout << nums[i] << " ";
    }

}