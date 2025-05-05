#include <iostream>
#include <vector>
using namespace std;

int main(){
    // vector<int> x = {1, 2, 1};
    // vector<int> h = {3, 2, 1}; // same as h'
    // vector<int> y(x.size() + h.size() - 1, 0); // output size is 5

    // for (int i = 0; i < y.size(); i++) {
    //     for (int j = 0; j < h.size(); j++) {
    //         if (i - j >= 0 && i - j < x.size()) { //checks if index i - j is a valid index into vector x
    //             y[i] += x[i - j] * h[j]; // At output position i, add the product of each filter value h[j] and the aligned input value x[i - j], if it's within bounds.
    //         }
    //     }
    // }

    // for (int num : y){
    //     cout << num << endl;
    // }

    // Input matrix (image)
    vector<vector<int>> input = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Kernel (filter) — not flipped for cross-correlation
    vector<vector<int>> kernel = {
        {1, 0},
        {0, -1}
    };

    int inputRows = input.size();
    int inputCols = input[0].size();
    int kernelRows = kernel.size();
    int kernelCols = kernel[0].size();

    int outputRows = inputRows - kernelRows + 1;
    int outputCols = inputCols - kernelCols + 1;

    // Output matrix filled with 0s
    vector<vector<int>> output(outputRows, vector<int>(outputCols, 0));

    // Cross-correlation operation
    for (int i = 0; i < outputRows; i++) {
        for (int j = 0; j < outputCols; j++) {
            int sum = 0;
            for (int m = 0; m < kernelRows; m++) {
                for (int n = 0; n < kernelCols; n++) {
                    sum += input[i + m][j + n] * kernel[m][n];
                }
            }
            output[i][j] = sum;
        }
    }

    // Print result
    cout << "2D Cross-Correlation Output:" << endl;
    for (const auto& row : output) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}




