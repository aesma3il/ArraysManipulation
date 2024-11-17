

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For accumulate
#include <set>     // For set operations

using namespace std;

// Function prototypes
void createArray(vector<int>& arr);
void accessElement(const vector<int>& arr);
void updateElement(vector<int>& arr);
void addElement(vector<int>& arr);
void removeElement(vector<int>& arr);
void checkLength(const vector<int>& arr);
void iterateArray(const vector<int>& arr);
void reverseArray(vector<int>& arr);
void enumerateArray(const vector<int>& arr);
void findElement(const vector<int>& arr);
void findIndex(const vector<int>& arr);
void checkExistence(const vector<int>& arr);
void sortArrayAscending(vector<int>& arr);
void sortArrayDescending(vector<int>& arr);
void customSortArray(vector<int>& arr);
void filterArray(vector<int>& arr);
void sumElements(const vector<int>& arr);
void findMax(const vector<int>& arr);
void findMin(const vector<int>& arr);
void calculateAverage(const vector<int>& arr);
void mapElements(vector<int>& arr);
void unionArrays(const vector<int>& arr1, const vector<int>& arr2);
void intersectionArrays(const vector<int>& arr1, const vector<int>& arr2);
void differenceArrays(const vector<int>& arr1, const vector<int>& arr2);
void uniqueElements(vector<int>& arr);
void shallowCopy(const vector<int>& arr);
void deepCopy(const vector<int>& arr);

int main() {
    vector<int> arr;
    int choice;

    while (true) {
        cout << "\nChoose an operation (1-30, or 0 to exit):\n";
        cout << "1. Create array\n2. Access element\n3. Update element\n4. Add element\n5. Remove element\n";
        cout << "6. Check length\n7. Iterate array\n8. Reverse array\n9. Enumerate array\n10. Find element\n";
        cout << "11. Find index\n12. Check existence\n13. Sort ascending\n14. Sort descending\n15. Custom sort\n";
        cout << "16. Filter elements\n17. Sum elements\n18. Find max\n19. Find min\n20. Calculate average\n";
        cout << "21. Map elements\n22. Union arrays\n23. Intersection arrays\n24. Difference arrays\n25. Unique elements\n";
        cout << "26. Shallow copy\n27. Deep copy\n0. Exit\n";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1: createArray(arr); break;
        case 2: accessElement(arr); break;
        case 3: updateElement(arr); break;
        case 4: addElement(arr); break;
        case 5: removeElement(arr); break;
        case 6: checkLength(arr); break;
        case 7: iterateArray(arr); break;
        case 8: reverseArray(arr); break;
        case 9: enumerateArray(arr); break;
        case 10: findElement(arr); break;
        case 11: findIndex(arr); break;
        case 12: checkExistence(arr); break;
        case 13: sortArrayAscending(arr); break;
        case 14: sortArrayDescending(arr); break;
        case 15: customSortArray(arr); break;
        case 16: filterArray(arr); break;
        case 17: sumElements(arr); break;
        case 18: findMax(arr); break;
        case 19: findMin(arr); break;
        case 20: calculateAverage(arr); break;
        case 21: mapElements(arr); break;
        case 22: {
            vector<int> arr2 = { 7, 8, 9 }; // Example second array
            unionArrays(arr, arr2);
            break;
        }
        case 23: {
            vector<int> arr2 = { 7, 8, 9 }; // Example second array
            intersectionArrays(arr, arr2);
            break;
        }
        case 24: {
            vector<int> arr2 = { 7, 8, 9 }; // Example second array
            differenceArrays(arr, arr2);
            break;
        }
        case 25: uniqueElements(arr); break;
        case 26: shallowCopy(arr); break;
        case 27: deepCopy(arr); break;
        default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

// Function implementations
void createArray(vector<int>& arr) {
    arr = { 1, 2, 3, 4, 5 };
    cout << "Array created: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
}

void accessElement(const vector<int>& arr) {
    int index;
    cout << "Enter index to access: ";
    cin >> index;
    if (index >= 0 && index < arr.size()) {
        cout << "Element at index " << index << ": " << arr[index] << endl;
    }
    else {
        cout << "Index out of range.\n";
    }
}

void updateElement(vector<int>& arr) {
    int index, value;
    cout << "Enter index and new value: ";
    cin >> index >> value;
    if (index >= 0 && index < arr.size()) {
        arr[index] = value;
        cout << "Updated array: ";
        for (int val : arr) cout << val << " ";
        cout << endl;
    }
    else {
        cout << "Index out of range.\n";
    }
}

void addElement(vector<int>& arr) {
    int value;
    cout << "Enter value to add: ";
    cin >> value;
    arr.push_back(value);
    cout << "Updated array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
}

void removeElement(vector<int>& arr) {
    int value;
    cout << "Enter value to remove: ";
    cin >> value;
    arr.erase(remove(arr.begin(), arr.end(), value), arr.end());
    cout << "Updated array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
}

 
void checkLength(const vector<int>& arr) {
    int length = 0;
    for (int val : arr) length++;
    cout << "Length of the array: " << length << endl;
}

void iterateArray(const vector<int>& arr) {
    cout << "Iterating through the array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

void reverseArray(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    cout << "Reversed array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
}

void enumerateArray(const vector<int>& arr) {
    cout << "Enumerating elements (index, value):\n";
    for (int i = 0; i < arr.size(); ++i) {
        cout << "(" << i << ", " << arr[i] << ")\n";
    }
}

void findElement(const vector<int>& arr) {
    int value, found = 0;
    cout << "Enter value to find: ";
    cin >> value;
    for (int val : arr) {
        if (val == value) {
            found = 1;
            break;
        }
    }
    cout << (found ? "Value found in the array.\n" : "Value not found in the array.\n");
}

void findIndex(const vector<int>& arr) {
    int value, index = -1;
    cout << "Enter value to find index: ";
    cin >> value;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == value) {
            index = i;
            break;
        }
    }
    if (index != -1)
        cout << "Index of value " << value << ": " << index << endl;
    else
        cout << "Value " << value << " not found in the array.\n";
}

void checkExistence(const vector<int>& arr) {
    int value, exists = 0;
    cout << "Enter value to check existence: ";
    cin >> value;
    for (int val : arr) {
        if (val == value) {
            exists = 1;
            break;
        }
    }
    cout << (exists ? "Exists\n" : "Does not exist\n");
}

void sortArrayAscending(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        for (int j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Array sorted in ascending order: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
}

void sortArrayDescending(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        for (int j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Array sorted in descending order: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
}

void filterArray(vector<int>& arr) {
    vector<int> filtered;
    for (int val : arr) {
        if (val % 2 == 0) { // Keep only even numbers
            filtered.push_back(val);
        }
    }
    cout << "Filtered array: ";
    for (int val : filtered) cout << val << " ";
    cout << endl;
}

void sumElements(const vector<int>& arr) {
    int sum = 0;
    for (int val : arr) sum += val;
    cout << "Sum of elements: " << sum << endl;
}

void findMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int val : arr) {
        if (val > maxVal) {
            maxVal = val;
        }
    }
    cout << "Maximum element: " << maxVal << endl;
}

void findMin(const vector<int>& arr) {
    int minVal = arr[0];
    for (int val : arr) {
        if (val < minVal) {
            minVal = val;
        }
    }
    cout << "Minimum element: " << minVal << endl;
}

void calculateAverage(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "Array is empty. Cannot calculate average.\n";
        return;
    }
    int sum = 0;
    for (int val : arr) sum += val;
    double average = static_cast<double>(sum) / arr.size();
    cout << "Average of elements: " << average << endl;
}

void mapElements(vector<int>& arr) {
    cout << "Mapping: Squaring each element.\n";
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] *= arr[i];
    }
    cout << "Mapped array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
}

void unionArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> result = arr1;
    for (int val : arr2) {
        bool found = false;
        for (int x : arr1) {
            if (x == val) {
                found = true;
                break;
            }
        }
        if (!found) result.push_back(val);
    }
    cout << "Union of arrays: ";
    for (int val : result) cout << val << " ";
    cout << endl;
}

void intersectionArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> intersection;
    for (int val1 : arr1) {
        for (int val2 : arr2) {
            if (val1 == val2) {
                intersection.push_back(val1);
                break;
            }
        }
    }
    cout << "Intersection of arrays: ";
    for (int val : intersection) cout << val << " ";
    cout << endl;
}

void differenceArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> difference;
    for (int val1 : arr1) {
        bool found = false;
        for (int val2 : arr2) {
            if (val1 == val2) {
                found = true;
                break;
            }
        }
        if (!found) difference.push_back(val1);
    }
    cout << "Difference of arrays: ";
    for (int val : difference) cout << val << " ";
    cout << endl;
}

void uniqueElements(vector<int>& arr) {
    vector<int> unique;
    for (int val : arr) {
        bool found = false;
        for (int x : unique) {
            if (x == val) {
                found = true;
                break;
            }
        }
        if (!found) unique.push_back(val);
    }
    cout << "Unique elements: ";
    for (int val : unique) cout << val << " ";
    cout << endl;
}

void shallowCopy(const vector<int>& arr) {
    vector<int> copy = arr;
    cout << "Shallow copy created. Copy contents: ";
    for (int val : copy) cout << val << " ";
    cout << endl;
}

void deepCopy(const vector<int>& arr) {
    vector<int> copy(arr.begin(), arr.end());
    cout << "Deep copy created. Copy contents: ";
    for (int val : copy) cout << val << " ";
    cout << endl;
}





