// 防止头文件被重复包含，先检查 STRING_HEADERS_H 宏是否未定义
#ifndef STRING_HEADERS_H
// 若未定义，则定义该宏
#define STRING_HEADERS_H

// 引入标准输入输出流库，用于使用 std::cout 和 std::cin 等进行输入输出操作
#include <iostream>
// 引入标准向量库，可使用 std::vector 容器来存储动态数组
#include <vector>
// 引入标准字符串库，用于处理字符串对象
#include <string>
// 引入字符串流库，可将字符串当作流进行输入输出操作
#include <sstream>
// 引入迭代器库，为容器提供迭代器支持
#include <iterator>
// 引入算法库，包含众多常用算法，如 std::max 等
#include <algorithm>

// 结束 #ifndef 块
#endif    