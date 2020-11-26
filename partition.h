typedef struct {
	int max_size;
	int size;
	int *elements;
	int sum;
} partition;

void initialize_partition(partition *p, int max_size);
partition *create_partition(int max_size);
void add_partition_element(partition *p, int e);
void remove_last_partition_element(partition *p);
void print_partition(partition *p);
void copy_partition(partition *d, partition *s);
void free_partition(partition *p);
