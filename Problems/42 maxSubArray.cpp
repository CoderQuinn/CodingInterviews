//
//  42 maxSubArray.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/19.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t size = nums.size();
        vector<int> d(size, 0);
        vector<int> rec(size, -1);
        
        d[size - 1] = nums[size - 1];
        rec[size - 1] = size - 1;
        int max_sum = d[size - 1];
        for (int i = size - 2; i >= 0; --i) {
            if (d[i + 1] > 0) {
                d[i] = d[i + 1] + nums[i];
                rec[i] = rec[i + 1];
            } else {
                d[i] = nums[i];
                rec[i] = i;
            }
            if (d[i] > max_sum) {
                max_sum = d[i];
            }
        }

        // 寻找子数组左右边界
        int l, r;
        for (auto i = 1; i < size; i++) {
            if (max_sum == d[i]) {
                l = i;
                r = rec[i];
            }
        }
        
        return max_sum;
    }
};
