**1.** CMake 不区分大小写，但是参数区分大小写

**2.** CMake中， C++是默认的编程语言

**3.** `cmake -H. -Bbuild`:

`-H.` 表示在当前目录中搜索 `CMakeLists.txt` 文件

`-Bbuild` 表示在一个名为 `build` 的目录中生成所有的文件

**4.** `cmake --build . --target <target-name>`
1. **all**
2. **clean**
3. **rebuild_cache**
4. **edit_cache**，允许目标直接编辑缓存
5. **test**
6. **install**
7. **package**
