void solve(partition *p) {
	int size = p->size;
	partition *forward = create_partition(size);
	partition *backward = create_partition(size);
	copy_partition_elements(forward, p);
	for (int i = size - 1; i >= 1; --i) {
		if(forward->sum == backward->sum) {
			print_partition(forward);
			puts("");
			print_partition(backward);
			free_partition(forward);
			free_partition(backward);
			return;
		}
		add_partition_element(backward, forward->elements[i]);
		remove_last_partition_element(forward);
	}
	puts("NOT_FOUND");
	return;
}
