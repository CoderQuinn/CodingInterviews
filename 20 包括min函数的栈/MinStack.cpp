//
//  MinStack.cpp
//  CodingInterviews
//
//  Created by Quinn on 2020/7/18.
//

#include <stdio.h>
#include <stack>
using namespace::std;

class Solution {
public:
    void push(int value) {
        val_stack.push(value);
        if (!min_stack.empty()) {
            int min_val = value > min_stack.top() ? min_stack.top() : value;
            min_stack.push(min_val);
        } else {
            min_stack.push(value);
        }

    }
    
    void pop() {
        val_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return val_stack.top();
    }
    
    int min() {
        return min_stack.top();
    }
    
private:
    std::stack<int> val_stack;
    std::stack<int> min_stack;
};
