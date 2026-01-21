#include <vector>
#include <iostream>
#include <span>

std::vector<int> sortedMerge(std::span<int> a, std::span<int> b) {
  std::vector<int> output;
  output.reserve(a.size() + b.size());
  int i = 0, j = 0;
  while (i < a.size() && j < b.size()) {
    if (a[i] < b[j]) output.push_back(a[i++]);
    else output.push_back(b[j++]);
  }
  for (; i < a.size(); i++) output.push_back(a[i]);
  for (; j < b.size(); j++) output.push_back(b[j]);

  return output;
}

std::vector<int> mergeSort(std::span<int> arr) {
  if (arr.size() == 0) return {};
  if (arr.size() == 1) return {arr[0]};

  int m = arr.size() / 2;
  int a = m;
  int b;
  if (arr.size() % 2 == 0) b = m;
  else b = m + 1;
  
  auto x = mergeSort(arr.first(a));
  auto y = mergeSort(arr.last(b));

  return sortedMerge(std::span(x), std::span(y));
}

int main() {
  std::vector<int> arr = {2, 4, 3, 1, 5, 0};
  std::span s(arr);

  auto sorted = mergeSort(s);
  for (auto x : sorted) std::cout << x << "\n";
}
