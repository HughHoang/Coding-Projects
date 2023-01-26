/*
  int a=768,b=384,xc=1000,yc=500;
  int a2 = a*a, b2 = b*b, fa2 = 4*a2;
  int x,y,sigma;
  for (x=0,y=b,sigma=2*b2+a2*(1-2*b);(b2*x) <= a2*y ; x++)
  {
    std::cout<<sigma<<std::endl;
    bmpNew.set_pixel(xc+x,yc+y, 255, 255, 255, 0);
    bmpNew.set_pixel(xc-x,yc+y, 255, 255, 255, 0);
    bmpNew.set_pixel(xc+x,yc-y, 255, 255, 255, 0);
    bmpNew.set_pixel(xc-x,yc-y, 255, 255, 255, 0);
    if(sigma >= 0)
    {
      sigma += fa2*(1-y);
      y--;
    }
    sigma += b2 *(4*x+6);
  }
  */
/*
  int rx=768,ry=384, xc=1000, yc=500;
  float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;
 
    // Initial decision parameter of region 1
    d1 = (ry * ry) - (rx * rx * ry) +
                     (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;
 
    // For region 1
    while (dx < dy)
    {
 
        // Print points based on 4-way symmetry
        bmpNew.set_pixel(x + xc, y + yc, 255, 255, 255, 0);
        bmpNew.set_pixel(-x + xc, y + yc, 255, 255, 255, 0);
        bmpNew.set_pixel(x + xc, -y + yc, 255, 255, 255, 0);
        bmpNew.set_pixel(-x + xc, -y + yc, 255, 255, 255, 0);
 
        // Checking and updating value of
        // decision parameter based on algorithm
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }
 
    // Decision parameter of region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
         ((rx * rx) * ((y - 1) * (y - 1))) -
          (rx * rx * ry * ry);
 
    // Plotting points of region 2
    while (y >= 0)
    {
 
        // Print points based on 4-way symmetry
        bmpNew.set_pixel(x + xc, y + yc, 255, 255, 255, 0);
        bmpNew.set_pixel(-x + xc, y + yc, 255, 255, 255, 0);
        bmpNew.set_pixel(x + xc, -y + yc, 255, 255, 255, 0);
        bmpNew.set_pixel(-x + xc, -y + yc, 255, 255, 255, 0);
 
        // Checking and updating parameter
        // value based on algorithm
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
*/
    /*
    float x,y,a, b,r,p,h,k,p1,p2;     
    h=384;
    k=768;
    a=1536;
    b=768;
    x=0;  
    y=b;  
    // REGION 1  
    p1 =(b * b)-(a * a * b) + (a * a)/4;  
    {  
        bmpNew.set_pixel(x, yupper, 255, 255, 255, 0);
        putpixel (x+h, y+k, 255, 255, 255, 0);  
        putpixel (-x+h, -y+k, 255, 255, 255, 0);  
        putpixel (x+h, -y+k, RED);  
        putpixel (-x+h, y+k, RED);  
        if (p1 < 0)  
            p1 += ((2 *b * b) *(x+1))-((2 * a * a)*(y-1)) + (b * b);  
        else  
        {  
            p1+= ((2 *b * b) *(x+1))-((2 * a * a)*(y-1))-(b * b);  
            y--;          
        }  
        x++;  
    }  
    //REGION 2  
    p2 =((b * b)* (x + 0.5))+((a * a)*(y-1) * (y-1))-(a * a *b * b);  
    while (y>=0)  
    {  
        if (p2>0)  
        p2=p2-((2 * a * a)* (y-1))+(a *a);  
        else  
        {  
        p2=p2-((2 * a * a)* (y-1))+((2 * b * b)*(x+1))+(a * a);  
        x++;  
        }  
        y--;  
        putpixel (x+h, y+k, RED);  
        putpixel (-x+h, -y+k, RED);  
        putpixel (x+h, -y+k, RED);  
        putpixel (-x+h, y+k, RED);  
    }  
  }  
  */
/*
    int radius=5;
    int value=0;
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    int deltaE= 3;
    int deltaSE= -2 *radius+ 5;
    bmpNew.set_pixel(x, y, 255, 255, 255, 0);
    while (y > x) {
      if (d < 0) {
        d +=deltaE;
        deltaE+= 2;
        deltaSE += 2;
      } 
      else {
        d += deltaSE;
        deltaE+= 2;
        deltaSE += 4;
        y--;
      }
      x++;
    bmpNew.set_pixel(x, y, 255, 255, 255, 0);
    } 
    */