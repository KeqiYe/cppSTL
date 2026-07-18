#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

/*
LeetCode 3：无重复字符的最长子串

问题：
给定字符串 s，求不包含重复字符的最长连续子串长度。子串必须连续。

本题要学会：
1. left/right 表示当前窗口 [left, right]；
2. unordered_set<char> 保存当前窗口内有哪些字符；
3. right 每次加入一个新字符；
4. 新字符已经存在时，持续移除 s[left]，直到窗口重新无重复；
5. 合法窗口长度为 right - left + 1。

注意：set 中保存的是当前窗口，而不是整个字符串中曾经出现过的所有字符。left 移动
时必须 erase 对应字符，否则 set 与窗口内容不一致。

预期平均时间复杂度 O(n)：每个字符最多加入和移出 set 各一次。
额外空间复杂度 O(k)，k 是字符集大小；若只考虑固定字符集，可视为 O(1)。
*/

int lengthOfLongestSubstring(const std::string &s)
{
    if (s.size() == 0)
        return 0;
    std::unordered_set<char> cata;
    int l = 0;
    int maxl = 1;
    cata.insert(s[0]);
    for (int r = 1; r < s.size(); r++)
    {
        while (cata.find(s[r]) != cata.end())
        {
            cata.erase(s[l]);
            l++;
        }
        cata.insert(s[r]);
        maxl = std::max(maxl, r - l + 1);
    }
    return maxl;
}

int lengthOfLongestSubstring2(const std::string &s)
{
    if (s.size() == 0)
        return 0;
    if (s.size() == 1)
        return 1;
    int l = 0;
    std::unordered_set<int> cata;
    cata.insert(s[l]);
    int maxl = 0;
    int r = 1;
    while (r < s.size())
    {
        while (r < s.size() && cata.find(s[r]) == cata.end())
        {
            cata.insert(s[r]);
            r++;
        }
        maxl = std::max((int)cata.size(), maxl);
        if (r == s.size())
            break;
        while (cata.find(s[r]) != cata.end())
        {
            cata.erase(s[l]);
            l++;
        }
    }
    return maxl;
}

int main()
{
    /*
    TODO：使用 assert 或自写 expectEqual 实现测试。

    必测用例：
    1. "abcabcbb" -> 3，对应 "abc"
    2. "bbbbb"    -> 1，对应 "b"
    3. "pwwkew"   -> 3，对应 "wke"
    4. ""         -> 0
    5. " "        -> 1
    6. "abba"     -> 2，检查 left 是否会错误回退

    口头回答：
    - 为什么子序列 "pwke" 不能作为答案？
    - 为什么嵌套 while 的总时间不是 O(n^2)？
    */
    int ans = lengthOfLongestSubstring("vbba");
    std::cout << ans << std::endl;

    std::cout << "TODO: implement lengthOfLongestSubstring and its tests\n";
    return 0;
}
