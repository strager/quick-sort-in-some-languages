all: quick_sort QuickSort.class quick-sort-cpp quick-sort-cpp-clang

QuickSort.class: QuickSort.java
	javac QuickSort.java

quick_sort: quick_sort.rs
	rustc -Copt-level=3 quick_sort.rs

quick-sort-cpp: quick-sort.cpp
	g++ -g -O3 quick-sort.cpp -o quick-sort-cpp

quick-sort-cpp-clang: quick-sort.cpp
	clang++ -g -O2 quick-sort.cpp -o quick-sort-cpp-clang

run: quick_sort QuickSort.class quick-sort-cpp quick-sort-cpp-clang
	./quick-sort-cpp ; sleep 1
	./quick-sort-cpp-clang ; sleep 1
	./quick_sort ; sleep 1
	java QuickSort; sleep 1
	node quick-sort.js ; sleep 1
	go run quick_sort.go
