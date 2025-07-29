/*
Given two integers a and b, write a function lcmAndGcd() to compute their LCM and GCD. The function inputs two integers a and b and returns a list containing their LCM and GCD.

Examples:

Input: a = 5 , b = 10
Output: [10, 5]
Explanation: LCM of 5 and 10 is 10, while their GCD is 5.
*/

# include<iostream>
# include<vector>
using namespace std;

int hcf1(int A, int B){
    int hcf;
    for(int i=1; i<=min(A,B); i++){
        if(A%i==0 && B%i==0){
            hcf=i ;
        }
    }
    return hcf;
}

int hcf2(int A, int B){
    int hcf ;
    for(int i=min(A,B); i>0 ; i--){
        if(A%i==0 && B%i==0){
            hcf=i ;
            break;
        }
        }
        return hcf;
}

int lcm(int A, int B){
long long int lcm,hcf;
for(int i=min(A,B); i>0 ; i--){
        if(A%i==0 && B%i==0){
            hcf=i ;
            break;
        }
        }
        return hcf;
lcm = (A*B)/hcf;
        cout<< endl;
        return lcm;
 
}



vector<int> lcmhcf(int a,int b){
    int lcm, hcf;
    for(int i=min(a,b); i>0 ; i--){
            if(a%i==0 && b%i==0){
                hcf=i ;
                break;
            }
        }
    lcm = (a*b)/hcf;
    return{lcm,hcf};
}

int main(){
    int A,B;
    cin >> A >>B;
    /*  cout <<  lcmhcf(A,B);      this code will give error as cout can't print a vector.
        isliye create a vector = lcmhcf(A,B). then try to print 
    */
   vector<int> result = lcmhcf(A,B);
   cout<< result[0] << result[1] ;
}