# include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, 40, ....., 300 */

int main()
{
  printf("This program prints a conversion table of Fahrenheit to Celsius\n\n");

	float fahr, celsius;
	float lower, upper, step;

	lower = 0;	/* lower limit of temperature scale */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	fahr = lower;
	while (fahr <= upper){
		celsius = (fahr - 32.0) * 5.0 / 9.0;
		printf("%3.0f %6.2f\n", fahr, celsius);
		fahr = fahr + step;
	}

}
