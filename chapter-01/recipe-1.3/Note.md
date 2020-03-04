**1.**

1. `add_library()`: 将指定的源码编译到库中

    参数1: 目标库名字，libxxx

    参数2: 库类型

2. `target_link_libraries()`: 将库链接到可执行文件

**2.**

`add_library()` 的第二个参数:

* **STATIC**: 静态库
* **SHARED**: 动态库
* **OBJECT**: 对象库，一次性创建静态库和动态库
* **MODULE**: DSO组，不链接到项目中的任何目标，但是可以进行动态加载
* **IMPROTED**: 表示位于项目外部的库。主要用途是对现有依赖项进行构建，将被视为不可变的
* **INTERFACE**: 与`IMPORTED`库类似，但是是可变的
* **ALIAS**: 为项目中已存在的库目标定义别名，不能为`IMPROTED`库选择别名
