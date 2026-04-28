/*
 * Key ideas:
 *
 *   logAndAdd is overloaded here.  Resolution of calls to the two overloads
 *   does not always work as expected.  The overload taking a universal
 *   reference is invoked in the last call, and that is probably not what we
 *   wanted...
 *
 *   Functions taking universal references are the greediest functions in C++.
 *   They instantiate to create exact matches for almost any type of argument.
 *   (The few kinds of arguments where this isn't the case are described in
 *   Item 30.)  This is why combining overloading and universal references is
 *   almost always a bad idea: the universal reference overload vacuums up far
 *   more argument types than the developer doing the overloading generally
 *   expects.
 *
 */

/*
 * 核心思想：
 *
 *   这里对 logAndAdd 进行了重载。对这两个重载的调用解析并不总是按预期工作。最后一次调用
 *   会调用接受万能引用的重载，而这很可能不是我们想要的结果。
 *
 *   接受万能引用的函数是 C++ 中最贪婪的函数。它们会实例化出几乎能精确匹配任何实参类型的
 *   函数。（少数不能这样匹配的实参类型见 Item 30。）这就是为什么把重载和万能引用结合起来
 *   几乎总是坏主意：万能引用重载会吸走远多于重载编写者通常预期的实参类型。
 */

#include <chrono>
#include <iostream>
#include <set>
#include <string>

std::multiset<std::string> names;      // global data structure

void log(const std::chrono::system_clock::time_point& t, const char* s)
{
  std::cout << "Making log entry" << std::endl;
}

std::string nameFromIdx(int idx)     // return name
{                                      // corresponding to idx
    std::string s("Test");
    return s;
}

template<typename T>
void logAndAdd(T&& name)
{
  auto now = std::chrono::system_clock::now();
  log(now, "logAndAdd");
  names.emplace(std::forward<T>(name));
}

void logAndAdd(int idx)
{
  auto now = std::chrono::system_clock::now();
  log(now, "logAndAdd");
  names.emplace(nameFromIdx(idx));
}

int main()
{

  short nameIdx;

  std::string petName("Darla");          // as before

  logAndAdd(petName);                    // as before, these
  logAndAdd(std::string("Persephone"));  // calls all invoke
  logAndAdd("Patty Dog");                // the T&& overload

  logAndAdd(22);                         // calls int overload

  nameIdx = 1;                           // give nameIdx a value
  //logAndAdd(nameIdx);                  // error!
}
