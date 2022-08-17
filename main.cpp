#include <bits/stdc++.h>
#include "gtest/gtest.h"
using namespace std;

int add(int a, int b) {
    return a + b;
}
vector<int> twoSum(vector<int> nums, int target) {
    unordered_map<int, int> hashtable;
    for(int i=0; i<nums.size(); i++)
    {
        auto it = hashtable.find(target-nums[i]);
        if(it != hashtable.end())
        {
            return {it->second, i};
        }
        hashtable[nums[i]] = i;
    }
    return {};

}
int merge_sort(vector<int>& nums, int l, int r, int length)
{
    if(l >= r) return 0;
    int mid = (l + r) >> 1;

    int res = merge_sort(nums, l, mid, length) + merge_sort(nums, mid + 1, r, length);
    int tmp[length];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        for(int k = j; k >= mid + 1; k --)
            if(nums[i] > 2 * nums[k])
            {
                res += k - mid;
            }

        if(nums[i] <= nums[j]) tmp[k++] = nums[i++];
        else
            tmp[k++] = nums[j++];

    }
    while(i <= mid)  tmp[k++] = nums[i++];
    while(j <= r)    tmp[k++] = nums[j++];
    for(int i = l, j = 0; i <= r; i++, j++)  nums[i] = tmp[j];
    return res;


}

int reversePairs(vector<int>& nums) {
    int n = nums.size();

    int res = merge_sort(nums, 0, n-1, n);
    return res;


}

int lengthOfLongestSubstring(string s) {
    int res = 0;
    unordered_map<char, int> hashtable;
    for(int i = 0, j = 0; i < s.size(); i ++)
    {
        auto it = hashtable.find(s[i]);
        if(it == hashtable.end()) hashtable[s[i]] = 1;
        else hashtable[s[i]] ++;
        while(hashtable[s[i]] > 1)
        {
            hashtable[s[j]] --;
            j ++;
        }
        res = max(res, i - j + 1);
    }
    return res;
}

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


TEST(add, zero) {
EXPECT_EQ(0, add(0, 0)) << "yes";
}

TEST(add, positive_number) {
EXPECT_EQ(3, add(1, 2));
}

TEST(add, negative_number) {
EXPECT_EQ(-3, add(-1, -2));
}

TEST(twoSum, TestCase) {
    vector<int> nums = {2,7,11,15};
    vector<int> result = {0,1};
    EXPECT_EQ(result, twoSum(nums, 9));
}

TEST(reversePairs, TestCase) {
    vector<int> nums = {2,4,3,5,1};
    int result = 3;
    EXPECT_EQ(result, reversePairs(nums));
}

TEST(lengthOfLongestSubstring, TestCase) {
    string s = "pwwkew";
    int result = 3;
    EXPECT_EQ(result, lengthOfLongestSubstring(s));
}

TEST(findMedianSortedArrays, TestCase) {
    vector<int> nums1 = {};
    vector<int> nums2 = {2, 3};
    double result = 2.5;
    EXPECT_EQ(result, findMedianSortedArrays(nums1, nums2));
}


int main() {

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
