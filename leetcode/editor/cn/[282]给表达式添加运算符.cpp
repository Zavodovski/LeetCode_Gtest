//给定一个仅包含数字 0-9 的字符串 num 和一个目标值整数 target ，在 num 的数字之间添加 二元 运算符（不是一元）+、- 或 * ，返回 
//所有 能够得到 target 的表达式。 
//
// 注意，返回表达式中的操作数 不应该 包含前导零。 
//
// 
//
// 示例 1: 
//
// 
//输入: num = "123", target = 6
//输出: ["1+2+3", "1*2*3"] 
//解释: “1*2*3” 和 “1+2+3” 的值都是6。
// 
//
// 示例 2: 
//
// 
//输入: num = "232", target = 8
//输出: ["2*3+2", "2+3*2"]
//解释: “2*3+2” 和 “2+3*2” 的值都是8。
// 
//
// 示例 3: 
//
// 
//输入: num = "3456237490", target = 9191
//输出: []
//解释: 表达式 “3456237490” 无法得到 9191 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= num.length <= 10 
// num 仅含数字 
// -2³¹ <= target <= 2³¹ - 1 
// 
//
// Related Topics 数学 字符串 回溯 👍 417 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
typedef long long LL;

class Solution {
public:

    vector<string> ans;
    string path;

    vector<string> addOperators(string num, int target) {
        path.resize(100);
        dfs(num, 0, 0, 0, 1, target);
        return ans;
    }

    void dfs(string num, int u, int len, LL a, LL b, int target)
    {
        if(u == num.size())
        {
            if(a == target) ans.push_back(path.substr(0, len - 1));
            return;
        }
        else
        {
            LL c = 0;
            for(int i = u; i < num.size(); i ++)
            {
                c = c * 10 + num[i] - '0';
                path[len ++] = num[i];

                path[len] = '+';
                dfs(num, i + 1, len + 1, a + b * c, 1, target);

                if(i + 1 < num.size())
                {
                    path[len] = '-';
                    dfs(num, i + 1, len + 1, a + b * c, -1, target);

                    path[len] = '*';
                    dfs(num, i + 1, len + 1, a, b * c, target);
                }

                if(num[u] == '0') break;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
