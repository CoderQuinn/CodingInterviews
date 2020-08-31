//
//  16 mypow.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/31.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <algorithm>

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        bool is_minus = n < 0;
        long long k = abs(n);
        
        while (k) {
            if (k & 1)
                res *= x;
            k >>= 1;
            x = x * x;
        }
        
        if (is_minus)
            res = 1 / res;
        
        return res;
    }
};
