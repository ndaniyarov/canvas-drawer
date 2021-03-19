#include <iostream>
#include "canvas.h"
using namespace std;
using namespace agl;

void drawline(canvas& drawer, int ax, int ay, int bx, int by)
{
   drawer.begin(LINES);
   drawer.vertex(ax, ay);
   drawer.vertex(bx, by);
   drawer.end();
}
int main(int argc, char** argv)
{
   canvas drawer(1000, 500);

   //left eye
   drawer.begin(CIRCLES);
   drawer.color(154, 205, 50);
   drawer.color(255,103,0);
   drawer.center(250,180);
   drawer.radius(170);
   drawer.gradient(true);
   drawer.end();

   //right eye
   drawer.begin(CIRCLES);
   drawer.color(154, 205, 50);
   drawer.color(255,103,0);
   drawer.center(750,180);
   drawer.radius(170);
   drawer.gradient(true);
   drawer.end();

   //left pupil
   drawer.begin(CIRCLES);
   drawer.filled(true);
   drawer.color(0,0,0);
   drawer.center(750,180);
   drawer.radius(70);
   drawer.end();

   //right pupil
   drawer.begin(CIRCLES);
   drawer.filled(true);
   drawer.color(0,0,0);
   drawer.center(250,180);
   drawer.radius(70);
   drawer.end();
   
   //light reflection
   drawer.begin(CIRCLES);
   drawer.filled(true);
   drawer.color(255,255,255);
   drawer.center(230,160);
   drawer.radius(10);
   drawer.end();
   drawer.begin(CIRCLES);
   drawer.filled(true);
   drawer.color(255,255,255);
   drawer.center(730,160);
   drawer.radius(10);
   drawer.end();

   //nose
   drawer.begin(TRIANGLES);
   drawer.filled(true);
   drawer.color(0,0,0);
   drawer.color(0,0,0);
   drawer.color(149,85,0);
   drawer.vertex(350,350);
   drawer.vertex(650,350);
   drawer.vertex(500,470);
   drawer.end();

   drawer.save("owl.png");

   //canvas draw(1000, 500);
   drawer.background(255,255,255);

   //left eye
   drawer.begin(CIRCLES);
   drawer.color(255,255,255);
   drawer.color(137, 207, 240);
   drawer.center(250,180);
   drawer.radius(170);
   drawer.gradient(true);
   drawer.end();

   //right eye
   drawer.begin(CIRCLES);
   drawer.color(255,255,255);
   drawer.color(137, 207, 240);
   drawer.center(750,180);
   drawer.radius(170);
   drawer.gradient(true);
   drawer.end();

   //left pupil
   drawer.begin(CIRCLES);
   drawer.filled(true);
   drawer.color(0,0,0);
   drawer.center(750,180);
   drawer.radius(70);
   drawer.end();

   //right pupil
   drawer.begin(CIRCLES);
   drawer.filled(true);
   drawer.color(0,0,0);
   drawer.center(250,180);
   drawer.radius(70);
   drawer.end();
   
   //light reflection
   drawer.begin(CIRCLES);
   drawer.filled(true);
   drawer.color(255,255,255);
   drawer.center(230,160);
   drawer.radius(10);
   drawer.end();
   drawer.begin(CIRCLES);
   drawer.filled(true);
   drawer.color(255,255,255);
   drawer.center(730,160);
   drawer.radius(10);
   drawer.end();

   //nose
   drawer.begin(TRIANGLES);
   drawer.filled(true);
   drawer.color(255,255,255);
   drawer.color(255,255,255);
   drawer.color(202, 123, 128);
   drawer.vertex(350,330);
   drawer.vertex(650,330);
   drawer.vertex(500,450);
   drawer.end();

   drawer.color(202, 123, 128);
   drawline(drawer, 500, 450, 500, 460);

   drawline(drawer, 500, 460, 490, 470);
   drawline(drawer, 500, 460, 510, 470);

   drawline(drawer, 490, 470, 475, 480);
   drawline(drawer, 510, 470, 525, 480);

   drawline(drawer, 475, 480, 450, 490);
   drawline(drawer, 525, 480, 550, 490);

   drawline(drawer, 450, 490, 370, 490);
   drawline(drawer, 550, 490, 630, 490);

   drawline(drawer, 370, 490, 350, 485);
   drawline(drawer, 630, 490, 650, 485);

   drawer.begin(LINES);
   drawer.color(255, 255, 255);
   drawer.color(0, 0, 0);
   drawer.vertex(400, 425);
   drawer.vertex(10, 300);
   drawer.end();

   drawer.begin(LINES);
   drawer.color(0, 0, 0);
   drawer.color(255, 255, 255);
   drawer.vertex(600, 425);
   drawer.vertex(990, 300);
   drawer.end();

   drawer.begin(LINES);
   drawer.color(255, 255, 255);
   drawer.color(0, 0, 0);
   drawer.vertex(370, 450);
   drawer.vertex(20, 400);
   drawer.end();

   drawer.begin(LINES);
   drawer.color(0, 0, 0);
   drawer.color(255, 255, 255);
   drawer.vertex(630, 450);
   drawer.vertex(980, 400);
   drawer.end();
   drawer.save("kitten.png");
   

}

