//给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的
// 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。 
//
// candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
//
// 对于给定的输入，保证和为 target 的不同组合数少于 150 个。 
//
// 
//
// 示例 1： 
//
// 
//输入：candidates = [2,3,6,7], target = 7
//输出：[[2,2,3],[7]]
//解释：
//2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
//7 也是一个候选， 7 = 7 。
//仅有这两种组合。 
//
// 示例 2： 
//
// 
//输入: candidates = [2,3,5], target = 8
//输出: [[2,2,2,2],[2,3,3],[3,5]] 
//
// 示例 3： 
//
// 
//输入: candidates = [2], target = 1
//输出: []
// 
//
// 
//
// 提示： 
//
// 
// 1 <= candidates.length <= 30 
// 1 <= candidates[i] <= 200 
// candidate 中的每个元素都 互不相同 
// 1 <= target <= 500 
// 
//
// Related Topics 数组 回溯 👍 2120 👎 0
#if 0
class Solution {
public:
    void solve(int i, vector<int>& candidates, int sum,
               vector<int> &ch, int target, vector<vector<int>>& ans) {
        // 注意这里的 ch 是引用。
        if (sum == target) { // 找到目标值，添加答案。
            ans.push_back(ch);
            return;
        }
        if (i == candidates.size() || sum > target) // 超出范围回溯。
            return;

        solve(i + 1, candidates, sum, ch, target, ans);

        ch.push_back(candidates[i]);
        solve(i, candidates, sum + candidates[i], ch, target, ans);
        ch.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> ch; // ch 记录已选择的数字。
        solve(0, candidates, 0, ch, target, ans);

        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, ans);
        return ans;
    }
private:
    void dfs(vector<int>& candidates, int target, int s, vector<int>& cur, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = s; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;
            cur.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, cur, ans);
            cur.pop_back();
        }
    }
};
#endif


#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<int> path;
    vector<vector<int>> ans;


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return ans;
    }

    void dfs(vector<int>& candidates, int u, int target)
    {
        if(target == 0)
        {
            ans.push_back(path);
            return;
        }
        if(u >= candidates.size() || target < 0) return;

        dfs(candidates, u + 1, target);

        for(int i = 1; i <= target / candidates[u]; i ++)
        {
            for(int j = i; j > 0; j --) path.push_back(candidates[u]);
            dfs(candidates, u + 1, target - i * candidates[u]);
            for(int j = i; j > 0; j --) path.pop_back();
            
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
