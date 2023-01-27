# Hello world

- 使用LLVM工具链（clangd、CodeLLDB、CMake）
- 使用conan管理依赖
- 已有代码说明
    - src：中CMakeLists中的正则表达式，区分是否以app_开头。app_开头编译成可执行程序，非app_开头全部变成 MY_LIB库
    - test：提供默认g_test，对gtest和glog以及MY_LIB调用；其他新建以test_开始文件会被编译成可执行文件

# Reference

- 参考： [Github Repo](https://github.com/Codesire-Deng/TemplateRepoCxx)