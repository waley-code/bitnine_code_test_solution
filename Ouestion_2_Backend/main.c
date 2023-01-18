/*
* iterative - takes an integer n as input, and calculates the value of
* F(n) using an iterative approach.
* @n: Integer input
*
*/

void iterative(int n) {
    int f0 = 0, f1 = 1, f2 = 2;
    for (int i = 3; i <= n; i++) {
        int f3 = f2 + f1;  // f3 is the next value of F(n)
        f0 = f1;  // shift the values of F(n-1), F(n-2) and F(n-3) to the left
        f1 = f2;
        f2 = f3;
    }
    printf("F(%d) = %d\n", n, f2);  // the final value of F(n) is stored in f2
}

/*
* recursive - takes an integer n as input, and calculates the value of
* F(n) using an recursive approach.
* @n: Integer input
*
*/
int recursive(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        return recursive(n - 3) + recursive(n - 2);
    }
}

/*
* dynamic - takes an integer n as input, and calculates the value of
* F(n) using an dynamic approach.
* @n: Integer input
*
*/
void dynamic(int n) {
    int f[n + 1];
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 3] + f[i - 2];
    }
    printf("F(%d) = %d\n", n, f[n]);
}
