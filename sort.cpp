#include <iostream>
#include <chrono>
#include <time.h>
#include <windows.h>
#include <fstream>

using namespace std;

int value, o;
int arr_size = 20;
int n = 100;
int error[5] = {};
long double avg[5] = {};
string names[5] = {"Selection", "Insertion", "Bubble", "Merge", "Quick"};
ofstream result("results.txt");
ofstream array("arrays.txt");

void Print_Array(int arr[], int size)
{
    array <<" [ ";
    for (int i = 0; i < size; i++)
    {
        array << arr[i] << " ";
    }
    array << "]\n";
}

void Copy_Array(int elements[], int elements_copy[], int size)
{
    for (int i = 0; i < size; i++)
    {
        elements_copy[i] = elements[i];
    }
}

bool Check_Array(int arr[], int arr_size)
{
    bool code = 0;

    for (int i = 0; i < arr_size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            code = 1;
            break;
        }
    }

    return code;
}

void Selection_Sort(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void Insertion_Sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void Bubble_Sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Merge(int arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[start + i];
    }

    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void Merge_Sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        Merge_Sort(arr, start, mid);
        Merge_Sort(arr, mid + 1, end);

        Merge(arr, start, mid, end);
    }
}

void Quick_Sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivot = arr[end];
        int i = start - 1;

        for (int j = start; j <= end - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[end]);

        int partition_index = i + 1;

        Quick_Sort(arr, start, partition_index - 1);
        Quick_Sort(arr, partition_index + 1, end);
    }
}

int main()
{
    chrono::time_point<std::chrono::high_resolution_clock> start, end;

    result << "Sample;";
    for (int i = 0; i < 5; i++)
    {
        result << names[i] + ";";
    }
    result << "\n";

    srand(time(0));

    int elements[arr_size];
    int elements_copy[arr_size];
    for (int a = 0; a < n; a++)
    {
        o = a + 1;
        result << o << ";";

        array << o << ": " <<"[ ";
        for (int i = 0; i < arr_size; i++)
        {
            value = rand() % 100;
            elements[i] = elements_copy[i] = value;
            array << value << " ";
        }
        array << "]\n";
        // Selection Sort

        start = chrono::high_resolution_clock::now();

        Selection_Sort(elements_copy, arr_size);

        end = chrono::high_resolution_clock::now();
        chrono::duration<long double> elapsed = end - start;

        result << elapsed.count() << ";";

        avg[0] += elapsed.count();

        error[0] += Check_Array(elements_copy, arr_size);

        Print_Array(elements_copy, arr_size);

        Copy_Array(elements, elements_copy, arr_size);

        // Insertion Sort

        start = chrono::high_resolution_clock::now();

        Insertion_Sort(elements_copy, arr_size);

        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        result << elapsed.count() << ";";

        avg[1] += elapsed.count();

        error[1] += Check_Array(elements_copy, arr_size);

        Print_Array(elements_copy, arr_size);

        Copy_Array(elements, elements_copy, arr_size);

        // Bubble Sort

        start = chrono::high_resolution_clock::now();

        Bubble_Sort(elements_copy, arr_size);

        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        result << elapsed.count() << ";";

        avg[2] += elapsed.count();

        error[2] += Check_Array(elements_copy, arr_size);

        Print_Array(elements_copy, arr_size);

        Copy_Array(elements, elements_copy, arr_size);

        // Merge Sort

        start = chrono::high_resolution_clock::now();

        Merge_Sort(elements_copy, 0, arr_size - 1);

        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        result << elapsed.count() << ";";

        avg[3] += elapsed.count();

        error[3] += Check_Array(elements_copy, arr_size);

        Print_Array(elements_copy, arr_size);

        Copy_Array(elements, elements_copy, arr_size);

        // Quick Sort

        start = chrono::high_resolution_clock::now();

        Quick_Sort(elements_copy, 0, arr_size - 1);

        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        result << elapsed.count() << ";\n";

        avg[4] += elapsed.count();

        error[4] += Check_Array(elements_copy, arr_size);

        Print_Array(elements_copy, arr_size);
    }
    result << "Avg;";
    for (int i = 0; i < 5; i++)
    {
        avg[i] /= n;
        result << avg[i] << ";";
    }

    for (int i = 0; i < 5; i++)
    {
        cout << names[i] << " sorting errors: " << error[i] << "\n";
    }

    result.close();
    array.close();

    return 0;
}