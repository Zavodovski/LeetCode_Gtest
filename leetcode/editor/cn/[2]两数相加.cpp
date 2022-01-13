//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。 
//
// 请你将两个数相加，并以相同形式返回一个表示和的链表。 
//
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 
//
// 示例 1： 
//
// 
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.
// 
//
// 示例 2： 
//
// 
//输入：l1 = [0], l2 = [0]
//输出：[0]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//输出：[8,9,9,9,0,0,0,1]
// 
//
// 
//
// 提示： 
//
// 
// 每个链表中的节点数在范围 [1, 100] 内 
// 0 <= Node.val <= 9 
// 题目数据保证列表表示的数字不含前导零 
// 
// Related Topics 递归 链表 数学 👍 7288 👎 0



 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3;
        ListNode* CurrentNode_l1 = l1;
        ListNode* CurrentNode_l2 = l2;
        ListNode* CurrentNode_l3 = l3;
        int plus = 0;
        while(CurrentNode_l1->next != nullptr && CurrentNode_l2->next != nullptr)
        {
            CurrentNode_l3->val = CurrentNode_l1->val + CurrentNode_l2->val + plus;
            plus = 0;
            if(CurrentNode_l3->val>10)
            {
                CurrentNode_l3->val = 0;
                plus = 1;
            }
            CurrentNode_l1 = CurrentNode_l1->next;
            CurrentNode_l2 = CurrentNode_l2->next;
            CurrentNode_l3 = CurrentNode_l3->next;
            l3->next = CurrentNode_l3->next;
        }
        if(CurrentNode_l1->next == nullptr)
        {
            while (CurrentNode_l2->next != nullptr)
            {
                CurrentNode_l3->val = CurrentNode_l2->val + plus;
                plus = 0;
                if (CurrentNode_l3->val > 10)
                {
                    CurrentNode_l3->val = 0;
                    plus = 1;
                }
                CurrentNode_l2 = CurrentNode_l2->next;
            }
        }
        if(CurrentNode_l2->next == nullptr)
        {
            while (CurrentNode_l1->next != nullptr)
            {
                CurrentNode_l3->val = CurrentNode_l1->val + plus;
                plus = 0;
                if (CurrentNode_l3->val > 10) {
                    CurrentNode_l3->val = 0;
                    plus = 1;
                }
                CurrentNode_l1 = CurrentNode_l1->next;
            }
        }
        return l3;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
