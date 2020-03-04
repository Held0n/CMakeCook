**1.**

利用`option()`命令，从外部对变量的值进行修改

`-D`为 CMake 设置任何类型的变量: 逻辑变量，路径等

`option(<option_variable> "help string" [initial value])`

* `<option_variable>` 表示选择的变量的名称
* `"help string"` 记录选项的字符串
* `[initial value]` 选项的默认值

