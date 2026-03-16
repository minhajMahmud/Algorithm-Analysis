#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100
/*Name mahmudul hasan
MUH2225029M
mahmudul2517@student.nstu.edu.bd
*/
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;
int isEmpty() {
    return top == NULL;
}

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode; 
}

int pop() {
    if (isEmpty()) {
        exit(1);
    }
    struct Node* temp = top;
    int data = top->data;
    top = top->next;
    free(temp);
    return data;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int calculate(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        default:
            exit(1);
    }
}

int eva(char* exp) {
    int len = strlen(exp);
    for (int i = 0; i < len; i++) {
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            push(num);
        } else if (isOperator(exp[i])) {
            int val1 = pop();
            int val2 = pop();
            int result = calculate(val2, val1, exp[i]);
            push(result);
        } else {
            printf("Erro\n");
            exit(1);
        }
    }
    return pop();
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter  Expression: ");
    scanf("%s", exp);

    int result = eva(exp);
    printf("Result: %d\n", result);

    return 0;
}
