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

int main()
{
    // Tinh 891239872398723984719239384579385 + 817263871643958039458
    // 1. Nhap, tach so, dua vao mang
    // 2. Cong
    // 3. In ra
    int num1[200], num2[200], num3[200];
    int n1 = input_number(num1);
    int n2 = input_number(num2);
    int n3;
    
    print_number(num1, n1);
    printf("+\n");
    print_number(num2, n2);

    n3 = add(num1, n1, num2, n2, num3);
    print_number(num3, n3);

    return 0;
}
