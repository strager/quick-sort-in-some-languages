#include <stdio.h>
#include <chrono>

  void swap(int * array, size_t i, size_t store) {
      int temp = array[i];
      array[i] = array[store];
      array[store] = temp;
  }

  int median(int * array, size_t left, size_t right) {
        size_t mid = (left + right) / 2;
        if (array[right] < array[left]) {
              swap(array, left, right);
        }
        if (array[mid] < array[left]) {
              swap(array, mid, left);
        }
        if (array[right] < array[mid]) {
              swap(array, right, mid);
        }
        swap(array, right, mid);
        return array[right];
  }

  size_t mePartition(int * arr, size_t left, size_t right) {
        auto pivot = median(arr, left, right);
        auto leftIndex = left - 1;
        auto rightIndex = right;
        for (;;) {
            for (;;) {
                leftIndex += 1;
                if (!(arr[leftIndex] < pivot)) {
                    break;
                }
            }
            for (;;) {
                rightIndex -= 1;
                if (!(rightIndex > 0 && arr[rightIndex] > pivot)) {
                    break;
                }
            }

              if (leftIndex >= rightIndex) {
                    // indexes crossed
                    break;
              } else {
                    // just swapped
                    swap(arr, leftIndex, rightIndex);
              }
        }
        swap(arr, leftIndex, right);
        return leftIndex;
  }

  void quickSort(int * array, size_t left, size_t right) {
          if (left < right) {
                auto pivot = mePartition(array, left, right);
                quickSort(array, left, pivot - 1);
                quickSort(array, pivot + 1, right);
          }
  }

int main() {
    printf("C++\n");

    size_t len = 3000000;
    auto data = new int[len];

    for (int attempt = 0; attempt < 10; ++attempt) {
        for (int i = 0; i < len; ++i) {
            data[i] = -(int)i;
        }

        auto start = std::chrono::steady_clock::now();
        quickSort(data, 0, len-1);
        auto end = std::chrono::steady_clock::now();

        for (int i = 0; i < len - 1; ++i) {
            if (data[i] > data[i+1]) {
                printf("sort failed\n");
                break;
            }
        }

        printf("took %dms\n", (int)std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
    }
}

