//
//  66 构建乘积数组.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/21.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        auto n = a.size();
        
        vector<int> b;
        for (int i = 0, p = 1; i < n
             ; i++) {
            b[i] = p;
            p *= a[i];
        }
        
        for (int i = n - 1, p = 1; i >= 0; i--) {
            b[i] *= p;
            p *= a[i];
        }
        
        return b;
    }
};
