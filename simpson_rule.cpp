// simpson_rule.cpp : This file contains the 'main' function. Program execution begins and ends there.
// references: (1) class notes
//             (2) A friendly introduction to numerical analysis by brian bradie
//             (3) Numerical methods for scientific and engineering computations - jain, iyenger, jain

# define _USE_MATH_DEFINES // allows me to use constant M_PI defined in cmath.
#include <iostream>
#include<string.h>
#include<math.h>
#include<cmath>

double func1_to_integrate(double xin)//integrand function 
{
    return 1 / (2 + (xin * xin));
}
double func2_to_integrate(double xinput)// another integrand function
{   
    //return sin(xinput);
    return exp(-xinput);
    //return 1 / (1 + xinput);
}

// function for composite simpson's  rule. it takes also takes the integrand function as an argument 
double simpson(int num_intervals, double lower_lt, double upper_lt, double (*func) (double))
{   
    std::cout << "i am inside the function" << std::endl;
    double step_size = (upper_lt - lower_lt) / (double)(num_intervals);
    std::cout << "step_size is = " <<step_size<< std::endl;
    double temp_sum_odd_ordinates = 0;
    std::cout << "initialised sum of odd ordinates is = " << temp_sum_odd_ordinates << std::endl;
    for (int j = 1; j <=(num_intervals/2); ++j)// note <=(num_interval/2)!
    {   
        std::cout << "evaluating sum of odd ordinates. j is = " <<j<< std::endl;
        std::cout << "odd ordinate evaluation : " << func(lower_lt + ((double)2 * j - 1) * step_size) << std::endl;
        temp_sum_odd_ordinates = temp_sum_odd_ordinates + func(lower_lt + ((double)2*j-1) * step_size);
        std::cout << "evaluating sum of odd ordinates. j is = " << j << std::endl;
    }
    
    double temp_sum_even_ordinates = 0;
    for (int j = 1; j <=(num_intervals / 2) - 1; ++j)// note <=(num_interval/2)-1!
    {
        std::cout << "evaluating sum of even ordinates. j is = " << j << std::endl;
        temp_sum_even_ordinates = temp_sum_even_ordinates + func(lower_lt + ((double)2*j) * step_size);

    }
    double final_result = 0;
    final_result = (step_size / 3) * (func(lower_lt) + func(upper_lt) + 2 * temp_sum_even_ordinates+4* temp_sum_odd_ordinates);
    return final_result;

}

int main()
{
    std::cout << "Hello World! this program is to numerically evaluate the integral using composite simpson's method\n";
    int num_of_intervals = 4;// note: for simpson's rule , integration range must be divided into even number of subintervals
    std::cout << "result of integral in problem 3 : " << simpson(num_of_intervals, 0, 1, &func2_to_integrate) << std::endl;
    return 0;
}




