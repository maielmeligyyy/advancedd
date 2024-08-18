#include <iostream>
#include <vector>

using namespace std;

void rearrange(vector<int>& A, int low, int high, int k) {
    if (low >= high) {
        return;
    }

    int pivot = A[low];
    int left = low;
    int right = high;

    while (left < right) {
        while (left < right && A[right] > k) {
            right--;
        }
        A[left] = A[right];

        while (left < right && A[left] <= k) {
            left++;
        }
        A[right] = A[left];
    }

    A[left] = pivot;

    rearrange(A, low, left - 1, k);
    rearrange(A, left + 1, high, k);
}

int main() {
    vector<int> A = {3, 2, 8, 5, 1, 7, 6, 4};
    int k = 5;

    cout << "Initial array: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    rearrange(A, 0, A.size() - 1, k);

    cout << "Rearranged array around pivot " << k << ": ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;
}
