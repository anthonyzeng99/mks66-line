#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
  
  clear_screen(s);

  time_t t;
  srand((unsigned) time(&t));
  
  c.red = rand() % 256;
  c.green = rand() % 256;
  c.blue = rand() % 256;
  draw_line(250, 500, 250, 250, s, c);
 
  c.red = rand() % 64;
  c.green = rand() % 256;
  c.blue = rand() % 256;
  draw_line(250, 250, 500, 500, s, c);

  c.red = rand() % 256;
  c.green = rand() % 256;
  c.blue = rand() % 256;
  draw_line(250, 250, 500, 250, s, c);

  c.red = rand() % 256;
  c.green = rand() % 256;
  c.blue = rand() % 256;
  draw_line(250, 250, 500, 0, s, c);

  c.red = rand() % 256;
  c.green = rand() % 256;
  c.blue = rand() % 256;
  draw_line(250, 250, 250, 0, s, c);

  c.red = rand() % 256;
  c.green = rand() % 256;
  c.blue = rand() % 256;
  draw_line(250, 250, 0, 0, s, c);

  c.red = rand() % 256;
  c.green = rand() % 256;
  c.blue = rand() % 256;
  draw_line(0, 250, 250, 250, s, c);

  c.red = rand() % 256;
  c.green = rand() % 256;
  c.blue = rand() % 256;
  draw_line(0, 500, 250, 250, s, c);
    
  display(s);
  save_extension(s, "lines.png");
}


