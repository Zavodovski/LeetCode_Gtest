//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 示例 4: 
//
// 
//输入: s = ""
//输出: 0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 5 * 10⁴ 
// s 由英文字母、数字、符号和空格组成 
// 
// Related Topics 哈希表 字符串 滑动窗口 👍 6662 👎 0

#include<string>
#include<unordered_map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> hashtable;
        for(int i = 0, j = 0; i < s.size(); i ++)
        {
            auto it = hashtable.find(s[i]);
            if(it == hashtable.end()) hashtable[s[i]] = 1;
            else hashtable[s[i]] ++;
            while(hashtable[s[i]] > 1)
            {
                hashtable[s[j]] --;
                j ++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
