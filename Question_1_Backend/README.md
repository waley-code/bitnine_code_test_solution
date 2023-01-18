# Coding Test  Backend

### [ Answer to Question No. 1 ]
    This programme Implements a function that returns fibonacci sequence based on the following arithmetic operations (+, -,
    *, /) and conditions. The fibonacci function was implemented using Dynamic Programming.
    Below is a quick documentation and thought process explaining the entire programme.

## How to compile and run the programme
    The programme was written in C language and developed using CodeBlocks IDE, source code can be found in the main.c file.
    run a compiled version main.exe within the directory from the command line with the command "./main.exe"
    or Simply open the source code using a CodeBlock IDE and click on the Build and run button to execute and output results of the programme



### typedef enum TypeTag
    This creates an enumeration type TypeTag which has 5 possible values: ADD, SUB, MUL, DIV,
    FIB which are used to represent the different types of operations that can be performed by the nodes.

            typedef enum TypeTag {
                ADD, SUB, MUL, DIV, FIB,
            } TypeTag;

### typedef struct Node
    This creates a struct called Node which has 4 fields:

    TypeTag type: an enumeration type representing the type of operation the node represents (ADD, SUB, MUL, DIV, FIB)
    int value: the result of the operation represented by the node
    struct Node* left: a pointer to the left operand of the operation
    struct Node* right: a pointer to the right operand of the operation

            typedef struct Node
            {
                TypeTag type;
                int value;
                int left;
                int right;
            } Node;

### int fibonacci(int x)
    This creates an enumeration type TypeTag which has 5 possible values:
    ADD, SUB, MUL, DIV, FIB which are used to represent the different types of operations
    that can be performed by the nodes.

            int fibonacci(int x) {
                if (x <= 1) return x;
                return fibonacci(x - 1) + fibonacci(x - 2);
            }


### Node* makeFunc(TypeTag type, int left, int right)
    This function creates a new node and initializes its fields with the given values. It takes in 3 arguments:

    TypeTag type: the type of operation the node represents
    Node* left: a pointer to the left operand of the operation
    Node* right: a pointer to the right operand of the operation
    It then allocates memory for the node using the malloc function and assigns
    the given values to the corresponding fields of the node. Finally, it returns a pointer to the newly created node.

            Node* makeFunc(TypeTag type, int left, int right) {
                Node* node = (Node*) malloc(sizeof(Node));
                node->type = type;
                node->left = left;
                node->right = right;
                return node;
            }


### int calc(Node* node)
    This function calculates the value of the operation represented by the given node.
    It takes in a pointer to a Node as an argument and returns an integer value.
    It first initializes two variables left and right to store the values of the left and right operands of the operation.
    Then it uses a switch statement to determine the type of operation represented by the node and performs
    the corresponding operation. For the ADD, SUB, MUL, and DIV cases, it uses recursion to calculate the values of
    the left and right operands by calling the calc() function on the left and right fields of the node. Then it assigns
    the result of the operation to the value field of the node. For the FIB case, it calculates the fibonacci value of
    the left operand by calling the fibonacci() function. Finally, it returns the value of the node.

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


### int main()
    This is the main function of the program. It first creates 4 nodes using the makeFunc() function.
    The first node represents the ADD operation with left operand 10 and right operand 6.
    The second node represents the MUL operation with left operand 5 and right operand 4.
    The third node represents the SUB operation with left operand the result of the MUL operation
    and right operand the result of the ADD operation. The fourth node represents the FIB operation
    with left operand the result of the SUB operation and right operand is NULL. Then, it uses
    the printf function to print the results of the operations represented by the 4 nodes by calling the
    calc() function on each node. Finally, it returns 0 to indicate that the program executed successfully.

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
