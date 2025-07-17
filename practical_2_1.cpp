#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int N = 100000;
vector<int> fn(int n)
{
    vector<int> ans(n);
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        ans[i] = rand() % N + 1;
    }
    return ans;
}

vector<int> selectionSort1(vector<int> &arr)
{
    vector<int> a = arr;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
    return a;
}

vector<int> bubbleSort1(vector<int> &arr)
{
    vector<int> a = arr;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                isSwapped = true;
                swap(a[j], a[j + 1]);
            }
        }
        if (!isSwapped)
        {
            break;
        }
    }
    return a;
}

vector<int> insertionSort1(vector<int> &arr)
{
    vector<int> a = arr;
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    return a;
}

int main()
{

    vector<int> arr = fn(10000);

    // Selection Sort iterative
    // cout << "Selection Sort:" << endl;
    // cout << "Before sorting: ";
    // for (int i : arr)
    //     cout << i << " ";
    // cout << endl;

    auto start1 = high_resolution_clock::now();
    vector<int> sortedArr1 = selectionSort1(arr);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<duration<double, micro>>(end1 - start1);

    // cout << "After sorting: ";
    // for (int i : sortedArr1)
    //     cout << i << " ";
    // cout << endl;
    cout << "Selection Sort time taken: " << duration1.count() << " microseconds" << endl
         << endl;

    // Bubble sort iterative
    // cout << "Before sorting: ";
    // for (int i : arr)
    //     cout << i << " ";
    // cout << endl;

    auto start2 = high_resolution_clock::now();
    vector<int> sortedArr2 = bubbleSort1(arr);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<duration<double, micro>>(end2 - start2);

    // cout << "After sorting: ";
    // for (int i : sortedArr2)
    //     cout << i << " ";
    // cout << endl;
    cout << "Bubble Sort time taken: " << duration2.count() << " microseconds" << endl
         << endl;

    // insertion sort iterative
    // cout << "Before sorting: ";
    // for (int i : arr)
    //     cout << i << " ";
    // cout << endl;

    auto start3 = high_resolution_clock::now();
    vector<int> sortedArr3 = insertionSort1(arr);
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<duration<double, micro>>(end3 - start3);

    // cout << "After sorting: ";
    // for (int i : sortedArr3)
    //     cout << i << " ";
    // cout << endl;
    cout << "Insertion Sort time taken: " << duration3.count() << " microseconds" << endl;

    return 0;
}