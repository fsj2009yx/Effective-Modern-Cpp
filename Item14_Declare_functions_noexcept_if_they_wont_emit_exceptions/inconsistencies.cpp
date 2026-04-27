/*
 * Key idea
 *
 *   Compilers typically offer no help in identifying inconsistencies between
 *   function implementations and their exception specifications.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

void setup() {};
void cleanup() {};

void doWork() noexcept
{
  setup();     // set up work to be done

  // ...       // do the actual work

  cleanup();   // perform cleanup actions
}


int main()
{
  doWork();
}
