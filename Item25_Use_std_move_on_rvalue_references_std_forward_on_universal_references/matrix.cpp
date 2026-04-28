/*
 * Key idea:
 *
 *   If you're in a function that returns by value, and you're returning an
 *   object bound to an rvalue reference or a universal reference, you'll want
 *   to apply std::move or std::forward when you return the reference.
 *
 */

/*
 * 核心思想：
 *
 *   如果你在一个按值返回的函数中，并且返回的是绑定到右值引用或万能引用的对象，那么在
 *   返回该引用时应使用 std::move 或 std::forward。
 */

#include <utility>

class Matrix {
public:
    Matrix& operator+=(const Matrix& rhs);
};

Matrix& Matrix::operator+=(const Matrix& rhs)
{
    return *this;
}

Matrix                                     // by-value return
operator+(Matrix&& lhs, const Matrix& rhs)
{
  lhs += rhs;
  return std::move(lhs);             // move lhs into return value
  //return lhs;                        // copy lhs into return value
}
