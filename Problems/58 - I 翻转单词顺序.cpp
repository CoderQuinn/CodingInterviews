//
//  58 - I 翻转单词顺序.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/20.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') continue;
            int j = i, t = k;
            while (j < s.size() && s[j] != ' ') {
                s[t++] = s[j++];
            }
            reverse(s.begin() + k, s.begin() + t);
            s[t++] = ' ';
            i = j;
            k = t;
        }
        if(k > 0) k--;
        s.erase(s.begin() + k, s.end());
        return s;
    }
};
