#include <iostream>
using namespace std;

void insertionSort()
{
    int arr[10] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};

    auto exchange = [](int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    };

    for (int i = 1; i < 10; i++)
    {
        // cout << "ITERATION " << i << endl;

        int current = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than current, to one position ahead
        while (j >= 0 && arr[j] > current)
        {
            exchange(arr[j + 1],arr[j]);
            j--;
        }
        arr[j + 1] = current;

        // Display the sorting step by step
        cout << "Iteration " << i << " completed." << endl;
    }

    // Print the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    insertionSort();
    return 0;
}
