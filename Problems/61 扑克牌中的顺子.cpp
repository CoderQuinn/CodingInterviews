//
//  61 扑克牌中的顺子.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/21.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        if (nums.empty()) return false;
        
        sort(nums.begin(), nums.end());
        
        int k = 0;
        while (nums[k] == 0) k++;
        
        for (int i = k + 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return false;
            }
        }
        
        bool ret = nums.back() - nums[k] <= 4;
        return ret;
    }
};
