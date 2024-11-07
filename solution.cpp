#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + ((r - l) / 2); // m = (l + r) / 2 if not consider overflow
            if (nums[m] < target) 
                l = m + 1;
            else if (nums[m] > target)
                r = m - 1;
            else 
                return m;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector <int> v = {-1,0,3,5,9,12};
    int target = 2; 
    int rs = solution.search(v, target);
    cout << "result " << rs; 
    return 0;
}