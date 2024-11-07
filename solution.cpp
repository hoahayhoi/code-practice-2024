#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// O(n^2) => double for each item
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};

        for (int i = 1; i < numRows; i++) {
            vector <int> row = res.back();
            row.insert(row.begin(), 0);
            row.push_back(0);
            vector <int> newRow;
            for (int j = 0; j <= row.size() - 2; j++) {
                newRow.push_back(row[j] + row[j + 1]);
            }
            res.push_back(newRow);
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> rs = solution.generate(5);

    for (const auto& innerVec : rs) {
        cout << "{ ";
        for (int val : innerVec) {
            cout << val << ' ';
        }
        cout << " }";
    }

    return 0;
}