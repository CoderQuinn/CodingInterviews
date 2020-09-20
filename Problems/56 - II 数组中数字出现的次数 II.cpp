//
//  56 - II 数组中数字出现的次数 II.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/18.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        long sum2 = 0;
        for (auto num : nums) {
            sum2 += num;
            set.insert(num);
        }
        
        long sum1 = 0;
        for (auto num : set) {
            sum1 += num;
        }
        return (sum1 * 3 - sum2) / 2;
    }
};

class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for (auto x : nums) {
            one = (one ^ x) & ~two;
            two = (two ^ x) & ~one;
        }
        return one;
    }
};
