#include <iostream>
#include <cstring>
#include<ctime>
using namespace std;

#define MAX 500

class BigIntMultiplication
{
private:
    int numA[MAX];
    int numB[MAX];
    int result[MAX * 2];

public:

    BigIntMultiplication()
    {
        memset(numA, 0, sizeof(numA));
        memset(numB, 0, sizeof(numB));
        memset(result, 0, sizeof(result));

    }

    void multiply(const string &numA , const string &numB)
    {
        int lenA = numA.size();
        int lenB = numB.size();

        if (lenA == 0 || lenB == 0 || numA == "0" || numB == "0")
        {
            cout << "0" << endl;
            return;
        }


        for (int i = lenA - 1 ; i >= 0; i--)
        {
            for (int j = lenB - 1; j >= 0; j--)
            {
                int product = (numA[i] - '0') * (numB[j] - '0');
                int sum = product + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        printResult(lenA + lenB);
    }

    void printResult(int lenResult)
    {
        int i = 0;
        while(i < lenResult && result[i] == 0)
        {
            i++;
        }
        if(i == lenResult)
        {
            cout << "0";
        }
        else
        {
            for(; i <lenResult ; i++)
            {
                cout << result[i];
            }
        }
        cout << "\n";
    }
};


int main()
{
    string X;
    cout << " Enter number X: ";
    cin >> X;

    string Y;
    cout << " Enter number Y: ";
    cin >> Y;


    BigIntMultiplication multiplier;

    clock_t startT = clock();

    cout << "Product: ";
    multiplier.multiply(X, Y);

    clock_t endT = clock();

    double duration;
    duration = (double)(endT - startT) / CLOCKS_PER_SEC;
    cout << "\nDuration: " << duration << " seconds";

    return 0;
}

