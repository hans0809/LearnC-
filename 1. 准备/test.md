## 常量

C++两种定义常量的两种方式：
- #define
- const
```cpp
#include <iostream>
using namespace std;

#define Day 7
int main()
{
    cout << "一周共有：" << Day  << " 天" << endl;
    const int month=12;//month不能被修改了
    cout<<"一年总共有"<<month<<"个月"<<endl;

    /*
    
    多行注释
    */

    //单行注释

    //变量
    int a = 10;
    cout << "a=" << a << endl;
    return 0;
}
```
## 一些规则
- 不要用关键字给命令命名，否则会发生歧义
- 标识符只能包含字母数字下划线
- 第一个字符必须是字母或下划线
- 区分大小写

