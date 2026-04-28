/*
 * Key ideas:
 *
 *   rvalue references bind only to objects that are candidates for moving.  If
 *   you have an rvalue reference parameter, you know that the object it's bound
 *   to may be moved.
 *
 *   rvalue references should be unconditionally cast to rvalues (via std::move)
 *   when forwarding them to other functions, because they're always bound to
 *   rvalues.
 *
 */

/*
 * 核心思想：
 *
 *   右值引用只绑定到可作为移动候选的对象。如果你有一个右值引用形参，就知道它绑定的对象
 *   可以被移动。
 *
 *   将右值引用转发给其他函数时，应无条件地把它们转换为右值（通过 std::move），因为它们
 *   总是绑定到右值。
 */

#include <memory>
#include <string>

class SomeDataStructure {};

class Widget {
public:
    Widget(Widget&& rhs)               // rhs is rvalue reference
    : name(std::move(rhs.name)),
      p(std::move(rhs.p))
      { /* ... */ }

private:
    std::string name;
    std::shared_ptr<SomeDataStructure> p;
};
