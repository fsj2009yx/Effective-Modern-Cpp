/*
 * Key ideas:
 *
 *   - text is not moved into value, it is copied.
 *   - two lessons learned:
 *       1) don't declare objects const if you want to be able to move from
 *          them.
 *       2) std::move not only doesn't actually move anything, it doesn't even
 *          guarantee that the object it's casting will be eligible to be moved.
 *
 */

/*
 * 核心思想：
 *
 *   - text 没有被移动到 value 中，而是被拷贝了。
 *   - 得到的两个教训：
 *       1) 如果你希望能够从对象移动，就不要把对象声明为 const。
 *       2) std::move 不仅实际上不移动任何东西，它甚至不保证被转换的对象有资格被移动。
 */

#include <string>

class Annotation {
public:

  //explicit Annotation(std::string text);  // param to be copied,
  //                                        // so per Item 41,
  //                                        // pass by value

  explicit Annotation(const std::string text)
  : value(std::move(text))  // "move" text into value; this code
  { /* ... */ }             // doesn't do what it seems to!

private:
  std::string value;
};
