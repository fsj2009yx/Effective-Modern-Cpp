/*
 * Key idea:
 *
 *   The third context in which reference collapsing occurs  is the generation
 *   and use of typedefs and alias declarations.  If, during creation or
 *   evaluation of a typedef, references to references arise, reference
 *   collapsing intervenes to eliminate them.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include "reference_collapsing_contexts02.h"

int main()
{
    Widget<int&> w;
}
