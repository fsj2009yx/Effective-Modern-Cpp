/*
 * Key Idea:
 *
 *   Member function templates cannot be disabled by hiding them
 *   into private scope because it's a different access level.
 *
 *   Deleted functions can be outside the class (in namespace scope).
 *
 *   中文解释：
 *   成员函数模板的特化不能简单放到 private 区域来禁用，
 *   因为显式特化的规则和访问控制并不适合这样做。
 *   使用 = delete 可以在类外把特定特化声明为不可调用。
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
