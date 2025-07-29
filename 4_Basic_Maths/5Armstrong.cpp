# include<iostream>
using namespace std;

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