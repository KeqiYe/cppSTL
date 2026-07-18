# 第三节：滑动窗口

滑动窗口使用 `left` 和 `right` 表示一个连续区间。`right` 向右扩张，把新元素加入窗口；当窗口不再满足条件时，移动 `left`，把左侧元素移出窗口。

```cpp
int left = 0;

for (int right = 0; right < n; ++right) {
    // 将 data[right] 加入窗口

    while (窗口不合法) {
        // 将 data[left] 移出窗口
        ++left;
    }

    // 此时窗口重新合法
}
```

窗口通常表示闭区间 `[left, right]`，长度是：

```cpp
right - left + 1
```

只要 `left` 和 `right` 都只向右移动，每个元素最多进入和离开窗口各一次，因此即使代码中有嵌套 `while`，总时间通常仍是 O(n)。

## `std::array` 和 `std::vector`

两者都连续存储元素，都支持 `[]`、`size()`、`begin()` 和 `end()`。

```cpp
std::array<int, 26> count{};  // 长度编译时固定为 26，{} 将元素初始化为 0
std::vector<int> nums(26);    // 长度运行时决定，可以继续增删元素
```

`std::array<T, N>` 的长度 `N` 是类型的一部分，创建后不能 `push_back`、`resize`。它适合英文字母计数、固定方向数组、固定尺寸数学数据等已知长度的场景。

`std::vector<T>` 的长度可以在运行时改变，支持 `push_back`、`pop_back`、`resize` 和 `reserve`。扩容可能重新申请内存，从而使原来的指针、引用和迭代器失效。

简单选择原则：长度编译期固定就优先考虑 `array`；长度由输入决定或需要增删元素就使用 `vector`。

本节先做第 3 题，理解可变长度窗口；再做第 438 题，理解固定长度窗口和 `array<int, 26>` 字符计数。
