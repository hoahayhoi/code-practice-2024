#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// O(n * strs[0].size())
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";  
        for (int i = 0 ; i < strs[0].size(); i ++) { 
            for (string s : strs) { 
                if (i == s.size() || s[i] != strs[0][i]) { 
                    return res; 
                }
            }
            res += strs[0][i];
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector <string> strs = {"flower", "flow", "flight"}; 
    cout << endl << "res: " << solution.longestCommonPrefix(strs); 
    

    return 0;
}