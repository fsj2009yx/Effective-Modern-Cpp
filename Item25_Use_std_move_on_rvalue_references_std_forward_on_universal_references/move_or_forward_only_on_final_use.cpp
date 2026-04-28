/*
 * Key idea:
 *
 *   Here, we want to make sure that text's value doesn't get changed by
 *   sign.setText, because we want to use that value when we call
 *   signHistory.add.  Ergo the use of std::forward on only the final use of the
 *   universal reference.
 *
 */

/*
 * 核心思想：
 *
 *   这里我们要确保 text 的值不会被 sign.setText 改变，因为调用 signHistory.add 时还要
 *   使用这个值。因此，只在万能引用的最后一次使用处应用 std::forward。
 */

// TODO:
//  fix sign and signHistory

#include <chrono>
#include <utility>

template<typename T>                       // text is
void setSignText(T&& text)                 // univ. reference
{
  sign.setText(text);                      // use text, but
                                           // don't modify it

  auto now =                               // get current time
    std::chrono::system_clock::now();

  signHistory.add(now,
                  std::forward<T>(text));  // conditionally cast
}                                          // text to rvalue
