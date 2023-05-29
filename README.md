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

# 一些值得注意的问题
- 不允许多行注释
- 可以在函数中声明新的结构/union/enum，允许使用typedef，但是不能在struct中定义函数，允许结构嵌套定义
- 不支持:(COLON)作为位域的用法

