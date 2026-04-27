/*
 * Key idea:
 *
 *   The following code is completely legal and, at first sight, looks
 *   reasonable, but it contains no virtual function overrides - not a single
 *   derived class function that is tied to a base class function.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

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
