//
//  09 CQueue.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <stack>
using namespace std;

class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        stack1_.push(value);
    }
    
    int deleteHead() {
        if (stack2_.empty()) {
            while (!stack1_.empty()) {
                int top = stack1_.top();
                stack2_.push(top);
                stack1_.pop();
            }
        }
        
        if (stack2_.empty()) {
            return -1;
        }
        
        int top = stack2_.top();
        stack2_.pop();
        return top;
    }
    
private:
    stack<int> stack1_;
    stack<int> stack2_;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
