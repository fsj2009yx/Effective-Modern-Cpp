/*
 * Key idea:
 *   The keyword override is reserved, but only in certain contexts.  It has a
 *   reserved meaning only when it occurs at the end of a member function
 *   declaration.  That means that if you have legacy code that already uses the
 *   name override, you don't need to change it for C++11.
 *
 */

/*
 * 核心思想：
 *
 *   关键字 override 是保留的，但只在特定上下文中如此。它只有出现在成员函数声明末尾时
 *   才具有保留含义。这意味着如果旧代码已经使用 override 这个名字，为了 C++11 并不需要
 *   修改它。
 */

class Warning {     // potential legacy class from C++98
public:
  void override();  // legal in both C++98 and C++11
                    // (with the same meaning)
};
