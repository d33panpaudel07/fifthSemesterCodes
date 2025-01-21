#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};

    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << endl
         << "final answer: ";
    for (int k = 0; k < 10; k++)
    {
        cout << arr[k] << ", ";
    }
}