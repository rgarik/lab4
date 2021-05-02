#include <cmath>
#include <iostream>

#include "main.h"

#define PI 3.14159265

void fillEdges(Edge *edgs) {

    int i, j, n = 0;

    for (i = 0; i < COL * ( ROW - 1 ); i += COL) {
        for (j = 0; j < COL -1; j++ ) {
            edgs[n].p1 = i + j;
            edgs[n].p2 = j + 1 + i;
            n++;
            edgs[n].p1 = i + j;
            edgs[n].p2 = j + COL + i;
            n++;
        }
        edgs[n].p1 = i + j;
        edgs[n].p2 = j + COL + i;
        n++;
    }

    for (; i < COL * ROW -1; i++) {
        edgs[n].p1 = i;
        edgs[n].p2 = i + 1;
        n++;
    }
}

void getTranslation(Point3D *s_points, Point3D *d_points, int dx, int dy, int dz) {
    for( int i = 0; i < COL * ROW; i++ ) {
        d_points[i].x = s_points[i].x + dx;
        d_points[i].y = s_points[i].y + dy;
        d_points[i].z = s_points[i].z + dz;
    }
}

void getScale(Point3D *s_points, Point3D *d_points, int sx, int sy, int sz) {
    for( int i = 0; i < COL * ROW; i++ ) {
        d_points[i].x = s_points[i].x * sx;
        d_points[i].y = s_points[i].y * sy;
        d_points[i].z = s_points[i].z * sz;
    }
}

void getRotationX(Point3D *s_points, Point3D *d_points, int angle) {
    double angleRad = PI / 180 * angle;
    for( int i = 0; i < COL * ROW; i++ ) {
        d_points[i].x = s_points[i].x;
        d_points[i].y = s_points[i].y * cos(angleRad) - s_points[i].z * sin(angleRad);
        d_points[i].z = s_points[i].y * sin(angleRad) + s_points[i].z * cos(angleRad);
    }
}

void getRotationY(Point3D *s_points, Point3D *d_points, int angle) {
    double angleRad = PI / 180 * angle;
    for( int i = 0; i < COL * ROW; i++ ) {
        d_points[i].x = s_points[i].x * cos(angleRad) + s_points[i].z * sin(angleRad);
        d_points[i].y = s_points[i].y;
        d_points[i].z = s_points[i].y * sin(angleRad) + s_points[i].z * cos(angleRad);
    }
}

void getRotationZ(Point3D *s_points, Point3D *d_points, int angle) {
    double angleRad = PI / 180 * angle;
    for( int i = 0; i < COL * ROW; i++ ) {
        d_points[i].x = s_points[i].x * cos(angleRad) - s_points[i].y * sin(angleRad);
        d_points[i].y = s_points[i].x * sin(angleRad) + s_points[i].y * cos(angleRad);
        d_points[i].z = s_points[i].z;
    }
}

void screenProection(Point3D *tP, Point2D *sP, int z, int sWidth, int sHeight) {
    double delta;
    int x, y;

    for( int i = 0; i < COL * ROW; i++ ) {
        delta  =  z / tP[i].z;
        x = round(sWidth / 2 + delta * tP[i].x);
        y = round(sHeight / 2 - delta * tP[i].y);

//        std::cout << "tP[i].z = " << tP[i].z << std::endl;
        std::cout << "x=" << x << " y=" << y << std::endl;

        if (x >= 0 && y >= 0 && x <= sWidth && y <= sHeight) {
            sP[i].x = x;
            sP[i].y = y;
        } else {
            sP[i].x = 0;
            sP[i].y = 0;
        }
    }
}
