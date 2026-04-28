/*
 * Key idea:
 *
 *   - Whereas std::move unconditionally casts its argument to an rvalue,
 *     std::forward does it only under certain conditions.  std::forward is a
 *     conditional cast.
 *
 */

/*
 * 核心思想：
 *
 *   - std::move 会无条件地把其实参转换为右值，而 std::forward 只在特定条件下这样做。
 *     std::forward 是一种条件转换。
 */

#ifndef TYPICAL_USE_OF_STD_FORWARD_H
#define TYPICAL_USE_OF_STD_FORWARD_H

#include <chrono>
#include <utility>

class Widget {};

void makeLogEntry(const char* message,
                  const std::chrono::time_point<std::chrono::system_clock> t) {}

void process(Widget& lvalArg);            // process lvalues
void process(Widget&& rvalArg);           // process rvalues

template<typename T>                      // template that passes
void logAndProcess(T&& param)             // param to process
{
  auto now =
    std::chrono::system_clock::now();     // get current time

  makeLogEntry("Calling 'process'", now);
  process(std::forward<T>(param));
}

#endif /* TYPICAL_USE_OF_STD_FORWARD_H */
