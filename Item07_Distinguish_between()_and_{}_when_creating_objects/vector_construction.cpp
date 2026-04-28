/*
 * Key idea:
 *
 *   * If you create a std::vector of a numeric type (e.g., a std::vector<int>)
 *     and you pass two arguments to the constructor, whether you enclose those
 *     arguments in parentheses or braces makes a tremendous difference.
 *
 */

/*
 * 核心思想：
 *
 *   * 如果创建一个数值类型的 std::vector（例如 std::vector<int>），并向构造函数传入两个
 *     实参，那么用圆括号还是花括号包住这些实参，会产生巨大差异。
 */

#include <vector>

int main()
{
  std::vector<int> v1(10, 20);  // use non-std::initializer_list
                                // ctor: create 10-element
                                // std::vector, all elements have
                                // value of 20

  std::vector<int> v2{10, 20};  // use std::initializer_list ctor:
                                // create 2-element std::vector,
                                // element values are 10 and 20
}
