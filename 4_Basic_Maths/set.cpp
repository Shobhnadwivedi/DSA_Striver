#include<iostream>
#include<set>
using namespace std;

int main(){
 set<int> st; 
 st.insert(1);
 st.emplace(2);
 st.insert(4);
 st.insert(5);
 st.insert(3);

 set<int> st2 = {2,2,2,6,7,8};

 for( auto it= st.begin() ; it != st.end() ; ++it ){
 cout<< " " << *it ;
 }

 cout<< " st2 before inserting = " ;
 for( auto it= st2.begin() ; it != st2.end() ; ++it ){
 cout<< " " << *it ;
 }

 st2.insert(st.find(3), st.end());
cout << endl << "st2 after inserting = " ;
 for( auto it= st2.begin() ; it != st2.end() ; ++it ){
 cout<< " " << *it ;
 }

return 0;

}