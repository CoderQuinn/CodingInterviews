//
//  14 - I cuttingRope.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 1) return 0;
        if (n <= 3) return n - 1;
        
        vector<int> res(n + 1, 0);
        
        res[1] = 1;
        res[2] = 2;
        res[3] = 3;

        for (int i = 4; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                res[i] = max(res[i], j * res[i - j]);
            }
        }
        return res[n];
    }
};
