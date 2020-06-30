#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SPEED 1
#define SENS 0.03
#define MAPSIZE 16
#define MAXVERTS 8

int forward, left, backward, right;

void object();
void ground();
void map();