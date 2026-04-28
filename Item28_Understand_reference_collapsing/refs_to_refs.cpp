/*
 * Key idea:
 *
 *   References to references are illegal in C++.
 *
 */

/*
 * 核心思想：
 *
 *   引用的引用在 C++ 中是非法的。
 */

int main()
{
    int x;

    //auto& & rx = x;    // error! can't declare reference to reference
}
