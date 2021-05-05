#ifndef heap_h
#define heap_h

void swap(int *a,int *b);
void heapify(int arr[],int root,int len);
void heap_sort(int arr[],int len);

void swap_string(char *a,char *b);
void heapify_char(int root,int size);
void heap_sort_char(int size);

#endif
