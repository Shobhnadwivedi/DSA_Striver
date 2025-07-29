
/*  Q.1) A Function to print N numbers . let n= 3.         */
# include<iostream>
using namespace std ;

int cnt=0;
void func1(int n){
    if(cnt==n){
        return ;
    }
    
    cout << cnt << endl;
    cnt++;
    func1(n);
}

int main(){
    func1(4);

}