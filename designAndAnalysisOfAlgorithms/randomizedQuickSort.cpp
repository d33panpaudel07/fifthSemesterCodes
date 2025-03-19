#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int passes = 0;
int steps = 0;

// Function Prototypes
void QuickSort(int arr[], int l, int r);
int partition(int arr[], int l, int r);
void swapElements(int &a1, int &a2);
void randomize(int arr[], int l, int r);

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
    // Randomize the pivot by swapping with a random index
    randomize(arr, l, r);

    int x = l + 1, y = r;
    int p = arr[l]; // Pivot is now randomized
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
    swapElements(arr[l], arr[y]); // Place pivot in its correct position
    steps++;
    return y;
}

void swapElements(int &a1, int &a2)
{
    int temp = a1;
    a1 = a2;
    a2 = temp;
}

void randomize(int arr[], int l, int r)
{
    // Generate a random index between l and r (inclusive)
    int random_index = l + rand() % (r - l + 1);
    swapElements(arr[l], arr[random_index]); // Swap pivot with random index
}

int main()
{
    srand(time(0)); // Seed random number generator

    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    QuickSort(arr, 0, n - 1);

    cout << "\nSorted Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
    cout << "Total passes: " << passes << endl;
    cout << "Total steps: " << steps << endl;

    return 0;
}
