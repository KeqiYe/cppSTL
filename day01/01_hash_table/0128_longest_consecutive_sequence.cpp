#include <iostream>
#include <limits>
#include <unordered_set>
#include <vector>

/*
LeetCode 128：最长连续序列

问题：
给定一个未排序整数数组，返回其中数字连续的最长序列长度。
数字在原数组中不需要相邻，算法需要达到平均 O(n) 时间。

本题要学会：
1. 用 unordered_set 去重并提供平均 O(1) 的存在性查询。
2. 只有当 x - 1 不存在时，x 才是一个连续序列的起点。
3. 只从起点向右扩展，避免从每个元素重复扫描。
4. 理解嵌套 while 不一定是 O(n^2)：这里每个元素最多被有效扩展一次。

核心不变量：
开始向右枚举时，current 所在序列不存在更小的前驱，因此当前枚举的是一条
完整且此前不会从其他元素重复开始的连续序列。

边界提醒：
- 空数组答案为 0；
- 重复元素不能增加长度；
- 对 INT_MIN 计算 x - 1、对 INT_MAX 计算 x + 1 会产生有符号溢出，必须保护。
*/

int longestConsecutive(const std::vector<int> &nums)
{
   std::unordered_map<int, int> c;
   int maxl = 0;
   if (nums.size() == 0)
      return 0;
   for (auto num : nums)
   {
      c[num]++;
   }
   for (const auto& cc : c)
   {
      if(c.count(cc.first - 1) != 0)
         continue;
      int t = cc.first;
      int l = 1;
      while(c.count(t+1) > 0)
      // while (c.find(t + 1) != c.end())
      {
         l++;
         t++;
      }
      maxl = std::max(l, maxl);
   }
   return maxl;
}
int longestConsecutivenew(const std::vector<int> &nums)
{
   std::unordered_set<int> c;
   int maxl = 0;
   if (nums.size() == 0)
      return 0;
   for (auto num : nums)
   {
      c.insert(num);
   }
   for (const auto& cc : c)
   {
      int l = 1;
      int t = cc;
      if(c.count(cc - 1)> 0)
         continue;
      while (c.find(t + 1) != c.end())
      {
         l++;
         t++;
      }
      maxl = std::max(l, maxl);
   }
   return maxl;
}
int main()
{
   /*
   TODO: 由你亲手实现测试，建议使用 assert 或自写 expectEqual。

   必测用例：

   1. 常规输入
      输入：{100, 4, 200, 1, 3, 2}
      期望：4，对应 1,2,3,4

   2. 包含重复元素
      输入：{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}
      期望：9

   3. 空数组
      输入：{}
      期望：0

   4. 全是重复元素
      输入：{5, 5, 5}
      期望：1

   5. 包含负数
      输入：{-2, -1, 0, 1, 2}
      期望：5

   6. 整数边界
      输入：{INT_MIN, INT_MIN + 1, INT_MAX}
      期望：2

   7. 无连续元素
      输入：{10, 30, 50}
      期望：1
   */
   int ans = longestConsecutive({0, 3, 7, 2, 5, 8, 4, 6, 0, 1});
   std::cout << ans << std::endl;

   ans = longestConsecutivenew({0, 3, 7, 2, 5, 8, 4, 6, 0, 1});
   std::cout << ans << std::endl;
   // printf("\d",ans);
   std::cout << "TODO: implement longestConsecutive and its tests\n";
   return 0;
}
