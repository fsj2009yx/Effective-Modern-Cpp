/*
 * Key idea:
 *
 *   If we're dealing with pass-by-value
 *
 *     template <typename T>
 *     void f(T param);        // param is now passed by value
 *
 *   That means that param will be a copy of whatever is passed in - a
 *   completely new object.  The fact that param will be a new object motivates
 *   the rules that govern how T is deduced from expr:
 *
 *   1. As before, if expr's type is a reference, ignore the reference part.
 *
 *   2. If, after ignoring expr's reference-ness, expr is const, ignore that,
 *      too.  If it's volatile, also ignore that. (volatile objects are uncommon.
 *      They're generally used only for implementing device drivers.)
 *
 */

/*
 * 核心思想：
 *
 *   如果处理的是按值传递：
 *
 *     template <typename T>
 *     void f(T param);        // param 现在按值传递
 *
 *   这意味着 param 会成为传入实参的一个副本，也就是一个全新的对象。正因为 param 是
 *   一个新对象，才产生了从 expr 推导 T 的规则：
 *
 *   1. 和前面一样，如果 expr 的类型是引用，忽略引用部分。
 *
 *   2. 在忽略 expr 的引用性之后，如果 expr 是 const，也忽略 const；如果是 volatile，
 *      也同样忽略。（volatile 对象并不常见，通常只用于实现设备驱动。）
 */

template<typename T>
void f(T param) {}          // param is now passed by value

int main()
{
  int x = 27;               // as before
  const int cx = x;         // as before
  const int& rx = x;        // as before
  f(x);                     // T's and param's types are both int

  f(cx);                    // T's and param's types are again both int

  f(rx);                    // T's and param's types are still both int


  const char* const ptr =   // ptr is const pointer to const object
    "Fun with pointers";

  f(ptr);                   // pass arg of type const char * const
}
