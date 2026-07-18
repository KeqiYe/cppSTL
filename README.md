# C++ STL × LeetCode Hot 100 两天手撕训练

本项目以力扣官方「热题 100」中的 **68 道中等题**为范围，按数据结构和解题模式重排。目标不是背答案，而是做到：看到题能选结构、说清不变量、写出 C++17 代码、分析复杂度并处理边界。

## 构建

```bash
cmake -S . -B build
cmake --build build -j
ctest --test-dir build --output-on-failure
```

第一讲入口：

```bash
./build/lc0049
./build/lc0128
```

## 使用规则

1. 每节课先阅读该目录中的 `README.md`。
2. 每道题对应一个独立 `.cpp`，在其中完成算法函数。
3. 根据文件注释给出的用例，亲手在 `main()` 中编写测试。
4. 编译并运行该题的独立可执行文件。
5. 通过后清空实现，闭卷重写一次。
6. 在 `notes/mistakes.md` 记录错误，不抄整份答案。

完整路线见 [notes/hot100_medium_roadmap.md](notes/hot100_medium_roadmap.md)。

课程采用“总知识放 README，题目相关知识嵌入 cpp”的结构。项目不预置参考答案，避免无意中看到实现。
