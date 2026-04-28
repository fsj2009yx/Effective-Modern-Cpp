/*
 * Key idea:
 *
 *   Even types with explicit move support may not benefit as much as you'd
 *   hope.  All containers in the standard C++11 library support moving, for
 *   example, but it would be a mistake to assume that moving all containers is
 *   cheap.  For some containers, this is because there's no truly cheap way to
 *   move their contents.  For others, it's because the truly cheap move
 *   operations the containers offer come with caveats the container elements
 *   can't satisfy.
 *
 * TODO: time this.
 *
 */

/*
 * 核心思想：
 *
 *   即使类型显式支持移动，收益也可能没有你期望的那么大。例如，标准 C++11 库中的所有容器
 *   都支持移动，但如果认为移动所有容器都很廉价，那就是错误的。对某些容器而言，这是因为
 *   根本不存在真正廉价的内容移动方式；对另一些容器而言，这是因为它们提供的真正廉价的移动
 *   操作带有容器元素无法满足的附加条件。
 *
 *   TODO：为此计时。
 */

#include <array>
#include <vector>

class Widget {};

int main()
{
    std::vector<Widget> vw1;

    // ...                      // put data into vw1

    auto vw2 = std::move(vw1);  // move vw1 into vw2.  Runs in
                                // constant time.  Only ptrs
                                // in vw1 and vw2 are modified


    std::array<Widget, 10000> aw1;

    // ...                      // put data into aw1

    auto aw2 = std::move(aw1);  // move aw1 into aw2.  Runs in
                                // linear time.  All elements in
                                // aw1 are moved into aw2.
}
