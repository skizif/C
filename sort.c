// gcc sort.c -o s

#include <stdio.h>

void sort(int a[], int size)
{	
	int sorted = 0, i = 0, tmp = 0, flag = 1;
	while (!sorted) {
		while (i < (size - 1)) {
			if (a[i] <= a[i+1]) { flag = 0;}
			else { flag = 1; break;}
			i++;
		}
		
		if (flag) { tmp = a[i+1];
		            a[i+1] = a[i];
		            a[i] = tmp;
		            i = 0;
		} else { 
			sorted = 1;
			for (i = 0; i < (size - 1); i++) {
				printf("%d ", a[i]);
			}
		}
	}
}

int main()
{
	int a[] = { 0,2,1,5,8,7,455,567,68,9,4,2,33,8,72,56,85 };
	int size = sizeof(a)/sizeof(a[0]);

	sort(a, size);
	printf("%d\n", a[size-1]);

	return 0;
}
