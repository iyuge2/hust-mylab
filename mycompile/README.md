    The compile is designed for C--
word analyse file:
    word.analyse.l (compiled by flex)
gramma parser file:
    syntax.y (compiled by bison)
creat gramma-tree file:
    syntaxTree.h
    syntaxTree.c
Refer to http://blog.csdn.net/qq_24421591/article/details/50045933

update-time 2016-11-20 00:03
    将语法树中每个标识符单元增加了类型（int,float,func,struct)
