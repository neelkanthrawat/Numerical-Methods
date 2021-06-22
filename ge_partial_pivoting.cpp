// this is just a program for gaussian elimination using partial pivoting

#include <iostream>
#include <cmath>// std::abs()
#include<iomanip>//std::setw, std::setprecision
using namespace std;

template <unsigned int rows, unsigned int cols>
void gepp(double(&inp_mat)[rows][cols], double(&output_pivoted)[rows][cols])// gepp: gauss elimination with partial pivoting
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            output_pivoted[i][j] = inp_mat[i][j];
        }
    }
    int ctr_out_max = 0;
    if (cols >= rows)
    {
        ctr_out_max = rows - 1;
    }
    else if (cols < rows)
    {
        ctr_out_max = cols;
    }
    for (int ctr_outmost = 0; ctr_outmost < ctr_out_max; ++ctr_outmost)
    {
        int old_max_row_index = ctr_outmost;
        int temp_max_row_index = ctr_outmost;
        int temp_max_col_index = ctr_outmost;// technically i don't need it but for the time being let's keep it for the sake of avoiding confusion
        double temp_max_val = output_pivoted[temp_max_row_index][temp_max_col_index];
        for (int index_below = (temp_max_row_index+1); index_below < rows; ++index_below)
        {
            if (abs(temp_max_val) < abs(output_pivoted[index_below][temp_max_col_index]))
            {
                temp_max_row_index = index_below;
                temp_max_val = output_pivoted[index_below][temp_max_col_index];
            }            
        }
        //swapping rows to have abs value of pivot entry to be the maximum in that row
        if (old_max_row_index != temp_max_row_index)
        {
            for (int swap_index_col = 0; swap_index_col < cols; ++swap_index_col)
            {
                double temp_val = output_pivoted[old_max_row_index][swap_index_col];
                output_pivoted[old_max_row_index][swap_index_col] = output_pivoted[temp_max_row_index][swap_index_col];
                output_pivoted[temp_max_row_index][swap_index_col] = temp_val;
            }
        }
        //reducing elements below the pivot entries on that column to zero: ( incorporating row operations )
        for (int row_ind_below_piv = (ctr_outmost + 1); row_ind_below_piv < rows; ++row_ind_below_piv)
        {
            double multiplier = (output_pivoted[row_ind_below_piv][ctr_outmost] / (output_pivoted[ctr_outmost][ctr_outmost]));
            for (int col_ind = 0; col_ind < cols; ++col_ind)
            {
                 output_pivoted[row_ind_below_piv][col_ind]= output_pivoted[row_ind_below_piv][col_ind]-( (output_pivoted[ctr_outmost][col_ind]) * multiplier );
            }
        }
        //displaying matrix after every outermost iteration
        cout << " iteration number :" << ctr_outmost + 1 << endl;
        for (int i = 0; i < rows; ++i)
        { 
            for (int j = 0; j < cols; ++j)
            {
                cout << fixed<<setprecision(7) << "|" <<output_pivoted[i][j] << "|" <<"\t";
            }
            cout << endl;
        }
    }
}

int main()
{
    const unsigned int num_rows = 3, num_cols = 4;// dimensions of my augmented matrix. (3X3 coefficient matrix + 3X1 RHS vector = 3X4 shaped Augmented matrix)
    double mat[num_rows][num_cols] = {{-1,1,-4,0},{2,2,0,1},{3,3,2,0.5}};// augmented matrix
    double pivoted_mat[num_rows][num_cols] = {0};// this will store the pivoted form of the matrix
    gepp(mat,pivoted_mat);
    cout << endl;
    cout << " partially pivoted Augmented Matrix:" << endl;
    for (int i = 0; i < num_rows; ++i)
    {
        for (int j = 0; j < num_cols; ++j)
        {
            cout << fixed << setprecision(7)<< pivoted_mat[i][j]<<"\t";
        }
        cout << endl;
    }
    //back subsitution to evaluate solutions of the system of linear equation given.
    double ans_vec[num_rows] = { 0 };
    for (int j = (num_rows-1); j >= 0; j = j - 1)
    {
        if (j == 2)
        {
            ans_vec[j] = (pivoted_mat[j][num_cols - 1] / pivoted_mat[j][j]);
        }
        else
        {
            double sum_val = 0;
            for (int sum_index = (num_cols-2); sum_index>j; sum_index = sum_index - 1)
            {
                sum_val = sum_val + (pivoted_mat[j][sum_index]* ans_vec[sum_index]);
            }
            ans_vec[j] = (pivoted_mat[j][num_cols - 1] - sum_val) / (pivoted_mat[j][j]);
        }
    }
    // printing the answer vector in the console
    cout << endl;
    cout << " solution of the given system of linear equation is:" << endl;
    for (int i = 0; i < num_rows; ++i)
    {
        cout << "xsoln[" << i << "] = " << ans_vec[i] << endl;
    }
    return 0;
}
