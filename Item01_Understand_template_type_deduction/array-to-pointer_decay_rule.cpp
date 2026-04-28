/*
 * Key idea:
 *
 *   In many contexts, an array decays into a pointer to its first element.
 *
 */

/*
 * 核心思想：
 *
 *   在许多上下文中，数组会退化为指向其首元素的指针。
 */

int main()
{
    const char name[] = "J. P. Briggs";  // name's type is
                                         // const char[13]

    const char * ptrToName = name;       // array decays to pointer

  // ptrToName points to the first element of name, so *ptrToName is 'J'
}
