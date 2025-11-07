#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double,double>> cars; // pair of (position, speed )

        for(int i=0; i<position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        stack<double> st; 
        double time0 = (target - cars[0].first) / cars[0].second  ;
        st.push(time0);
        int cnt=1;

        for(int i=1 ; i<cars.size();i++){
            double time = (target - cars[i].first)/ cars[i].second;
            if(time > st.top()){
                st.push(time);
                cnt++;
            }
        }
        return cnt;
    }
};