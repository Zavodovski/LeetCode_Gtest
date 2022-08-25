//给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。 
//
// 返回所有可能的结果。答案可以按 任意顺序 返回。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "()())()"
//输出：["(())()","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：s = "(a)())()"
//输出：["(a())()","(a)()()"]
// 
//
// 示例 3： 
//
// 
//输入：s = ")("
//输出：[""]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 25 
// s 由小写英文字母以及括号 '(' 和 ')' 组成 
// s 中至多含 20 个括号 
// 
//
// Related Topics 广度优先搜索 字符串 回溯 👍 758 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<string> ans;

    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for(auto x : s)
        {
            if(x == '(') l ++;
            else if(x == ')')
            {
                if (l == 0) r++;
                else l--;
            }
        }

        dfs(s, 0, "", 0, l, r);
        return ans;
    }

    void dfs(string s, int u, string path, int cnt, int l, int r)
    {
        if(u == s.size())
        {
            if(!cnt) ans.push_back(path);
            return;
        }

        if(s[u] != '(' && s[u] != ')') dfs(s, u + 1, path + s[u], cnt, l, r);
        else if(s[u] == '(')
        {
            int k = u;
            while(k < s.size() && s[k] == '(') k ++;
            l -= k - u;
            for(int i = k - u; i >= 0; i --)
            {
                if (l >= 0) dfs(s, k, path, cnt, l, r);
                path += '(';
                cnt++, l++;
            }
        }
        else if(s[u] == ')')
        {
            int k = u;
            while(k < s.size() && s[k] == ')') k ++;
            r -= k - u;
            for(int i = k - u; i >= 0; i --)
            {
                if(cnt >= 0 && r >= 0) dfs(s, k, path, cnt, l, r);
                path += ')';
                cnt --, r ++;
            }

        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
