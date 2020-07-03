
**vector** 

1. `resize(n)`后再`push_back()`会在n+1处


**find**

1. 迭代器查找`[4,5,6]`时`lower_bound(3)`返回的是`begin()`
2. `lower_bound(7)`返回的是`end()`
3. `std::set`自带lower_bound和upper_bound


**iterator**

1. iterator it `++ , --` `随机访问`迭代器和`双向`迭代器都可以用，但是`双向`迭代器不能`it+4,it-5`  

| name           | fangwen      |
| -------------- | ------------ |
| vector         | 随机访问     |
| deque          | 随机访问     |
| list           | 双向         |
| set / multiset | 双向         |
| map / multimap | 双向         |
| stack          | 不支持迭代器 |
| queue          | 不支持迭代器 |
| priority_queue | 不支持迭代器 |

**unorder_map**
1. -std=c++11
2. 常数巨大，以洛谷P3913为例，统计序列中数字的种类，用unorder_map 调用size 比 sort再遍历求和要慢(???)