#include <iostream>
#include <algorithm> // For std::swap
using namespace std;

int steps = 0;

void heapify(int arr[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // Left child index
    int r = 2 * i + 2; // Right child index

    // Check if left child exists and is greater than the root
    if (l < n)
    {
        steps++; // Count comparison
        if (arr[l] > arr[largest])
        {
            largest = l;
        }
    }

    // Check if right child exists and is greater than the current largest
    if (r < n)
    {
        steps++; // Count comparison
        if (arr[r] > arr[largest])
        {
            largest = r;
        }
    }

    // If the largest is not the root, swap and continue heapifying
    if (largest != i)
    {
        swap(arr[i], arr[largest]); // Count swap
        steps++;
        heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

void heapSort(int arr[], int n)
{
    // Build a max heap
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root (largest) to the end
        swap(arr[0], arr[i]);
        steps++; // Count swap

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    heapSort(arr, n);

    cout << "\nSorted Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
    cout << "Total steps: " << steps << endl;

    return 0;
}
