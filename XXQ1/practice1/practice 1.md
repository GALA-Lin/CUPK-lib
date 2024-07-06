# 实践一：文件加密/解密
>   加密利用数学方法将明文转化为密文，从而达到保护数据的目的。生产生活中对加密的需求很多，例如软件公司的源代码程序文件,工程设计公司的图纸文件,制造企业的配方,军工企业涉及的军事秘密等,对于企业来说这些文件都非常重要,直接关系到企业的经济利益和国家机密,不希望流失到企业外部、竞争对手或敌对势力手里。但是,怎样才能使这些文件不被流失呢?<br>加密和限制访问是通常的解决办法。

  本次实践对文件进行简单加密，以期提高对文件读取、简单加密算法的掌握。

## 实现方法

- 通过文件操作语句打开数据文件，并执行文件读写操作。
- 采用异或算法对文件内容执行初步的加密处理。
- 利用堆栈数据结构实现字符串的逆序排列，以执行进一步的加密步骤。
- 再次调用加密函数，对文件执行逆向加密过程以实现解密

## 使用到的数据结构
```c
/* 顺序栈结构体定义 */
typedef struct
{
    ElemType *base;  /* 栈底指针，在初始化之前和销毁之后，base 值为 NULL */
    ElemType *top;   /* 栈顶指针，指向栈顶元素的下一个位置 */
    int stacksize;   /* 当前栈已分配的内存空间大小（以元素个数为单位） */
} SqStack;
```

###	 	数据结构操作

​	~~谢谢周ht~~

```c
/* 初始化栈 */
Status InitStack_Sq(SqStack *S)
/* 销毁栈 */
Status DestroyStack_Sq(SqStack *S)
/* 清空栈 */
Status ClearStack_Sq(SqStack *S)
/* 判断栈是否为空 */
Status StackEmpty_Sq(SqStack S)
/* 获取栈长度 */
int StackLength_Sq(SqStack S)
/* 获取栈顶元素 */
Status GetTop_Sq(SqStack S, ElemType *e)
/* 入栈操作 */
Status Push_Sq(SqStack *S, ElemType e)
/* 出栈操作 */
Status Pop_Sq(SqStack *S, ElemType *e)
/* 遍历栈并对每个元素执行 Visit 函数 */
Status StackTraverse_Sq(SqStack S, void(Visit)(ElemType))
{
    ElemType *p = S.base;
    
    while (p < S.top)
        Visit(*p++);
    
    return OK;
}
```

## 算法思想

~~本次实验比较简单，毕竟是第一节课 /手动狗头~~



