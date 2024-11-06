#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// for -> O(n) mp.find() -> O(1)
class Solution
{ public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (mp.find(diff) != mp.end()) {
                return {mp[diff], i};
            }
            else {
                mp[nums[i]] = i;
            }
        }
        return {0, 0};
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3,3};
    int target = 6;
    vector<int> a = solution.twoSum(nums, target);
    cout << endl;
    cout << a[0] << " " << a[1] << endl;
    return 0;
}