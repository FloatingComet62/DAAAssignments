#include <stdio.h>

int main() {
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int target = 23;

  int l = 0;
  int r = sizeof(arr) / sizeof(*arr);
  int m;
  while (l <= r) {
    m = (l + r) / 2;
    if (arr[m] == target) {
      break;
    } else if (arr[m] > target) {
      r = m;
    } else {
      l = m;
    }
  }

  if (arr[m] == target) {
    printf("Item found at index %d\n", m);
  } else {
    printf("Item not found\n");
  }

  return 0;
}
