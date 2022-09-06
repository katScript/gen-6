/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class myCmp {
public:
    int operator() (const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        priority_queue<ListNode*, vector<ListNode*>, myCmp> minHeap;
        
        for (auto l: lists) {
            if (l) minHeap.push(l);   
        }
        
        ListNode * result = new ListNode();
        ListNode * cur = result;
        while(!minHeap.empty()) {
            ListNode* topNode = minHeap.top();
            minHeap.pop();
            
            cur->next = topNode;
            cur = cur->next;
            if (topNode->next)
                minHeap.push(topNode->next);
        }
        
        return result->next;
    }
};