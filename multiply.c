#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int input_number(int num[])
{
    // Input: 1 mang cac chu so
    // Ouput: Dien chu so da nhap va tra ve so chu so
    char char_num[200];
    int n;
    fgets(char_num, 200, stdin);
    n = strlen(char_num)-1;
    for (int i = 0; i < n; i++) {
        num[n-i-1] = char_num[i]-'0';
    }
    return n;
}

void print_number(int num[], int n)
{
    // Input: 1 mang chu so (nguoc), so chu so
    // Output: in ra man hinh theo thu tu nguoc lai
    for (int i = n-1; i >= 0; i--) {
        printf("%d", num[i]);
    }
    printf("\n");
}

int add(int num1[], int n1, int num2[], int n2, int num3[])
{
    // Input: mang chu so (num1, n1), (num2, n2) (thu tu chu so nguoc), ket qua num3
    // Output: cac chu so trong num3 va so chu so cua num3
    int i = 0, remember = 0;
    while (i < n1 || i < n2 || remember > 0) {
        int x1 = (i < n1) ? num1[i] : 0;
        int x2 = (i < n2) ? num2[i] : 0;
        int x = x1 + x2 + remember;
        num3[i] = x % 10;
        remember = x / 10;
        i++;
    }
    return i;
}

int multiply_digit(int num[], int n, int digit, int unit, int result[])
{
    // Input: (num, n) so can nhan, digit: chu so can nhan, unit: hang cua digit
    // Ouput: result: cac chu so, return so chu so
    // 125
    // 200
    // multiply_digit(521, 3, 2, 2, ...)
    // result 00052
    int i = 0, remember = 0;
    for (int j = 0; j < unit; j++)
        result[j] = 0;

    while (i < n || remember > 0) {
        int x = (i < n) ? num[i] : 0;
        x = x * digit + remember;
        result[i + unit] = x % 10; // dich phai unit don vi
        remember = x / 10;
        i++;
    }
    return i+unit; // dich phai unit don vi
}

int multiply(int num1[], int n1, int num2[], int n2, int num3[])
{
    // Input: mang chu so (num1, n1), (num2, n2) (thu tu chu so nguoc), ket qua num3
    // Output: ket qua nhan num1*num2 vao cac chu so trong num3 va so chu so cua num3
    // 1. num3 = 0
    // 2. nhan tung chu so cua num2 voi num 1 duoc kq la tmp
    // 3. cong num3 voi tmp
    int n3;
    int tmp[200];
    // Dat num3 = 0
    num3[0] = 0;
    n3 = 1;

    for (int i = 0; i < n2; i++) {
        int n_tmp = multiply_digit(num1, n1, num2[i], i, tmp);
        n3 = add(num3, n3, tmp, n_tmp, num3);
    }
    return n3;
}

int main()
{
    // Tinh 891239872398723984719239384579385 * 817263871643958039458
    // 1. Nhap, tach so, dua vao mang
    // 2. Nhan
    // 3. In ra
    int num1[200], num2[200], num3[200];
    int n1 = input_number(num1);
    int n2 = input_number(num2);
    int n3;
    
    print_number(num1, n1);
    printf("+\n");
    print_number(num2, n2);

    n3 = multiply(num1, n1, num2, n2, num3);
    print_number(num3, n3);

    return 0;
}
