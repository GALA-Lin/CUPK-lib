#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

/**
 * @brief 密钥输入函数，用户输入密钥。
 * @return 返回用户输入的密钥字符
 */
char InputKey() {
    char key;

    printf("Please enter the password : (1-254):\n");
    scanf("%c", &key);
    if((int)key > 255 || (int)key < 0) {
        printf("输入的密钥不符合要求，请检查后重新输入。\n");
        scanf("%c", &key);
    }

    return key;
}

/**
 * @brief 对文件中的内容进行加密或解密，并逆序存储。
 *
 * @param fp 已打开的文件指针
 * @param key 密钥字符，用于异或加密/解密
 */
void decrypt(FILE * fp, char key) {
    SqStack S;  // 栈的声明和初始化
    InitStack_Sq(&S);
    char ch;

    rewind(fp);             // 将文件指针移到开头
    ch = fgetc(fp);         // 读取文件内容并进行异或处理
    while(ch != EOF)  {
        ch = ch ^ key;
        fseek(fp, -1L, SEEK_CUR);  // 将文件指针向前移动一个位置
        fputc(ch, fp);            // 写回处理后的字符
        fseek(fp, 0, SEEK_CUR);
        ch = fgetc(fp);
    }

    // 逆序操作
    fseek(fp, 0, SEEK_SET);  // 将文件指针移到开头，实现正向压栈操作
    ch = fgetc(fp);
    while(ch != EOF)  {
        Push_Sq(&S, ch);
        ch = fgetc(fp);
    }

    rewind(fp);               // 将文件指针重新移到开头，进行反向出栈操作
    while(StackLength_Sq(S) != 0)  {
        Pop_Sq(&S, &ch);
        fputc(ch, fp);
    } 

    printf("\n加/解密成功\n");
}
/*
//同一文件中读写
int main(int argc, char* argv[]) {
    FILE *fp1;
    char key = '\0';

    fp1 = fopen("D:\\XXQ1\\practice1\\test.dat", "rt+");  // 打开文件
    if(fp1 == NULL) {
        printf("无法打开文件，请检查后重试。\n");
        exit(1);
    }

    key = InputKey();  // 调用InputKey函数输入密钥
    decrypt(fp1, key);  // 调用decrypt函数对文件进行加密解密
    // 由于加密方式为逆序+异或，因此第一次调用函数为加密，第二次调用函数为解密

    fclose(fp1);

    return 0;
}
*/
/**
 * @brief 主函数，负责文件操作和调用加密解密。
 * @param argc 参数个数
 * @param argv 参数列表
 * @return 返回执行状态
 */
int main(int argc, char* argv[]) {
    FILE *fp1;
    char ch;
    char key = '\0';
    FILE *fp2;

    fp1 = fopen("D:\\XXQ1\\practice1\\test.dat", "rt+");  // 打开文件
    if(fp1 == NULL) {
        printf("无法打开文件，请检查后重试。\n");
        exit(1);
    }

    fp2 = fopen("D:\\XXQ1\\practice1\\test_before.dat", "wt+");  // 打开存储原始内容的文件
    if(fp2 == NULL) {
        printf("无法创建文件，请检查后重试。\n");
        fclose(fp1);
        exit(1);
    }

    // 保存原始文件内容到另一个文件中
    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp2);
    }

    key = InputKey();  // 调用InputKey函数输入密钥
    decrypt(fp1, key);  // 调用decrypt函数对文件进行加密解密
    // 由于加密方式为逆序+异或，因此第一次调用函数为加密，第二次调用函数为解密

    fclose(fp1);
    fclose(fp2);
    return 0;
}