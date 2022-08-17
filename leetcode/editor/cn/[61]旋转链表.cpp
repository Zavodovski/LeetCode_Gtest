//给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[4,5,1,2,3]
// 
//
// 示例 2： 
// 
// 
//输入：head = [0,1,2], k = 4
//输出：[2,0,1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 500] 内 
// -100 <= Node.val <= 100 
// 0 <= k <= 2 * 10⁹ 
// 
//
// Related Topics 链表 双指针 👍 814 👎 0

//优化版，一次移动k个节点

ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return NULL;
    int n = 0;
    ListNode *tail;
    for (ListNode *p = head; p; p = p->next)
    {
        n ++ ;
        tail = p;
    }
    k %= n;
    if (!k) return head;
    ListNode *a = head;
    for (int i = 0; i < n - k - 1; i ++ )
    {
        a = a ->next;
    }
    ListNode *b = a -> next;
    tail->next = head;
    a->next = NULL;
    return b;
}


//leetcode submit region begin(Prohibit modification and deletion)
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        int length = 0;
        for(auto p = head; p; p = p->next) length ++;
        k = k % length;
        for(int i = 0; i < k; i++)
        {
            auto b = dummy, c = b->next;
            while(c->next)
            {
                b = b->next;
                c = c->next;
            }
            c->next = dummy->next;
            dummy->next = c;
            b->next = nullptr;
        }
        return dummy->next;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
