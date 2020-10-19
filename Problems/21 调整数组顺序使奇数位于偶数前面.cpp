//
//  21 exchange.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/9.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0, j = int(nums.size() - 1);
        
        while (i < j) {
            while (i < j && (nums[i] & 1)) {
                i++;
            }
            while (i < j && !(nums[j] & 1)) {
                j--;
            }
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        
        return nums;
    }
};
