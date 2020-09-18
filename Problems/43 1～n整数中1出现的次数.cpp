//
//  43 1～n整数中1出现的次数.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/17.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int get(vector<int> &nums, int l, int r)
    {
        int res = 0;
        for (int i = l; i >= r; i--) {
            res = res * 10 + nums[i];
        }
        return res;
    }
    
    int countDigitOne(int n) {
        if(n <= 0) return 0;
        int res = 0;
        vector<int> nums;
        while (n) {
            nums.push_back(n % 10);
            n /= 10;
        }
        
        int m = nums.size() - 1;
        for (int i = m; i >= 0; i--) {
            int x = nums[i];
            int left = get(nums, m, i + 1);
            int right = get(nums, i - 1, 0);
            int p = pow(10, i);
            
            if (x == 0) {
                res += left * p;
            } else if (x == 1) {
                res += left * p + right + 1;
            } else {
                res += (left + 1) * p;
            }
        }
        
        return res;
    }
};
