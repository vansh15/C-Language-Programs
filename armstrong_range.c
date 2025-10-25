/*
 * Program Name: Armstrong Numbers in a Given Range
 * Problem Statement:
 *   Print all Armstrong numbers between two given integers.
 *
 * Example:
 *   Input: 100 500
 *   Output: 153 370 371 407
 *
 * Compilation:
 *   gcc armstrong_range.c -o armstrong_range
 * Execution:
 *   ./armstrong_range
 *
 * Time Complexity: O(n * d) where d = number of digits
 */

#include <stdio.h>
#include <math.h>

int isArmstrong(int num) {
    int original = num, digits = 0, sum = 0;

    // Count digits
    int temp = num;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    // Calculate sum of powers of digits
    temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == original;
}

int main() {
    int start, end;
    printf("Enter the range (start end): ");
    scanf("%d %d", &start, &end);

    printf("Armstrong numbers between %d and %d are:\n", start, end);
    for (int i = start; i <= end; i++) {
        if (isArmstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
