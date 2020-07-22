//
//  printListFromTailToHead.cpp
//  CodingInterviews
//
//  Created by Quinn on 2020/7/15.
//

#include <stdio.h>
#include <vector>
#include <stack>
using namespace::std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

// 思路1: 利用c++的倒置函数
class Solution01 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vector;
        ListNode *p = head;
        while (p) {
            vector.push_back(p->val);
            p = p->next;
        }
        reverse(vector.begin(), vector.end());
        return vector;
    }
};

// 思路2: 栈+数组
class Solution02 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vector;
        stack<int> stack;
        
        ListNode *p = head;
        while (p) {
            stack.push(p->val);
            p = p->next;
        }
        
        while (!stack.empty()) {
            vector.push_back(stack.top());
            stack.pop();
        }
        
        return vector;
    }
};

// 思路3: 递归
class Solution03 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vector;
        if (!head) return vector;
        
        vector = printListFromTailToHead(head->next);
        vector.push_back(head->val);
        return vector;
    }
};

// 思路4: 反转链表
class Solution04 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vector;
        
        ListNode *ptr = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = ptr;
            ptr = curr;
            curr = next;
        }
        
        while (ptr) {
            vector.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        return vector;
    }
};
