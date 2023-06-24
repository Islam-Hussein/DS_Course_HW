#include "vector.h"

Vector::Vector(int size) : size(size)
{
    if (size < 0)
            size = 1;

    capacity = size + 10;   

    arr = new int[capacity] { };
}


int Vector::get(int idx)
{
    //assert(0 <= idx && idx < size);
    return arr[idx];
}

void Vector::set(int idx, int val)
{
    arr[idx] = val;
}


void Vector::print()
{
    for(int i = 0 ; i < size ; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n"; 
}

int Vector::find(int val)
{
    for(int i = 0 ; i < size ; ++i)
    {
        if(arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}

void Vector::push_back(int val)
{
    // we can't add any more
	if (size == capacity)
		expand_capacity();
	arr[size++] = val;
}

void Vector::expand_capacity()
{
	// Double the actual array size
	capacity *= 2;
	std::cout << "Expand capacity to "
				<< capacity << "\n";
	int *arr2 = new int[capacity] { };
	for (int i = 0; i < size; ++i)
		arr2[i] = arr[i];	// copy data

	std::swap(arr, arr2);
	delete[] arr2;
}

void Vector::insert(int idx , int val)
{
    //we can't add anymore elements
    if(size == capacity)
    {
        expand_capacity();
    }
    for(int p = size -1 ; p >= idx; --p)
    {
        arr[p+1] = arr[p];
    }
    arr[idx] =val; 
    ++size;
}


int Vector::get_front()
{
    return arr[0];
}

int Vector::get_back()
{
    return arr[size-1];
}

void Vector::right_rotation()
{
    int temp = arr[size -1];

    for(int p = size-1 ; p >= 0 ; p-- )
    {
        arr[p+1] = arr[p];
    }
    arr[0] = temp;  
}

void Vector::left_rotation()
{
    int temp = arr[0];
    for(int p = 0 ; p <= size-1 ; p++ )
    {
        arr[p] = arr[p+1];
    }
    arr[size-1] = temp;
}

void Vector::right_rotation_with_steps(int n)
{
    while(n != 0)
    {
        right_rotation();
        n--;

    }
}

void Vector::left_rotation_with_steps(int n)
{
    while(n != 0)
    {
        left_rotation();
        n--;
    }
}

int Vector::pop(int idx)
{
    int temp = arr[idx];

    for(int p = idx ; p <= size-1 ; p++)
    {
        arr[p] = arr[p+1];
    }
    return temp;
}


int Vector::find_transposition(int val)
{
    int idx ;
    int temp;
    for(int p = 0 ; p <= size -1 ; p++)
    {
        if(arr[p] == val)
        {
            idx = p-1;
            temp = arr[p];
            if(p != 0)
            {
                arr[p] = arr[p-1];
                arr[p-1] = temp;
            }
            return idx;
        }
    }
    return -1;
}

Vector::~Vector()
{
    delete[] arr;
    arr = nullptr;
}
