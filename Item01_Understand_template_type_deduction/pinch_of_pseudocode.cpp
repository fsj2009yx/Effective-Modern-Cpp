/*
 * Key idea:
 *
 *   If the function template looks like this:
 *
 *     template <typename T>
 *     void f(ParamType param);
 *
 *   then two types are deduced: one for T and one for ParamType.  These types
 *   are frequently different, because ParamType often contains adornments,
 *   e.g., const- or reference qualifiers.
 *
 */

/*
 * 核心思想：
 *
 *   如果函数模板如下：
 *
 *     template <typename T>
 *     void f(ParamType param);
 *
 *   那么会推导出两个类型：一个用于 T，一个用于 ParamType。这两个类型经常不同，因为
 *   ParamType 往往带有修饰，例如 const 或引用限定符。
 */

template<typename T>
void f(const T& param) {}  // ParamType is const T&

int main()
{
  int x = 0;
  f(x);                    // call f with an int
}
