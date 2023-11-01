#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& array, int key)
{
    int start = 0 , end = (int)array.size() - 1;

    while(start <= end)
    {
        int mid = (start + (end - start)) / 2;
        if(array[mid] == key)
        {
            return mid;
        }
        if(array[mid] > key)
        {
            start = mid - 1;

        }
        if(array[mid] < key)
        {
            start = mid + 1;
        }
    }

    return -1;
} 

int main()
{



    return 0;
}