//
//  46 把数字翻译成字符串.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/18.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        auto n = s.length();
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1];
            if (i > 1) {
                int tmp = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                if (tmp >= 10 && tmp <= 25) {
                    f[i] += f[i - 2];
                }
            }
        }
        
        return f[n];
    }
};
