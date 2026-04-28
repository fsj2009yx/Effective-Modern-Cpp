/*
 * Key Idea:
 *
 *   A technique to prevent calls with implicit conversions is
 *   to create deleted overloads for the types.
 *
 */

/*
 * 核心思想：
 *
 *   阻止隐式转换调用的一种技巧，是为相关类型创建删除的重载。
 */

bool isLucky(int number) { return true; }  // original function

bool isLucky(char) = delete;    // reject chars

bool isLucky(bool) = delete;    // reject bools

bool isLucky(double) = delete;  // reject doubles and
                                // floats

int main()
{
  //if (isLucky('a')) {}  // is 'a' a lucky number?
                          // error! call to deleted function

  //if (isLucky(true)) {}  // is "true"?
                           // error!

  //if (isLucky(3.5)) {}   // should we truncate to 3
                           // before checking for luckiness?
                           // error!

  //if (isLucky(3.5f)) {}  // error!
}
