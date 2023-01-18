#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
/*
* TypeTag - creates an enumeration type TypeTag which has 5 possible values:
* ADD, SUB, MUL, DIV, FIB
*
*/
typedef enum TypeTag {
    ADD, SUB, MUL, DIV, FIB,
} TypeTag;


/*
* struct Node - creates a struct called Node which has 4 fields:
* ADD, SUB, MUL, DIV, FIB
*
*/
typedef struct Node
{
    TypeTag type;
    int value;
    int left;
    int right;
} Node;


/*
* fibonacci - fibonacci function using recursion
* @x:  an integer x as an input
* Return: returns the nth fibonacci number
*/
int fibonacci(int x) {
    if (x <= 1) return x;
    return fibonacci(x - 1) + fibonacci(x - 2);
}

/*
* makeFunc - creates a new node and initializes its fields
*   with the given values. It takes in 3 arguments
* @TypeTag type:  an integer x as an input
* @left: the left operand of the operation
* @right:  the right operand of the operation
* Return: returns a pointer to the newly created node.
*/

Node* makeFunc(TypeTag type, int left, int right) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->type = type;
    node->left = left;
    node->right = right;
    return node;
}

/*
* calc - calculates the value of the operation represented by the given node
* @node:  a pointer to a Node as an argument
* Return: returns an integer value.
*/
int calc(Node* node) {
    int left, right;
    switch (node->type) {
        case ADD:
            left = node->left;
            right = node->right;
            node->value = left + right;
            break;
        case SUB:
            left = node->left;
            right = node->right;
            node->value = calc(node->right) - calc(node->left);
            break;
        case MUL:
            left = node->left;
            right = node->right;
            node->value = left * right;
            break;
        case DIV:
            left = node->left;
            right = node->right;
            node->value = left / right;
            break;
        case FIB:
            left = (calc(node->left)) + 7;
            node->value = fibonacci(left);
            break;
    }
    return node->value;
}

/*
* main - main entry point of the program.
*
* Return: returns 0.
*/

int main()
{
    Node *add = makeFunc(ADD, 10, 6);
    Node *mul = makeFunc(MUL, 5, 4);
    Node *sub = makeFunc(SUB, mul, add);
    Node *fibo = makeFunc(FIB, sub, NULL);
    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));
    return 0;
}
