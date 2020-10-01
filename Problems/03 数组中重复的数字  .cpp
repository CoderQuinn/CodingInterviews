//
//  03 findRepeatNumber.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> hash_set;
        int ans = -1;
        for (auto num : nums) {
            if (hash_set.count(num) > 0) {
                ans = num;
                break;
            }
            hash_set.insert(num);
        }
        
        return ans;
    }
};
