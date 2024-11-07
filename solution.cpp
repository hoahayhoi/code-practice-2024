#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Use Boyer-Moore algorithm
// O(n) and use O(1) space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) 
                res = nums[i];
            count += (res == nums[i] ? 1 : -1);
        }
        return res;
    }
};


// O(n) and use O(n) space
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int arrsize = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < arrsize; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] > arrsize / 2) 
                return nums[i];
        }
        return 0;
    }
};

int main()
{
    Solution solution;

    vector<int> v = {2,2,1,1,1,2,2};
    int rs = solution.majorityElement(v);
    cout << "result: " << rs;

    return 0;
}