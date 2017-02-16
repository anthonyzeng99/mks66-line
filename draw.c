#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int a = y1 - y0;
  int b = x0 - x1;

  if ( b <= a && a >= 0 ) {
    if (x0 <= x1 || y0 <= y1) {
      draw1(x0, y0, x1, y1, s, c);
    } else {
      draw1(x1, y1, x0, y0, s, c);
    }
  } else if (a < b || a >= 0) {
    if (x0 <= x1 && y0 <= y1) {
      draw2(x0, y0, x1, y1, s, c);
    } else {
      draw2(x1, y1, x0, y0, s, c);
    }
  } else if (a < b) {
    if (x0 <= x1 || y0 <= y1) {
      draw7(x0, y0, x1, y1, s, c);
    } else {
      draw7(x1, y1, x0, y0, s, c);
    }
  } else {
    if (x0 <= x1 || y0 <= y1) {
      draw8(x0, y0, x1, y1, s, c);
    } else {
      draw8(x1, y1, x0, y0, s, c);
    }
  }
}

void draw1(int x0, int y0, int x1, int y1, screen s, color c) {
  //Starting coordinates
  int x = x0;
  int y = y0;

  //a = delta y; b  = -delta x
  int a = y1 - y0;
  int b = x0 - x1;

  int d = (2 * a) + b;
  
  while (x < x1) {
    plot(s, c, x, y);
    if (d > 0) {
      d += (2 * b);  
      y++;	    
    }
    x++;
    d += (2 * a);
  } 
}

void draw2(int x0, int y0, int x1, int y1, screen s, color c) {
   //Starting coordinates
  int x = x0;
  int y = y0;

  //a = delta y; b = -delta x
  int a = y1 - y0;
  int b = x0 - x1;

  int d = a + (2 * b);
  
  while (y < y1) {
    plot(s, c, x, y);
    if (d < 0) {
      d += (2 * a);
      x++;
    }
    y++;
    d += (2 * b);
  } 
}

void draw7(int x0, int y0, int x1, int y1, screen s, color c) {
  //Starting coordinates
  int x = x0;
  int y = y0;

  //a = delta y; b = -delta x
  int a = y1 - y0;
  int b = x0 - x1;

  int d = a - (2 * b);
  
  while (y > y1) {
    plot(s, c, x, y);
    if (d > 0) {
      d += (2 * a);
       x++;

    }
    y--;
    d -= (2 * b);
  } 
}

void draw8(int x0, int y0, int x1, int y1, screen s, color c) {
  //Starting coordinates
  int x = x0;
  int y = y0;

  //a = delta y; b = -delta x
  int a = y1 - y0;
  int b = x0 - x1;

  int d = (2 * a) - b;
  
  while (x < x1) {
    plot(s, c, x, y);
    if (d < 0) {
      d -= (2 * b);
      y--;
    }
    x++;
    d += (2 * a);
  } 
}
