//
//  17 printNumbers.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/9.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    
    vector<int> printNumbers(int n) {
        vector<int> res;
        int max = pow(10, n) - 1;
        for (int i = 1; i <= max; i++) {
            res.push_back(i);
        }
        return res;
    }
};
