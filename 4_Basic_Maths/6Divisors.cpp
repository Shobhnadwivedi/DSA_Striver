# include<iostream>
# include<math.h>
# include<vector>
# include<algorithm>
using namespace std;

int divisor1(int N){
    for(int i=1; i<=N; i++){
        if(N%i==0){
            cout<< i<< " ";
        }
    }
    return 0;
}

int divisor2(int N){
    for(int i=1; i<= sqrt(N); i++){
        if(N%i==0){
            cout<< i << " ";
        }
         if(N/i != i && N%(N/i)==0){
                cout << N/i << " ";
        }
    }
    return 0;
}

int divisor3(int N){
    vector<int> ls;
    for(int i=1; i<= sqrt(N); i++){
        if(N%i==0){
            ls.push_back(i);
        }
         if(N/i != i && N%(N/i)==0){
            ls.push_back(N/i);
        }
    }
    sort(ls.begin(), ls.end());
    for(auto it=ls.begin(); it< ls.end(); it++){
        cout << *it<< " ";
    }
    return 0;
}

int sumofdiv1(int N){
    int f=0;
    for(int i=1; i<=N; i++){
        if(N%i==0){
            f=f+i;
        }
    }
    cout << f;
    return 0;
}

int sumofdiv2(int N){
    int f=0;
    for(int i=1; i<= sqrt(N); i++){   
        if(N%i==0 ){
            f= f+i ;
        }
        if(N/i != i && N%(N/i)==0 ){    
            f = f + (N/i);
        }
    }
    return f;
}

int sumation1(int N){
    int sum=0;
    for(int j=1; j<= N; j++){
        int f=0;
        for(int i=1; i<=j; i++){
          if(j%i==0){
            f=f+i;
          }
        }
       sum= sum + f;
    }
    return sum;
}

long long sumation2(int N)
    {
     std::vector<long long> divisorSum(N + 1, 0);

    // Calculate sum of divisors for each number
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            divisorSum[j] += i;
        }
    }

    long long totalSum = 0;
    for (int i = 1; i <= N; ++i) {
        totalSum += divisorSum[i];
    }

    return totalSum;
}

int sumation3(int N){
    int sum=0;
    for(int j=1; j<= N; j++){
        int f=0;
        for(int i=1; i<= sqrt(j); i++){   
        if(j%i==0 ){
            f= f+i ;
        }
        if(j/i != i && j%(j/i)==0 ){    
            f = f + (j/i);
        }
    }
       sum= sum + f;
    }
    return sum;
}

 /* Method to calculate the total sum of the sum of divisors.
    In above methods, no. of steps were coming out to be = (N)^2
    N = (10)^6 NUMBERS
    SO, N^2 = (10)^12 Numbers
    but in 1 second...only (10)^8 steps can be done by the computer.    
    
 */

long long int sumation4(int N){
    long long int a,f=0;
    for(int i=1; i<=N; i++){
        a=(N/i)*i;
        f=f+a; 
    }
    return f;
}

int main(){
int N;
cin>> N;
int totalsum = sumation4(N);
cout<< totalsum;

}