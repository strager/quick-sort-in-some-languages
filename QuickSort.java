class QuickSort {
    public static void main(String[] args) {
        System.out.println("Java");

        int[] data = new int[3000000];

        for (int attempt = 0; attempt < 10; ++attempt) {
            for (int i = 0; i < data.length; ++i) {
                data[i] = -i;
            }

            long before = System.currentTimeMillis();
            quickSort(data, 0, data.length-1);
            long after = System.currentTimeMillis();

            for (int i = 0; i < data.length - 1; ++i) {
                if (data[i] > data[i+1]) {
                    System.err.println("sort failed");
                    break;
                }
            }

            System.out.println("took " + (after-before) + "ms");
        }
    }

      public static void quickSort(int[] array, int left, int right)
      {
              if (left < right)
              {
                    var pivot = mePartition(array, left, right);
                    quickSort(array, left, pivot - 1);
                    quickSort(array, pivot + 1, right);
              }
      }

      private static int mePartition(int[] arr, int left, int right)
      {
            var pivot = median(arr, left, right);
            var leftIndex = left - 1;
            var rightIndex = right;
            while(true)
            {
                  do ++leftIndex; while (arr[leftIndex] < pivot);
                  do --rightIndex; while (rightIndex > 0 && arr[rightIndex] > pivot);

                  if (leftIndex >= rightIndex)
                  {
                        // indexes crossed
                        break;
                  }
                  else
                  {
                        // just swapped
                        swap(arr, leftIndex, rightIndex);
                  }
            }
            swap(arr, leftIndex, right);
            return leftIndex;
      }

      private static int median(int[] array, int left, int right)
      {
            var mid = (left + right) / 2;
            if (array[right] < array[left])
            {
                  swap(array, left, right);
            }
            if (array[mid] < array[left])
            {
                  swap(array, mid, left);
            }
            if (array[right] < array[mid])
            {
                  swap(array, right, mid);
            }
            swap(array, right, mid);
            return array[right];
      }

      private static void swap(int[] array, int i, int store)
      {
            int temp = array[i];
            array[i] = array[store];
            array[store] = temp;
      }
}
