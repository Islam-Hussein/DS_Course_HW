#include <iostream>
#include <vector>

using namespace std;

vector<int> CountSort(vector<int>& array)
{   
    //Find Maximum Value
    int size = array.size() , mxValue = array[i];
    for(int i = 1 ; i < size ; i++)
    {
        if(array[i] > mxValue)
        {
            mxValue = array[i];
        }
    } 

    
    //Compute Frequency
    vector<int> count(mxValue + 1); //Zeros array with size of Maximum Value
    for(int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }
    
    //Put Values back in the array
    int idx = 0;
    for(int i = 0 ; i < mxValue ; i++)
    {
        for(int j = 0 ; j < count[i] ; ++j , ++idx)
        {
            array[idx] = i;
        }
    }

    return array;

}

int main()
{



    return 0;
}