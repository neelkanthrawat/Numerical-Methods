// lu_decomp_attempt1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program is to find the LU decomposition of a sqaure matrix using do-little algorithm
//https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
#include <iostream>
#include <vector>

using namespace std;
template <unsigned int rows,unsigned int cols>
void lu_decompose(float (&inp_coeff_array)[rows][cols], float (&inp_u)[rows][cols], float (&inp_l)[rows][cols])
{
    for (int i = 0; i < rows; ++i)//working :)
    {
        inp_l[i][i] = 1;
    }
    for (int ctr_outermost = 0; ctr_outermost < rows; ++ctr_outermost)//ctr_out=outermost_for_loop's counter
    {
        int ctr_out = ctr_outermost;
        //std::cout << " coutner_outermost=" << ctr_outermost << std::endl;
        //evaluating u elements
        for (int ctr_u = ctr_out; ctr_u < cols; ++ctr_u)
        {
            float sum1 = 0;
           // std::cout << "ctr_out is =" << ctr_out << std::endl;
            if (ctr_outermost != 0)
            {
                //std::cout << "i am here" << std::endl;
                for (int sum1_index = 0; sum1_index <= (ctr_out - 1); ++sum1_index)// less than and equal to
                {
                //   std:: cout << " is sum being evaluated" << std::endl;
                    sum1 = sum1 + (inp_l[ctr_out][sum1_index] * inp_u[sum1_index][ctr_u]);
                }
                //std::cout <<"at ctr_outermost="<<ctr_outermost<<" and ctr_u="<<ctr_u<< " sum1 right now is : " << sum1 << std::endl;
            }
            inp_u[ctr_out][ctr_u] = inp_coeff_array[ctr_out][ctr_u] - sum1;
        }
        //evaluating l elements
        for (int ctr_l = ctr_out + 1; ctr_l < rows; ++ctr_l)
        {
            float sum2 = 0;
            if (ctr_outermost != 0)
            {
                for (int sum2_index = 0; sum2_index <= (ctr_out - 1); ++sum2_index)// less than equal to
                {
                    sum2 = sum2 + (inp_l[ctr_l][sum2_index] * inp_u[sum2_index][ctr_out]);
                }
            }
            inp_l[ctr_l][ctr_out] = (1 / (inp_u[ctr_out][ctr_out])) * (inp_coeff_array[ctr_l][ctr_out] - sum2);
        }
    }
}

int main()
{
    const int numrows = 3, numcols = 3;
    float coeff_array[numrows][numcols] = { {3,6,-3},{2,-4,-9},{1,2,3} };
    float umat[numrows][numcols] = {0};
    float lmat[numrows][numcols] = {0};
    lu_decompose(coeff_array,umat,lmat);
    // printing l matrix
    std::cout << " l matrix" << std::endl;
    for (int i = 0; i < numrows; ++i)
    {
        std::cout << i << ": ";
        for (int j = 0; j < numcols; ++j)
            std::cout << lmat[i][j] << '\t';
        std::cout << std::endl;
    }
    //printing u matrix
   std::cout << " u matrix" << std::endl;
    for (int i = 0; i < numrows; ++i)
    {
        std::cout << i << ": ";
        for (int j = 0; j < numcols; ++j)
            std::cout << umat[i][j] << '\t';
        std::cout << std::endl;
    }
    return 0;
}




