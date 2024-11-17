#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// BruceForce O(n^2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0; 
        for(int i = 0; i < prices.size() - 1; i++) {
            for(int j = i + 1; j < prices.size(); j++) {
                int diff = prices[j] - prices[i];
                if (prices[j] > prices[i] && diff > res) {
                    res = diff;
                }
            }
        }
        return res;
    }
};

// Two poiter Mem: O(1), T : O(n)
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1; 
        int res = 0; 
        while (r < prices.size()) {
            int diff = prices[r] - prices[l];
            if (prices[r] > prices[l]) {
                res = max(diff, res);
            }
            else {
                l = r; 
            }
            r++;
        }
        return res;
    }
};

int main()
{
    Solution2 solution;
    vector <int> v = {7,1,5,3,6,4};
    cout << "Max profit: " << solution.maxProfit(v);
    return 0;
}