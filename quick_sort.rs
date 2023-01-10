use std::time::Instant;
fn main() {
    println!("Rust");

    let mut data = Box::new([0i32; 3000000]);

    for attempt in 0..10 {
        for i in 0..data.len() {
            data[i] = -(i as i32);
        }

        let start = Instant::now();
        let len = data.len();
        quickSort(&mut data[..], 0, len-1);
        let duration = start.elapsed();

        for i in 0..(data.len() - 1) {
            if data[i] > data[i+1] {
                eprintln!("sort failed\n");
                break;
            }
        }

        println!("took {}ms", duration.as_millis());
    }
}

  fn quickSort(array: &mut [i32], left: usize, right: usize) {
          if left < right {
                let pivot = mePartition(array, left, right);
                quickSort(array, left, pivot - 1);
                quickSort(array, pivot + 1, right);
          }
  }

  fn mePartition(arr: &mut [i32], left: usize, right: usize) -> usize {
        let pivot = median(arr, left, right);
        let mut leftIndex = left - 1;
        let mut rightIndex = right;
        loop {
            loop {
                leftIndex += 1;
                if !(arr[leftIndex] < pivot) {
                    break
                }
            }
            loop {
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

  fn median(array: &mut [i32], left: usize, right: usize) -> i32 {
        let mid: usize = (left + right) / 2;
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

  fn swap(array: &mut [i32], i: usize, store: usize) {
      let temp: i32 = array[i];
      array[i] = array[store];
      array[store] = temp;
  }
