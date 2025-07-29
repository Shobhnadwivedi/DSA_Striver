/*
Number of digits in the munber that evenly divides the number completely.
*/

#include<iostream>
using namespace std;
int evenlydivide(int n){
    int cnt=0;
    int number = n;
    
    while(n>0){
        int a = n%10 ;
        n/=10;
        if (a !=0 && number%a==0 ){
        cnt=cnt +1;}
    }
    return cnt;
}

/*
Given a positive integer num, return the number of positive integers less than or equal to num whose digit sums are even.

The digit sum of a positive integer is the sum of all its digits.

 

Example 1:

Input: num = 4
Output: 2
Explanation:
The only integers less than or equal to 4 whose digit sums are even are 2 and 4. 

*/

int countEven(int num) {
    int cnt =0;
    if(num>=1 && num<=1000){ 
        
        while(num>0){
            int sum=0;
            int k=num;
            while(k!=0){
                int a =k%10;
                sum = sum +a;
                k=k/10;
            }
            if(sum%2==0){cnt++;}
            num--;
        } 
    }
    return cnt;      
}

int main (){
    int n;
    cin>> n;
    int cnt = countEven(n);
    cout<< cnt;
    
    
    }

