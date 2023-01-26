#include <iostream>
#include "BMP.h"
#include <cmath>

int main() {
  //width screen dimension is 2000, height screen dimension is 1000, major axis/x center point is 768, minor/y center point is 384
  int dimx=2000,dimy=1000,major=768,minor=384;
  //create screen with dimensions
  BMP bmpNew(dimx,dimy,false);
  //spacing between edges of ellipse and screen border
  int xspacing=dimx-2*major;
  int yspacing=dimy-2*minor;
  //graphs x=equation
  for(int x=0;x<bmpNew.bmp_info_header.width/2-xspacing/2;x++)
    {
      //calculates upper part of ellipse
      int yupper=sqrt((x*(-x+2*major)))/2;
      //starting arc
      bmpNew.set_pixel(x+xspacing/2, yupper+yspacing/2+minor, 255, 255, 255, 0);
      //mirrors it to the bottom left
      //bmpNew.set_pixel(x+xspacing/2, -yupper+yspacing/2+minor, 255, 255, 255, 0);
      //mirrors it to the top right
      bmpNew.set_pixel(-x+xspacing/2+2*major, yupper+yspacing/2+minor, 255, 255, 255, 0);
      //mirrors it to the bottom right
      //bmpNew.set_pixel(-x+xspacing/2+2*major, -yupper+yspacing/2+minor, 255, 255, 255, 0);
      //std::cout<<"x:"<<x<<std::endl;
      //std::cout<<"yu:"<<yupper<<std::endl;
    }
  //graphs y-equation to supplement missing pixels
  for(int y=0;y<bmpNew.bmp_info_header.height/2-yspacing/2;y++)
    {
      //calculates upper part of ellipse
      int xupper=2*sqrt(y*(-y+major));
      //starting arc
      //bmpNew.set_pixel(xupper+xspacing/2+major, y+yspacing/2, 255, 255, 255, 0);
      //mirrors it to the bottom left
      //bmpNew.set_pixel(-xupper+xspacing/2+major, y+yspacing/2, 255, 255, 255, 0);
      //mirrors it to the top right
      bmpNew.set_pixel(xupper+xspacing/2+major, -y+yspacing/2+2*minor, 255, 255, 255, 0);
      //mirrors it to the top left
      bmpNew.set_pixel(-xupper+xspacing/2+major, -y+yspacing/2+2*minor, 255, 255, 255, 0);
      //std::cout<<"y:"<<y<<std::endl;
      //std::cout<<"xu:"<<xupper<<std::endl;
    }

  //I also wanted to try using the Midpoint algorithm from the pdf and I used that as a basis and also information about Bresenham’s algorithm. Unlike the circle algorithm on the pdf, an ellipse has a 4-way symmetry instead of a circle’s 8 way symmetry which mean we have to calculate the arc in a single quadrant. In order to do so we find the curve which is divided into two regions which in region I is the slope on the curve is greater than –1 while in region II less than –1.
  //xcenter is 1000 and ycenter is 500
  //major axis a is 768 and minor axis b 384
  /*
  int rx=768,ry=384, xc=1000, yc=500;
  
  int x,y;
  float d1,d2,dx,dy;
  x = 0;                  
  y = ry;                 
  // decision parameter d1
    d1 = pow(ry,2) - (pow(rx,2) * ry) + ((1/4) * pow(rx,2));
    dx = 2 * pow(ry,2) * x;
    dy = 2 * pow(rx,2) * y;
  //region 1
    do                         
    {
      // plot points by 4 point symmetry because ellipse has 4 instead of a circle's 8
        bmpNew.set_pixel(xc+x,yc+y, 255, 255, 255, 0);
        bmpNew.set_pixel(xc-x,yc+y, 255, 255, 255, 0);
        bmpNew.set_pixel(xc+x,yc-y, 255, 255, 255, 0);
        bmpNew.set_pixel(xc-x,yc-y, 255, 255, 255, 0);
        if(d1<0)
        {
            x++;
            dx = dx + (2 * (pow(ry,2)));
            d1 = d1 + dx +(pow(ry,2));
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * (pow(ry,2)));
            dy = dy - (2 * (pow(rx,2)));
            d1 = d1 + dx - dy + (pow(ry,2));
        }
    }while(dx<dy);      // change to 2nd region
  // region two
    do                       
    {
        //plot points by 4 point symmetry because ellipse has 4 instead of a circle's 8
        bmpNew.set_pixel(xc+x,yc+y, 255, 255, 255, 0);
        bmpNew.set_pixel(xc-x,yc+y, 255, 255, 255, 0);
        bmpNew.set_pixel(xc+x,yc-y, 255, 255, 255, 0);
        bmpNew.set_pixel(xc-x,yc-y, 255, 255, 255, 0);

      
        if(d2>0)
        {
            x = x;
            y--;
            dy = dy - (2 * (pow(rx,2)));
            d2 = d2 - dy + pow(rx,2);
        }
          
        else
        {
            x++;
            y--;
            dy = dy - (2 * (pow(rx,2)));
            dx = dx + (2 * (pow(ry,2)));
            d2 = d2 +dx - dy + pow(rx,2);
 
        }
    }while(y>0);
  */
  
    

    
    bmpNew.write("output.bmp");


}
