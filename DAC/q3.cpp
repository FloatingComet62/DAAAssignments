#include <vector>
#include <iostream>

void quickSort(std::vector<int>& arr, int low, int high) {
  if (low >= high) return;

  int mid = (low + high) / 2;
  int pivot = arr[mid];

  int i = low, j = high;

  while (i <= j) {
    while (arr[i] < pivot) i++;
    while (arr[j] > pivot) j--;
    if (i <= j) {
      std::swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }

  quickSort(arr, low, j);
  quickSort(arr, i, high);
}

int main() {
  std::vector<int> arr = {2, 4, 3, 1, 5, 0};
  quickSort(arr, 0, arr.size() - 1);
  for (auto x : arr) {
    std::cout << x << "\n";
  }
}
