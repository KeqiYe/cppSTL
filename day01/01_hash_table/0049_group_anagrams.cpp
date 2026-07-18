#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/*
LeetCode 49：字母异位词分组

问题：
给定一个字符串数组，把包含相同字符且字符出现次数相同的字符串分到一组。
返回时，组与组之间、同组字符串之间的顺序均不重要。

本题要学会：
1. 用“排序后的字符串”作为规范化 key。
2. 使用 unordered_map<string, vector<string>> 完成分组。
3. 分清原字符串 word 与用于查询的 key。
4. 理解 groups[key] 在 key 不存在时会创建一个空 vector。

建议先实现排序 key 版本：
- n 表示字符串数量，k 表示平均字符串长度；
- 预期时间复杂度 O(n * k log k)；
- 额外空间复杂度 O(n * k)。

完成后思考：
- 若字符范围只有 a-z，能否用 26 个计数生成 key，把单串处理降为 O(k)？
- groups.reserve(strs.size()) 有什么作用？
- 收集结果时怎样避免复制每个分组？
*/
using namespace std;
std::vector<std::vector<std::string>> groupAnagrams(
    const std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    groups.reserve(strs.size());

    for (const std::string& word : strs) {
        std::string key = word;
        std::sort(key.begin(), key.end());
        groups[std::move(key)].push_back(word);
    }

    std::vector<std::vector<std::string>> result;
    result.reserve(groups.size());
    for (auto& [key, group] : groups) {
        result.push_back(std::move(group));
    }
    return result;
}

vector<vector<string>> mygroupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;
        for(auto s:strs)
        {
         string si = s;
         sort(si.begin(),si.end());
         if(groups.find(si) == groups.end())
         {
            groups[si] = vector<string>{s};
         }
         else
         {
            groups[si].push_back(s);
         }
        }
        vector<vector<string>> ans;
        ans.resize(groups.size());
        int i = 0;
        for(auto [tag,value]:groups)
        {
         ans[i++] = value;
        }
        return ans;
    }

int main() {
    /*
    TODO: 由你亲手实现测试，不要只打印结果目测。

    推荐做法：
    - 写一个 normalize 函数：先排序每个组，再排序所有组；
    - 使用 assert(actual == expected)；
    - 或自己写 expectEqual，失败时输出用例名称并返回非 0。

    必测用例：

    1. 常规分组
       输入：{"eat", "tea", "tan", "ate", "nat", "bat"}
       期望：{{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}
       注意：返回顺序不作要求。

    2. 空字符串
       输入：{""}
       期望：{{""}}

    3. 单字符串
       输入：{"a"}
       期望：{{"a"}}

    4. 重复字符串
       输入：{"ab", "ab", "ba"}
       期望：{{"ab", "ab", "ba"}}

    5. 空数组
       输入：{}
       期望：{}
    */
   vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
   vector<vector<string>> ans = mygroupAnagrams(input);
   for(auto an:ans)
   {
      for(auto a:an)
      {
         cout<<a<<"\t";
      }
      printf("\n");
   }
   //  std::cout << "TODO: implement groupAnagrams and its tests\n";
    return 0;
}
