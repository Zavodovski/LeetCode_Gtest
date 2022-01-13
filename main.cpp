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


int main() {

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
