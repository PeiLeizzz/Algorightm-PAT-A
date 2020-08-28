# 基本的三个函数

1. `upper_bound(iterator first, iterator last, x)` 返回**第一个 `> x` 的数**的下标（也是 `x` 应当插入数组的**最后一个位置**），若 `x` 比所有数都大，则返回 `last` 位置（即 `x` 插入后**应该所在的位置**）
2. `lower_bound(iterator first, iterator last, x)` 返回**第一个 `>= x` 的数**的下标（也是 `x` 应当插入数组的**第一个位置**），若 `x` 比所有数都大，则返回 `last` 位置（即 `x` 插入后**应该所在的位置**）
3. `binary(iterator first, iterator last, x)` 返回**是否存在这个数 `x` **，返回值是 `bool` 类型

# 应用

1. 查找 `<` 某个数 `x` 的**最大**的那个数的位置：只需要 `lower_bound(.., .., x) - 1` 
2. 查找 `<=` 某个数 `x` 的**最大**的那个数的位置：只需要 `upper_bound(.., .., x) - 1` 