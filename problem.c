void solve(partition *p) {
	partition *forward = p;
	int size = p->size;
	partition *backward = partition_create(size);
	for (int i = size - 1; i >= 0; --i) {
		if(forward->sum == backward->sum) {
			partition_print(forward);
			partition_print_backward(backward);
			partition_free(forward);
			partition_free(backward);
			return;
		}
		partition_add_element(backward, forward->elements[i]);
		partition_remove_last_element(forward);
	}
	puts("NOT_FOUND");
	partition_free(forward);
	partition_free(backward);
	return;
}
