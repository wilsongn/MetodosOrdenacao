all:
	gcc BucketSort.c  MergeSort.c BubbleSort.c InsertionSort.c SelectionSort.c QuickSort.c CountingSort.c RadixSort.c AppServices.c  GeradorDeTestes.c main.c -o main

run:
	./main