/*
 * Key idea
 *
 *   Compilers typically offer no help in identifying inconsistencies between
 *   function implementations and their exception specifications.
 *
 */

/*
 * 核心思想：
 *
 *   编译器通常不会帮助识别函数实现与其异常说明之间的不一致。
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
