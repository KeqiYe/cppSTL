#include <algorithm>
#include <iostream>
#include <vector>

/*
LeetCode 11：盛最多水的容器

问题：
数组 height[i] 表示第 i 条竖线的高度。选择两条线作为容器两侧，求能够容纳的
最大水量。

若左右下标为 left 和 right：

    宽度 = right - left
    高度 = min(height[left], height[right])
    面积 = 宽度 * 高度

本题要学会：
1. vector 下标访问；
2. 从数组两端开始的双指针；
3. 每轮移动较短的一侧；
4. 用“不可能变得更好”解释为什么可以排除一侧。

为什么移动短边：
假设左边更短。保持左边不动而右指针向左移动，宽度一定缩小，容器高度又不可能
超过左边，因此面积不可能超过当前面积。想获得更大面积，只能尝试更高的左边。

预期时间复杂度 O(n)，额外空间复杂度 O(1)。
*/

int maxArea(const std::vector<int> &height)
{
    int l = 0;
    int r = height.size() - 1;
    int area = 0;
    while (l < r)
    {
        int hight_l = height[l];
        int hight_r = height[r];
        int tmp = (r - l) * std::min(hight_l, hight_r);
        area = std::max(area, tmp);
        if (hight_l < hight_r)
            l++;
        else
            r--;
    }
    return area;
}

int main()
{
    /*
    TODO：亲手实现测试，建议使用 assert(maxArea(input) == expected)。

    必测用例：

    1. 输入：{1,8,6,2,5,4,8,3,7}，期望：49
    2. 输入：{1,1}，期望：1
    3. 输入：{1,2,1}，期望：2
    4. 输入：{1,2,3,4,5}，期望：6
    5. 输入：{5,4,3,2,1}，期望：6

    口头回答：
    - 为什么不能总是移动较高的一侧？
    - left == right 时为什么停止？
    - 如果高度和数组长度很大，面积是否需要 long long？本题约束下是否需要？
    */
    int ans = maxArea({1, 2, 1});
    printf("%d\n", ans);
    std::cout << "TODO: implement maxArea and its tests\n";
    return 0;
}
