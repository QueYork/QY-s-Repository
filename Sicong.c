//ע�⣬���������д�����ļ����ﴴ����������� num1.txt, num2.txt, num3.txt
//�ſ�����

#include <stdio.h>
#include <math.h>
#include <string.h>

//�Ѵ��ļ��е��ַ����ı�תΪ���ִ��� int ����
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
    fgets(c_num1, 100, fopen("num1.txt", "r")); //���ļ�
    fgets(c_num2, 100, fopen("num2.txt", "r"));

    fclose(fopen("num1.txt", "r"));     //�ر��ļ�
    fclose(fopen("num2.txt", "r"));

    int len = store_num(c_num2, num, store_num(c_num1, num, 0));    //���ú���������
    int x, y, z;

    for (x = 0; x < len; x++) {           //����
        for (y = 0; y < len - 1; y++) {
            if (num[y] > num[y + 1]) {
                z = num[y];
                num[y] = num[y + 1];
                num[y + 1] = z;
            }
        }
    }

    FILE* f = fopen("num3.txt", "w");           //��Ҫд����ļ�
    for (x = 0; num[x]; x++) {

        char output[10] = {};
        char reverse[10] = {};

        for (y = 0; num[x]; num[x] /= 10, y++) {      //�ٽ� int �����е�����ת���ַ���
            output[y] = (num[x] % 10) + '0';
        }

        for (z = 0; output[z]; z++) {
            reverse[strlen(output) - 1 - z] = output[z];
        }
        fputs(reverse, f);          //���ַ���д��Ŀ���ļ���
        fputs(" ", f);
    }
    fclose(f);
}