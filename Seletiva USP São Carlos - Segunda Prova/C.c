#include <stdio.h>
#include <string.h>

inline int isRepeated(int num, int num_repeated, int *repeated) {
	int i;
	for (i = 0; i < num_repeated; i++) {
		if (num == repeated[i]) {
			return 1;
		}
	}
	return 0;
}

int main(void) {
	int repeated[10000];
	int num_repeated;
	int t,n,tmp,i,j,count;
	scanf(" %d ", &t);
	for (i = 0; i < t; i++) {
		scanf( " %d ", &n);
		count = 0;
		num_repeated = 0;
		memset(repeated, 0, 10000);
		for (j = 0; j < n; j++) {
			scanf( " %d ", &tmp);
			if (!isRepeated(tmp, num_repeated, repeated)) {
				repeated[num_repeated] = tmp;
				num_repeated++;
				count++;
			}
		}
		printf("%d\n", count);
	}
}