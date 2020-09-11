//
//  31 validateStackSequences.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/9.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        size_t size = pushed.size();
        for (auto num : popped) {
            while ((s.empty() || s.top() != num) && i < size) {
                s.push(pushed[i]);
                i++;
            }
            
            if (!s.empty() && s.top() == num) {
                s.pop();
            }
        }
        
        return s.empty();
    }
};
