//给你一个字符串 s，找到 s 中最长的回文子串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出："bb"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由数字和英文字母组成 
// 
// Related Topics 字符串 动态规划 👍 4784 👎 0

#include<string>
#include<vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        if(n < 2) return s;
        vector<vector<int>> dp(n, vector<int>(n));
        int start = 0, maxlen = 1;
        for(int i = 0; i < n; i ++)
        {
            dp[i][i] = 1;
            if(s[i] == s[i + 1] && i + 1 < n)
            {
                dp[i][i + 1] = 1;
                start = i;
                maxlen = 2;
            }
        }
        //枚举一下子串长度
        for(int k = 3; k <= n; k ++)
        {
            for(int i = 0; i + k - 1 < n; i ++)
            {
                int j = i + k - 1;
                if(s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                    start = i;
                    maxlen = k;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
