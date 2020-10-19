//
//  30 MinStack.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        stack_ = new stack<int>();
        min_stack_ = new stack<int>();
    }
    
    void push(int x) {
        stack_->push(x);
        if (min_stack_->empty() || min_stack_->top() >= x) {
            min_stack_->push(x);
        } else {
            min_stack_->push(min_stack_->top());
        }
    }
    
    void pop() {
        stack_->pop();
        min_stack_->pop();
    }
    
    int top() {
        return stack_->top();
    }
    
    int min() {
        return min_stack_->top();
    }
    
private:
    stack<int> *stack_;
    stack<int> *min_stack_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
