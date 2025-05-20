#include "app.hpp"
#include <SDL2/SDL.h>
#include <cstdio>

int main(int argv, char** args)
{
  constexpr unsigned int disp_width = 1024;
  constexpr unsigned int disp_height = 576;

  if (!application::init_app (disp_width, disp_height))
    {
      printf ("ERROR - App failed to initialise\n");
      application::shut_down_app ();
      return 1;
    }
  application::run_app ();
  return 0;
}
