#include "Simulator.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Team.h"

#ifdef XOPENME
  #include <xopenme.h>
#endif

int main(int argc, char *argv[])
{
#ifdef XOPENME
  xopenme_init(1,3);
#endif

char *var1 = getenv("home_field_advantage");
char *var2 = getenv("apply_scaling");
int home_field_advantage = std::stoi(var1);
std::stringstream ss(var2);
bool b;
std::istringstream(var2) >> b;

#ifdef XOPENME
  xopenme_clock_start(0);
#endif

run(home_field_advantage,b,argv[1]);

#ifdef XOPENME
  xopenme_clock_end(0);
#endif

#ifdef XOPENME
  xopenme_dump_state();
  xopenme_finish();
#endif
}
