# include <stdio.h>

# define LOWER 0 /* lower limit of table */
# define UPPER 300 /* upper limit */
# define STEP 20 /* step size */

/*print Fahrenheit-Celsius table using for loop*/
int main()
{
  printf("This program prints a Fahrenheit Celsius conversion table in reverse, using a for loop\n\n");
  int fahr;
  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr - 32));
}
