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

vector<int> fn2(int n)
{
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        arr[i] = i;
    return arr;
}

vector<int> fn3(int n)
{
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        arr[i] = n - i;
    return arr;
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

// Recursive Selection Sort
void selectionSortRecursive(vector<int> &arr, int start, int n)
{
    if (start >= n - 1)
        return;

    int minIndex = start;
    for (int i = start + 1; i < n; i++)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }

    swap(arr[start], arr[minIndex]);
    selectionSortRecursive(arr, start + 1, n);
}

vector<int> selectionSort2(vector<int> &arr)
{
    vector<int> a = arr;
    selectionSortRecursive(a, 0, a.size());
    return a;
}

void bubbleSortRecursive(vector<int> &arr, int n)
{
    if (n == 1)
        return;

    bool swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            swapped = true;
        }
    }

    if (!swapped)
        return;
    bubbleSortRecursive(arr, n - 1);
}

vector<int> bubbleSort2(vector<int> &arr)
{
    vector<int> a = arr;
    bubbleSortRecursive(a, a.size());
    return a;
}

void insertionSortRecursive(vector<int> &arr, int n)
{
    if (n <= 1)
        return;

    insertionSortRecursive(arr, n - 1);

    int key = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

vector<int> insertionSort2(vector<int> &arr)
{
    vector<int> a = arr;
    insertionSortRecursive(a, a.size());
    return a;
}

long long measure(auto sortFunction, vector<int> &arr) {
    vector<int> a = arr;
    auto start = high_resolution_clock::now();
    sortFunction(a);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

void benchmarkAndWrite(const string &filename, function<vector<int>(int)> inputGen)
{
    ofstream fout(filename);
    fout << "InputSize,Selection1,Bubble1,Insertion1,Selection2,Bubble2,Insertion2\n";

    for (int n = 0; n <= 10000; n += 1000)
    {
        vector<int> arr = inputGen(n);

        long long t1 = measure(selectionSort1, arr);
        long long t2 = measure(bubbleSort1, arr);
        long long t3 = measure(insertionSort1, arr);
        long long t4 = measure(selectionSort2, arr);
        long long t5 = measure(bubbleSort2, arr);
        long long t6 = measure(insertionSort2, arr);

        fout << n << "," << t1 << "," << t2 << "," << t3 << ","
             << t4 << "," << t5 << "," << t6 << "\n";

        cout << "Done " << filename << ": " << n << endl;
    }
}
int main()
{

    srand(time(0));
    benchmarkAndWrite("ascending.csv", fn2);
    benchmarkAndWrite("descending.csv", fn3);
    benchmarkAndWrite("random.csv", fn);

    // Selection Sort iterative
    // cout << "Selection Sort:" << endl;
    // cout << "Before sorting: ";
    // for (int i : arr)
    //     cout << i << " ";
    // cout << endl;

    // auto start1 = high_resolution_clock::now();
    // vector<int> sortedArr1 = selectionSort1(arr);
    // auto end1 = high_resolution_clock::now();
    // auto duration1 = duration_cast<duration<double, micro>>(end1 - start1);

    // cout << "After sorting: ";
    // for (int i : sortedArr1)
    //     cout << i << " ";
    // cout << endl;
    // cout << "Selection Sort 1 time taken: " << duration1.count() << " microseconds" << endl
    //      << endl;

    // Bubble sort iterative
    // cout << "Before sorting: ";
    // for (int i : arr)
    //     cout << i << " ";
    // cout << endl;

    // auto start2 = high_resolution_clock::now();
    // vector<int> sortedArr2 = bubbleSort1(arr);
    // auto end2 = high_resolution_clock::now();
    // auto duration2 = duration_cast<duration<double, micro>>(end2 - start2);

    // cout << "After sorting: ";
    // for (int i : sortedArr2)
    //     cout << i << " ";
    // cout << endl;
    // cout << "Bubble Sort 1 time taken: " << duration2.count() << " microseconds" << endl
    //      << endl;

    // insertion sort iterative
    // cout << "Before sorting: ";
    // for (int i : arr)
    //     cout << i << " ";
    // cout << endl;

    // auto start3 = high_resolution_clock::now();
    // vector<int> sortedArr3 = insertionSort1(arr);
    // auto end3 = high_resolution_clock::now();
    // auto duration3 = duration_cast<duration<double, micro>>(end3 - start3);

    // cout << "After sorting: ";
    // for (int i : sortedArr3)
    //     cout << i << " ";
    // cout << endl;
    // cout << "Insertion Sort 1 time taken: " << duration3.count() << " microseconds" << endl << endl;

    // Selection Sort recursive
    // cout << "Before sorting: ";
    // for (int i : arr)
    //     cout << i << " ";
    // cout << endl;
    // auto start4 = high_resolution_clock::now();
    // vector<int> sortedArr4 = selectionSort2(arr);
    // auto end4 = high_resolution_clock::now();
    // auto duration4 = duration_cast<duration<double, micro>>(end4 - start4);
    // cout << "After sorting: ";
    // for (int i : sortedArr4)
    //     cout << i << " ";
    // cout << endl;
    // cout << "Selection Sort 2 time taken : " << duration4.count() << " microseconds" << endl << endl;

    // Bubble Sort recursive
    // cout << "Before sorting: ";
    // for (int i : arr)
    //     cout << i << " ";
    // cout << endl;
    // auto start5 = high_resolution_clock::now();
    // vector<int> sortedArr5 = bubbleSort2(arr);
    // auto end5 = high_resolution_clock::now();
    // auto duration5 = duration_cast<duration<double, micro>>(end5 - start5);
    // cout << "After sorting: ";
    // for (int i : sortedArr5)
    //     cout << i << " ";
    // cout << endl;
    // cout << "Bubble Sort 2 time taken : " << duration5.count() << " microseconds" << endl << endl;

    // Insertion Sort recursive
    // cout << "Before sorting: ";
    // for (int i : arr)
    //     cout << i << " ";
    // cout << endl;
    // auto start6 = high_resolution_clock::now();
    // vector<int> sortedArr6 = insertionSort2(arr);
    // auto end6 = high_resolution_clock::now();
    // auto duration6 = duration_cast<duration<double, micro>>(end6 - start6);
    // cout << "After sorting: ";
    // for (int i : sortedArr5)
    //     cout << i << " ";
    // cout << endl;
    // cout << "Insertion Sort 2 time taken : " << duration6.count() << " microseconds" << endl << endl;

    return 0;
}