#include <iostream>
#include <cstring>
using namespace std;

#define MAX 200

class BigIntMultiplication {
private:
    int numA[MAX], numB[MAX], result[MAX];  // Arrays to store digits of A, B, and the result
    int lenA, lenB;

public:
    // Constructor initializes arrays and lengths
    BigIntMultiplication() {
        memset(numA, 0, sizeof(numA));  // Initialize numA to zero
        memset(numB, 0, sizeof(numB));  // Initialize numB to zero
        memset(result, 0, sizeof(result));  // Initialize result to zero
        lenA = lenB = 0;  // Initialize lengths
    }

    // Function to store a number into an array of digits (in reverse order)
    void storeNumber(int num, int arr[], int &length) {
        while (num > 0) {
            arr[length++] = num % 10;  // Store digits in reverse order (least significant digit first)
            num /= 10;
        }
    }

    // Function to multiply two big integers
    void multiply(int A, int B) {
        if (A == 0 || B == 0) {
            cout << "0" << endl;  // If any number is 0, the product is 0
            return;
        }

        // Store the digits of A and B in reverse order
        storeNumber(A, numA, lenA);
        storeNumber(B, numB, lenB);

        // Multiply each digit of numA by each digit of numB and accumulate the result
        for (int i = 0; i < lenA; i++) {
            for (int j = 0; j < lenB; j++) {
                result[i + j] += numA[i] * numB[j];  // Add the product to the appropriate position
                if (result[i + j] >= 10) {
                    result[i + j + 1] += result[i + j] / 10;  // Handle carry to the next position
                    result[i + j] %= 10;  // Store only the unit digit in the current position
                }
            }
        }

        // Print the result
        printResult();
    }

    // Function to print the result of multiplication
    void printResult() {
        int lenResult = lenA + lenB;

        // Remove leading zeros
        while (lenResult > 1 && result[lenResult - 1] == 0) {
            lenResult--;
        }

        // Print the result in correct order (most significant digit first)
        for (int i = lenResult - 1; i >= 0; i--) {
            cout << result[i];
        }
        cout << endl;
    }
};

// Driver code
int main() {
    int A, B;
    cout << "Enter two integers: ";
    cin >> A >> B;

    BigIntMultiplication multiplier;
    cout << "Product: ";
    multiplier.multiply(A, B);

    return 0;
}
