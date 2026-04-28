/*
 * Key idea:
 *
 *   The following code is completely legal and, at first sight, looks
 *   reasonable, but it contains no virtual function overrides - not a single
 *   derived class function that is tied to a base class function.
 *
 */

/*
 * 核心思想：
 *
 *   下面的代码完全合法，乍看也很合理，但它没有包含任何虚函数重写；也就是说，没有一个
 *   派生类函数真正绑定到基类函数。
 */

class Base {
public:
  virtual void mf1() const;
  virtual void mf2(int x);
  virtual void mf3() &;
  void mf4() const;
};

class Derived: public Base {
public:
  virtual void mf1();
  virtual void mf2(unsigned int x);
  virtual void mf3() &&;
  void mf4() const;
};
