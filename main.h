#ifndef MAIN_H
#define MAIN_H

#define COL 3
#define ROW 3

struct Point3D {
    double x, y, z;
};

struct Point2D {
    int x, y;
};

struct Edge {
    int p1, p2;
};

void getTranslation(Point3D *, Point3D *, int, int, int);
void getScale(Point3D *, Point3D *, int, int, int);
void getRotationX(Point3D *, Point3D *, int);
void getRotationY(Point3D *, Point3D *, int);
void getRotationZ(Point3D *, Point3D *, int);

void screenProection(Point3D *, Point2D *, int, int, int);

void fillEdges(Edge *);

#endif // MAIN_H
