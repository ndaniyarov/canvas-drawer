#include <iostream>
#include "canvas.h"

using namespace agl;
using namespace std;

void test_line(canvas& drawer, int ax, int ay, int bx, int by, const std::string& savename)
{
   drawer.background(0, 0, 0);
   drawer.begin(LINES);
   drawer.vertex(ax, ay);
   drawer.vertex(bx, by);
   drawer.end();
   drawer.save(savename);
}

int main(int argc, char** argv)
{
   canvas drawer(100, 100);

   //points
   drawer.begin(POINTS);
   drawer.color(254, 127, 156);
   drawer.vertex(50,50);
   drawer.end();

   drawer.begin(POINTS);
   drawer.drawPoint();
   drawer.color(254, 127, 156);
   drawer.vertex(25,50);
   drawer.end();

   drawer.begin(POINTS);
   drawer.drawPoint();
   drawer.color(254, 127, 156);
   drawer.vertex(75,50);
   drawer.end();
   
   drawer.save("point.png");

   drawer.color(255, 255, 255);
   test_line(drawer, 0, 50, 100, 50, "horizontal-line.png");
   test_line(drawer, 50, 0, 50, 100, "vertical-line.png");
   test_line(drawer, 0, 0, 100, 100, "diagonal-line-1.png"); // slope = 1
   test_line(drawer, 25, 10, 75, 25,  "h-lessthan-w-line-1.png"); // slope H < W
   test_line(drawer, 25, 25, 75, 75,  "w-lessthan-h-line-1.png"); // slope W < H
   test_line(drawer, 0, 100, 100, 0, "diagonal-line-2.png"); // slope H < W
   test_line(drawer, 25, 90, 75, 75,  "h-lessthan-w-line-2.png"); // slope H < W
   test_line(drawer, 25, 90, 75, 25,  "w-lessthan-h-line-2.png"); // slope W < H
   // test line interpolation
   drawer.background(0, 0, 0);
   drawer.begin(LINES);
   drawer.color(255, 0, 255);
   drawer.vertex(0, 0);
   drawer.color(0, 255, 255);
   drawer.vertex(100, 100);
   drawer.end();

   drawer.begin(LINES);
   drawer.color(255, 0, 255);
   drawer.vertex(0, 1);
   drawer.color(0, 255, 255);
   drawer.vertex(98, 100);
   drawer.end();
   drawer.save("line-color-interpolation.png");

   drawer.begin(LINES);
   drawer.color(255, 0, 255);
   drawer.vertex(1, 0);
   drawer.color(0, 255, 255);
   drawer.vertex(100, 98);
   drawer.end();
   drawer.save("line-color-interpolation.png");

//outlined triangle
  drawer.background(0, 0, 0);
   drawer.begin(TRIANGLES);
   drawer.filled(false);
   drawer.color(254, 127, 156);
   drawer.vertex(15, 10);
   drawer.vertex(85, 50);
   drawer.vertex(15, 90);
   drawer.end();
   drawer.save("triangle-outlined.png");

//filled triangle
  drawer.background(0, 0, 0);
   drawer.begin(TRIANGLES);
   drawer.filled(true);
   drawer.color(254, 127, 156);
   drawer.vertex(15, 10);
   drawer.vertex(85, 50);
   drawer.vertex(15, 90);
   drawer.end();
   drawer.save("triangle-filled.png");

   // test triangle with interpolation
   drawer.background(0, 0, 0);
   drawer.begin(TRIANGLES);
   drawer.filled(true);
   drawer.color(255, 0, 255);
   drawer.vertex(15, 10);
   drawer.color(0, 255, 255);
   drawer.vertex(85, 50);
   drawer.color(255, 255, 0);
   drawer.vertex(15, 90);
   drawer.end();
   drawer.save("triangle.png");

   // test 2 triangle with interpolation
   drawer.background(0, 0, 0);
   drawer.begin(TRIANGLES);
   drawer.filled(true);
   drawer.color(255, 0, 255);
   drawer.vertex(10, 10);
   drawer.vertex(10, 90);
   drawer.vertex(90, 90);

   drawer.color(255, 255, 0);
   drawer.vertex(90, 90);
   drawer.vertex(90, 10);
   drawer.vertex(10, 10);
   drawer.end();
   drawer.save("quad.png");

   //circle outlined
   drawer.background(0, 0, 0);
   drawer.begin(CIRCLES);
   drawer.color(254, 127, 156);
   drawer.center(50, 50);
   drawer.radius(40);
   drawer.end();
   drawer.save("circleOutline.png");

   //circle filled
   drawer.background(0, 0, 0);
   drawer.begin(CIRCLES);
   drawer.color(254, 127, 156);
   drawer.center(50, 50);
   drawer.radius(40);
   drawer.filled(true);
   drawer.end();
   drawer.save("circleFilled.png");

   //circle gradient
   drawer.background(0, 0, 0);
   drawer.begin(CIRCLES);
   drawer.color(255,255,255);
   drawer.color(254, 127, 156);
   drawer.gradient(true);
   drawer.center(50, 50);
   drawer.radius(40);
   drawer.end();
   drawer.save("circleGradient.png");

   //rectangle outlined
   drawer.background(0,0,0);
   drawer.begin(RECTANGLES);
   drawer.filled(false);
   drawer.color(254, 127, 156);
   drawer.center(50,50);
   drawer.heightRec(60);
   drawer.widthRec(80);
   drawer.end();
   drawer.save("rectangleOutlined.png");

   //rectangle filled
   drawer.background(0,0,0);
   drawer.begin(RECTANGLES);
   drawer.filled(true);
   drawer.color(254, 127, 156);
   drawer.center(50,50);
   drawer.heightRec(60);
   drawer.widthRec(80);
   drawer.end();
   drawer.save("rectangleFilled.png");
   
   return 0;

}
