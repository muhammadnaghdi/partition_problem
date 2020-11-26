#include <stdlib.h>

partition *partition_create(int max_size) {
	partition *p = (partition *) malloc(sizeof(partition));
	p->max_size = max_size;
	p->size = 0;
	p->sum = 0;
	p->elements = malloc(max_size * sizeof(int));
	return p;
}

void partition_add_element(partition *p, int e) {
	p->elements[p->size++] = e;
	p->sum += e;
}

void partition_remove_last_element(partition *p) {
	p->sum -= p->elements[--p->size];
}

void partition_print(partition *p) {
	printf("partition:\nsize: %d\nsum: %d\nelements: ", p->size, p->sum);
	for (int i = 0; i < p->size; ++i) {
		printf("%d ", p->elements[i]);
	}
	puts("");
}

void partition_print_backward(partition *p) {
	printf("partition:\nsize: %d\nsum: %d\nelements: ", p->size, p->sum);
	for (int i = p->size - 1; i >=0; --i) {
		printf("%d ", p->elements[i]);
	}
	puts("");
}

void partition_free(partition *p) {
	free(p->elements);
	free(p);
}
