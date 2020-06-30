#include <stdio.h>

int main()
{
	const char *f_r = "untitled.obj", *f_w = "vertices.txt";
	FILE *fp_r, *fp_w;
	int n;

	fp_r = fopen(f_r, "r");
	fp_w = fopen(f_w, "w");
	
	while((n = getc(fp_r)) != EOF) {		
		if((n == 'v') && ((n = getc(fp_r)) == ' ')) {
			while((n = getc(fp_r)) != '\n') {
				putc(n, fp_w);
			}
			
			putc('\n', fp_w);
		}
	}

	fclose(fp_r);
	fclose(fp_w);
	
	return 0;
}