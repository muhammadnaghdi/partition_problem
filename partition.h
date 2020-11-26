typedef struct {
	int max_size;
	int size;
	int *elements;
	int sum;
} partition;

partition *partition_create(int max_size);
void partition_add_element(partition *p, int e);
void partition_remove_last_element(partition *p);
void partition_print(partition *p);
void partition_copy(partition *d, partition *s);
void partition_free(partition *p);
