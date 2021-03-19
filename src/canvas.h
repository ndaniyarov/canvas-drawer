#ifndef canvas_H_
#define canvas_H_

#include <string>
#include <vector>
#include "ppm_image.h"

namespace agl
{
   enum PrimitiveType {UNDEFINED, LINES, TRIANGLES, CIRCLES, RECTANGLES};
   class canvas
   {
   public:
      canvas(int w, int h);
      virtual ~canvas();

      // Save to file
      void save(const std::string& filename);
      void begin(PrimitiveType type);
      void line(point a, point b);
      void lines();
      void lineLow(int H, int W, point a, point b);
      void lineHigh(int H, int W, point a, point b);
      void outlinedTriangle();
      void outlineTriangle(point a, point b, point c);
      void filledTriangle();
      float barycentric_coord(point a, point b, point input);
      void barycentric_fill(point a, point b, point c);
      void outlinedCircle(point o, int r);
      void filledCircle(point o, int r);
      void gradientCircle(point o, int r);
      void filledRectangle(point o, int h, int w);
      void outlinedRectangle(point o, int h, int w);
      void radius(int r);
      void center(int x, int y);
      void heightRec(int h);
      void widthRec(int w);
      void filled(bool f);
      float distance(point p1, point p2);
      void gradient(bool g);
      void hole(int h);
      void end();

      // Specifiy a vertex at raster position (x,y)
      // x corresponds to the column; y to the row
      void vertex(int x, int y);

      // Specify a color. Color components are in range [0,255]
      void color(unsigned char r, unsigned char g, unsigned char b);

      // Fill the canvas with the given background color
      void background(unsigned char r, unsigned char g, unsigned char b);

   private:
      ppm_image _canvas;
      PrimitiveType primType;
      std::vector<ppm_pixel> drawingColor;
      std::vector<point> points;
      point cen;
      int hR;
      int wR;
      int holeR;
      int radiusVar;
      bool fill;
      bool grad;
   };
}

#endif


