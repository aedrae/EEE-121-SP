#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

/*
1. flatten the array (can be used in central tendency for 2d) -- DONE
2. quicksort -- DONE
3. reshape array
*/

// quicksort import VV
    void quicksort(vector<float>& vec, int length);
    void quicksort_recursion(vector<float>& vec, int low, int high);
    int partition(vector<float>& vec, int low, int high);

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



int main(){

    int columnsize1 = 3;
    int rowsize1 = 3;
    vector<float> flat_ds1;
    vector<vector<float>> ds1 = {
        {3.5, 1.2, 7.8},
        {0.4, 9.1, 2.2},
        {8.6, 5.3, 4.4}
    };
    
    
    int columnsize2 = 2;
    int rowsize2 = 2;
    vector<float> flat_ds2;
    vector<vector<float>> ds2 = {
        {6.7, 2.3},
        {1.9, 8.8}
    };
    

    // flatten the 2d vector:
    // ds1
    for (int i = 0; i < rowsize1; i++){
        for (int j = 0; j < columnsize1; j++){
            flat_ds1.push_back(ds1[i][j]);
        }
    }

    // ds2
    for (int i = 0; i < rowsize2; i++){
        for (int j = 0; j < columnsize2; j++){
            flat_ds2.push_back(ds2[i][j]);
        }
    }
    cout << "unsorted ";
    for (float val : flat_ds1){
        cout << val << " ";
    }
    cout << endl << "sorted " << endl;
    // quicksort here *
    quicksort(flat_ds1, flat_ds1.size());
    for (float val : flat_ds1){
        cout << val << " ";
    }

    cout << endl <<"unsorted " << endl;
    for (float val : flat_ds2){
        cout << val << " ";
    }
    cout << endl << "sorted" << endl;
    quicksort(flat_ds2, flat_ds2.size());
    for (float val : flat_ds2){
        cout << val << " ";
    }

    // RESHAPING VECTORS

    //ds1

    ds1.clear();
    
    int count = 0;

    for (int i = 0; i < rowsize1; i++) //depth/rows
    {
        vector<float> row; // temp row variable, will be appended per for loop
        for (int j = 0; j < columnsize1; j++)  //width/columns    
        {
        row.push_back(flat_ds1[count++]);
        }
        ds1.push_back(row);
    }

    //ds2

    ds2.clear();

    count = 0;

    for (int i = 0; i < rowsize2; i++) //depth/rows
    {
        vector<float> row; // temp row variable, will be appended per for loop
        for (int j = 0; j < columnsize2; j++)  //width/columns    
        {
        row.push_back(flat_ds2[count++]);
        }
        ds2.push_back(row);
    }

    cout << endl << "ds1 sorted" << endl;

    for (int i = 0; i < rowsize1; i++) {
        for (int j = 0; j < columnsize1; j++) {
            cout << ds1[i][j] << " ";
        }
        cout << endl;
    }

    // ds1 central tendencies

    cout << endl << "ds2" << endl;

    for (int i = 0; i < rowsize2; i++) {
        for (int j = 0; j < columnsize2; j++) {
            cout << ds2[i][j] << " ";
        }
        cout << endl;
    }

    // ds2 central tendencies
    
    
    
    

}

