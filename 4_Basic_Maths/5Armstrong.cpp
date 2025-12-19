# include<iostream>
using namespace std;

/* 
An Amrstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.


Input:N = 153
Output:True
Explanation: 1^3+5^3+3^3 = 1 + 125 + 27 = 153
*/

bool armstrong(int x){
    int original =x, num=0,a;
    while(x!=0){
        a=x%10;
        x=x/10;
        num= num + (a*a*a) ;
    }
    if(num!= original || num<0){return false;}
    return true;
}

int main(){
    int x;
    cin>> x;
    if(armstrong(x)){
        cout<< "Number is an Armstrong number.";
    }
    else  cout<< "Number is not an Armstrong number.";

}