function main() {
    console.log("JavaScript (typed arrays)");

    let data = new Int32Array(3000000);

    for (let attempt = 0; attempt < 10; ++attempt) {
        for (let i = 0; i < 3000000; ++i) {
            data[i] = -i;
        }

        let before = performance.now();
        quickSort(data, 0, data.length-1);
        let after = performance.now();

        for (let i = 0; i < data.length - 1; ++i) {
            if (data[i] > data[i+1]) {
                console.error("sort failed");
                break;
            }
        }

        console.log("took " + (after-before) + "ms");
    }
}

  function quickSort(array, left, right)
  {
          if (left < right)
          {
                let pivot = mePartition(array, left, right);
                quickSort(array, left, pivot - 1);
                quickSort(array, pivot + 1, right);
          }
  }

  function mePartition(arr, left, right)
  {
        let pivot = median(arr, left, right);
        let leftIndex = left - 1;
        let rightIndex = right;
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

  function median(array, left, right)
  {
        let mid = (left + right) >> 1;
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

  function swap(array, i, store)
  {
        let temp = array[i];
        array[i] = array[store];
        array[store] = temp;
  }

main();
