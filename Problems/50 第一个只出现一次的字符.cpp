//
//  50 firstUniqChar.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        int digits[26] = {0};
        for (auto ch : s) {
            digits[ch - 'a'] += 1;
        }
        char ans = ' ';
        for (auto ch : s) {
            if (digits[ch - 'a'] == 1) {
                ans = ch;
                break;
            }
        }

        return ans;
    }
};

class Solution1
{
public:
    char firstNotRepeatingChar(string s)
    {
        unordered_map<char, int> digits;
        for (auto &ch : s)
        {
            digits[ch]++;
        }

        for (auto &ch : s)
        {
            if(digits[ch] == 1)
                return ch;
        }

        return '#';
    }
};
