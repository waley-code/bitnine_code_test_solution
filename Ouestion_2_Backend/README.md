# Coding Test � Backend

### [ Answer to Question No. 2 ]
This programme Implements the following piecewise recurrence relation in the 3 different ways.
Below is a quick documentation and thought process explaining the entire programme.

## How to compile and run the programme
    The programme was written in C language and developed using CodeBlocks IDE, source code can be found in the main.c file.
    Simply open the source code using a CodeBlock IDE and click on the Build and run button to execute and output results of the programme


### 1. Iterative solution using a for loop:

    This function takes an integer n as input, and calculates the value of F(n) using an iterative approach.
    It uses a for loop to iterate from 3 to n, and uses the recurrence relation F(n) = F(n-3) + F(n-2)
    to calculate the value of F(n).
    It starts by initializing three variables f0, f1 and f2 with the values of F(0), F(1) and F(2) respectively.
    In the for loop, the next value of F(n) is calculated by adding F(n-3) and F(n-2) and is stored in the variable f3.
    Then the values of f1, f2 and f3 are shifted to the left, so that f1 will now hold the value of F(n-1),
    f2 will hold the value of F(n-2) and f3 will hold the value of F(n-3). This process is repeated for every iteration of the for loop until
    the value of i is greater than n. At the end of the loop, the final value of F(n) will be stored in the variable f2 and is printed out.
                    void iterative(int n) {
                        int f0 = 0, f1 = 1, f2 = 2;
                        for (int i = 3; i <= n; i++) {
                            int f3 = f2 + f1;
                            f0 = f1;
                            f1 = f2;
                            f2 = f3;
                        }
                        printf("F(%d) = %d\n", n, f2);
                    }


### 2. Recursive Solution

    This function takes an integer n as input, and calculates the value of F(n) using a recursive approach.
    It uses a base case to check if n is equal to 0, 1, or 2, and returns the corresponding value for F(0), F(1) or F(2).
    If n is greater than 2, it calls the recursive function twice, once with the input as n-3 and once with the input as n-2.
    The function returns the sum of the values returned by these two recursive calls.
    This process is repeated until the base case is reached.
    The function will have a high time complexity, O(2^n) and risk of stack overflow for large n.
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


### 3. Dynamic Solution

    This function takes an integer n as input, and calculates the value of F(n) using a dynamic programming approach.
    It uses an array to store the values of previously calculated F(n) so that they don't have to be recalculated.
    It starts by initializing an array f with the size n+1 and assigns the values of F(0), F(1) and F(2) to the first three elements of the array.
    In the for loop, it uses the recurrence relation F(n) = F(n-3) + F(n-2) to calculate the value of F(n) by adding the values of F(n-3) and F(n-2)
    stored in the array. This process is repeated for every iteration of the for loop until the value of i is greater than n. At the end of the loop,
    the final value of F(n) will be stored in the array at the index n, and is printed out.
    The dynamic programming approach is more efficient than the recursive approach as it uses an array to store the values of previously calculated F(n)
    which reduces the number of function calls. However, it still takes up more memory and takes longer to run than the iterative solution.
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


## Differences (advantages, disadvantages) between the 3.
    The dynamic programming approach is more efficient than the recursive approach as it uses an array to store the values of previously calculated F(n)
    which reduces the number of function calls. However, it still takes up more memory and takes longer to run than the iterative solution.
