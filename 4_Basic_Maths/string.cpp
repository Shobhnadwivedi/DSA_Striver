#include<iostream>
using namespace std ;

int sizeinbyte(string str){
    
    cout <<" the size of sho is : " << sizeof(str) << " bytes/n. " ;
    return sizeof(str);
}
int main(){
    string str;
cin >> str ;
    sizeinbyte(str);

}