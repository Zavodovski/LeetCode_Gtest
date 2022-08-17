//给定单个链表的头
// head ，使用 插入排序 对链表进行排序，并返回 排序后链表的头 。 
//
// 插入排序 算法的步骤: 
//
// 
// 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。 
// 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。 
// 重复直到所有输入数据插入完为止。 
// 
//
// 下面是插入排序算法的一个图形示例。部分排序的列表(黑色)最初只包含列表中的第一个元素。每次迭代时，从输入数据中删除一个元素(红色)，并就地插入已排序的列表
//中。 
//
// 对链表进行插入排序。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: head = [4,2,1,3]
//输出: [1,2,3,4] 
//
// 示例 2： 
//
// 
//
// 
//输入: head = [-1,5,3,4,0]
//输出: [-1,0,3,4,5] 
//
// 
//
// 提示： 
//
// 
// 
//
// 
// 列表中的节点数在 [1, 5000]范围内 
// -5000 <= Node.val <= 5000 
// 
//
// Related Topics 链表 排序 👍 538 👎 0
ListNode* insertionSortList(ListNode* head) {
    ListNode *dummy = new ListNode(-1);
    while (head)
    {
        ListNode *next = head->next;
        ListNode *p = dummy;
        while (p->next && p->next-> val <= head->val) p = p->next;

        head->next = p->next;
        p->next = head;

        head = next;
    }
    return dummy->next;
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head->next) return head;
        auto dummy = new ListNode(-1);
        int length = 0;
        for(auto p = head; p; p = p->next) length ++;

        for(int i = 0; i < length; i ++)
        {
            auto p = dummy;
            while(p->next && p->next->val <= head->val) p = p->next;
            auto tmp = head->next;
            head->next = p->next;
            p->next = head;
            head = tmp;
        }

        return dummy->next;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
