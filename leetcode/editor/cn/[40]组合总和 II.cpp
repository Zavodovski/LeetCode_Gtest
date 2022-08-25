//给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的每个数字在每个组合中只能使用 一次 。 
//
// 注意：解集不能包含重复的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//] 
//
// 示例 2: 
//
// 
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//] 
//
// 
//
// 提示: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
//
// Related Topics 数组 回溯 👍 1075 👎 0

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        dfs(c, 0, target);

        return ans;
    }

    void dfs(vector<int>& c, int u, int target) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (u == c.size()) return;

        int k = u + 1;
        while (k < c.size() && c[k] == c[u]) k ++ ;
        int cnt = k - u;

        for (int i = 0; c[u] * i <= target && i <= cnt; i ++ ) {
            dfs(c, k, target - c[u] * i);
            path.push_back(c[u]);
        }

        for (int i = 0; c[u] * i <= target && i <= cnt; i ++ ) {
            path.pop_back();
        }
    }
};


#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<int> temp;
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return ans;
    }

    void dfs(vector<int>& candidates, int u, int target)
    {
        if(u == candidates.size())
        {
            if(target == 0) ans.push_back(temp);
            return;
        }

        int k = u + 1;
        while(k < candidates.size() && candidates[k] == candidates[u]) k ++;

        dfs(candidates, k, target);
        if(target - candidates[u] < 0) return;
        else
        {
            temp.push_back(candidates[u]);

            dfs(candidates, u + 1, target - candidates[u]);
            temp.pop_back();
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)
