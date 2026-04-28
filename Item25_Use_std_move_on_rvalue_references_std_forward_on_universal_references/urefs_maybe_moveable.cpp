/*
 * Key ideas:
 *
 *   A universal reference, might be bound to an object that's eligible for
 *   moving.  Universal references should be cast to rvalues only if they were
 *   initialized with rvalues.
 *
 *   Universal references should be conditionally cast to rvalues (via
 *   std::forward) when forwarding them, because they're only sometimes bound to
 *   rvalues.
 *
 */

/*
 * 核心思想：
 *
 *   万能引用可能绑定到有资格移动的对象。只有当万能引用由右值初始化时，才应把它转换为右值。
 *
 *   转发万能引用时，应有条件地把它们转换为右值（通过 std::forward），因为它们只是在某些
 *   情况下绑定到右值。
 */

#include <memory>
#include <string>

class Widget {
public:
  template<typename T>
  void setName(T&& newName)             // newName is
  { name = std::forward<T>(newName); }  // universal reference

private:
  std::string name;
};
