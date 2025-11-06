#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> st;  // stack to store indices of the temperatures

        for(int i=0; i<temperatures.size(); i++){
            while(!st.empty()  && temperatures[i] > temperatures[st.top()] ){
                int idx = st.top();
                st.pop();
                result[idx] = i - idx;
            }
            st.push(i);
        }

        return result;
          
    }
};




int main (){
    Solution sol;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> result = sol.dailyTemperatures(temperatures);
    for(auto it: result){
        cout<< it << " ";
    }
    cout << endl;
}