/*
 * Key idea:
 *
 *   Although functions can't declare parameters that are truly arrays, they can
 *   declare parameters that are references to arrays.
 *
 *   The type deduced for T is the actual type of the array!  That type includes
 *   the size of the array, so in this example T is deduced to be const
 *   char[13], and the type of f's parameter (a reference to this array) is
 *   const char (&)[13].
 *
 */

/*
 * 核心思想：
 *
 *   虽然函数不能声明真正的数组形参，但可以声明数组引用形参。
 *
 *   T 会被推导为数组的真实类型。这个类型包含数组大小，所以在本例中 T 被推导为
 *   const char[13]，而 f 的形参类型（该数组的引用）是 const char (&)[13]。
 */

template<typename T>
void f(T& param) {}  // template with by-reference parameter

int main()
{
    const char name[] = "J. P. Briggs";  // name's type is
                                         // const char[13]

    f(name);                   // pass array to f
}
