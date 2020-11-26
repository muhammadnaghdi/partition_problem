#include <stdio.h>
#include <stdlib.h>
#include "partition.h"
#include "partition.c"
#include "problem.h"
#include "problem.c"

int main() {
	int size;
	printf("%s", "Enter a size: ");
	scanf("%d", &size);
	partition *p = create_partition(size);
	int in;
	for (int i = 0; i < size; ++i) {
		printf("Enter element index %d: ", i);
		scanf("%d", &in);
		add_partition_element(p, in);
	}
	solve(p);
	free_partition(p);
	return 0;
}
