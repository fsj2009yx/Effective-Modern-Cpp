/*
 * Key Idea:
 *
 *   Member function templates cannot be disabled by hiding them
 *   into private scope because it's a different access level.
 *
 *   Deleted functions can be outside the class (in namespace scope).
 *
 */

/*
 * 核心思想：
 *
 *   成员函数模板不能通过隐藏到 private 作用域来禁用，因为那只是不同的访问级别。
 *
 *   删除函数可以位于类外部（命名空间作用域）。
 */

class Widget {
public:

  // ...

  template<typename T>
  void processPointer(T* ptr)
  { }

private:
  // template<>                                    // error!
  // void processPointer<void>(void*);

};

template<>                                         // still
void Widget::processPointer<void>(void*) = delete; // public,
                                                   // but
                                                   // deleted
