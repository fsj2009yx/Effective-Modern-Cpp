/*
 * Key idea:
 *
 *   Overloading for const lvalues and for rvalues could solve the problem,
 *   but there are drawbacks:
 *
 *     - it's more sourcecode to write and maintain (two functions instead of
 *       a simple template).
 *
 *     - it can be less efficient.
 *
 *     - such a design has poor scalability: n parameters necessitates 2^n
 *       overloads.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <iostream>
#include <string>

std::string getWidgetName()       // factory function
{
    return std::string("SomeWidgetName");
}

class Widget {

public:
  void setName(const std::string& newName)  // set from
  { name = newName; }                       // const lvalue

  void setName(std::string&& newName)       // set from
  { name = std::move(newName); }            // rvalue

private:
  std::string name;
  //std::shared_ptr<SomeDataStructure> p;  // REMARK: this is not really necessary for this example.
};

int main()
{
    Widget w;

    auto n = getWidgetName();         // n is local variable

    w.setName(n);                     // moves n into w!

    std::cout << n << std::endl;      // n's value now unknown

    w.setName("Adela Novak");
}
