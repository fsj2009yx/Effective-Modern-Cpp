/*
 * Key idea:
 *
 *   std::make_unique is not part of C++11, but a basic version of it is easy
 *   to write yourself.
 *
 */

/*
 * 核心思想：
 *
 *   std::make_unique 不是 C++11 的一部分，但很容易自己编写一个基础版本。
 */

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
