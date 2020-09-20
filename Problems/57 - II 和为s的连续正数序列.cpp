//
//  57 - II 和为s的连续正数序列.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/20.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        
        for (int i = 1, j = 1, s = 1; i <= target; i++) {
            while (s < target) {
                j++;
                s += j;
            }
            
            if (s == target && j != i) {
                vector<int> seq;
                for (int k = i
                     ; k <= j; k++) {
                    seq.push_back(k);
                }
                res.push_back(seq);
            }
            
            s -= i;
        }
        
        return res;
    }
};
