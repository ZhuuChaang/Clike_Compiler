## Clike_Compiler
a C like compiler for ZJU compile principle course


# goals:
- 使用lex(flex)进行词法分析。要求能够识别C语言中基本的关键字，运算符，标识符，数字等等。要求实现对于代码中注释的排除。
- 使用yacc(bison)进行语法分析, 生成抽象语法树
- 代码生成，通过llvm库进行中间代码和可执行代码的生成


# environment:
- ubuntu
- bison 3.8.2
- flex  2.6.4
- llvm 14

# 运行方法：
- 在本文件夹中输入命令“cd build”进入build文件夹。
- 输入“cmake .”和“cmake”命令重新构建我们的编译器，clike就是我们的编译器。
- "./clike [-p ] [-O/-O1/-O2/-O3/ ] [source code name]" 编译源代码。[ -p]指定是否打印ast，[-O/-O1/-O2/-O3/ ]说明优化等级。
- 目标文件是与源代码同名的.o文件。
- “gcc -no-pie [ xxxx.o]" 生成二进制可执行文件a.out。
- "./a.out" 运行可执行文件。 

# 运行测试
- 我们的测试源代码在"./test/Finaltest"中
- build文件夹中有test.c文件，也可以将需要运行的代码复制到其中，执行run.sh运行。
- ircode中存放中间代码，语法树会直接输出到终端。
