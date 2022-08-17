//////给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。 
//////
////// 你需要返回给定数组中的重要翻转对的数量。 
//////
////// 示例 1: 
//////
////// 
//////输入: [1,3,2,3,1]
//////输出: 2
////// 
//////
////// 示例 2: 
//////
////// 
//////输入: [2,4,3,5,1]
//////输出: 3
////// 
//////
////// 注意: 
//////
////// 
////// 给定数组的长度不会超过50000。 
////// 输入数组中的所有数字都在32位整数的表示范围内。 
////// 
////// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 326 👎 0
////
//
#include<vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int merge_sort(vector<int>& nums, int l, int r, int length)
    {
        if(l >= r) return 0;
        int mid = (l + r) >> 1;

        int res = merge_sort(nums, l, mid, length) + merge_sort(nums, mid + 1, r, length);
        int tmp[length];
        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= r) {
            for(int m = j; m >= mid + 1; m --)
                if(nums[i] > 2 * nums[m])
                {
                    res += m - mid;
                    break;
                }
            if(nums[i] <= nums[j]) tmp[k++] = nums[i++];
            else
                tmp[k++] = nums[j++];

        }
        while(i <= mid)
        {
            tmp[k++] = nums[i++];
            for(int m = r; m >= mid + 1; m --)
                if(nums[i] > 2 * nums[m])
                {
                    res += m - mid;
                    break;
                }

        }
        while(j <= r)    tmp[k++] = nums[j++];
        for(int i = l, j = 0; i <= r; i++, j++)  nums[i] = tmp[j];
        return res;


    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        int res = merge_sort(nums, 0, n-1, n);
        return res;


    }
};
//leetcode submit region end(Prohibit modification and deletion)
