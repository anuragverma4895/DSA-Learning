#include <stdio.h>

void towerOfHanoi(int n, char a, char b, char c) {
    // Base case: If n is less than or equal to 0, return
    if (n <= 0) {
        return;
    }

    // Move n-1 disks from a to b using c as auxiliary rod
    towerOfHanoi(n - 1, a, c, b);

    // Move the nth disk from a to c
    printf("Move disk %d from %c to %c\n", n, a, c);

    // Move the n-1 disks from b to c using a as auxiliary rod
    towerOfHanoi(n - 1, b, a, c);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'a', 'b', 'c');
    return 0;
}
