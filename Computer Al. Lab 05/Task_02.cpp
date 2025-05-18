#include<iostream>
#include<cmath>
using namespace std;

int inversionCount = 0;

void Merge(int arr[] , int p , int q , int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1] , R[n2];

    for(int i = 0 ; i < n1 ; i++)
    {
        L[i] = arr[p + i];
    }

    for(int j = 0 ; j < n2 ; j++)
    {
        R[j] = arr[q + 1 + j];
    }

    int i = 0 , j = 0 , k = p;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            inversionCount += (n1 - i);
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Merge_sort(int a[] , int p , int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
        Merge_sort(a , p , q);
        Merge_sort(a, (q + 1) , r);

        Merge(a, p , q , r);

    }
}

int main()
{
    int d;
    cout << "Enter the number of datasets: ";
    cin >> d;

    while(d--)
    {
        int n;
        cout << "Enter the number of elements of the array: ";
        cin >> n;

        int A[n];
        cout << "Enter the elements of the array: ";
        for(int i = 0 ; i < n ; i++)
        {
            cin >> A[i];
        }

        inversionCount = 0;
        Merge_sort(A , 0 , n - 1);

        cout << "\nNumber of swaps: " << inversionCount << "\n";
    }

    return 0;
}

