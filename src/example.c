/*********************************************************************************************************
				                                    C R E D I T S

This application uses DISLIN v11.1 plotting library. The DISLIN software is free for non-commercial use.
You can find more information about the project below.

Autor: Helmut Michels
DISLIN Home Page: http://www.dislin.de

**********************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "dislin.h"

int main (){ 
	char *gtit = "TITLE OF GRAPH";
	char text[1000], aux[100];
	char post = ','; 
	float xa, xe, xor, xstep, ya, ye, yor, ystep;
	int ic;
	int i, j, lower = 0, upper = 10000;
	float y[10], x[10];
	strcpy(text, "A[10] = {");
	/*genera 10 numeros aleatorios entre 1 a 10000*/
	srand(time(0));
	for(i = 0;i<10;++i){
	  y[i] = (float)(rand() % (upper - lower + 1)) + lower;
	  x[i] = (float)i;
	  if(i==(10-1))
	  	post = ' ';
	  sprintf(aux, " %d%c", (int)y[i], post);
	  strcat(text, aux);
	}
	strcat(text, "}");

	/*empieza a configurar el histograma*/
	setpag("hp4l");	//page of 2718*1900 points
	metafl("cons");	//metafile format, cons = graphics output on the screen
	scrmod("revers");	//color background
	disini();	//initializes DISLIN
	complx();	//font
	pagera();	//plots a border around the page
	incmrk(1);	//selects line or symbol mode for curve()
	titlin(gtit, 2); //plots a title over an axis system
	axslen(2300, 1000); //length of the graph
	axspos(300, 1500); //position on the page
	messag(text, 300, 1700);	//plots text
	setgrf("labels", "labels", "line", "line"); //removes a part of an axis or a complete axis from an axis system
	ic = intrgb(0.95, 0.95, 0.95);	//creates an explicit colour value from RGB coordinates
	axsbgd(ic);	//defines a background colour for axis systems
	polcrv("LINEAR"); //defines an interpolation method used by curve() to connect points

	hsymbl(25);	//defines the size of symbols
	marker(21); //select the symbols used to plot points

	xa = 0.0;	//lower limit of x-axis
	xe = sizeof(x)/sizeof(float)-1; 	//upper limit of x-axis
	xor = 0.0;	// first x-axis label
	xstep = (sizeof(x)/sizeof(float))/10;	//step between labels in x-axis
	ya = 0.0;	//lower limit of y-axis
	ye = (float)upper;	//upper limit of y-axis
	yor = 0.0;	//first y-axis label
	ystep = (float)(upper/10);	//step between labels in y-axis
	graf(xa, xe, xor, xstep, ya, ye, yor, ystep); //plots a two-dimensional polar axis system
	grid(1, 1); //numbers of grid lines between labels

	thkcrv(3.0); //defines the thickness of curves
	color("red"); //defines the colours used for plotting text and lines
	curve(x, y, sizeof(x)/sizeof(float)); //connects data points with lines or plots them with symbols
	
	color("fore");
	height(50);	//defines the character heigh
	title();	//This routine plots a title over an axis system

	endgrf();	//terminates an axis system and sets the level to 1

	disfin();	//terminates DISLIN
	
	return 0;
}
