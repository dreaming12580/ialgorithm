






void Reverse(int* array, int p, int q) {
  for (; p < q; p++, q--) {
    int temp = array[q];
    array[q] = array[p];
    array[p] = temp;
  }
}

void RightShift(int* array, int n, int k) {
  k %= n;
  Reverse(array, 0, n - k - 1);
  Reverse(array, n - k - 1, n - 1);
  Reverse(array, 0, n - 1);
}











