/*
 * Key idea:
 *
 *   Because array parameter declarations are treated as if they were pointer
 *   parameters, the type of an array that's passed to a template function by
 *   value is deduced to be a pointer type.
 *
 */

/*
 * 核心思想：
 *
 *   由于数组形参声明会被当作指针形参处理，按值传给模板函数的数组，其类型会被推导为
 *   指针类型。
 */

template<typename T>
void f(T param) {}  // template with by-value parameter

int main()
{
    const char name[] = "J. P. Briggs";  // name's type is
                                         // const char[13]

    f(name);                   // what types are deduced for T and param?
                               // -> name is array, but T deduced as const char*
}
