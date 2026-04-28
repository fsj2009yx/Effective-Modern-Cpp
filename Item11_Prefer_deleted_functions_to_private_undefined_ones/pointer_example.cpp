/*
 * Key Idea:
 *
 *   Deleted functions can be used to disable template instantiations.
 *   You can't do this using private member functions.
 *
 */

/*
 * 核心思想：
 *
 *   删除函数可用于禁用模板实例化。使用 private 成员函数无法做到这一点。
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
