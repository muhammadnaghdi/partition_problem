#include <stdlib.h>

void initialize_partition(partition *p, int max_size) {
	p->max_size = max_size;
	p->size = 0;
	p->sum = 0;
	p->elements = malloc(max_size * sizeof(int));
}

partition *create_partition(int max_size) {
	partition *p = (partition *) malloc(sizeof(partition));
	initialize_partition(p, max_size);
	return p;
}

void add_partition_element(partition *p, int e) {
	p->elements[p->size++] = e;
	p->sum += e;
}

void remove_last_partition_element(partition *p) {
	p->sum -= p->elements[--p->size];
}

void print_partition(partition *p) {
	printf("partition:\nsize: %d\nsum: %d\nelements: ", p->size, p->sum);
	for (int i = 0; i < p->size; ++i) {
		printf("%d ", p->elements[i]);
	}
	puts("");
}

void copy_partition_elements(partition *d, partition *s) {
	if(d->max_size < s->size) {
		puts("COPY_OVERFLOW_ERROR");
		return;
	}
	d->size = 0;
	d->sum = 0;
	for (int i = 0; i < s->size; ++i) {
		add_partition_element(d, s->elements[i]);
	}
}

void free_partition(partition *p) {
	free(p->elements);
	free(p);
}
