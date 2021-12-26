/* sin example */
#include <stdio.h>      /* printf */
#include <math.h>       /* sin */

#define PI 3.14159265

/// sin() functioin

int main ()
{
  double param, result;
  param = 30.0;
  result = sin (param*PI/180);
  printf ("The sine of %f degrees is %f.\n", param, result );
  return 0;
}


----------------------------------------------------------------------------------------------------------

/// asin() function

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double x = 0.25, result;
  result = asin(x);
  
  cout << "asin(x) = " << result << " radians" << endl;
  // result in degrees
  cout << "asin(x) = " << result*180/3.1415 << " degrees" << endl;
  
  return 0;
}
