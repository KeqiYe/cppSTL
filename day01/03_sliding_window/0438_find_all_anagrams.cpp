#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
/*
LeetCode 438：找到字符串中所有字母异位词

问题：
给定字符串 s 和 p，找出 s 中所有与 p 互为字母异位词的连续子串，返回这些子串
在 s 中的起始下标。题目字符范围为小写英文字母。

本题要学会：
1. 窗口长度固定为 p.size()；
2. array<int, 26> 保存 26 个字母的出现次数；
3. 字符 c 对应下标 c - 'a'；
4. right 加入字符时计数加一，left 移出字符时计数减一；
5. 两个 std::array 可以直接使用 == 比较全部元素。

示例：字符 'c' 的计数位置是：

    int index = 'c' - 'a';  // 2

初始化必须使用 {}：

    std::array<int, 26> count{};

这样 26 个整数都会初始化为 0。

预期时间复杂度 O(n)。每次比较两个长度固定为 26 的 array 需要 O(26)，在本题中
视为常数。额外空间 O(26)，即 O(1)。
*/

std::vector<int> findAnagrams_m1(const std::string &s, const std::string &p)
{
    std::unordered_set<std::string> needs;
    std::string tmp = p;
    std::sort(tmp.begin(), tmp.end());
    needs.insert(tmp);
    std::vector<int> ans;
    for (int i = 0; i < s.size() - p.size() + 1; i += 1)
    {
        std::string tmp;
        for (int j = 0; j < p.size(); j++)
            tmp.push_back(s[i + j]);
        std::sort(tmp.begin(), tmp.end());
        if (needs.find(tmp) != needs.end())
            ans.push_back(i);
    }

    return ans;
}
std::vector<int> findAnagrams_m2(const std::string &s, const std::string &p)
{
    if (p.size() > s.size())
        return {};
    std::array<int, 26> need{};
    std::array<int, 26> window{};
    std::vector<int> ans;
    for (auto &pi : p)
        need[pi - 'a']++;
    for (int i = 0; i < p.size(); i++)
        window[s[i] - 'a']++;
    for (int i = 0; i < s.size() - p.size() + 1; i += 1)
    {
        if (window == need)
            ans.push_back(i);

        {
            window[s[i] - 'a']--;
            window[s[i + p.size()] - 'a']++;
        }
    }

    return ans;
}

int main()
{
    /*
    TODO：亲手实现自动测试。vector<int> 可以直接使用 == 比较。

    必测用例：
    1. s="cbaebabacd", p="abc" -> {0, 6}
    2. s="abab",       p="ab"  -> {0, 1, 2}
    3. s="a",          p="ab"  -> {}
    4. s="baa",        p="aa"  -> {1}
    5. s="aaaaaaaaaa", p="aa"  -> {0,1,2,3,4,5,6,7,8}

    口头回答：
    - 为什么窗口超过 p 的长度时必须移除最左字符？
    - 为什么只比较总字符数相等不够，必须比较每个字母的次数？
    */
    struct TestCase
    {
        std::string s;
        std::string p;
        std::vector<int> expected;
    };

    const std::vector<TestCase> tests{
        {"cbaebabacd", "abc", {0, 6}},
        {"abab", "ab", {0, 1, 2}},
        {"baa", "aa", {1}},
        {"aaaaaaaaaa", "aa", {0, 1, 2, 3, 4, 5, 6, 7, 8}},
        {"abc", "abc", {0}},
        {"abc", "d", {}},
        {"a", "a", {0}},
        // 放在最后：当前实现对此用例存在 size_t 下溢风险。
        {"a", "ab", {}},
    };

    int passed = 0;
    for (std::size_t i = 0; i < tests.size(); ++i)
    {
        const auto actual = findAnagrams_m2(tests[i].s, tests[i].p);
        const bool ok = actual == tests[i].expected;

        std::cout << "Test " << i + 1 << ": " << (ok ? "PASS" : "FAIL")
                  << "  s=\"" << tests[i].s << "\""
                  << "  p=\"" << tests[i].p << "\"" << std::endl;

        if (!ok)
        {
            std::cout << "  expected:";
            for (int index : tests[i].expected)
                std::cout << ' ' << index;

            std::cout << "\n  actual:  ";
            for (int index : actual)
                std::cout << ' ' << index;
            std::cout << '\n';
        }
        else
        {
            ++passed;
        }
    }

    std::cout << "Passed " << passed << '/' << tests.size() << " tests\n";
    return passed == static_cast<int>(tests.size()) ? 0 : 1;
}
