#include <limits.h>
#include <stdio.h>

int max3(int a, int b, int c) {
  if (a > b) {
    if (a > c) {
      return a;
    }
    return c;
  }
  if (b > c) {
    return b;
  }
  return c;
}
int max2(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int max_sum_around_point(int* arr, int m, int l, int r) {
  int left_side_max_sum = INT_MIN;
  int left_side_sum = 0;
  for (int i = m - 1; i >= l; i--) {
    left_side_sum += arr[i];
    left_side_max_sum = max2(left_side_max_sum, left_side_sum);
  }

  int right_side_max_sum = INT_MIN;
  int right_side_sum = 0;
  for (int i = m + 1; i < r; i++) {
    right_side_sum += arr[i];
    right_side_max_sum = max2(right_side_max_sum, right_side_sum);
  }

  return left_side_max_sum + arr[m] + right_side_max_sum;
}

int max_sum(int* arr, int l, int r) {
  if (l == r) {
    return arr[l];
  }

  int m = (l + r) / 2;
  return max3(
    max_sum(arr, l, m),
    max_sum(arr, m + 1, r),
    max_sum_around_point(arr, m, l, r)
  );
}

int main() {
  int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
  printf("%d\n", max_sum(arr, 0, 7));
}
