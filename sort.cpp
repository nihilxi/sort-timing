#include <iostream>
#include <chrono>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;
using namespace chrono;

string times[100];
int base_elements[10000];

void saveData(string f)
{
    ofstream MyFile("results_" + f + ".txt");

    for (int q = 0; q < 100; q++)
    {
        MyFile << times[q] + "\n";
    }
    MyFile.close();
}

void bubble_sort(int arr[], int q)
{
    auto start_time = high_resolution_clock::now();
    for (int x = 10000; x > 0; x--)
    {
        for (int y = 0; y < x; y++)
        {
            if (arr[y] > arr[y + 1])
            {
                int temp = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = temp;
            }
        }
    }
    auto end_time = high_resolution_clock::now();
    int duration = duration_cast<chrono::milliseconds>(end_time - start_time).count();
    int seconds = duration / 1000;
    int miliseconds = duration - (seconds * 1000);
    string a = to_string(seconds) + "," + to_string(miliseconds) + " s";
    times[q] = a;
}

void selection_sort(int arr[], int q)
{
    int temp = 0;
    int idx;

    auto start_time = high_resolution_clock::now();

    for (int x = 0; x < 10000; x++)
    {
        for (int y = x; y < 10000; y++)
        {
            if (arr[y] > temp)
            {
                temp = arr[y];
                idx = y;
            }
        }
        int move = arr[x];
        arr[x] = temp;
        arr[idx] = move;
    }
    auto end_time = high_resolution_clock::now();
    int duration = duration_cast<chrono::milliseconds>(end_time - start_time).count();
    int seconds = duration / 1000;
    int miliseconds = duration - (seconds * 1000);
    string a = to_string(seconds) + "," + to_string(miliseconds) + " s";
    times[q] = a;
}

void insertion_sort(int arr[], int q)
{
    int temp = 0;
    int idx;

    auto start_time = high_resolution_clock::now();

    for (int x = 1; x < 10000; x++)
    {
        for (int i = x; i > 0; i--)
        {
            if (arr[i - 1] > arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
    }

    auto end_time = high_resolution_clock::now();
    int duration = duration_cast<chrono::milliseconds>(end_time - start_time).count();
    int seconds = duration / 1000;
    int miliseconds = duration - (seconds * 1000);
    string a = to_string(seconds) + "," + to_string(miliseconds) + " s";
    times[q] = a;
}

int main()
{
    srand(time(0));

    // Bubble sort

    for (int q = 0; q < 100; q++)
    {
        for (int i = 0; i < 10000; i++)
        {
            base_elements[i] = rand() % 100;
        }

        bubble_sort(base_elements, q);
    }

    saveData("b");

    // Selection sort

    for (int q = 0; q < 100; q++)
    {
        for (int i = 0; i < 10000; i++)
        {
            base_elements[i] = rand() % 100;
        }

        selection_sort(base_elements, q);
    }

    saveData("s");

    // Insertion sort

    for (int q = 0; q < 100; q++)
    {
        for (int i = 0; i < 10000; i++)
        {
            base_elements[i] = rand() % 100;
        }

        insertion_sort(base_elements, q);
    }

    saveData("i");

    return 0;
}
