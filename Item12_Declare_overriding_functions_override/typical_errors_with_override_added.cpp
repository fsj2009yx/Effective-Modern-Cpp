/*
 * Key idea:
 *
 *   The below code won't compile, but, when written this way, compilers will
 *   kvetch about all the overriding-related problems.
 *
 */

/*
 * 核心思想：
 *
 *   下面的代码无法编译，但以这种方式编写时，编译器会抱怨所有与重写相关的问题。
 */

class Base {
public:
  virtual void mf1() const;
  virtual void mf2(int x);
  virtual void mf3() &;
  void mf4() const;
};

// Uncomment this, compile and see the compiler errors.
//class Derived: public Base {
//public:
//  virtual void mf1() override;
//  virtual void mf2(unsigned int x) override;
//  virtual void mf3() && override;
//  void mf4() const override;
//};
