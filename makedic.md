# makedic.hpp使用方法

主文件应当包含 makedic.hpp ，并且在主函数中使用 system("chcp 65001"); 来保证中文的正常输出。makedic.hpp 中实现了 work 和 search 两个函数，分别用来初始化字典和搜索垃圾。需要注意的是在使用代码的时候在相同目录之下应当放置 garbage.csv 以供读取。注意不要使用 std::sort ，这和本代码中的变量命名冲突。
我使用的主函数模板如下：

```cpp
#include "makedic.hpp"
int main(){
    system("chcp 65001");
    work();
    search();
    return 0;
}
```
