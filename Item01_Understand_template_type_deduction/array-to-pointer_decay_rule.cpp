/*
 * Key idea:
 *
 *   In many contexts, an array decays into a pointer to its first element.
 *
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

int main()
{
    const char name[] = "J. P. Briggs";  // name's type is
                                         // const char[13]

    const char * ptrToName = name;       // array decays to pointer

  // ptrToName points to the first element of name, so *ptrToName is 'J'
}
