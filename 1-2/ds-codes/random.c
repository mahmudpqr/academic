#include <stdio.h>
#include <math.h>
#include <string.h>

int fact_it(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
}

int fact_re(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return n * fact_re(n - 1);
}

int fibo_it(int n) {
    if (n == 0) {
        return 0;
    }

    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }

    return b;
}

int fibo_re(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    return fibo_re(n - 1) + fibo_re(n - 2);
}

_Bool armstrong(int n) {
    int temp = n, count = 0, sum = 0;
    while (temp > 0) {
        count++;
        temp /= 10;
    }

    temp = n;
    while (temp > 0) {
        int last = temp % 10;
        sum += pow(last, count);
        temp /= 10;
    }

    if (sum == n) {
        return 1;
    }
    return 0;
}

_Bool palindrome(char a[], int n) {
    int left = 0, right = n - 1;

    while (left <= right) {
        if (a[left] != a[right]) {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}

int main() {
    int x;
    while(1) {
        printf("\n1. Factorial it");
        printf("\n2. Factorial re");
        printf("\n3. Fibonacci it");
        printf("\n4. Fibonacci re");
        printf("\n5. Armstrong number");
        printf("\n6. Palindrome");
        printf("\n7. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &x);
        
        if (x == 1) {
            int n;
            printf("\nEnter number: ");
            scanf("%d", &n);

            int result = fact_it(n);
            printf("\n%d! = %d\n", n, result);
        } else if (x == 2) {
            int n;
            printf("\nEnter number: ");
            scanf("%d", &n);

            int result = fact_re(n);
            printf("\n%d! = %d\n", n, result);
        } else if (x == 3) {
            int n;
            printf("\nEnter index: ");
            scanf("%d", &n);

            int result = fibo_it(n);
            printf("\nF%d = %d\n", n, result);
        } else if (x == 4) {
            int n;
            printf("\nEnter index: ");
            scanf("%d", &n);

            int result = fibo_it(n);
            printf("\nF%d = %d\n", n, result);
        } else if (x == 5) {
            int n;
            printf("\nEnter number: ");
            scanf("%d", &n);

            if (armstrong(n)) {
                printf("\n%d is armstrong\n", n);
            } else {
                printf("\n%d is not armstrong\n", n);
            }
        } else if (x == 6) {
            int n;
            printf("\nEnter string length: ");
            scanf("%d", &n);

            char a[n+1];
            printf("Enter string: ");
            getchar();
            fgets(a, sizeof(a), stdin);
            
            if (palindrome(a, n)) {
                printf("\n%s is palindrome\n", a);
            } else {
                printf("\n%s is not palindrome\n", a);
            }
        } else if (x == 7) {
            break;
        } else {
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}