#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//O(n x n!)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        if (nums.size() == 1) {
            return {nums};
        }

        for (int i = 0; i < nums.size(); i++) {
            int t = nums.front();
            nums.erase(nums.begin());

            vector<vector<int>> perms = this->permute(nums);
            for (auto& perm : perms) { 
                perm.push_back(t);
            }
            
            res.insert(res.end(), perms.begin(), perms.end()); 
            nums.push_back(t);
        }

        return res;
    }
};

// swap: 

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = solution.permute(nums);

    // In kết quả
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

