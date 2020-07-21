//
//  IsPopOrder.cpp
//  CodingInterviews
//
//  Created by Quinn on 2020/7/18.
//

#include <stdio.h>
#include <vector>
#include <stack>
using namespace::std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        bool result = false;
        stack<int> stack;
        vector<int>::iterator popV_it = popV.begin();
        for (vector<int>::iterator it = pushV.begin(); it != pushV.end(); ++it) {
            stack.push(*it);
            while (!stack.empty() && popV_it != popV.end() && stack.top() == *popV_it) {
                stack.pop();
                ++popV_it;

            }
        }

        result = stack.empty();

        return result;
    }
};
