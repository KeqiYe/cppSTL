# 第一节：哈希表

## 这一节必须学会什么

### 1. 什么时候想到哈希表

当题目反复出现下面的需求时，应考虑哈希表：

- 某个元素是否出现过；
- 某个键对应的计数、下标或一组元素；
- 去重；
- 把一种对象转换成统一特征后分组；
- 希望把线性查询降低为平均 O(1)。

哈希表通常是在用额外空间换查询时间。

### 2. `unordered_set` 与 `unordered_map`

```cpp
std::unordered_set<int> seen;                 // 只关心元素是否存在
std::unordered_map<std::string, int> count;   // 一个 key 对应一个 value
```

常用操作：

```cpp
seen.insert(x);
seen.count(x);          // 返回 0 或 1
seen.find(x);           // 返回迭代器

++count[key];           // key 不存在时先插入默认值 0
auto it = count.find(key); // 只查询，不插入
count.erase(key);
```

### 3. 面试必须讲清楚的复杂度

`unordered_map` 和 `unordered_set` 的插入、删除、查询：

- 平均时间复杂度 O(1)；
- 哈希冲突严重时最坏 O(n)；
- 空间复杂度通常 O(n)。

不要简单地说成“哈希表查询一定是 O(1)”。

### 4. `reserve`、rehash 与迭代器失效

已知大致元素数量时可以：

```cpp
std::unordered_set<int> values;
values.reserve(nums.size());
```

这能够减少扩容和重新散列。rehash 后，容器迭代器会失效，因此不要在可能触发扩容后继续使用旧迭代器。

### 5. `operator[]` 的副作用

```cpp
if (map[key] == 0) { /* ... */ }
```

即使原来不存在 `key`，上面的代码也会把它插入容器。只想查询时优先使用 `find` 或 `count`。

## 本节题目顺序

0. `0000_unordered_map_basics.cpp`：先建立类型、构造、写入、查询和遍历的基本认识。
1. `0049_group_anagrams.cpp`：学习“规范化键 + 分组”。
2. `0128_longest_consecutive_sequence.cpp`：学习“集合查询 + 只从序列起点枚举”。

## 完成标准

每题不仅要运行通过，还要能口述：

- 为什么选 `unordered_map` 或 `unordered_set`；
- key 和 value 分别表示什么；
- 平均与最坏时间复杂度；
- 空输入、重复元素和整数边界如何处理；
- 如果不使用哈希表，替代方案的复杂度是什么。
