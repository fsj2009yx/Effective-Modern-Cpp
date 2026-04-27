/*
 * Key Idea:
 *
 *   Deleted functions can be used to disable template instantiations.
 *   You can't do this using private member functions.
 *
 *   中文解释：
 *   = delete 可以禁止某些特定模板实例化，例如不允许处理 void* 或 char*。
 *   这种禁用发生在重载解析之后，比试图用 private 成员函数隐藏模板更直接可靠。
 */

template<typename T>
void processPointer(T* ptr) {};

template<>
void processPointer<void>(void*) = delete;

template<>
void processPointer<char>(char*) = delete;

template<>
void processPointer<const void>(const void*) = delete;

template<>
void processPointer<const char>(const char*) = delete;
