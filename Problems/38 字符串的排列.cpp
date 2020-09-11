//
//  38 字符串的排列.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/9.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    unordered_set<string> res;
    string path;
    vector<bool> state;
    
    vector<string> permutation(string s) {
        path.resize(s.length(), '#');
        state.resize(s.length());
        
        dfs(s, 0);
        vector<string> vec;
        for (auto s : res) {
            vec.push_back(s);
        }
        
        return vec;
    }
    
    void dfs(string s, int level)
    {
        if (level == s.length()) {
            if (res.count(path)) {
                res.insert(path);
            }
            return;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (!state[i]) {
                path[level] = s[i];
                state[i] = true;
                dfs(s, level + 1);
                state[i] = false;
                path[level] = '#';
            }
        }
    }
};
