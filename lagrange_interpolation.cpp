// lagrange_interpolation_first_attempt.cpp : This file contains the 'main' function. Program execution begins and ends there.
// nth order polynomials have n+1 coefficients. (one for each power of independent variable , plus a constant term)
// from n+1 data points one can determine the polynomial of degree atmost n

#include <iostream>
#include<vector>
#include<iomanip>
#include<math.h>
#include<string>// allows me to use getline
#include<fstream>// header required to read/write from/to file
#include<cassert>// allows me to use assert


//this function evaluates the lagrange polynomial at the given value of x
float lagrange_poly(float xin, const std::vector <float> &pbref_xdata, const std::vector <float> &pbref_ydata)//pbref= passed by reference
{   //evaluating the maximum nth order inerpolating polynomial from n+1 data points
    float poly_sum = 0;
    for (int j = 0; j < pbref_ydata.size(); ++j)
    {
        float temp_prod = 1;
        for (int i = 0; i < pbref_xdata.size(); ++i)
        {
            if (i != j)
            {
                temp_prod = temp_prod * ((xin - pbref_xdata[i]) / (pbref_xdata[j] - pbref_xdata[i]));
            }
        }
        std::cout << "temp product is = " << temp_prod << std::endl;
        poly_sum = poly_sum + (temp_prod)*pbref_ydata[j];
    }
    std::cout << "polynomial sum is = " << poly_sum << std::endl;
   
    return poly_sum; 
}

/*
// function passing a vector to a function // passing a dynamic vector to function
void vector_to_fn(const std::vector <float> &vec_pbref )//pbref is short for pass by reference
{
    for (int i = 0; i < vec_pbref.size();++i)
    {
        std::cout << "dyn_xin[" << i << "] = " << vec_pbref[i];
    }
}
*/

int main()
{
    std::cout << "Hello World!\n";
    std::vector <float> dyn_xin{} ;//vector of floats x input values
    std::vector <float> dyn_yin{ };// vector of floats y input values

    //code for reading file begins from here
    std::ifstream read_file("data_file_thermo.dat" , std::ios_base::in);//defining the input stream variable.
    assert(read_file.is_open());//checking whether the file can be opened for the required purpose or not
    // the next line is to skip the string-header line present in my dat file
    std::string file_first_line;
    getline(read_file, file_first_line);
    while (!read_file.eof())//this boolean variable associated with the input stream variable (read_file in our case) takes the variable "true" when the End Of the File (that is why eof) is reached.
    {
        std::cout << "i am inside" << std::endl;
        float tempx = 5, tempy = 0;
        read_file >> tempx >> tempy;
        dyn_xin.push_back(tempx);
        dyn_yin.push_back(tempy);
    }
    read_file.close();
    dyn_xin.pop_back();//temporary solution to get rid of extra row. I am yet to figure out why is this happening
    dyn_yin.pop_back();//temporary solution to get rid of extra row. I am yet to figure out why is this happening
    // code for reading file ends here

    float point_of_interest = 480;//valjue at which i want to evaluate the value of interpolating polynomial
    lagrange_poly(point_of_interest, dyn_xin, dyn_yin);
    return 0;
}




