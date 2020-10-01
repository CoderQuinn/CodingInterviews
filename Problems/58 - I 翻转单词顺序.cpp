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
        int n = s.length();

        int k = 0;
        for (int i = 0, j = 0; i < n; i++)
        {
            while (j < n && s[j] == ' ')
            {
                j++;
            }
            if(j == n) return s;

            int t = k;
            while (j < n && s[j] != ' ')
            {
                s[k++] = s[j++];
            }
            reverse(s.begin() + t, s.begin() + k);
            if (k < n)
                s[k++] = ' ';
            i = j;
        }

        s.erase(s.begin() + k, s.end());

        return s;
    }
};
