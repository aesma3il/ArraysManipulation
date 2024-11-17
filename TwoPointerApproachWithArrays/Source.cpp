#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <numeric>
using namespace std;

// Function Prototypes
void reverseArray();
void findPairWithSum();
void findTripletsWithSum();
void sortColors();
void checkPalindrome();
void mergeTwoSortedArrays();
void removeDuplicates();
void longestSubstringWithoutRepeating();
void containerWithMostWater();
void trappingRainWater();
void findIntersectionOfSortedArrays();
void detectCycleInLinkedList(); // Placeholder: Requires linked list implementation
void findMedianOfTwoSortedArrays();

int main() {
    int choice;
    cout << "Choose a problem to solve using the Two-Pointer Approach:\n";
    cout << "1. Reverse Array\n";
    cout << "2. Find Pair with Sum\n";
    cout << "3. Find Triplets with Sum\n";
    cout << "4. Sort Array of 0s, 1s, and 2s\n";
    cout << "5. Check Palindrome\n";
    cout << "6. Merge Two Sorted Arrays\n";
    cout << "7. Remove Duplicates\n";
    cout << "8. Longest Substring without Repeating Characters\n";
    cout << "9. Container with Most Water\n";
    cout << "10. Trapping Rain Water\n";
    cout << "11. Intersection of Two Sorted Arrays\n";
    cout << "12. Detect Cycle in Linked List (Not implemented)\n";
    cout << "13. Find Median of Two Sorted Arrays\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: reverseArray(); break;
    case 2: findPairWithSum(); break;
    case 3: findTripletsWithSum(); break;
    case 4: sortColors(); break;
    case 5: checkPalindrome(); break;
    case 6: mergeTwoSortedArrays(); break;
    case 7: removeDuplicates(); break;
    case 8: longestSubstringWithoutRepeating(); break;
    case 9: containerWithMostWater(); break;
    case 10: trappingRainWater(); break;
    case 11: findIntersectionOfSortedArrays(); break;
    case 12: cout << "Cycle detection in Linked List is not implemented.\n"; break;
    case 13: findMedianOfTwoSortedArrays(); break;
    default: cout << "Invalid choice!\n"; break;
    }

    return 0;
}

// Function Implementations

void reverseArray() {
    vector<int> arr = { 1, 2, 3, 4, 5 };
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    cout << "Reversed Array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
}

void findPairWithSum() {
    vector<int> arr = { 2, 7, 11, 15 };
    int target = 9;
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            cout << "Pair: " << arr[left] << ", " << arr[right] << endl;
            return;
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    cout << "No Pair Found\n";
}

void findTripletsWithSum() {
    vector<int> arr = { -1, 0, 1, 2, -1, -4 };
    sort(arr.begin(), arr.end());
    vector<vector<int>> triplets;
    for (int i = 0; i < arr.size() - 2; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        int left = i + 1, right = arr.size() - 1;
        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == 0) {
                triplets.push_back({ arr[i], arr[left], arr[right] });
                while (left < right && arr[left] == arr[left + 1]) left++;
                while (left < right && arr[right] == arr[right - 1]) right--;
                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    cout << "Triplets: ";
    for (auto triplet : triplets) {
        cout << "[";
        for (int val : triplet) cout << val << " ";
        cout << "]";
    }
    cout << endl;
}

void sortColors() {
    vector<int> arr = { 2, 0, 2, 1, 1, 0 };
    int left = 0, right = arr.size() - 1, mid = 0;
    while (mid <= right) {
        if (arr[mid] == 0) {
            swap(arr[left], arr[mid]);
            left++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[right]);
            right--;
        }
    }
    cout << "Sorted Colors: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
}

void checkPalindrome() {
    string s = "abba";
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            cout << "Not a Palindrome\n";
            return;
        }
        left++;
        right--;
    }
    cout << "Is a Palindrome\n";
}

void mergeTwoSortedArrays() {
    vector<int> arr1 = { 1, 3, 5 };
    vector<int> arr2 = { 2, 4, 6 };
    vector<int> merged;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i++]);
        }
        else {
            merged.push_back(arr2[j++]);
        }
    }
    while (i < arr1.size()) merged.push_back(arr1[i++]);
    while (j < arr2.size()) merged.push_back(arr2[j++]);
    cout << "Merged Array: ";
    for (int val : merged) cout << val << " ";
    cout << endl;
}

void removeDuplicates() {
    vector<int> arr = { 1, 1, 2, 2, 3 };
    int left = 0;
    for (int right = 1; right < arr.size(); right++) {
        if (arr[right] != arr[left]) {
            left++;
            arr[left] = arr[right];
        }
    }
    cout << "Array without Duplicates: ";
    for (int i = 0; i <= left; i++) cout << arr[i] << " ";
    cout << endl;
}

void longestSubstringWithoutRepeating() {
    string s = "abcabcbb";
    unordered_set<char> set;
    int left = 0, maxLength = 0;
    for (int right = 0; right < s.size(); right++) {
        while (set.count(s[right])) {
            set.erase(s[left++]);
        }
        set.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }
    cout << "Longest Substring Length: " << maxLength << endl;
}

void containerWithMostWater() {
    vector<int> heights = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    int left = 0, right = heights.size() - 1;
    int maxArea = 0;

    while (left < right) {
        int width = right - left;
        int area = min(heights[left], heights[right]) * width;
        maxArea = max(maxArea, area);

        if (heights[left] < heights[right]) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << "Maximum Water Container Area: " << maxArea << endl;
}

void trappingRainWater() {
    vector<int> heights = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int left = 0, right = heights.size() - 1;
    int leftMax = 0, rightMax = 0;
    int totalWater = 0;

    while (left < right) {
        if (heights[left] < heights[right]) {
            if (heights[left] >= leftMax) {
                leftMax = heights[left];
            }
            else {
                totalWater += leftMax - heights[left];
            }
            left++;
        }
        else {
            if (heights[right] >= rightMax) {
                rightMax = heights[right];
            }
            else {
                totalWater += rightMax - heights[right];
            }
            right--;
        }
    }

    cout << "Total Trapped Rain Water: " << totalWater << endl;
}

void findIntersectionOfSortedArrays() {
    vector<int> arr1 = { 1, 2, 2, 3, 4 };
    vector<int> arr2 = { 2, 2, 3, 5 };
    vector<int> intersection;

    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] == arr2[j]) {
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    cout << "Intersection: ";
    for (int val : intersection) cout << val << " ";
    cout << endl;
}

void detectCycleInLinkedList() {
    cout << "Detect Cycle in Linked List: Placeholder implementation." << endl;
    // This requires a linked list structure with fast and slow pointer detection.
}

void findMedianOfTwoSortedArrays() {
    vector<int> arr1 = { 1, 3 };
    vector<int> arr2 = { 2 };
    int totalSize = arr1.size() + arr2.size();
    int medianPos = totalSize / 2;
    bool isOdd = totalSize % 2 != 0;

    int i = 0, j = 0, count = 0;
    int prev = 0, current = 0;

    while (count <= medianPos) {
        prev = current;
        if (i < arr1.size() && (j >= arr2.size() || arr1[i] <= arr2[j])) {
            current = arr1[i++];
        }
        else {
            current = arr2[j++];
        }
        count++;
    }

    if (isOdd) {
        cout << "Median: " << current << endl;
    }
    else {
        cout << "Median: " << (prev + current) / 2.0 << endl;
    }
}
