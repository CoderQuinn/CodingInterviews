//
//  05 replaceSpace.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/29.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (auto c : s) {
            if (c == ' ') {
                res += "%20";
            } else
                res += c;
        }
        return res;
    }
};

class Solution1 {
public:
    string replaceSpace(string s) {
        int cnt = 0;
        for (auto c : s) {
            if (c == ' ') {
                cnt++;
            }
        }
        if (cnt == 0) return s;
        
        int old_size = (int)s.length();
        int new_size = old_size + cnt * 2;
        s.resize(new_size);
        
        int i = old_size - 1;
        int j = new_size - 1;
        
        while (i >= 0 && j > i) {
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            } else {
                s[j--] = s[i];
            }
            i--;
        }
        
        return s;
    }
};
