// numerical_integration_trapezoidal_rule.cpp : This file contains the 'main' function. Program execution begins and ends there.
//This simple code is to numerically evaluate the integral of a function using trapezoidal rule.
// numerical integration using composite trapezoidal and composite simpson's scheme
// references: (1) class notes
//             (2) "A friendly introduction to Numerical Analysis" by Brian Bradie
//             (3) Numerical methods for scientific and engineering computations - Jain, Iyenger, Jain
#include <iostream>
#include<math.h>
#include <cmath>
//using namespace std;
double func1_to_integrate(double xin)//function i want to
{
    return 1/(2+(xin*xin));
}
double func2_to_integrate(double xinput)
{
    return exp(-xinput);
}

// function for composite trapezoidal rule. it takes also takes the integrand function as an argument 
double trapezoidal(int num_intervals, float lower_lt, float upper_lt, double (*func) (double))
{
    double step_size = ((double)upper_lt - (double)lower_lt) / (double)(num_intervals);
    double temp_sum = 0;
    for (int j = 1; j < num_intervals - 1; ++j)
    {
        temp_sum = temp_sum + func((double)lower_lt + j * step_size);

    }
    double final_result = 0;
    final_result = (step_size / 2) * (func(lower_lt) + func(upper_lt) + 2 * temp_sum);
    return final_result;
}

int main()
{
    std::cout << "Hello World!\n";
    int num_of_intervals = 100;
    float lower_limit = 0;
    //float upper_limit = M_PI;
    std::cout << "result of integral in problem 2 : " << trapezoidal(num_of_intervals, 0, 3, &func1_to_integrate) << std::endl;
    std::cout << "result of integral in problem 3 : " << trapezoidal(num_of_intervals, 0, 1, &func2_to_integrate) << std::endl;
    return 0;
}

//something new i learned while writing this program #define _USE_MATH_DEFINES//reference:https://www.quantstart.com/articles/Mathematical-Constants-in-C/
/* To include the mathematical constants, you need to use a #define macro called _USE_MATH_DEFINES 
and add it before importing the cmath library:
*/
