/*
 * Key idea:
 *
 *   References to references are illegal in C++.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

int main()
{
    int x;

    //auto& & rx = x;    // error! can't declare reference to reference
}
