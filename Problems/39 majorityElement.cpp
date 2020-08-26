//
//  39 majorityElement.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, count = 0;
        for (auto num : nums) {
            if (count == 0) {
                ans = num;
                count++;
            } else if(num == ans){
                count++;
            } else {
                count--;
            }
            
        }
        return ans;
    }
};
