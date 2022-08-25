//你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i 个火柴棒的长度。你要用 所有的火柴棍 拼成一个正方形。你 不能
//折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次 。 
//
// 如果你能使这个正方形，则返回 true ，否则返回 false 。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: matchsticks = [1,1,2,2,2]
//输出: true
//解释: 能拼成一个边长为2的正方形，每边两根火柴。
// 
//
// 示例 2: 
//
// 
//输入: matchsticks = [3,3,3,3,4]
//输出: false
//解释: 不能用所有火柴拼成一个正方形。
// 
//
// 
//
// 提示: 
//
// 
// 1 <= matchsticks.length <= 15 
// 1 <= matchsticks[i] <= 10⁸ 
// 
//
// Related Topics 位运算 数组 动态规划 回溯 状态压缩 👍 431 👎 0

class Solution {
public:
    vector<int> nums;
    vector<bool> st;

    bool dfs(int start, int cur, int length, int cnt) {
        if (cnt == 3) return true;
        if (cur == length) return dfs(0, 0, length, cnt + 1);
        for (int i = start; i < nums.size(); i ++ ) {
            if (st[i]) continue;
            if (cur + nums[i] <= length) {
                st[i] = true;
                if (dfs(i + 1, cur + nums[i], length, cnt)) return true;
                st[i] = false;
            }
            if (!cur || cur + nums[i] == length) return false;
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i ++ ;
        }
        return false;
    }

    bool makesquare(vector<int>& _nums) {
        nums = _nums;
        if (nums.empty()) return false;
        st.resize(nums.size());
        int sum = 0;
        for (auto x: nums) sum += x;
        if (sum % 4) return false;
        sum /= 4;
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(0, 0, sum, 0);
    }
};


#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> nums;
    vector<bool> st; // 表示每根木棍有没有被用过

    bool dfs(int start, int cur, int length, int cnt) {
        if (cnt == 3) return true; // 如果已经拼出三根了，那么最后一根就不用管了，一定能拼出来
        if (cur == length) return dfs(0, 0, length, cnt + 1); // 如果当前长度就是每条边要拼的总长度，说明已经拼出来了新的一根

        for (int i = start; i < nums.size(); i ++ ) { // 从start开始枚举
            if (st[i]) continue; // 如果当前火柴已经被用过了就跳过
            if (cur + nums[i] <= length) { // 如果当前火柴加当前长度是不超过总长度的，那么就要搜一下
                st[i] = true;
                if (dfs(i + 1, cur + nums[i], length, cnt)) return true; // 这里搜索的时候是 i + 1，这是剪枝的一种，要求按编号递增地搜索
                st[i] = false;
            }
            if (cur == 0 || cur + nums[i] == length) return false; // 如果是在第一根或者最后一根失败的，就剪掉当前分支
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i ++ ; // 将当前相同长度的木棍跳过
        }
        return false;
    }

    bool makesquare(vector<int>& _nums) {
        nums = _nums;
        if (nums.empty()) return false; // 特判为空的情况
        st.resize(nums.size());
        int sum = 0;
        for (auto x: nums) sum += x;
        if (sum % 4 != 0) return false;
        sum /= 4;
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(0, 0, sum, 0); // 从第0个火柴开始枚举，当前长度是0，每条边的总长度是sum，当前拼的是第0根
    }

};
//leetcode submit region end(Prohibit modification and deletion)
