#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//O(n)

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;

        stack <char> st; 
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false; 

                char t = st.top();
                if ((t == '(' && c == ')') || 
                    (t == '{' && c == '}') || 
                    (t == '[' && c == ']')) {
                    st.pop(); 
                } else {
                    return false; 
                }
                
            }
        }
        return st.empty(); 
    }
};  

int main()
{
    Solution solution;
    string s = "(]";

    cout << endl << solution.isValid(s);

    return 0;
}