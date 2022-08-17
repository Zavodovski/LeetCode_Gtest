//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。 
//
// 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [4,2,1,3]
//输出：[1,2,3,4]
// 
//
// 示例 2： 
// 
// 
//输入：head = [-1,5,3,4,0]
//输出：[-1,0,3,4,5]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 5 * 10⁴] 内 
// -10⁵ <= Node.val <= 10⁵ 
// 
//
// 
//
// 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ 
//
// Related Topics 链表 双指针 分治 排序 归并排序 👍 1742 👎 0


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
    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        int n = 0;
        for(auto p = head; p; p = p->next) n ++;

        for(int i = 1; i < n; i = 2 * i)
        {
            auto cur = dummy;
            for(int j = 1; j + i <= n; j += 2 * i)
            {
                auto p = cur->next, q = p;
                for(int k = 0; k < i; k ++) q = q->next;

                int x = 0, y = 0;
                while(x < i && y < i && p && q)
                {
                    if(p->val <= q->val) cur = cur->next = p, p = p->next, x++;
                    else cur = cur->next = q, q = q->next, y ++;
                }
                while(x < i && p) cur = cur->next = p, p = p->next, x ++;
                while(y < i && q) cur = cur->next = q, q = q->next, y ++;

                cur->next = q;

            }
        }
        return dummy->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
