//
//  58 - II 左旋转字符串.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/21.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <string>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        auto size = s.length();
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + size - n);
        reverse(s.begin() + size - n, s.end());
        
        return s;
    }
};
