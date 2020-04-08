// Input: 2 m: so dong, n: so cot
// Output: 1 bang so xoay tron oc theo chieu kim dong ho co m dong, n cot, cac so tu 1 -> m*n
// VD: m = 3, n = 4
//  1  2  3  4
// 10 11 12  5
//  9  8  7  6

#include <stdio.h>

int generate_ring(int a[100][100], int top, int left, int bottom, int right, int start_value)
{
    // input: mang, goc trai tren, phai duoi cua hinh chu nhat, so dau tien
    // output: dien so vao vien cua hinh chu nhat
    // return: so can dien tiep theo
    for (int j = left; j <= right; j++) a[top][j] = start_value++; // move_right()
    for (int i = top+1; i <= bottom; i++) a[i][right] = start_value++; // move_down()
    for (int j = right-1; top < bottom && j >= left; j--) a[bottom][j] = start_value++; // move_left()
    for (int i = bottom-1; left < right && i >= top+1; i--) a[i][left] = start_value++; // move_up()
    return start_value;
}

void print_matrix(int a[100][100], int m, int n)
{
    // output: in ma tran 2 chieu m dong n cot
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    printf("--------------\n");
}

int main()
{
    int top = 0, left = 0, bottom, right;
    int k = 1;
    int a[100][100];
    int m, n;

    scanf("%d%d", &m, &n);
    bottom = m-1;
    right = n-1;

    while (top <= bottom && left <= right) {
        k = generate_ring(a, top, left, bottom, right, k);
        print_matrix(a, m, n);

        top++, left++, bottom--, right--;
    }

    return 0;
}
