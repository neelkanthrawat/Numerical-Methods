// exp_evaluation.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This was HW assignment

#include <iostream>
#include <math.h>
#include<string>
#include<cmath>
#include<vector>
#include<iomanip>//setw
#include <fstream>// header: to write/read to/from a file
#include<cassert>//allows me to use assert

/*
long double factorial(unsigned int num)// will take only positive integer //factorial working well.
{
    long double return_val = 1;
    if (num == 0)
    {
        return_val = 1;
    }
    else
    {
        for (int i = 2; i <= num; ++i)
        {
            return_val = return_val * i;
        }
    }
    return return_val;
}
*/

// using method 1 given in the assignment sheet.
long double fn_1_series_eval(int num_terms, long double xin)
{
    long double series_sum = 1;
    for (int j = 1; j <= num_terms; ++j)
    {
        //std::cout << "factorial j = "<<j <<" is = " << factorial(j) << std::endl;
        long double temp_prod_term = 1;
        for (int i = 1; i <= j; ++i)
        {
            temp_prod_term = temp_prod_term* (-xin) / (i);
        }
        series_sum = series_sum + temp_prod_term;//thanks to  Saurabh Mishra (PH20C038): He suggested me not to use factorial. (pow(-1,j)*pow(xin,j))/(factorial(j));
        //task for me: figure out why Saurabh's suggestion works . things to figure out: Floating point related aspects.
    }
    return series_sum;
}

// using method 2 given in the assignment sheet: recurssion relation method. It is not a good method as well
long double fn_2_series_eval(int num_terms, long double xin)
{
    long double old_term = 1;
    long double series_sum = old_term;
    for (int i = 1; i <= num_terms; ++i)
    {
        long double new_term = (-1) * old_term * xin / (i);
        series_sum = series_sum + new_term;
        old_term = new_term;
    }
    return series_sum;
}
// using method 3 given in the assignment sheet: recurssion relation method : this method works really well
double fn_3_series_eval(int num_terms, double xin)
{
    double old_term = 1;
    double series_sum = old_term;
    for (int i = 1; i <= num_terms; ++i)
    {
        double new_term =  old_term * xin / (i);
        series_sum = series_sum + new_term;
        old_term = new_term;
    }
    return pow(series_sum,-1);
}

int main()
{
    std::cout << "Hello World!\n";
    //int xarray[4] = { -12, -5, 5 ,12 };// 100
    std::vector <int> n_array{};
    for (int i = 10; i <= 1000; i = i + 10)
    {
        n_array.push_back(i);//creates array n_array=[10,20,30,40,...,100]

    }
    std::cout << "for x value = 10" <<std::endl;
    long double xval = 15;//note we would be calculating exp(-xval)


    std::cout << "no. of terms" << std::setw(25) << "from series" << std::setw(20) << "inbuilt function" << std::setw(20) << "relative error" << std::endl;

    //displaying result obtained from method 1 in the assignment sheet 2 in the console
    std::cout << "result obtained from method 1" << std::endl;
    for (int i = 0; i < n_array.size(); ++i)
    {
        std::cout << n_array[i] << std::setw(30) << fn_1_series_eval(n_array[i], xval) << std::setw(25) << exp(-xval) << std::setw(25) << abs((fn_1_series_eval(n_array[i], xval )-exp(-xval))/ exp(-xval))<< std::endl;
    }
    //displaying result obtained from method 2 in the assignment sheet 2 in the console
    std::cout << "result obtained from method 2" << std::endl;
    std::cout << "no. of terms" << std::setw(25) << "from series" << std::setw(20) << "inbuilt function" << std::setw(20) << "relative error" << std::endl;
    for (int i = 0; i < n_array.size(); ++i)
    {
         std::cout << n_array[i] << std::setw(30) << fn_2_series_eval(n_array[i],xval) << std::setw(25) << exp(-xval) << std::setw(25) << abs((fn_2_series_eval(n_array[i], xval) - exp(-xval)) / exp(-xval))<<std::endl;
    }
    //displaying result obtained from method 3 in the assignment sheet 2 in the console
    std::cout << "result obtained from method 3" << std::endl;
    std::cout << "no. of terms" << std::setw(25) << "from series" << std::setw(20) << "inbuilt function" << std::setw(20) << "relative error" << std::endl;
    for (int i = 0; i < n_array.size(); ++i)
    {
        std::cout << n_array[i] << std::setw(30) << fn_3_series_eval(n_array[i], xval) << std::setw(25) << exp(-xval) << std::setw(25)<< abs((fn_3_series_eval(n_array[i], xval) - exp(-xval)) / exp(-xval)) << std::endl;
    }
    //storing data in file
    std::ofstream write_output("exp_of_minus_15.dat");// i need to learn how to automate it. was esay in python not so here
    write_output << "no. of terms" << std::setw(20) << "Rerr_meth_1" << std::setw(20) << "Rerr_meth_2" << std::setw(20) << "Rerr_meth_3" << "\n";
    for (int i = 0; i < n_array.size(); ++i)
    {
        write_output << n_array[i] << std::setw(25) << abs((fn_1_series_eval(n_array[i], xval) - exp(-xval)) / exp(-xval)) << std::setw(25) << abs((fn_2_series_eval(n_array[i], xval) - exp(-xval)) / exp(-xval)) << std::setw(25) << abs((fn_3_series_eval(n_array[i], xval) - exp(-xval)) / exp(-xval)) << "\n";
    }
    write_output.close();//closing the file
    return 0;
    //next job is to store them in a file.
}




