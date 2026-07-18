#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/*
unordered_map 基础实验

最重要的类型公式：

    std::unordered_map<Key类型, Value类型> 变量名;

它表示：每一个 Key 对应一个 Value。

默认构造时不需要传入任何数据，只需要在尖括号中确定 Key 和 Value 的类型：

    std::unordered_map<std::string, int> ages;

这句话可以从右向左读：
    ages 是一个哈希表；
    它的 key 是 string；
    它的 value 是 int。

默认情况下，Key 类型需要：
1. 能判断相等；
2. 标准库知道怎样计算它的哈希值。

int、string 等常用类型已经满足。自定义结构体作为 Key 时，需要额外提供哈希函数；
现阶段先不处理自定义 Key。
*/
void test(std::vector<std::string> words)
{
    if (words.empty())
    {
        std::cout << "No words provided.\n";
        return;
    }
    std::unordered_map<std::string, int> f;
    for (auto word : words)
    {
        f[word]++;
    }
    for (const auto &[word, count] : f)
    {
        std::cout << word << " -> " << count << '\n';
    }
}

int main()
{
    // 示例 1：string -> int。一名玩家对应一个分数。
    std::unordered_map<std::string, int> scores;

    scores["Alice"] = 100; // 不存在 Alice 时，先创建，再赋值 100。
    scores["Bob"] = 80;
    scores["Alice"] += 20;

    std::cout << "Alice score: " << scores["Alice"] << '\n';

    // find 只查询，不会创建不存在的 key。
    auto bob = scores.find("Bob");
    if (bob != scores.end())
    {
        std::cout << "Found Bob, score: " << bob->second << '\n';
    }

    // 遍历时，每个元素都是一个 pair：first 是 key，second 是 value。
    for (const auto &[name, score] : scores)
    {
        std::cout << name << " -> " << score << '\n';
    }

    // 示例 2：string -> vector<string>。一个分类对应多个字符串。
    // 注意：Value 类型本身完全可以是一个 vector。
    std::unordered_map<std::string, std::vector<std::string>> groups;

    groups["aet"].push_back("eat");
    groups["aet"].push_back("tea");
    groups["ant"].push_back("tan");

    std::cout << "Words whose key is aet:\n";
    for (const std::string &word : groups["aet"])
    {
        std::cout << "  " << word << '\n';
    }
    std::vector<std::string> test_string = {"ppc", "cpp", "stl", "cpp", "engine"};
    test(test_string);
    /*
    轮到你练习：把代码直接写在这里，再重新编译运行。

    练习 A：词频统计
    1. 构造一个 string -> int 的 unordered_map，名字为 frequency。
    2. 给定 words = {"cpp", "stl", "cpp", "engine"}。
    3. 使用 ++frequency[word] 统计次数。
    4. 输出 cpp 的次数，应该为 2。

    练习 B：理解 key 和 value
    构造一个 int -> string 的 unordered_map，表示：
        1001 -> "Player"
        2001 -> "Enemy"
    然后使用 find 查询 2001，不要使用 operator[] 查询。

    练习 C：回答而不是写代码
    对下面这个类型逐层解释 key 和 value：
        unordered_map<string, vector<string>>
    */
    std::unordered_map<int, std::string> f;
    f[1001] = "Player";
    f[2001] = "Enemy";
    auto it = f.find(2001);

    if (it != f.end())
    {
        std::string s = it->second;
        printf("Found 2001, value: %s\n", s.c_str());
    }
    return 0;
}
