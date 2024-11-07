#include <bits/stdc++.h>
#include <iostream>
using namespace std;



// Solution 1 use extra space 
// O(n) , .erase -> O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = 1;
            }
            else {
                mp.erase(nums[i]);
            }
        }
        auto it = mp.begin();
        return it->first;
    }
};

// Solution 2 not use extra space 
// O(n) , apply xor operator in binary
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0; 
        for (int i = 0; i < nums.size(); i++) {
            result = result ^ nums[i];
        }
        return result;
    }
};


int main()
{
    Solution solution2;

    vector<int> v = {2,2,1};
    int rs = solution2.singleNumber(v);
    cout << "result: " << rs;
    return 0;
}