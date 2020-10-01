//
//  59-I maxSlidingWindow.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> window;
        
        auto size = nums.size();
        for (int i = 0; i < size; i++) {
            if (!window.empty() && i - window.front() + 1 > k) {
                window.pop_front();
            }
            
            while (!window.empty() && nums[i] >= nums[window.back()]) {
                window.pop_back();
            }
            
            window.push_back(i);
            
            if (i + 1 >= k) {
                ans.push_back(nums[window.front()]);
            }
        }
        return ans;
    }
};
