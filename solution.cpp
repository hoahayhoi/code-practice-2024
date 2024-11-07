#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// O(n^2) -> 2 for
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                for (int j = i; j < nums.size() - 1; j++){
                    nums[j] = nums[j + 1];
                    nums[j + 1] = 0;
                }
            }
        }

    }
};

// O(n) but use extra space 
class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> v; 
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) count++;
            else v.push_back(nums[i]);
        }
        for(int i = 0; i < count; i++) {
            v.push_back(0);
        }
        nums = v;
    }
};

// Not optimal 
class Solution3 {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0; 
        while(l < nums.size() - 1) {
            if (nums[l] == 0) {
                int r = l + 1;
                while(r < nums.size()) {
                    if (nums[r] != 0) {
                        nums[l] = nums[r];
                        nums[r] = 0;
                        r++;
                        l++;
                    } 
                    else 
                        r++;
                }
            }
            l++; // avoid permanent loop
        }
    }
};

// The most optimal 
class Solution3 {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;  
        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] != 0) {
                swap(nums[l], nums[r]);
                l++;
            }
        }
    }
};



int main()
{
    Solution3 solution;
    vector<int> v = {0};
    solution.moveZeroes(v);

    for (int item : v) {
        cout << item << endl;
    }
    return 0;
}