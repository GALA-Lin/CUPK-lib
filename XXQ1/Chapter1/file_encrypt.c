#include <stdio.h>
#include <time.h>
#include <F:\DownTheSky\VS_code_C\xiaoxueqi\Chapter1\decrypt.c>

int main(int argc, char* argv[])    {
    clock_t start=clock();
    FILE *fp;
    char key = '\0';

    fp = fopen("F:\\VS_code_C\\xiaoxueqi\\Chapter1\\ceshi.txt", "rt+");             //打开文件
    if(fp == NULL) {
        printf("无法打开文件，请检查后重试。\n");
        exit(1);
    }


    key = InputKey();               //调用InputKey函数输入密钥

    decrypt(fp, key);               //调用decrypt函数对文件进行加密解密。
    /*由于加密方式为逆序+异或，因此第一次调用函数为加密，第二次调用函数为解密。*/

    fclose(fp);

    clock_t ends = clock();

    printf("%f", ends-start)

    return 0;
}