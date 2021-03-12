// numerical_integration_trapezoidal_rule.cpp : This file contains the 'main' function. Program execution begins and ends there.
//This simple code is to numerically evaluate the integral of a function using trapezoidal rule.
// numerical integration using composite trapezoidal and composite simpson's scheme
// references: (1) class notes
//             (2) A friendly introduction to numerical analysis by brian bradie
//             (3) Numerical methods for scientific and engineering computations - jain, iyenger, jain
#include <iostream>
#include <vector>
#include<string>
#include<fstream>
#include<math.h>
#include <cmath>

using namespace std;

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
    final_result = (step_size / 2) * (func(lower_lt) + func(lower_lt) + 2 * temp_sum);
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


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

/* To include the mathematical constants, you need to use a #define macro called _USE_MATH_DEFINES 
and add it before importing the cmath library:
*/
