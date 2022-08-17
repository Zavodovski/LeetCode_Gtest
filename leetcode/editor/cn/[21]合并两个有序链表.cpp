//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
// 
//
// 示例 1： 
// 
// 
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
// 
//
// 示例 2： 
//
// 
//输入：l1 = [], l2 = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [], l2 = [0]
//输出：[0]
// 
//
// 
//
// 提示： 
//
// 
// 两个链表的节点数目范围是 [0, 50] 
// -100 <= Node.val <= 100 
// l1 和 l2 均按 非递减顺序 排列 
// 
//
// Related Topics 递归 链表 👍 2603 👎 0


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list2) return list1;
        if(!list1) return list2;
        auto dummy = new ListNode(-1);
        auto head = dummy;
        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                dummy->next = list1;
                list1 = list1->next;
                dummy = dummy->next;
            }
            else
            {
                dummy->next = list2;
                list2 = list2->next;
                dummy = dummy->next;
            }
        }
        while(list1) { dummy->next = list1; list1 = list1->next; dummy = dummy->next; }
        while(list2) { dummy->next = list2; list2 = list2->next; dummy = dummy->next; }
        return head->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
