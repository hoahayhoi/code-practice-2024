#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Kind of binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (r + l) / 2; 
            if (target == nums[m]) {
                return m;
            }
            else if (nums[m] > target) {
                r = m - 1; 
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }
};
// [1, 3, 5]

int main()
{
    Solution solution;
    vector <int> v = {1,3,5,6};
    cout << "res " << solution.searchInsert(v, 4);

    return 0;
}