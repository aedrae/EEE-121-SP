#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
/*
td list:
1D: implement quicksort -- quicksort(array, length)
2D: sort function
*/ 

// sort functions

// 1D sort function -- quick sort

void quicksort(vector<float>& vec, int length);
void quicksort_recursion(vector<float>& vec, int low, int high);
int partition(vector<float>& vec, int low, int high);

// int main()
// {
//     vector<float> a = {10.55, 11, 23, 44, 8, 15, 3, 9, 12, 45, 56, 45, 45};
//     int length = a.size(); // this counts the number of elements, not indeces

//     quicksort(a, length);

//     for (int i = 0; i < length; i++){
//         cout << a[i] << " ";
//     }
//     cout << endl << endl;


//     return 0;
      
// }

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



int main() {
string menuoption;

// --- menu ---
    bool valid = false;

    while (valid==false){
        cout << "Please enter the dimension of your dataset ('1D' or '2D'): " << endl;
        cin >> menuoption;

        if (menuoption == "1D"){
            break;
        }
        else if (menuoption == "2D"){
            break;
        }
        else{
            system("cls");
            cout <<"ERROR: " << "'" << menuoption <<"'" << " is an invalid input." << endl;
        }

    }


// 1D implementation
if (menuoption == "1D"){

    // integers for size of the lists
    int size1;
    int size2;



    // 1D datasets
    vector<float> ds1;
    vector<float> ds2;
    float userinput;

// --- first dataset --- //

    cout << endl << "enter the size of dataset 1:";
    cin >> size1; 

    // first dataset inputs
    cout << "dataset 1 inputs (VVV)"<< endl;
    for (int i = 0; i < size1; i++){
        cout << "input #" << i+1 << "... ";
        cin >> userinput;
        ds1.push_back(userinput);
    }


    // ds1 sort
    int ds1_length = ds1.size();
    quicksort(ds1, ds1_length);

    cout << "First dataset:" << endl;
    for (float num : ds1) {
        cout << num << " ";
    }

// --- second dataset --- //

    cout << endl << "enter the size of dataset 2:";
    cin >> size2; 

    // second dataset inputs
    cout << "dataset 2 inputs (VVV)"<< endl;

    // second dataset inputs
    for (int i = 0; i < size2; i++){
        cout << "input #" << i+1 << "... ";
        cin >> userinput;
        ds2.push_back(userinput);
    }

    system("cls");
    // ds2 sort

    int ds2_length = ds2.size();
    quicksort(ds2, ds2_length);

    cout << "1D" << endl;

    cout << "First dataset:" << endl;
    for (float num : ds1) {
        cout << num << " ";
    }

    cout << endl;

    cout << "Second dataset:" << endl;
    for (float num : ds2) {
        cout << num << " ";
    }
}

// 2D implementation
    if (menuoption == "2D"){

        vector<vector<float>> ds1;
        vector<vector<float>> ds2;

        int columnsize1, rowsize1;
        int columnsize2, rowsize2;

        cout << "ds1 width: ";
        cin >> columnsize1;
        cout << endl;

        cout << "ds1 depth: ";
        cin >> rowsize1;
        cout << endl;

        bool constraint_bool = false; //for the constraint that the 2nd ds cannot have fewer columns and rows than the 1st ds
        while (!constraint_bool){
        cout << "ds2 width: ";
        cin >> columnsize2;
        cout << endl;

        cout << "ds2 depth: ";
        cin >> rowsize2;
        cout << endl;
        if (columnsize2 > columnsize1 ||  rowsize2 > rowsize1){
            system("cls");
            cout << "ERROR — Invalid dataset parameters: Dataset 2 cannot have more rows or columns than Dataset 1." << endl;
        }
        else{
            break;
        }

    }

        // note: add constraint^^ -- DONE

        // add to 2D dataset, all this does is redefine 'userinput2d' as many times as there is rows and columns.

        float userinput2d;

        for (int i = 0; i < rowsize1; i++){
            cout << "row #" << i+1 << "..." << endl;
            vector<float> row; //temp variable that will be pushed into the dataset
            for (int j=0; j < columnsize1; j++){
                cout << "column #" << j+1 << " ";
                cin >> userinput2d;
                cout << endl;
                row.push_back(userinput2d);}
            ds1.push_back(row);
        }

        system("cls");
        
        cout << "Printing Dataset 1 ... " << endl;

        for (int i = 0; i < rowsize1; i++){
            for (int j = 0; j < columnsize1; j++){
                cout << ds1[i][j] << " ";
            }
            cout << endl;
        }



        cout << endl << "DATASET 2 ... " << endl;

        for (int i = 0; i < rowsize2; i++){
            cout << "row #" << i+1 << "..." << endl;
            vector<float> row; //temp variable that will be pushed into the dataset
            for (int j=0; j < columnsize2; j++){
                cout << "column #" << j+1 << " ";
                cin >> userinput2d;
                cout << endl;
                row.push_back(userinput2d);}
            ds2.push_back(row);
        }
    // printing 2d datasets:

    system("cls");

    cout << "2D" << endl;
    cout << "Dataset 1 ..." << endl;

    for (int i = 0; i < rowsize1; i++){
        for (int j = 0; j < columnsize1; j++){
            cout << ds1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Dataset 2 ..." << endl;

    for (int i = 0; i < rowsize2; i++){
        for (int j = 0; j < columnsize2; j++){
            cout << ds2[i][j] << " ";
        }
        cout << endl;
    }

        
}
}



