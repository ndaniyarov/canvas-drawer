#include "canvas.h"
#include <cassert>

using namespace std;
using namespace agl;

canvas::canvas(int w, int h) : _canvas(w, h)
{
}

canvas::~canvas()
{
}

void canvas::save(const std::string& filename)
{
   _canvas.save(filename);
}

void canvas::begin(PrimitiveType type)
{
   primType = type;
}

void canvas::end()
{
   if (primType == LINES){
      if (points.size() > 2)
         lines();
      else
         line(points[0], points[1]);
   }
   if (primType == TRIANGLES){
      if (fill == true)
         filledTriangle();
      else 
         outlinedTriangle();
   }
   if (primType == CIRCLES){
      if (fill == true) 
         filledCircle(cen, radiusVar);
      if (grad == true)
         gradientCircle(cen, radiusVar);
      else 
         outlinedCircle(cen, radiusVar);
   }
   if (primType == RECTANGLES){
      if (fill == true)
         filledRectangle(cen, hR, wR);
      else
         outlinedRectangle(cen, hR, wR);
   }
   points.clear();
   drawingColor.clear();
   fill = false;
   grad = false;
}

void canvas::lineLow(int H, int W, point a, point b)
{
   int y = a.y;
   int inc = 1;
   float i = 0;
   float incColor;
   ppm_pixel start, end;
   ppm_pixel c = drawingColor[0];
   if (drawingColor.size() > 1){
      incColor = 1/(float)W;
      start = drawingColor[0];
      end = drawingColor[1];
   }
   if (H < 0){
      inc = -1;
      H = abs(H);
   }
   int F = 2*H - W;
   for(int x=a.x; x <= b.x; x++)
   {
      _canvas.set(x,y, c);
      if (drawingColor.size() > 1){
         i = i + incColor;
         c.r = start.r*(1-i) + end.r*i;
         c.g = start.g*(1-i) + end.g*i;
         c.b = start.b*(1-i) + end.b*i;
      }
      if (F > 0){
         y = y + inc;
         F += 2*(H-W);
      }
      else{
         F += 2*H;
      }
   }
}
void canvas::lineHigh(int H, int W, point a, point b)
{
   int x = a.x;
   int inc = 1;
   float i, incColor = 0;
   ppm_pixel start, end;
   ppm_pixel c = drawingColor[0];
   if (drawingColor.size() > 1){
      incColor = 1/(float)b.y;
      start = drawingColor[0];
      end = drawingColor[1];
   }
   if (W < 0){
      inc = -1;
      W = 0-W;
   }
   int F = 2*W - H;
   for(int y=a.y; y <= b.y; y++)
   {
      _canvas.set(x,y, c);
      if (drawingColor.size() > 1){
         i = i + incColor;
         c.r = start.r*(1-i) + end.r*i;
         c.g = start.g*(1-i) + end.g*i;
         c.b = start.b*(1-i) + end.b*i;
      }
      if (F > 0){
         x = x+inc;
         F += 2*(W-H);
      }
      else{
         F += 2*W;
      }
   }
}
void canvas::lines(){
   for (int i = 0; i < points.size(); i=i+2){
      line(points[i], points[i+1]);
   }
}
void canvas::line(point a, point b)
{
   int W = b.x - a.x;
   int H = b.y - a.y;
   if (abs(W) > abs(H)){
      if (a.x < b.x)
         lineLow(H,W,a,b);
      else
         lineLow(a.y-b.y,a.x-b.x,b,a);
   }
   else {
      if (a.y < b.y)
         lineHigh(H,W,a,b);
      else 
         lineHigh(a.y-b.y,a.x-b.x,b,a);
   }
}
float canvas::barycentric_coord(point a, point b, point input){
   float result = (b.y - a.y)*(input.x - a.x) - (b.x - a.x)*(input.y - a.y);
   return result;
}
void canvas::barycentric_fill(point a, point b, point c){
   int xmin = min(min(a.x,b.x), c.x);
   int ymin = min(min(a.y,b.y), c.y);
   int xmax = max(max(a.x,b.x), c.x);
   int ymax = max(max(a.y,b.y), c.y);
   
   int f_alpha = barycentric_coord(b, c, a);
   int f_beta = barycentric_coord(a, c, b);
   int f_gamma = barycentric_coord(a, b, c);
   ppm_pixel color = drawingColor[0];
   ppm_pixel v1, v2, v3;
   float w1,w2,w3 = 0;
   
   if (drawingColor.size() == 3){
      v1 = drawingColor[0];
      v2 = drawingColor[1];
      v3 = drawingColor[2];
   }
   for (int row = xmin; row <= xmax; row++){
      for (int col = ymin; col <= ymax; col++){
         point p = point(row, col);
         float alpha = barycentric_coord(b, c, p)/f_alpha;
         float beta = barycentric_coord(a, c, p)/f_beta;
         float gamma = barycentric_coord(a, b, p)/f_gamma;
         if (alpha >= 0 && beta >= 0 && gamma >= 0){
            point p1 = point(-1, -1);
            bool drawAlpha = (alpha > 0 || f_alpha*barycentric_coord(b, c, p1) >= 0);
            bool drawBeta= (beta > 0 || f_beta*barycentric_coord(a, c, p1) >= 0);
            bool drawGamma= (gamma > 0 || f_gamma*barycentric_coord(a, b, p1) >= 0);
            
            if (drawAlpha && drawBeta && drawGamma){
               if (drawingColor.size() == 3){
                  w1 = (float)((b.y-c.y)*(p.x - c.x) + (c.x-b.x)*(p.y-c.y))/(float)
                        ((b.y-c.y)*(a.x-c.x) + (c.x - b.x)*(a.y-c.y));
                  w2 = (float)((c.y-a.y)*(p.x - c.x) + (a.x-c.x)*(p.y-c.y))/(float)
                        ((b.y-c.y)*(a.x-c.x) + (c.x - b.x)*(a.y-c.y));
                  w3 = 1 - w1 - w2;
                  color.r = w1*(int)v1.r + w2*(int)v2.r + w3*(int)v3.r;
                  color.g = w1*(int)v1.g + w2*(int)v2.g + w3*(int)v3.g;
                  color.b = w1*(int)v1.b + w2*(int)v2.b + w3*(int)v3.b;
               } 
               _canvas.set(row,col,color);
            }
         }
      }
   }
}
void canvas::filledTriangle()
{
   ppm_pixel color = drawingColor[1];
   point a,b,c,d,e,f;
   a = points[0];
   b = points[1];
   c = points[2];
   if (points.size() == 6){
      d = points[3];
      e = points[4];
      f = points[5];
   }
   barycentric_fill(a,b,c);
   drawingColor[0] = color;
   barycentric_fill(d,e,f);
}
void canvas::outlinedTriangle(){
   ppm_pixel color = drawingColor[0];
   point a,b,c,d,e,f;
   a = points[0];
   b = points[1];
   c = points[2];
   if (points.size() == 6){
      d = points[3];
      e = points[4];
      f = points[5];
   }
   outlineTriangle(a,b,c);
   drawingColor[0] = color;
   outlineTriangle(d,e,f);
}
void canvas::outlineTriangle(point a, point b, point c){
   line(a,b);
   line(b,c);
   line(c,a);
}
void canvas::outlinedCircle(point o, int r){
   static const double PI = 3.1415926535;
   int numSlice = 100;
   float change, angle1, angle2;
   change = 2*PI/numSlice;
   for(int i = 0; i < numSlice; i++){
      angle1 = i*change;
      angle2 = (i+1)*change;
      point p1 = point(o.x+r*cos(angle1), o.y+r*sin(angle1));
      point p2 = point(o.x+r*cos(angle2), o.y+r*sin(angle2));
      line(p1,p2);
   }
}
void canvas::filledCircle(point o, int r){
   for(int x = -r; x <= r; x++){
      for(int y = -r; y <= r; y++){
         if(x*x+y*y <= r*r)
            _canvas.set(o.x + x, o.y + y, drawingColor[0]);
      }
   }
}
float canvas::distance(point o, point p){
   float result = sqrt((o.x-p.x)*(o.x-p.x) + (o.y - p.y)*(o.y-p.y));
   if (radiusVar < result)
      return 0;
   return result;
}
void canvas::gradientCircle(point o, int r){
   color(drawingColor[1].r, drawingColor[1].g, drawingColor[1].b);
   static const double PI = 3.1415926535;
   int numSlice = 1000;
   float change, angle1, angle2;
   change = 2*PI/numSlice;
   for(int i = 0; i < numSlice; i++){
      angle1 = i*change;
      angle2 = (i+1)*change;
      point p1 = point(o.x+r*cos(angle1), o.y+r*sin(angle1));
      point p2 = point(o.x+r*cos(angle2), o.y+r*sin(angle2));
      barycentric_fill(o, p1,p2);
   }
}
void canvas::filledRectangle(point o, int h, int w){
   for (int i = o.x-w/2; i <= o.x+w/2;i++){
      for (int j = o.y - h/2; j <= o.y+h/2; j++){
         _canvas.set(i,j, drawingColor[0]);
      }
   }
}
void canvas::outlinedRectangle(point o, int h, int w){
   point lowerLeft = point(o.x-w/2, o.y+h/2);
   point upperLeft = point(o.x-w/2, o.y-h/2);
   point upperRight = point(o.x+w/2, o.y-h/2);
   point lowerRight = point(o.x+w/2, o.y+h/2);
   line(upperRight, upperLeft);
   line(upperLeft, lowerLeft);
   line(lowerLeft, lowerRight);
   line(lowerRight, upperRight);
}
void canvas::center(int x, int y){
   point c = point(x,y);
   cen = c;
}
void canvas::heightRec(int h){
   hR = h;
}
void canvas::widthRec(int w){
   wR = w;
}
void canvas::hole(int h){
   holeR = h;
}
void canvas::radius(int r){
   radiusVar = r;
}
void canvas::filled(bool f){
   fill = f;
}
void canvas::gradient(bool g){
   grad = g;
}
void canvas::vertex(int x, int y)
{
   if (x < 0)
      x = 0;
   if (y < 0)
      y = 0;
   if (x >= _canvas.width())
      x = _canvas.width()-1;
   if (y >= _canvas.height())
      y = _canvas.height()-1;
   point p = point(x, y);
   points.push_back(p);
}

void canvas::color(unsigned char r, unsigned char g, unsigned char b)
{
   ppm_pixel c;
   c.r = r;
   c.g = g;
   c.b = b;

   drawingColor.push_back(c);
}

void canvas::background(unsigned char r, unsigned char g, unsigned char b)
{
   ppm_pixel bg;
   bg.r = r;
   bg.g = g;
   bg.b = b;
   for (int i = 0; i < _canvas.width(); i++){
      for (int j = 0; j < _canvas.height(); j++){
         _canvas.set(i,j,bg);
      }
   }
}

