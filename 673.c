#include <stdio.h>

char stack[130];
char line[130];

int main() {
    int n;
    char *c;
    fgets(line, 130, stdin);
    sscanf(line, "%d", &n);
    while (n--) {
        int i = 0;
        fgets(line, 130, stdin);
        for (c = line; *c != '\n'; c++) {
            switch (*c) {
                case '(':
                case '[':
                    stack[i++] = *c;
                    break;
                case ')':
                    if (i <= 0 || stack[i-1] != '(') {
                        printf("No\n");
                        goto done;
                    }
                    i--;
                    break;
                case ']':
                    if (i <= 0 || stack[i-1] != '[') {
                        printf("No\n");
                        goto done;
                    }
                    i--;
                    break;
            }
        }
        if (i != 0) { printf("No\n"); goto done; }
        printf("Yes\n");
done:
        ;
    }
    return 0;
}

