# 面试常用 STL 速查

## 选择容器

- 连续存储、缓存友好、随机访问：`vector<T>`。
- 固定长度且长度编译期已知：`array<T, N>`。
- 键值查询，平均 O(1)：`unordered_map<K, V>`。
- 有序键值、需要 `lower_bound`：`map<K, V>`。
- 先进先出：`queue<T>`；双端进出：`deque<T>`。
- 后进先出：`stack<T>`。
- 动态取得最大/最小元素：`priority_queue<T>`。

## 高频写法

```cpp
std::sort(v.begin(), v.end());
std::reverse(v.begin(), v.end());
auto it = std::lower_bound(v.begin(), v.end(), target);

std::unordered_map<int, int> count;
++count[x];
if (auto it = count.find(x); it != count.end()) {
    // 使用 it->first / it->second，避免重复查找
}

std::priority_queue<int> maxHeap;
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
```

## 手撕时必须主动说明

- `vector` 扩容会使指针、引用和迭代器失效；已知规模可先 `reserve`。
- `unordered_map` 平均查询 O(1)，最坏 O(n)，且 rehash 会使迭代器失效。
- `map` 查询 O(log n)，元素按键有序。
- `sort` 为 O(n log n)，要求随机访问迭代器。
- 不要用 `operator[]` 只做查询：它会插入缺失的键。
- 下标、容量及可能溢出的和，优先考虑 `std::size_t` 或 `long long`。
