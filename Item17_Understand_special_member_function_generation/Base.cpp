/*
 * Key idea:
 *
 *   Unless a class inherits a destructor that's already virtual, the only way
 *   to make a destructor virtual is to explicitly declare it that way.  Often,
 *   the default implementation would be correct, and "=default" is a good way
 *   to express that.
 *   However, a user-declared destructor suppresses generation of the move operations, so
 *   if movability is to be supported, "=default" often finds a second
 *   application.
 *   Declaring the move operations disables the copy operations, so if
 *   copyability is also desired, one more round of "=default" does the job.
 *
 */

/*
 * 核心思想：
 *
 *   除非类继承的析构函数已经是虚函数，否则让析构函数成为虚函数的唯一方法就是显式这样
 *   声明。默认实现通常是正确的，而 =default 是表达这一点的好方法。
 *
 *   但是，用户声明的析构函数会抑制移动操作的生成；因此如果要支持可移动性，=default
 *   往往还会有第二个用途。
 *
 *   声明移动操作会禁用拷贝操作；如果还希望支持可拷贝性，再使用一轮 =default 即可。
 */

class Base {
public
  virtual ~Base() = default;               // make dtor virtual

  Base(Base&&) = default;                  // support moving
  Base& operator=(Base&&) = default;

  Base(const Base&) = default;             // support copying
  Base& operator=(const Base&) = default;
};
