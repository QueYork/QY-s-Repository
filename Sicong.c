//注意，先在你运行代码的文件夹里创建测试所需的 num1.txt, num2.txt, num3.txt
//才可运行

#include <stdio.h>
#include <math.h>
#include <string.h>

//把打开文件中的字符串文本转为数字存入 int 数组
int store_num(char* c_num, int* num, int num_len) {
    int x, y, z;
    for (x = strlen(c_num) - 1, y = num_len, z = 0; x >= 0; x--) {
        while (c_num[x] != ' ' && x >= 0) {
            num[y] += ((int)c_num[x] - '0') * (pow(10, z));
            z++;
            x--;
        }
        z = 0;
        y++;
    }
    return y;
}

int main()
{
    char c_num1[100] = {}, c_num2[100] = {};
    int num[100] = {};
    fgets(c_num1, 100, fopen("num1.txt", "r")); //打开文件
    fgets(c_num2, 100, fopen("num2.txt", "r"));

    fclose(fopen("num1.txt", "r"));     //关闭文件
    fclose(fopen("num2.txt", "r"));

    int len = store_num(c_num2, num, store_num(c_num1, num, 0));    //调用函数存数据
    int x, y, z;

    for (x = 0; x < len; x++) {           //排序
        for (y = 0; y < len - 1; y++) {
            if (num[y] > num[y + 1]) {
                z = num[y];
                num[y] = num[y + 1];
                num[y + 1] = z;
            }
        }
    }

    FILE* f = fopen("num3.txt", "w");           //打开要写入的文件
    for (x = 0; num[x]; x++) {

        char output[10] = {};
        char reverse[10] = {};

        for (y = 0; num[x]; num[x] /= 10, y++) {      //再将 int 数组中的数字转成字符串
            output[y] = (num[x] % 10) + '0';
        }

        for (z = 0; output[z]; z++) {
            reverse[strlen(output) - 1 - z] = output[z];
        }
        fputs(reverse, f);          //将字符串写入目标文件中
        fputs(" ", f);
    }
    fclose(f);
}