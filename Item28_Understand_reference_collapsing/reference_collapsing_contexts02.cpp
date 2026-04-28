/*
 * Key idea:
 *
 *   The third context in which reference collapsing occurs  is the generation
 *   and use of typedefs and alias declarations.  If, during creation or
 *   evaluation of a typedef, references to references arise, reference
 *   collapsing intervenes to eliminate them.
 *
 */

/*
 * 核心思想：
 *
 *   引用折叠发生的第三种上下文，是 typedef 和别名声明的生成与使用。如果在创建或求值
 *   typedef 的过程中出现引用的引用，引用折叠会介入并消除它们。
 */

#include "reference_collapsing_contexts02.h"

int main()
{
    Widget<int&> w;
}
