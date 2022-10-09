# 开发指北
* 环境要求：cmake 3.16+，c/c++ 编译器（gcc,llvm）
* 运行调试:problem_num为leetcode 题号
    ```SHELL
    >./build.sh ${problem_num}
    ```

* 新增题目解法：
    * solves/problems.h下面新增对应题目class，类名为P${problem_num}
    * 在examples下新增对应测试样例，测试样例格式任意，自行解析
    * 在solves下新增 类型 cc文件，编写测试样例解析，并调用solve_ts(内部调用solve)
    * 运行算法调试