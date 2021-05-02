#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//using namespace std;

#include "main.h"

int main()
{
    Point3D origPoints[COL * ROW];
    Point3D transformPoints[COL * ROW];
    Point2D screenPoints[COL * ROW];
    Edge edges[2*(COL-1)*(ROW-1)+COL-1+ROW-1];

    fillEdges(edges);

    std::string line;

    std::ifstream fin("/home/garik/tmp/schools_exams.csv");
    if (!fin) {
        std::cerr << "No file with name: " << std::endl;
        return 1;
    }

/*
 *  Чтение из ВСЕГО файла
 */
//    int i = 0;
//    int n = 0;
//    while(std::getline(fin, line)) {
//        std::stringstream lineStream(line);
//        std::string cell;

//        int j = 0;
//        while(std::getline(lineStream, cell, ',')) {
//            origPoints[n].x = i;
//            origPoints[n].y = j;
//            origPoints[n].z = std::stod(cell);
//            n++;
//            j++;
//        }
//        i++;
//    }

/*
 * Чтение из файла ТОЛЬКО COL на ROW значений
 */

    int n = 0;
    for ( int i = 0; i < COL; i++ ) {
        std::getline(fin, line);
        std::stringstream lineStream(line);
        std::string cell;
        for ( int j = 0; j < ROW; j++ ) {
            std::getline(lineStream, cell, ',');
            origPoints[n].x = i;
            origPoints[n].y = j;
            origPoints[n].z = std::stod(cell);
            n++;
       }
    }

//    for ( int i = 0; i < COL * ROW; i ++ ) {
//        std::cout << "x= " << origPoints[i].x << " y= " << origPoints[i].y << " z= " << origPoints[i].z << std::endl;
//    }

//    return 0;

//    for( int i = 0; i <= 3; i++ ) {
//        std::cout << "x=" << points[i].x << " y=" << points[i].y << " z=" << points[i].z << std::endl;
//    }
    getTranslation(origPoints, transformPoints, 10, 20, 30);
//    getRotationX(origPoints, transformPoints, 1);


//    for( int i = 0; i <= 3; i++ ) {
//        std::cout << "x=" << screeen_points[i].x << " y=" << screeen_points[i].y << " z=" << screeen_points[i].z << std::endl;
//    }

// Координата Z проекционной плоскости
    int zScreen = 100;
// Размер экрана
    int wScreen = 800; // ширина
    int hScreen = 600; // высота

    screenProection(transformPoints, screenPoints, zScreen, wScreen, hScreen);
    for( int i = 0; i <= 2*(COL-1)*(ROW-1)+COL-1+ROW-1; i++ ) {
//      for( int i = 0; i <= 4; i++ ) {
//        if ( screenPoints[edges[i].p1].x > 0 && screenPoints[edges[i].p1].y > 0 &&
//             screenPoints[edges[i].p2].x > 0 && screenPoints[edges[i].p2].y > 0 ) {
            std::cout << "x1=" << screenPoints[edges[i].p1].x << " y1=" << screenPoints[edges[i].p1].y  << " x2=" << screenPoints[edges[i].p2].x << " y2=" << screenPoints[edges[i].p2].y << std::endl;
//        }
    }

    return 0;
}
