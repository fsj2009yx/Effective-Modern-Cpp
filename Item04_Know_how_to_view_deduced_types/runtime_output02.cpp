/*
 * Key idea:
 *
 *   The results of std::type_info::name are not reliable.
 *   Compiler diagnostics are a more dependable source of information about the
 *   results of type deduction.
 *
 */

/*
 * 核心思想：
 *
 *   std::type_info::name 的结果并不可靠。编译器诊断信息是了解类型推导结果的更可靠
 *   来源。
 */

#include <iostream>
#include <typeinfo>
#include <vector>

class Widget {};

template<typename T>  // declaration only for TD;
class TD;             // TD = "Type Displayer"

template<typename T>                // template function to
void f(const T& param)              // be called
{
  using std::cout;
  cout << "T =     " << typeid(T).name() << '\n';     // show T
  cout << "param = " << typeid(param).name() << '\n'; // show
                                                      // param's
                                                      // type

//  TD<T> TType;                    // elicit errors containing
//  TD<decltype(param)> paramType;  // T's and param's types
}

std::vector<Widget> createVec()    // factory function
{
    std::vector<Widget> vw;
    Widget w;
    vw.push_back(w);
    return vw;
}

int main()
{
    
    const auto vw = createVec();        // init vw w/factory return
    
    if (!vw.empty()) {
      f(&vw[0]);                        // call f
      // ...
    }
}
