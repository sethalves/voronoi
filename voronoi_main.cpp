/*
* The author of this software is Shane O'Sullivan.
* Permission to use, copy, modify, and distribute this software for any
* purpose without fee is hereby granted, provided that this entire notice
* is included in all copies of any software which is or includes a copy
* or modification of this software and in all copies of the supporting
* documentation for such software.
* THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
* WARRANTY.  IN PARTICULAR, NEITHER THE AUTHORS NOR AT&T MAKE ANY
* REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
* OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <malloc.h>
#include <string>
#include <iostream>
#include <sstream>
#include "VoronoiDiagramGenerator.h"


int main(int argc, char **argv)
{
	if (argc != 5) {
		fprintf(stderr, "usage: %s low-x low-y high-x high-y\n", argv[0]);
		exit(1);
	}

	float xLow = atof(argv[1]);
	float yLow = atof(argv[2]);
	float xHigh = atof(argv[3]);
	float yHigh = atof(argv[4]);

	Points points;
	std::string line;
	while (std::getline(std::cin, line))
	{
		std::istringstream sstream(line);
		float x, y;
		sstream >> x >> y;
		Point p {x, y};
		points.push_back(p);
	}

	VoronoiDiagramGenerator vdg;
	vdg.generateVoronoi(points, xLow, xHigh, yLow, yHigh, 3);

	vdg.resetIterator();

	float x1, y1, x2, y2;

	while (vdg.getNext(x1, y1, x2, y2))
	{
		printf("%f %f %f %f\n", x1, y1, x2, y2);
	}

	return 0;
}
