#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//O(n x 2^n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        function<void(int)> dfs = [&](int i) {
            if (i >= nums.size()) {
                res.push_back(subset);
                return;
            }
            subset.push_back(nums[i]);
            dfs(i + 1);

            subset.pop_back();
            dfs(i + 1);
        };

        dfs(0);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.subsets(nums);

    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}

