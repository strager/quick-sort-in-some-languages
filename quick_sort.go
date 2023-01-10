package main

import "fmt"
import "time"

func main() {
    fmt.Println("Go")

    data := make([]int32, 3000000);

    for attempt := 0; attempt < 10; attempt += 1 {
        for i := 0; i < len(data); i += 1 {
            data[i] = -int32(i);
        }

        before := time.Now();
        quickSort(data, 0, len(data)-1);
        duration := time.Since(before);

        for i := 0; i < len(data) - 1; i += 1 {
            if data[i] > data[i+1] {
                fmt.Printf("sort failed\n");
                break;
            }
        }

        fmt.Printf("took %v\n", duration);
    }
}

  func quickSort(array []int32, left int, right int) {
          if left < right {
                pivot := mePartition(array, left, right);
                quickSort(array, left, pivot - 1);
                quickSort(array, pivot + 1, right);
          }
  }

  func mePartition(arr []int32, left int, right int) int {
        pivot := median(arr, left, right);
        leftIndex := left - 1;
        rightIndex := right;
        for {
            for {
                leftIndex += 1;
                if !(arr[leftIndex] < pivot) {
                    break
                }
            }
            for {
                rightIndex -= 1;
                if !(rightIndex > 0 && arr[rightIndex] > pivot) {
                    break
                }
            }

              if leftIndex >= rightIndex {
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

  func median(array []int32, left int, right int) int32 {
        mid := (left + right) / 2;
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

  func swap(array []int32, i int, store int) {
      temp := array[i];
      array[i] = array[store];
      array[store] = temp;
  }
