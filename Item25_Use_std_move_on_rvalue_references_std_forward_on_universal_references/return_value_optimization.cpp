/*
 * Key idea:
 *
 *   Given a function returning a local variable by value, it is not a good idea
 *   to turn the copy into a move in the return statement.
 *
 *   The "copying" version of makeWidget can avoid the need to copy the local
 *   variable w by constructing it in the memory alloted for the function's
 *   return value.  This is known as Return Value Optimization (RVO).
 *
 *   The moving version of makeWidget does just what its name says it does
 *   (assuming Widget offers a move constructor): it moves the contents of w
 *   into makeWidget's return value location.
 *
 *   Developers trying to help their compilers optimize by applying std::move to
 *   a local variable that's being returned are actually limiting the
 *   optimization options available to their compilers!
 *
 *   When the RVO is permitted, either copy elision takes place or std::move is
 *   implicitly applied to local objects being returned.
 *
 */

/*
 * 核心思想：
 *
 *   对于返回局部变量且按值返回的函数，在 return 语句中把拷贝变成移动并不是好主意。
 *
 *   makeWidget 的“拷贝”版本可以通过直接在函数返回值的内存中构造局部变量 w，避免拷贝 w。
 *   这称为返回值优化（RVO）。
 *
 *   makeWidget 的移动版本会按其名称所示执行（假设 Widget 提供移动构造函数）：把 w 的内容
 *   移动到 makeWidget 的返回值位置。
 *
 *   开发者试图通过对正在返回的局部变量应用 std::move 来帮助编译器优化，实际上是在限制
 *   编译器可用的优化选项。
 *
 *   当允许 RVO 时，要么发生拷贝消除，要么 std::move 会被隐式应用于正在返回的局部对象。
 */

class Widget {};

Widget makeWidget()
{
  Widget w;               // local variable

  // ...                  // configure w

  return w;               // "copy" w into return value

  //return std::move(w);  // move w into return value
}                         // (don't do this!)


Widget makeWidget(Widget w)  // by value parameter of same
{                            // type as function's return
  // ...
  
  return w;                  // treat w as rvalue
}
