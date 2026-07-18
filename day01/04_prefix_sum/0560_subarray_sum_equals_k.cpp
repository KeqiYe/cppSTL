#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/*
LeetCode 560：和为 K 的子数组

问题：
给定整数数组 nums 和整数 k，返回和等于 k 的连续子数组数量。

本题要学会：
1. prefixSum 表示从数组开头累加到当前位置的和；
2. 若 prefixSum - oldPrefixSum == k，则中间子数组之和为 k；
3. unordered_map<long long, int> 记录每种前缀和出现的次数；
4. frequency[0] = 1 表示扫描开始前的空前缀；
5. 必须先查询 prefixSum - k，再记录当前 prefixSum。

注意：
- 子数组必须连续；
- 答案统计的是子数组数量，不是不同的和值数量；
- 数组可能包含负数，不能依赖普通滑动窗口的单调性。

预期时间复杂度 O(n)，额外空间复杂度 O(n)。
*/

int subarraySum(const std::vector<int>& nums, int k)
{
    // TODO：使用“前缀和 + 出现次数哈希表”完成实现。
    // 提示：初始化 frequency[0] = 1。
    (void)nums;
    (void)k;
    return 0;
}

int main()
{
    struct TestCase
    {
        std::string name;
        std::vector<int> nums;
        int k;
        int expected;
    };

    const std::vector<TestCase> tests{
        {"basic repeated", {1, 1, 1}, 2, 2},
        {"whole and single", {1, 2, 3}, 3, 2},
        {"negative and zero", {1, -1, 0}, 0, 3},
        {"all zeros", {0, 0, 0}, 0, 6},
        {"mixed values", {3, 4, 7, 2, -3, 1, 4, 2}, 7, 4},
        {"empty input", {}, 0, 0},
        {"no matching subarray", {1, 2, 3}, 10, 0},
    };

    int passed = 0;

    for (std::size_t i = 0; i < tests.size(); ++i)
    {
        const int actual = subarraySum(tests[i].nums, tests[i].k);
        const bool ok = actual == tests[i].expected;

        std::cout << "Test " << i + 1 << " (" << tests[i].name << "): "
                  << (ok ? "PASS" : "FAIL")
                  << "  expected=" << tests[i].expected
                  << "  actual=" << actual << '\n';

        if (ok)
            ++passed;
    }

    std::cout << "Passed " << passed << '/' << tests.size() << " tests\n";
    return passed == static_cast<int>(tests.size()) ? 0 : 1;
}
