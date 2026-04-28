/*
 * Key idea:
 *
 *   C++11 deprecates the automatic generation of copy operations for classes
 *   declaring copy operations or a destructor.  This means that if you have
 *   code that depends on the generation of copy operations in classes declaring
 *   a destructor or one of the copy operations, you should consider upgrading
 *   these classes to eliminate the dependence.  C++11's "=default" lets you say
 *   that explicitly.
 *
 */

/*
 * 核心思想：
 *
 *   C++11 弃用了为声明了拷贝操作或析构函数的类自动生成拷贝操作。这意味着，如果你的代码
 *   依赖于在声明析构函数或某个拷贝操作的类中生成拷贝操作，就应该考虑升级这些类以消除
 *   这种依赖。C++11 的 =default 允许你显式表达这一点。
 */

class Widget {
public:
  // ...
  ~Widget();                             // user-declared dtor

  // ...                                 // default copy-ctor
  Widget(const Widget&) = default;       // behavior is OK
  
  Widget&                                // default copy-assign
    operator=(const Widget&) = default;  // behavior is OK
  // ...
};
