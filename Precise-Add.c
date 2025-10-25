//代码解释：这个程序实现了两个大整数的加法运算。
//首先，它读取两个字符串形式的整数，然后将这些字符串转换为整数数组，并倒序存储。
//接着，它逐位相加两个数组的对应元素，并处理进位。
//最后，它将结果转换为字符串并输出。

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char sa[1001], sb[1001];
int i, la, lb, lc, a[1001], b[1001], c[1001];

int main() {
    scanf("%s", sa);  // 输入两个不多于1000位的整数
    scanf("%s", sb);
    
    la = strlen(sa);
    lb = strlen(sb);
    
    memset(a, 0, sizeof(a));  // 初始化数组a为0
    memset(b, 0, sizeof(b));  // 初始化数组b为0
    memset(c, 0, sizeof(c));  // 初始化数组c为0
    
    // 把字符串值转化为整数值并把数位倒过来放在整数数组里
    for(i = 0; i < la; i++)
        a[la - i - 1] = sa[i] - '0';
    
    for(i = 0; i < lb; i++)
        b[lb - i - 1] = sb[i] - '0';
    
    lc = la > lb ? la : lb;  // 确定结果的最大长度
    
    // 从低位向高位逐位相加
    for(i = 0; i < lc; i++) {
        c[i] = a[i] + b[i] + c[i];
        if(c[i] >= 10) {  // 处理进位
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    
    // 如果最高位有进位，长度加1
    if(c[lc] > 0)
        lc++;
    
    // 输出结果
    for(i = lc - 1; i >= 0; i--)
        printf("%d", c[i]);
    printf("\n");

    system("pause");
    
    return 0;
}