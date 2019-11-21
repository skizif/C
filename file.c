#include <stdio.h>

int main()
{
	const char *f_r = "untitled.obj", *f_w = "map.txt";
	FILE *fp_r, *fp_w;
	int n, i;

	fp_r = fopen(f_r, "r");
	fp_w = fopen(f_w, "w");

	if(!fp_r || !fp_w)
		return 1;

	while((n = getc(fp_r)) != EOF)
		if((n == 'v') && ((n = getc(fp_r)) == ' ')) {
			fprintf(fp_w, "glVertex3f(");
				while((n = getc(fp_r)) != '\n') {
					if(n != ' ') {	
						putc(n, fp_w);
					} else {
						fprintf(fp_w, ", ");
					}
				}

			fprintf(fp_w, ");\n");
		}
	
	fclose(fp_r);
	fclose(fp_w);

	return 0;
}
