// Jake Kistler
// University of Oklahoma
// CS 2414
// Quick sort

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
int listSize = 10000;

template <typename T>
T*createArrayFromFile(const string& fileName, const int listSize)
{
    ifstream file(fileName); // file is an opject of the ifstream class. It's like "File" from java
    if (!file)
    {
        cerr << "Error opening file: " << fileName << endl;
        return NULL;
    }

    // create and populate array
    int *arr = new int[listSize];

    // fill the array from the file
    int i = 0;
    while (!file.eof())
    {
        file >> arr[i];
        i++;
    }

    return arr;
} // End of createArrayFromFile

template <typename T>
void displayArray(T *arr, const int size)
{
    const int MAX_DISPLAY_SIZE = 200;
    const int COLUMNS = 10;

    if (size <= MAX_DISPLAY_SIZE)
    {
        // display the entire array
        for (int i = 0; i < size; i++)
        {
            cout << setw(6) << arr[i] << " ";

            if ((i + 1) % COLUMNS == 0)
            {
                cout << endl;
            }
        }
        cout << endl;
    }
    else
    {
        // display the firts 200 elements
        for (int i = 0; i < 100; i++)
        {
            cout << setw(6) << arr[i] << " ";

            if ((i + 1) % COLUMNS == 0)
            {
                cout << endl;
            }
        }
        cout << "... (Skipping " << (size - 200) << " elements)..." << endl;

        // display the last 100 elements
        for (int i = size - 100; i < size; i++)
        {
            cout << setw(6) << arr[i] << " ";

            if ((i + 1) % COLUMNS == 0)
            {
                cout << endl;
            }
        }
        cout << endl;
    }
} // End of displayArray

void swapElement(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

} //End of swapElement

template <typename T>
int partition( T *arr, int low, int high)
{
    srand(time(NULL)); //intalize a random seed
    int randomPivotIndex = low + rand() % (high - low);

    swapElement(arr[randomPivotIndex], arr[low]);

    int pivot = arr[low];
    int i = low + 1;

    for(int j = i; j <= high; j++)
    {
        if(arr[j] < pivot)
        {
            swapElement(arr[i], arr[j]);
            i++;
        }
    }

    swapElement(arr[low], arr[i -1]);
    return i - 1; 

} //End of partition

template <typename T>
void qucikSort(T *arr, int low, int high)
{
    if(low < high)
    {
        int pivotIndex = partition(arr, low, high);

        //recusive calls for left of pivot and right of pivot sub arrays
        qucikSort(arr, low, pivotIndex - 1);
        qucikSort(arr, pivotIndex + 1, high);
    }
} //End of quickSort

int main(int argc, char **argv)
{
    string filename;

    cout << "Welcome to insertion sort\nChecking to see if input file was sent in as command line argument...\n";

    // check to see if the command line has arguments
    if (argc > 1)
    {
        cout << "File name collected off the command line\n";
        filename = argv[1];
        listSize = atoi(argv[2]);
    }
    else
    {
        // prompt user for file name and list length
        cout << "Enter the file name you wish to sort: ";
        getline(cin, filename);

        cout << "\nNow the list size: ";
        cin >> listSize;
        cout << endl;
    }

    // create and populate the array
    int *arr = createArrayFromFile<int>(filename, listSize);

    // display the array
    cout << "UNSORTED ARRAY" << endl;
    displayArray(arr, listSize);

    cout << "Quick sorting the array..." << endl;
    qucikSort(arr,0, listSize);

    cout << "SORTED ARRAY" << endl;
    displayArray(arr, listSize);

    return 0;

} //End of main