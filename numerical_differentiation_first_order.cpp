// numerical_differentiation_first_order.cpp : This file contains the 'main' function. Program execution begins and ends there.
// note : I have not used "namespace std" as i found that it is not a good programming practise in c++. 
// this program evaluates the first derivative of function using different numerical approximations and prints the result in output
// a class of first order numerical derivative has been defined which consists of different methods to evaluate the numerical derivative.

#include <iostream>
#include <math.h>
#include <cmath>
#include<string.h>

//function whose derivative we want to find
float func_of_interest(float xin)
{
    //float return_value = pow(xin,3)+2 * pow(xin, 2)+((float)2 * xin);//3x^3+2x^2+2x
    float return_value = atan(xin);
    return return_value;
}


class first_order_numerical_derivative// using the concept of class without default constructor so that it becomes compulsory for the user to supply xvalue and stepsize to use this class
{
private :
    float ans_derivative=0.0;//initialising to some random value (good practise)
public:
    float step_size = 1;//initialising to some random value (good practise)
    float xval_in = 0.5;//initialising to some random value (good practise)
    //overloaded constructor with no default constructor
    first_order_numerical_derivative(float xvalue, float step_size_val)
    {
        xval_in = xvalue;
        step_size = step_size_val;
        std::cout << "overloaded constructor creates xval = " << xval_in << " and step_size = " << step_size_val << std::endl;
    }
    // method 1
    // three point backward difference formula (also called second-order backward difference approximation) :: (3f(xval)-4f(xval-h)+f(xval-2h))/(2h)
    float three_pt_back_diff_first_deri()
    {
        float ans_derivative = (3 * func_of_interest(xval_in) - 4 * func_of_interest(xval_in- step_size) + func_of_interest(xval_in - 2 * step_size)) / ((float)2 * step_size);
        return ans_derivative;
    }
    //method 2
    // three point forward difference formula (also called second-order forward difference approximation) :: (-3f(xval)+4f(xval+h)-f(xval+2h))/(2h)
    float three_pt_for_diff_first_deri()//
    {
        float ans_derivative = (-3 * func_of_interest(xval_in) + 4 * func_of_interest(xval_in + step_size) - func_of_interest(xval_in + 2 * step_size)) / ((float)2 * step_size);
        return ans_derivative;
    }
    //method 3
    // the next function evaluates the first derivative of the function at xval_in using central difference approximation method. 
    float two_point_central_diff_first_deri()//
    {
        float ans_derivative = (func_of_interest(xval_in + step_size) - func_of_interest(xval_in - step_size)) / ((float)2 * step_size);// (f(xval_in+h)-f(xval_in-h))/(2h)
     /*std::cout << "func_of_interest(xval_in + step_size_in)" << func_of_interest(xval_in + step_size_in) << std::endl;
     //std::cout << "func_of_interest(xval_in - step_size_in)" << func_of_interest(xval_in - step_size_in) << std::endl;
     //std::cout << "2*step_size_in" << ((float)2 * step_size_in) << std::endl;
     */
        return ans_derivative;
    }
};

//

int main()
{
    std::cout << "Hello World! This program is to numericall evaluate the derivative of the function at the desired point using desired stepsize \n";
    std::cout << "enter the x value at which you want to evaluate the derivative of the function " << std::endl;
    float xin = 0;
    std::cin >> xin;
    float stepsize = 0.01;
 
    first_order_numerical_derivative derivative_ans(xin, stepsize);// instantiating an object of class first_order_numerical_derivative
    //envoking different methods defined in the class first_order_numerical_derivative and displaying result in the console
    std::cout << "derivative at the desired point using central difference approximation = " << derivative_ans.two_point_central_diff_first_deri() << std::endl;
    std::cout << "derivative at the desired point using three point backward difference approximation = " << derivative_ans.three_pt_back_diff_first_deri() << std::endl;
    std::cout << "derivative at the desired point using three point forward difference approximation = " << derivative_ans.three_pt_for_diff_first_deri() << std::endl;
    return 0;
}


