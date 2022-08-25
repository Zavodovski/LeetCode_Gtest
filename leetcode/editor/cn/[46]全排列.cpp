//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1]
//输出：[[0,1],[1,0]]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1]
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// nums 中的所有整数 互不相同 
// 
//
// Related Topics 数组 回溯 👍 2170 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    std::vector<bool> st;
    std::vector<int> path;
    std::vector<std::vector<int>> ans;

    std::vector<vector<int>> permute(std::vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); i ++) st.push_back(false);
        dfs(nums, 0);
        return ans;
    }

    void dfs(std::vector<int>& nums, int u)
    {
        if(u == nums.size())
        {
            ans.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i ++)
        {
            if(!st[i])
            {
                st[i] = true;
                path.push_back(nums[i]);
                dfs(nums, u + 1);
                st[i] = false;
                path.pop_back();
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
