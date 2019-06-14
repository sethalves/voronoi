#
#
#

CXX=clang++
CXXFLAGS=-std=c++11 -g -Wall -pedantic

voronoi: voronoi_main.o VoronoiDiagramGenerator.o
	${CXX} $^ -o $@

clean:
	rm -f *~ voronoi voronoi_main.o VoronoiDiagramGenerator.o
