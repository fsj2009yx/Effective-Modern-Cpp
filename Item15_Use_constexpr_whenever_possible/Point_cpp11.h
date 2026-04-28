/*
 * Key idea:
 *
 *   Constructors and other member functions may be constexpr.
 *
 */

/*
 * 核心思想：
 *
 *   构造函数和其他成员函数可以是 constexpr。
 */

class Point {
public:
  constexpr Point(double xVal = 0, double yVal = 0) noexcept
  : x(xVal), y(yVal)
  {}

  constexpr double xValue() const noexcept { return x; }
  constexpr double yValue() const noexcept { return y; }

  void setX(double newX) noexcept { x = newX; }
  void setY(double newY) noexcept { y = newY; }

private:
  double x, y;
};
