/*      Q.1)    N! = N* (N-1)* (N-2) * (N-3)*...1
A number n is called a factorial number if it is the factorial of a positive integer. For example, the first few factorial numbers are 1, 2, 6, 24, 120,
Given a number n, the task is to return the list/vector of the factorial numbers smaller than or equal to n.

Examples:

Input:      n = 3
Output:     1 2
Explanation:    The first factorial number is 1 which is less than equal to n. The second number is 2 which is less
                than equal to n,but the third factorial number is 6 which is greater than n. So we print only 1 and 2.
*/

#include<iostream>
#include<vector>
using namespace std;

/*     SIMPLE FUNCTION USING LOOPS */
class Solution2{
    public:
    vector<long long> factorialNumbers2(long long n){
        int k=1,fac=1;
        vector<long long> v1;
            while(fac<=n){
                                        /*    pehle I wrote in this order , which was wrong = 
                                        fac=fac * k ;             
                                        k++ ;
                                        v1.push_back(fac);     */
                                        
               v1.push_back(fac);
                k++;
                fac=fac*k;
                
            }
        for(int j=0; j<v1.size(); j++){
            cout << v1[j]<< ' ' ;
        }
    
        return v1;
    }
    
};

class Solution1 {
  public:
    // Function to find factorial numbers less than or equal to N.
    vector<long long> factorialTrueSolution(long long n) {
        vector<long long> ans;
        long long int fact = 1;
        int x = 2;

        // Iterating until factorial is less than or equal to N.
        while (fact <= n) {
            // Adding factorial to the answer list.
            ans.push_back(fact);

            // Calculating next factorial by multiplying with next number.
            fact = fact * x;
            x++;
        }
        // Returning the list of factorial numbers.
        return ans;
    }
};

class Solution{
    public:
    int k=1, fac=1;
    vector<long long> ans;
    vector<long long> factorialNumbers(long long n) {
        
        
        if (fac >= n) {
            return ans;
        }
        
        fac = fac * k;
        ans.push_back(fac);
        k++;
        
        return factorialNumbers(n);
        }
    
};   
        


int main(){

Solution sol;
vector<long long> res = sol.factorialNumbers(24);

for(int i=0; i<res.size(); i++){
    cout << res[i] << ' ';
 
}

}