#include <iostream>
using namespace std;

int passes = 0;
int steps = 0;
void QuickSort(int arr[], int l, int r);
int partition(int arr[], int l, int r);
void swapElements(int &a1, int &a2);

void QuickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        passes++;
        int p = partition(arr, l, r);
        QuickSort(arr, l, p - 1);
        QuickSort(arr, p + 1, r);
    }
}

int partition(int arr[], int l, int r)
{
    int x = l + 1, y = r;
    int p = arr[l];
    while (x <= y)
    {
        while ((x <= y) && arr[x] <= p)
        {
            x++;
            steps++;
        }
        while ((x <= y) && arr[y] > p)
        {
            y--;
            steps++;
        }
        if (x < y)
        {
            swapElements(arr[x], arr[y]);
            steps++;
        }
    }
    swapElements(arr[l], arr[y]);
    steps++;
    return y;
}
void swapElements(int &a1, int &a2)
{
    int temp = a1;
    a1 = a2;
    a2 = temp;
}

int main()
{
    int n;
    cout << "Enter size of arrays: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    QuickSort(arr, 0, n - 1);
    cout << "\n Sorted Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
    cout << "Total passes: " << passes << endl;
    cout << "Total steps: " << steps << endl;
    return 0;
}
