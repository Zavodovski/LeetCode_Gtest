//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。 
//
// 
// 
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,2]
//输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// 
//
// Related Topics 位运算 数组 回溯 👍 905 👎 0

#if 0
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int u)
    {
        int n = nums.size();
        if(u == n)
        {
            res.push_back(path);
            return;
        }

        int k = u;
        while(k < nums.size() && nums[k] == nums[u]) k++;
        dfs(nums, k); //当前这种数一个都不选
        for(int i = u; i < k; i++) //分别选1个,2个...
        {
            path.push_back(nums[u]);
            dfs(nums, k);
        }
        path.erase(path.end() - (k - u), path.end()); //回溯，将选择的这一段相同的数全部清空
    }
};

#endif

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    std::vector<vector<int>> res;
    std::vector<int> path;

    vector<vector<int>> subsetsWithDup(std::vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 把所有相同的数放在一起，方便后续处理
        dfs(nums, 0);
        return res;
    }

    void dfs(std::vector<int>& nums, int u)
    {
        res.push_back(path);
        for (int i = u; i < nums.size(); i ++)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
            // 只要前一个数和后一个数相同，就不再遍历这个数
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++ i;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
