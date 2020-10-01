//
//  59 - II MaxQueue.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <queue>
using namespace std;

// 维护一个最大值的单调队列
class MaxQueue {
public:
    MaxQueue() {
        
    }
    
    int max_value() {
        if (max_queue_.empty()) return -1;
        
        return max_queue_.front();
        
    }
    
    void push_back(int value) {
        queue_.push(value);
        
        while (!max_queue_.empty() && max_queue_.back() <= value) {
            max_queue_.pop_back();
        }
        
        max_queue_.push_back(value);
    }
    
    int pop_front() {
        if(queue_.empty()) return -1;
        
        int top = queue_.front();
        queue_.pop();
        
        if (top == max_queue_.front()) {
            max_queue_.pop_front();
        }
        
        return top;
    }
    
private:
    queue<int> queue_;
    deque<int> max_queue_;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
