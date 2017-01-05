C++中常用stl && lib库函数 汇总
------------------------------------------------------------------------------------------------------------------------
1. vector

1) 头文件 #include <vector>
2) 常用操作
 <1> push_back() -- 插入元素
 <2> size()      -- 求vector元素个数

 Example
 ---------------------------------------------------------------------------
 ... 
 vector<int> ret;
 ret.push_back(-1);
 int size = ret.size();



2. unordered_map

1) 头文件 #include <unordered_map>
2) 常用操作
 <1> unordered_map<key, map> -- 定义以key为键值，以map为对应匹配类型的Hash table.
 <2> operator[key] = map     -- 通过key值可以定位到与之对应的map；同样地，可以通过key值通过赋值运算=创建相应map.
 <3> find(key)               -- 通过key值找是否有与key对应的map. 
 <4> end()                   -- 和find()结合，找不到就返回end().

 Example
 ---------------------------------------------------------------------------
 ... 
 string s = "abcde";
 unordered_map<char, int> m;
 for (int i = 0; i < s.length(); ++i) {
     m[s[i]] = i;
 }
 if (m.find('s') != m.end()) {
     return;
 } 

























