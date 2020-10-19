//
//  20 isNumber.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/9.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        size_t size = s.length();
        int i = 0, j = int(size - 1);
        
        // 去掉字符串前后的空格
        while (i < size && s[i] == ' ') {
            i++;
        }
        while (j >= 0 && s[j] == ' ') {
            j--;
        }
        if (i > j) return false;
        
        s = s.substr(i, j - i + 1);
        
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1);
        
        if (s.empty() || (s.size() == 1 && s[0] == '.')) return false;
        
        int dot_cnt = 0, e_cnt = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                continue;
            } else if (s[i] == '.') {
                dot_cnt++;
                if (dot_cnt > 1 || e_cnt > 0) { // .个数大于1 或者 .前有e
                    return false;
                }
            } else if (s[i] == 'e' || s[i] == 'E') {
                e_cnt++;
                if (i == 0 || i + 1 == s.size() || e_cnt > 1 || (i == 1 && s[i - 1] == '.')) { // e前无数字， e后无数字，e个数大于1, .e1的情况
                    return false;
                } else if (s[i + 1] == '+' || s[i + 1] == '-') { // 过滤掉e后的+ -
                    i++;
                    if (i + 1 == s.size()) {
                        return false;
                    }
                }
                
            } else {
                return false;
            }
        }
        
        return true;
    }
};
