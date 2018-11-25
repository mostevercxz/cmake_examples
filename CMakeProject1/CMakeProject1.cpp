// CMakeProject1.cpp: 定义应用程序的入口点。
//

#include "CMakeProject1.h"
#include "TutorialConfig.h"
#ifdef USE_MYMATH
#include "add.h"
#endif // USE_MYMATH

// A simple program that computes the square root of a number
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stdout, "Usage: %s number\n", argv[0]);
		return 1;
	}	
#ifdef USE_MYMATH
	int tmp = myadd(1, 1);
#else
	int tmp = 3;
#endif // USE_MYMATH

	fprintf(stdout, "version=%d,%d,%d,%d", HELLO_WORLD_MAJOR, HELLO_WORLD_MINOR, tmp, test_abs(tmp));
	double inputValue = atof(argv[1]);
	double outputValue = sqrt(inputValue);
	fprintf(stdout, "The square root of %g is %g\n",
		inputValue, outputValue);
	return 0;
}
