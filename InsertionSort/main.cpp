#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &nums)
{
    for(int i = 1 ; i < (int)nums.size() ;i++)
    {
        int key = nums[i];
        int j = i -1;

        while(j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }

}

void display(vector<int> &nums)
{
    for(int i = 0 ; i < (int)nums.size() ;i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> arr;

    arr.push_back(205);
    arr.push_back(100);
    arr.push_back(5);
    arr.push_back(0);
    arr.push_back(50);
    arr.push_back(20);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(9);

    cout << "Before Sorting..\n";

    display(arr);

    cout << "After Sorting..\n";
    insertion_sort(arr);
    display(arr);


    return 0;
}