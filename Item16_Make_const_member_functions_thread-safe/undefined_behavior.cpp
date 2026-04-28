/*
 * Key idea:
 *
 *   Inside roots, one or both of these threads might try to modify the data
 *   members rootsAreValid and rootVals.  That means that this code could have
 *   different threads reading and writing the same memory without
 *   synchronization, and that's the definition of a data race.  This code has
 *   undefined behavior.
 *
 */

/*
 * 核心思想：
 *
 *   在 roots 内部，这两个线程中的一个或两个可能会尝试修改数据成员 rootsAreValid 和
 *   rootVals。这意味着这段代码可能让不同线程在没有同步的情况下读写同一块内存，而这正是
 *   数据竞争的定义。这段代码具有未定义行为。
 */

#include <thread>

#include "Polynomial2.h"

Polynomial p;

void func1()
{
  /* Thread 1 */
  auto rootsOfP = p.roots();
}

void func2()
{
  /* Thread 2 */
  auto valsGivingZero = p.roots();
}

int main()
{
  std::thread t1(func1);
  std::thread t2(func2);
 
  t1.join();
  t2.join();
}
