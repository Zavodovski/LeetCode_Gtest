//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。 
//
// 算法的时间复杂度应该为 O(log (m+n)) 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [1,3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1,2,3] ，中位数 2
// 
//
// 示例 2： 
//
// 
//输入：nums1 = [1,2], nums2 = [3,4]
//输出：2.50000
//解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
// 
//
// 
//
// 
//
// 提示： 
//
// 
// nums1.length == m 
// nums2.length == n 
// 0 <= m <= 1000 
// 0 <= n <= 1000 
// 1 <= m + n <= 2000 
// -10⁶ <= nums1[i], nums2[i] <= 10⁶ 
// 
// Related Topics 数组 二分查找 分治 👍 5063 👎 0

#include<vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int idx = (nums1.size() + nums2.size()) / 2;
        int i = 0, j = 0;
        vector<int> nums3;
        while(i < nums1.size() && j < nums2.size())
        {

            if(nums1[i] <= nums2[j])
            {
                nums3.push_back((nums1[i]));
                i ++;
            }
            else
            {
                nums3.push_back(nums2[j]);
                j ++;
            }
            if(nums3.size() > idx) break;
        }
        while(nums3.size() <= idx)
        {
            if(i < nums1.size()) nums3.push_back(nums1[i ++]);
            if(j < nums2.size()) nums3.push_back(nums2[j ++]);
        }

        if((nums1.size() + nums2.size()) % 2 == 1) return nums3.back();
        else return (nums3[nums3.size() - 1] + nums3[nums3.size() - 2]) / 2.0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
