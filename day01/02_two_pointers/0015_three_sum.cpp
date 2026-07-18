#include <algorithm>
#include <iostream>
#include <vector>

/*
LeetCode 15：三数之和

问题：
找出数组中所有和为 0 且下标互不相同的三元组。答案中不能包含重复三元组。

本题要学会：
1. sort 将无序问题转成有序问题；
2. 固定第一个数 nums[i]；
3. 在 i 右侧使用 left/right 寻找另外两个数；
4. 根据 sum 与 0 的关系移动指针；
5. 对 i、left、right 分别去重。

排序后：
- sum < 0，说明总和太小，需要让 left 向右移动；
- sum > 0，说明总和太大，需要让 right 向左移动；
- sum == 0，记录答案，然后跳过左右两侧的重复值。

不要使用 unordered_set<vector<int>> 去重：标准库没有直接提供 vector<int> 的哈希，
而且排序后的相邻去重已经足够。

预期时间复杂度 O(n^2)：外层固定 i 为 O(n)，每个 i 的左右扫描合计 O(n)。
排序为 O(n log n)，不会超过 O(n^2)。除返回结果外，额外空间取决于 sort 实现。
计算三数之和时可以使用 long long，避免扩展约束下整数溢出。
*/

std::vector<std::vector<int>> threeSum(std::vector<int> nums)
{
   // 参数按值传入，可以直接排序 nums，不会修改调用者的数组。
   // TODO：排序、固定 i、左右夹逼、三处去重。
   std::vector<std::vector<int>> ans;
   std::sort(nums.begin(), nums.end());
   for (int i = 0; i < nums.size() - 2; i++)
   {
      if (nums[i] > 0)
         break;

      if (i > 0 && nums[i] == nums[i - 1])
         continue;
      int l = i + 1;
      int r = nums.size() - 1;
      int sum = nums[i];

      while (l < r)
      {
         int num_l = nums[l];
         int num_r = nums[r];
         if (sum + num_l + num_r > 0)
            r--;
         else if (sum + num_l + num_r < 0)
            l++;
         else
         {
            ans.push_back({nums[i], nums[l], nums[r]});
            while (l < r && num_r == nums[r])
               r--;
            while (l < r && num_l == nums[l])
               l++;
         }
      }
   }
   return ans;
}

int main()
{

   /*
   TODO：亲手实现自动测试。返回顺序不固定，比较前应先规范化：
   1. 对每个三元组排序；
   2. 对整个结果 vector 排序；
   3. 再与期望结果比较。

   必测用例：

   1. 输入：{-1,0,1,2,-1,-4}
      期望：{{-1,-1,2}, {-1,0,1}}

   2. 输入：{0,1,1}
      期望：{}

   3. 输入：{0,0,0}
      期望：{{0,0,0}}

   4. 输入：{0,0,0,0}
      期望仍然只有：{{0,0,0}}

   5. 输入：{-2,0,1,1,2}
      期望：{{-2,0,2}, {-2,1,1}}

   6. 输入：{}
      期望：{}

   口头回答：
   - 为什么排序后能够根据 sum 的大小决定移动方向？
   - 为什么仅使用不同下标还不够，还需要跳过相同数值？
   */
   std::vector<std::vector<int>> ans = threeSum({-1, 0, 1, 2, -1, -4});
   for (auto &ta : ans)
   {
      for (auto &a : ta)
         std::cout << a << '\t';
      std::cout << '\n';
   }
   std::cout << "TODO: implement threeSum and its tests\n";
   return 0;
}
