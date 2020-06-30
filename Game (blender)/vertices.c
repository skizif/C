/* 
gcc vertices.c -o vertices.exe
*/

#include <stdio.h>

#define MAXVERTS 8

int main()
{
	const char *f_r = "vertices.txt", *f_w = "map.c";
	FILE *fp_r, *fp_w;
	int i, j, n;
	float v[MAXVERTS][3];

	fp_r = fopen(f_r, "r");
	fp_w = fopen(f_w, "w");
	
	for(i = 0; i < MAXVERTS; i++) {
		for(j = 0; j < 3; j++) {
			fscanf(fp_r, "%f", &v[i][j]);
		}
	}
	
	fprintf(fp_w, "#include \"game.h\"\n\nvoid map()\n{\n\tground();");
	fprintf(fp_w, "\n\n\tglPushMatrix();\n\n");
	
	// 5 sided polygons only! >:(
	// This is pure cancer
	// I am yandredev
	fprintf(fp_w, "\tglColor3f(0.2, 0.2, 0.2);\n");
	fprintf(fp_w, "\tglBegin(GL_POLYGON);\n");
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[4][0], v[4][1], v[4][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[6][0], v[6][1], v[6][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[7][0], v[7][1], v[7][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[5][0], v[5][1], v[5][2]);
	fprintf(fp_w, "\tglEnd();\n");
	
	fprintf(fp_w, "\tglColor3f(0.3, 0.3, 0.3);\n");
	fprintf(fp_w, "\tglBegin(GL_POLYGON);\n");
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[0][0], v[0][1], v[0][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[4][0], v[4][1], v[4][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[5][0], v[5][1], v[5][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[1][0], v[1][1], v[1][2]);
	fprintf(fp_w, "\tglEnd();\n");
	
	fprintf(fp_w, "\tglColor3f(0.4, 0.4, 0.4);\n");
	fprintf(fp_w, "\tglBegin(GL_POLYGON);\n");
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[0][0], v[0][1], v[0][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[1][0], v[1][1], v[1][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[3][0], v[3][1], v[3][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[2][0], v[2][1], v[2][2]);
	fprintf(fp_w, "\tglEnd();\n");
	
	fprintf(fp_w, "\tglColor3f(0.5, 0.5, 0.5);\n");
	fprintf(fp_w, "\tglBegin(GL_POLYGON);\n");
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[5][0], v[5][1], v[5][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[7][0], v[7][1], v[7][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[3][0], v[3][1], v[3][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[1][0], v[1][1], v[1][2]);
	fprintf(fp_w, "\tglEnd();\n");
	
	fprintf(fp_w, "\tglColor3f(0.6, 0.6, 0.6);\n");
	fprintf(fp_w, "\tglBegin(GL_POLYGON);\n");
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[2][0], v[2][1], v[2][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[3][0], v[3][1], v[3][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[7][0], v[7][1], v[7][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[6][0], v[6][1], v[6][2]);
	fprintf(fp_w, "\tglEnd();\n");
	
	fprintf(fp_w, "\tglColor3f(0.7, 0.7, 0.7);\n");
	fprintf(fp_w, "\tglBegin(GL_POLYGON);\n");
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[0][0], v[0][1], v[0][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[2][0], v[2][1], v[2][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[6][0], v[6][1], v[6][2]);
	fprintf(fp_w, "\tglVertex3f(%f,%f,%f);\n", v[4][0], v[4][1], v[4][2]);
	fprintf(fp_w, "\tglEnd();\n\n\tglPopMatrix();\n}");

	fclose(fp_r);
	fclose(fp_w);
	
	return 0;
}