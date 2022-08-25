//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
//
// Related Topics 字符串 动态规划 回溯 👍 2815 👎 0

class Solution {
public:

    vector<string> ans;

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }

    void dfs(int n, int lc, int rc, string seq) {
        if (lc == n && rc == n) ans.push_back(seq);
        else {
            if (lc < n) dfs(n, lc + 1, rc, seq + '(');
            if (rc < n && lc > rc) dfs(n, lc, rc + 1, seq + ')');
        }
    }
};


//自己写的版本
class Solution {
public:

    vector<string> ans;
    string path;

    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n);
        return ans;
    }

    void dfs(int left, int right, int n)
    {
        if(left == n && right == n)
        {
            ans.push_back(path);
            return;
        }
        
        if(left < n)
        {
            path += '(';
            dfs(left + 1, right, n);
            path.pop_back();
        }

        if(left > right && right < n)
        {
            path += ')';
            dfs(left, right + 1, n);
            path.pop_back();
        }
        
    }
};


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<string> res;

    vector<string> generateParenthesis(int n) {
        if(n == 0) return res;
        dfs(0, 0, n, "");
        return res;
    }

    void dfs(int l, int r, int n, string cur)
    {
        if(l == n && r == n)
        {
            res.push_back(cur);
            return;
        }
        if(l < n) dfs(l + 1, r, n, cur + '(');
        if(r < l) dfs(l, r + 1, n, cur + ')');
    }
};
//leetcode submit region end(Prohibit modification and deletion)
