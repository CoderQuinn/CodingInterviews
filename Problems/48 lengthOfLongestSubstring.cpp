//
//  48 lengthOfLongestSubstring.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ch_set;
        auto size = s.length();
        int max_size = 0;
        
        for (int i = 0, j = -1; i < size; ++i) {
            if (i > 0) ch_set.erase(s[i - 1]);
            
            while (j + 1 < size && ch_set.count(s[j + 1]) <= 0) {
                j++;
                ch_set.insert(s[j]);
            }
            
            max_size = max(max_size, j - i + 1);
            
        }
        return max_size;
    }
};
