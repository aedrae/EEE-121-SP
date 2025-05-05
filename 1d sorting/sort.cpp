#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

/*
1. figure out a way to sort the lists
2. implement into milestone 2
*/

// Quick Sort
/*
    quick sort is a divide and conquer algorithm. as it goes on,
    it will sort smaller and smaller arrays
    
    the last element is the initial pivot
*/


void quicksort(vector<float>& vec, int length);
void quicksort_recursion(vector<float>& vec, int low, int high);
int partition(vector<float>& vec, int low, int high);

int main()
{
    vector<float> a = {10.55, 11, 23, 44, 8, 15, 3, 9, 12, 45, 56, 45, 45};
    int length = a.size(); // this counts the number of elements, not indeces

    quicksort(a, length);

    for (int i = 0; i < length; i++){
        cout << a[i] << " ";
    }
    cout << endl << endl;


    return 0;
      
}

void quicksort(vector<float>& vec, int length){
    quicksort_recursion(vec, 0, length - 1); //sorts the array from low index to high index (length - 1)

}

void quicksort_recursion(vector<float>& vec, int low, int high) // will recursively implement recursion to the left and right portion
{
    if (low < high){
    int pivot_index = partition(vec, low, high);
    quicksort_recursion(vec, low, pivot_index - 1); //everything but not including the pivot
    quicksort_recursion(vec, pivot_index + 1, high);
    }
}

// the quicksort recursion applies the "divide" aspect of the function
// the pivot is not included since we know that its already in the right place
// we will eventually reach a portion of the array thats so small that we cant go on. so we stop
// eventually, our low index will be greater than the high index    

int partition(vector<float>& vec, int low, int high)
{
    float pivot_value = vec[high];

    int i = low;
    for (int j = low; j < high; j++)
    {
        if (vec[j] <= pivot_value)
        {
            swap(vec[i], vec[j]);
            i++;
        }
    }
    swap(vec[i], vec[high]);
    return i;
}
