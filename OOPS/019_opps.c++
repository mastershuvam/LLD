//File Handling

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ofstream outFile("data.txt"); // file open for writing
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " numbers:\n";
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        outFile << arr[i] << " "; // write to file
    }
    outFile.close(); // close file after writing

    // Now read from file
    ifstream inFile("data.txt");
    vector<int> nums;
    int x;

    while (inFile >> x) { // read all numbers
        nums.push_back(x);
    }
    inFile.close();

    // Sort the numbers
    sort(nums.begin(), nums.end());

    cout << "\nSorted numbers:\n";
    for (int num : nums) {
        cout << num << " ";
    }

    
    ofstream sortedFile("data.txt");
    
    for (int num : nums) {
        sortedFile << num << " ";
    }
    sortedFile.close();

    cout << "\n\nSorted data saved to 'data.txt'\n";

    return 0;
}
