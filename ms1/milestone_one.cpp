#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
/*
td list:
CENTRAL TENDENCY IMPLEMENT ON 1D
*/

// central tendency functions

float mean1d(vector<float>&vec){
    float sum = 0;
    for (float num : vec){
        sum += num;
    }

    float mean1d = (sum) / vec.size();
    return mean1d;
}

float median1d(vector<float>&vec){ //must be used with sorted list
    int length = vec.size();
    if (length % 2 == 0){
        return ((vec[vec.size()/2]+vec[(vec.size()/2)-1])/2);

    }
    else{
        int middle = (vec.size()/2);
        return vec[middle];
        
    }
}

vector<float> mode1d(vector<float>& vec) //this function returns a vector containing the modes

{
    vector<float> modes;
    int maxCount = 0;

    for (int i = 0; i < vec.size(); i++) {
        int count = 0;

        for (int j = 0; j < vec.size(); j++) {
            if (vec[j] == vec[i]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            modes.clear();         // found a new max, reset modes
            modes.push_back(vec[i]);
        } else if (count == maxCount) {
            bool alreadyAdded = false;
            for (float m : modes) {
                if (m == vec[i]) {
                    alreadyAdded = true;
                    break;
                }
            }
            if (!alreadyAdded) {
                modes.push_back(vec[i]);
            }
        }
    }

    if (maxCount == 1) {
        return {}; // no mode
    }

    return modes;
}

// quicksort function

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

    // ds1 central tendencies
    float ds1_mean = mean1d(ds1);
    float ds1_median = median1d(ds1);
    vector<float> ds1_mode = mode1d(ds1); 

    // printing ds1 central tendencies
    cout << endl << endl << "DS1 Central Tendencies" << endl;
    cout << endl << "Mean -- " << ds1_mean << endl;
    cout << "Median -- " << ds1_median << endl;
        // mode conditional
        if (ds1_mode.empty()){
            cout << "No mode for ds1" << endl;
        }
        else{
            cout << "Mode(s) for ds1: ";
        for (float val : ds1_mode) 
        {
        cout << val << " ";
        }
        cout << endl;
        }

    cout << endl;

    cout << "Second dataset:" << endl;
    for (float num : ds2) {
        cout << num << " ";
    }

        // ds2 central tendencies
    float ds2_mean = mean1d(ds2);
    float ds2_median = median1d(ds2);
    vector<float> ds2_mode = mode1d(ds2); 

    // printing ds2 central tendencies
    cout << endl << endl << "DS2 Central Tendencies" << endl;
    cout << endl << "Mean -- " << ds2_mean << endl;
    cout << "Median -- " << ds2_median << endl;
        // mode conditional
        if (ds2_mode.empty()){
            cout << "No mode for ds2" << endl;
        }
        else{
            cout << "Mode(s) for ds2: ";
        for (float val : ds2_mode) 
        {
        cout << val << " ";
        }
        cout << endl;
        }

    cout << endl;

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
        
        cout << "Printing Dataset 1 ... (unsorted) " << endl;

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

    // --- SORTING 2D DATASETS ---
    /*
    need: per ds
    1. column and row size
    2. flat dataset
    3. quicksort flattened list
    4. reshape dataset
    5. print central tendencies
    a. of entire dataset and of each row
    */
    
    // DS1
    vector<float> flat_ds1;
    for (int i = 0; i < rowsize1; i++){
        for (int j = 0; j < columnsize1; j++){
            flat_ds1.push_back(ds1[i][j]);
        }
    }
        // sort flat ds1
        quicksort(flat_ds1, flat_ds1.size());

    // DS2
    vector<float> flat_ds2;
    for (int i = 0; i < rowsize2; i++){
        for (int j = 0; j < columnsize2; j++){
            flat_ds2.push_back(ds2[i][j]);
        }
    }
        // sort flat ds2
        quicksort(flat_ds2, flat_ds2.size());

    // RESHAPING DATASETS

    // ds1
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

    // printing 2d datasets:

    system("cls");

    cout << "2D" << endl;
    cout << "Dataset 1 (sorted)..." << endl << endl;

    for (int i = 0; i < rowsize1; i++){
        for (int j = 0; j < columnsize1; j++){
            cout << ds1[i][j] << " ";
        }
        cout << endl;
    }

    // dataset 1 central tendencies (per row) + per dataset -- DONE

    for (int i = 0; i < (rowsize1); i++)
    {

    cout << endl << endl << "central tendencies row #" << i + 1 << endl;
    vector<float> row = ds1[i];
    float ds1_row_mean = mean1d(row);
    float ds1_row_median = median1d(row);
    vector<float> ds1_row_mode = mode1d(row);

    cout << "row # " << i + 1 << " mean: " << ds1_row_mean << " | median: " << ds1_row_median << " | ";

    //mode conditional print
    if (ds1_row_mode.empty()){
        cout << "No mode for row # " << i + 1;
    }
    else{
        cout << "mode: ";
    for (float val : ds1_row_mode) 
    {
    cout << val << " ";

    /*cout << endl << endl << "Dataset 1 Overall Central Tendencies ()";
    float ds1_flat_mean = mean1d(flat_ds1);
    float ds1_flat_median = median1d(flat_ds1);
    vector<float> ds1_flat_mode = mode1d(flat_ds1);
    cout << endl << "mean: " << ds1_flat_mean << " | median: " << ds1_flat_median << " | ";
    if (ds1_flat_mode.empty()){
        cout << "no mode ";
    }
    else{
        cout << "mode: ";
    for (float val : ds1_flat_mode) 
    {
    cout << val << " ";
    }
    cout << endl;*/
    }
    }


    }
    cout << endl << endl << "Dataset 1 Overall Central Tendencies";
    float ds1_flat_mean = mean1d(flat_ds1);
    float ds1_flat_median = median1d(flat_ds1);
    vector<float> ds1_flat_mode = mode1d(flat_ds1);
    cout << endl << "mean: " << ds1_flat_mean << " | median: " << ds1_flat_median << " | ";
    if (ds1_flat_mode.empty()){
        cout << "no mode ";
    }
    else{
        cout << "mode: ";
    for (float val : ds1_flat_mode) 
    {
    cout << val << " ";
    }
    cout << endl;
}


    
    cout << endl << endl << "Dataset 2 (sorted)..." << endl << endl;

    for (int i = 0; i < rowsize2; i++){
        for (int j = 0; j < columnsize2; j++){
            cout << ds2[i][j] << " ";
        }
        cout << endl;
    }

    // dataset 2 central tendencies (per row) & per dataset

    
    for (int i = 0; i < (rowsize2); i++)
    {

    cout << endl << endl << "central tendencies row #" << i + 1 << endl;
    vector<float> row = ds2[i];
    float ds2_row_mean = mean1d(row);
    float ds2_row_median = median1d(row);
    vector<float> ds2_row_mode = mode1d(row);

    cout << "row # " << i + 1 << " mean: " << ds2_row_mean << " | median: " << ds2_row_median << " | ";

    //mode conditional print
    if (ds2_row_mode.empty()){
        cout << "No mode for row # " << i + 1;
    }
    else{
        cout << "mode: ";
    for (float val : ds2_row_mode) 
    {
    cout << val << " ";
    }
    }
    
    /*cout << endl << endl << "Dataset 2 Overall Central Tendencies";
    
    float ds2_flat_mean = mean1d(flat_ds2);
    float ds2_flat_median = median1d(flat_ds2);
    vector<float> ds2_flat_mode = mode1d(flat_ds2);
    cout << endl << "mean: " << ds2_flat_mean << " | median: " << ds2_flat_median << " | ";
    if (ds2_flat_mode.empty()){
        cout << "no mode ";
    }
    else{
        cout << "mode: ";
    for (float val : ds2_flat_mode) 
    {
    cout << val << " ";
    }
    cout << endl;*/
    }

    cout << endl << endl << "Dataset 2 Overall Central Tendencies";
    
    float ds2_flat_mean = mean1d(flat_ds2);
    float ds2_flat_median = median1d(flat_ds2);
    vector<float> ds2_flat_mode = mode1d(flat_ds2);
    cout << endl << "mean: " << ds2_flat_mean << " | median: " << ds2_flat_median << " | ";
    if (ds2_flat_mode.empty()){
        cout << "no mode ";
    }
    else{
        cout << "mode: ";
    for (float val : ds2_flat_mode) 
    {
    cout << val << " ";
    }
    cout << endl;
    





        
}
}
}


