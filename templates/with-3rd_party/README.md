# 链接第三方库
- [链接第三方库](#链接第三方库)
- [项目结构](#项目结构)
- [一些有用的第三方库](#一些有用的第三方库)
  - [Boost](#boost)
    - [Boost源码](#boost源码)
    - [编译Boost](#编译boost)
    - [使用boost库](#使用boost库)


# 项目结构
```bash
├─app
│  ├─CMakeLists.txt
|  └─test.cpp
└─CMakeLists.txt
```

# 一些有用的第三方库
## Boost

### Boost源码
https://www.cnblogs.com/cmranger/p/4759223.html

Boost的源码可以在[Boost官方网站](https://www.boost.org/)中的[Download](https://www.boost.org/users/download/)下载，解压之后进入目录 `boost_<version>` 下
```bash
.
├─boost     # boost 源码
├─doc       # 文档
├─libs      # 所有组件的示例/测试/编译代码和说明文档
├─more      # 库作者相关的文档
├─status    # 可用于测试boost库的各个组件
└─tools     # b2、quickbook等一些自带的工具
```
### 编译Boost
- for Unix/Linux
```bash
./bootstrap.sh
```

- for windows   
修改 `call .\build.bat`(约15行) 为 `call .\build.bat gcc`，修改`SET TOOLSET=msvc`(约34行) 为 `SET TOOLSET=gcc`

然后执行命令来完成配置 `Bootstrapping`
```bash
./bootstrap.bat
```
运行后会在Boost目录下产生 `b2.exe`



- for windows

编译完全版本
```ps1
./b2.exe `
  install `
  --toolset=gcc `
  --prefix="..\boost" `
  --without-python `
  --build-type=complete `
  --address-model=64 `
  -j8
```
编译部分版本
```ps1
./b2.exe `
  install `
  --toolset=gcc `
  --prefix="..\boost" `
  --runtime-link=shared `
  --without-python `
  --variant=release `
  --threading=multi `
  --address-model=64 `
  -j8
```

- for Unix/Linux
```bash

```
| 参数                           | 说明                                                                                                         |
| ------------------------------ | ------------------------------------------------------------------------------------------------------------ |
| `install/stage`                | 安装方式，install安装头文件和库文件，stage仅库文件                                                           |
| `toolset=[gcc,msvc,...]`       | 指定编译工具                                                                                                 |
| `prefix/stagedir=""`           | 指定库文件存放路径                                                                                           |
| `build-dir=""`                 | 指定过程中生成的中间文件目录，默认在同目录下的`bin.v2`，编译完可以删除                                       |
| `link=[static,shared]`         | 编译静态(static)/动态(shared)库                                                                              |
| `runtime-link=[shared,static]` | 编译动态(shared)/静态(static)链接库                                                                          |
| `build-type=complete`          | 指定是否生成完全编译版本，相当于 `variant=release, threading=multi;link=shared\|static;runtime-link=shared`  |
| `with-/without-`               | 选择编译/不编译指定库，例如--with-regex只编译regex库，--without-python不编译python(编译python需要python环境) |
| `variant=[debug,release]`      | 编译release/debug版本，默认release                                                                           |
| `threading=[multi,single]`     | 编译成多线程/单线程库                                                                                        |
| `address-model=[32,64]`        | 生成库是32/64位，默认32位                                                                                    |
| `-a`                           | 是否全部重新编译                                                                                             |




https://cmake.org/cmake/help/v3.8/module/FindBoost.html
https://cmake.org/cmake/help/v3.21/module/FindBoost.html

### 使用boost库
boost库大多组件不需要编译链接就可以直接使用，因为大多数组件都是以`.hpp`，因此在自己工程中直接包含头文件`.hpp`就可以了，但是有一些库则是必须要编译成库才能使用的。

参数 ``./b2 --show-libraries`` 查看需要编译的库，进行[编译Boost](#编译boost)

