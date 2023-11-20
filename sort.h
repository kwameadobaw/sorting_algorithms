#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void swap(int *a, int *b);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
listint_t *create_listint(const int *array, size_t size);
void quicksort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2);
void counting_sort(int *array, size_t size);
int get_max_number(int *array, int size);
void merge_recursive(int *array, size_t size);
void merge_arrays(int *array, size_t left_size, int *right, size_t right_size);
void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void heapify(int *array, size_t size);
void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t start, size_t end, size_t size);
int hoare_partition(int *arr, int low, int high);
void quicksort_recurssive(int *arr, int low, int high);
void quick_sort_hoare(int *array, size_t size);
int getMax(int *array, size_t size);
void countingSort(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);

#endif /* SORT_H */
