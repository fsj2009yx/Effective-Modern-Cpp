/*
 * Key Idea:
 *
 *   Using nullptr improves code clarity especially when auto variables are
 *   involved.
 *
 *   中文解释：
 *   使用 nullptr 可以让代码意图更清楚，尤其是变量用 auto 推导时。
 *   看到 nullptr 就能明确知道这里是在和“空指针”比较，而不是和整数 0 比较。
 */

int* findRecord() {
  return nullptr;
}

int main()
{

  {
    auto result = findRecord( /* arguments */ );
    
    if (result == 0) {
    }
  }


  {
    auto result = findRecord( /* arguments */ );

    if (result == nullptr) {
    }
  }

}
