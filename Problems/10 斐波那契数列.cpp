//
//  10- I fib.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/31.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int numWays(int n) {
        if(n <= 1) return 1;
        
        const int P = 1e9 + 7;
        
        long res = 0;
        long f1 = 1, f2 = 1;
        for (int i = 2; i <= n; i++) {
            res = (f1 + f2) % P;
            f1 = f2;
            f2 = res;
        }
        
        return (int)res;
    }
};
