#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 100

char stack[N];
int top = -1;


int prec(char a) {
    if (a == '^') return 3;
    if (a == '*' || a == '/') return 2;
    if (a == '+' || a == '-') return 1;
    return 0;
}

int isRightAssociative(char op) {
    return op == '^';
}

void push(char x) {
    if (top < N - 1) {
        stack[++top] = x;
    } else {
        printf("Stack Overflow\n");
    }
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

void infixtopostfix(char exp[], char res[]) {
    int j = 0;
    int length = strlen(exp);

    for (int i = 0; i < length; i++) {
        char p = exp[i];

        if (isalnum(p)) {
            res[j++] = p;
        } else if (p == '(') {
            push(p);
        } else if (p == ')') {
            while (top != -1 && peek() != '(') {
                res[j++] = pop();
            }
            if (top != -1) pop();
        } else {
            while (top != -1 && peek() != '(' &&
                   (prec(peek()) > prec(p) ||
                    (prec(peek()) == prec(p) && !isRightAssociative(p)))) {
                res[j++] = pop();
            }
            push(p);
        }
    }


    while (top != -1) {
        res[j++] = pop();
    }

    res[j] = '\0';
}

int main() {
    char exp[N];
    char res[N];

    printf("Enter the expression:\n");
    scanf("%s", exp);

    infixtopostfix(exp, res);

    printf("The postfix expression is: %s\n", res);

    return 0;
}
