#include <iostream>
#include <chrono>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;
using namespace chrono;

string times[100];
int base_elements[10000];

void bubble_sort(int arr[], int q)
{
    auto start_time = high_resolution_clock::now();
    for (int x = 9999; x > 0; x--)
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
    auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
    int seconds = duration_cast<chrono::seconds>(duration).count();
    int remaining_milliseconds = duration.count();

    string a = to_string(seconds) + "," + to_string(remaining_milliseconds) + " s";
    times[q] = a;
}

int main()
{
    srand(time(0));
    for (int q = 0; q < 100; q++)
    {
        for (int i = 0; i < 10000; i++)
        {
            base_elements[i] = rand() % 100;
        }

        bubble_sort(base_elements, q);
        cout<<q+1<<". Done"<<endl;
    }
    ofstream MyFile("results.txt");

    for (int q = 0; q < 100; q++)
    {
    MyFile << times[q]+"\n";
    }
    MyFile.close();

    return 0;
}
