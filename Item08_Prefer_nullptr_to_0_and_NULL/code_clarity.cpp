/*
 * Key Idea:
 *
 *   Using nullptr improves code clarity especially when auto variables are
 *   involved.
 *
 */

/*
 * 核心思想：
 *
 *   使用 nullptr 可以提高代码清晰度，尤其是在涉及 auto 变量时。
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
