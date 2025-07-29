#include<iostream>
using namespace std;

/*

*/
void pattern1(int n){

    for(int i=0; i < n; i++)
    {
        for(int j=0; j < n; j++) 
        {
            cout << "* " ;
        } 
    
        cout << endl ;
    }
}

void pattern2(int n){

    for(int i=0; i < n; i++)
    {
        for(int j=0; j<=i; j++) 
        {
            cout << "* " ;
        } 
    
        cout << endl ;
    }
}

void pattern3(int n){

    for(int i=0; i < n; i++)
    {
        for(int j=0; j<=i; j++) 
        {
            cout << j+1 << " " ;
        } 
    
        cout << endl ;
    }
}

void pattern4(int n){

    for(int i=0; i < n; i++)
    {
        for(int j=0; j<=i; j++) 
        {
            cout << i+1 << " " ;
        } 
    
        cout << endl ;
    }
}

void pattern5(int n){
    for(int i=0; i < n; i++)
    {
        for(int j= 0 ; j < n-i ; j++) 
        {
            cout << "* " ;
        } 
    
        cout << endl ;
    }
}

void pattern6(int n){
    for(int i=0; i<n; i++)
    {
        for (int j=0; j+i < n  ; j++ )
        {
            cout <<  j+1 << " " ;
        }
         cout << endl ;
    }
}    

void pattern7(int n){

    for(int i=0; i < n ; i++)
    {
        for (int j=0; j+i < n-1 ; j++ )
        {
            cout << "  " ;
        }
         
    

        for (int j=0 ; j < 2*i +1  ; j++ )
        {
            cout << "* " ;
        }
         


        for (int j = 0 ; j < n-1-i ; j++ )
        {
            cout << "  " ;
        }

         cout << endl ;
    }
    
}   

void pattern8(int n){

    for(int i=0; i < n ; i++)
    {
        for (int j=0; j < i ; j++ )
        {
            cout << "  " ;
        }
         
    

        for (int j=0 ; j < 2*n -1 - 2*i ; j++ )
        {
            cout << "* " ;
        }
         


        for (int j = 0 ; j < i ; j++ )
        {
            cout << "  " ;
        }

         cout << endl ;
    }
    
}   

void pattern9(int n){

    for(int i=0; i < n ; i++)
    {
        for (int j=0; j+i < n-1 ; j++ )
        {
            cout << "  " ;
        }
         
    

        for (int j=0 ; j < 2*i +1  ; j++ )
        {
            cout << "* " ;
        }
         


        for (int j = 0 ; j < n-1-i ; j++ )
        {
            cout << "  " ;
        }

         cout << endl ;
    }

     for(int i=0; i < n ; i++)
    {
        for (int j=0; j < i ; j++ ){
            cout << "  " ;
        }
         
    

        for (int j=0 ; j < 2*n -1 - 2*i ; j++ ) {
            cout << "* " ;
        }
         


        for (int j = 0 ; j < i+1 ; j++ ){
            cout << "  " ;
        }

         cout << endl ;
    }

    
}   

void pattern10(int n){
    for(int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<i+1 ; j++)
        {
            cout<< "* ";
        }
        cout << endl;
    }

    for (int i=0 ; i< n-1 ; i++)
    {
        for (int j=0 ; j<n-1-i ; j++)
        {
            cout<< "* ";
        }
        cout<< endl;
    }
}

void pattern11(int n){
    int start = 1;
    for(int i=0 ; i<n ; i++){
        if(i%2==0) start = 1;
        else start = 0;

        for(int j=0; j<=i ; j++){
            cout<< start;
            start = 1 - start ;
        }
        cout<< endl;
    }
}

void pattern12(int n){
    for(int i=0; i<n ; i++){
        for(int j=0; j<i+1 ; j++){
            cout << j+1 << " ";
            
        }
        for(int j=0; j<= 2*n-3-2*i ; j++){
            cout <<"  ";
        }
        for(int j=0 ; j< i+1 ; j++){
           cout<< i+1-j << " "; 

        }
        cout<< endl;

    }
}

void pattern13(int n){
    int start =1;
    for (int i=0; i<n ; i++){
        for(int j=0 ; j<=i ; j++){
            cout<< start << " ";
            start = 1+ start;
        }
        cout<< endl;
    }
}

void pattern14(int n){
    for(int i=0; i<n ; i++)
    {
        for(char ch = 'A' ; ch< 'A'+1+i ; ch++)
        {
            cout<< ch <<" ";
        }
        cout<< endl;
    }
}

void pattern15(int n){
    for(int i=n ; i >0 ; i-- ){
        for(char ch='A' ; ch < 'A' +i ; ch++)
        {
            cout<< ch << " ";
        }
        cout<< endl ;
    }
}

void pattern16(int n){
    char ch='A';
    for(int i=0; i<n ; i++){
        for(int j=0; j<=i; j++){
            cout<< (ch='A'+i) <<" ";
        }
        cout<< endl;
    }
}

void pattern17(int n){
    char ch='A';
    for(int i=1; i<=n ; i++){
        
        for(int j=1; j<=n-i ; j++)
        {
            cout<< "  ";
        }
        
        for(char ch='A'; ch<= 'A'+i-1 ; ch++){
            cout<< ch << " ";
        }

        for(int j=1 ; j<i  ; j++ ){
            cout<< (ch = 'A'+(i-j)-1 ) << " ";
        }

        for(int j=1; j<=n-i ; j++)
        {
            cout<< "  ";
        }
        cout<< endl ; 
    }
}

void pattern18(int n){
    char ch='E';
    for(int i=1; i<=n; i++){
        for(int j=1;j<=i; j++){
            cout<< (ch='E'-(i-j)) << " " ; 
        }
        cout<< endl;
    }
}

void pattern18a(int n){
    for(int i=0; i<n; i++){
        for(char ch='E'-i ; ch <= 'E' ; ch++) {
            cout<< ch << " ";
        
        }
        cout<< endl ;
    }
    
}

void pattern19(int n){
    for(int i=0;i<n;i++){
        
        for(int j=0 ; j<n-i ; j++ ){
            cout<< "* ";
        }

        for(int j=0 ; j < 2*i ; j++){
            cout<< "  ";
             
        }
         

        for(int j=0;j<n-i;j++){
            cout<< "* ";
        }
      
        cout<< endl ;
    }

    for(int i=0;i<n;i++){
        
        for(int j=0 ; j<i+1 ; j++ ){
            cout<< "* ";
        }

        for(int j=0 ; j < 2*n-2-2*i ; j++){
            cout<< "  ";
             
        }
         

        for(int j=0 ; j<i+1 ; j++){
            cout<< "* ";
        }
      
        cout<< endl ;
    }
}

void pattern19a(int n){
    int inis = 0;
    for(int i=0;i<n;i++){
          

        for(int j=0 ; j<n-i ; j++ ){
            cout<< "* ";
        }

        for(int j=0 ; j < inis; j++){
            cout<< "  ";
             
        }
         
        for(int j=0;j<n-i;j++){
            cout<< "* ";
        }

        inis += 2 ;
        cout<< endl ;
    }

    for(int i=0;i<n;i++){
        int space= 2*n-2 ;  

        for(int j=0 ; j<i+1 ; j++ ){
            cout<< "* ";
        }

        
         
        for( int j=0 ; j< i+1 ; j++ ){
            cout<< "* ";
        }

        inis += 2 ;
        cout<< endl ;
    }


}

void pattern20(int n){
    int inis = 2*n-2 ;
    for(int i=1 ; i<= 2*n-1 ; i++){
        // stars of one side
        int star=i ;
        if(i > n) star = 2*n-i ;

        for(int j=1; j<= star ; j++ ){
        cout<< "* ";
        
        }

        // spaces on between
        for(int j=1; j<= inis ; j++){
            cout<< "  ";
            
        }
            if(i>=n) inis+= 2 ; 
            else inis -= 2 ;

        // stars of 2nd side
       
        for(int j=1; j<= star ; j++ ){
        cout<< "* ";
        
        }
        cout<< endl ;


    }
}

void pattern21(int n){
    for(int i=1; i<=n ; i++){
        for(int j=1;j<=n;j++){

            if(i==1 || j==1 || i==n || j==n)
            cout << "* ";
            else cout<< "  ";  // WHY ELSE LAGANA IS ZAROORI ?? ISN'T IT OBVIOUS SPAVE HI AYEGA ??
        
        }
        cout<< endl ;
    }

}

void pattern22(int n){
  for(int i=0; i<2*n-1 ; i++){
    for(int j=0 ; j<2*n-1 ; j++){
        int top=i ;
        int left=j ;
        int bottom= (2*n-1)-1 -i ;
        int right = (2*n-1)-1 -j ;

        cout<< n - min(min(top,bottom) , min(left,right)) << " " ;
    }
    cout<< endl;
       
}
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i<t ; i++)
    {
        int n;
        cin >> n;

    pattern22(n); 
    
    }


    return 0;


}