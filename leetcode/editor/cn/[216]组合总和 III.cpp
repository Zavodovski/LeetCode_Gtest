//找出所有相加之和为 n 的 k 个数的组合，且满足下列条件： 
//
// 
// 只使用数字1到9 
// 每个数字 最多使用一次 
// 
//
// 返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。 
//
// 
//
// 示例 1: 
//
// 
//输入: k = 3, n = 7
//输出: [[1,2,4]]
//解释:
//1 + 2 + 4 = 7
//没有其他符合的组合了。 
//
// 示例 2: 
//
// 
//输入: k = 3, n = 9
//输出: [[1,2,6], [1,3,5], [2,3,4]]
//解释:
//1 + 2 + 6 = 9
//1 + 3 + 5 = 9
//2 + 3 + 4 = 9
//没有其他符合的组合了。 
//
// 示例 3: 
//
// 
//输入: k = 4, n = 1
//输出: []
//解释: 不存在有效的组合。
//在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。
// 
//
// 
//
// 提示: 
//
// 
// 2 <= k <= 9 
// 1 <= n <= 60 
// 
//
// Related Topics 数组 回溯 👍 528 👎 0

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, n, k);
        return ans;
    }

    void dfs(int start, int n, int k) {
        if (!n) {
            if (!k) ans.push_back(path);
        } else if (k) {
            for (int i = start; i <= 9; i ++ )
                if (n >= i) {
                    path.push_back(i);
                    dfs(i + 1, n - i, k - 1);
                    path.pop_back();
                }
        }
    }
};


#include <vector>
using namespace std;


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<int> path;
    vector<vector<int>> ans;
    

    vector<vector<int>> combinationSum3(int k, int n) {
        if(k >= n) return ans;
        dfs(k, n, 1);
        return ans;
    }

    void dfs(int k, int n, int u)
    {
        if(k == 0)
        {
            if(n == 0) ans.push_back(path);
            return;
        }

        if(n < 0 || u > 9) return;

        dfs(k, n, u + 1);

        path.push_back(u);
        dfs(k - 1, n - u, u + 1);
        path.pop_back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
