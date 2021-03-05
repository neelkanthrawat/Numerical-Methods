// this is the first program i uploaded in the Github repsitory.
//references:  I used come advanced c++ STL concepts. I am including the references i used while learning about these features
//            (1) concept of iterators: https://www.geeksforgeeks.org/introduction-iterators-c/
//            (2) other refrence book i used for syntax and other advanced features : sam teach yourself series on C++ (Beautiful book for beginners in c++)

#include <iostream>
#include <string>
#include <vector>
#include<iterator>// for iterator : new thing that i learned today
//#include <algorithm>
// during my free time i would love to leisurely learn about these libraries in great detail
using namespace std;

void binary_to_decimal(string binary_num) // need to copy the program written in the main function to this function.
{
    /*cout << "binary value you entered " << endl;
    cout << binary_num << endl;*/

    vector<char> vec_binary(binary_num.begin(), binary_num.end());
    
    /* // needed while i was debugging the code.
    cout << "size of the binary vector is=" << vec_binary.size() << endl;

    for (int i = 0; i < vec_binary.size(); ++i)
    {
        cout << "vec_binary[" << i << "] is = " << vec_binary[i] << endl;
    }//successful
    */

    // need to find the position of the charater "." if it is present
    char key = '.';//note: not "." use  single quotes for chars.
    vector <char>::iterator itr = find(vec_binary.begin(), vec_binary.end(), key);

    // This is the first time in my life i have read about iterators hence it is important to 
    //now this concept of distance i am not very much aware of yet. i think that i have kinda understoof the concept now. will explore it in detail as i read iterators properly once again
    if (itr != vec_binary.end())//reference: https://www.techiedelight.com/find-index-element-vector-cpp/
    {
        int index_of_dot = distance(vec_binary.begin(), itr);
        //cout << "element is present at index (zero_based indexing)" << index_of_dot << endl;
        //cout << "this implies that the decimal is at " << index_of_dot + 1 << " place" << endl;

        //following section of code is to convert the binary value before the binary point to its decimal equivalent
        float multiplier_of_2 = 1;
        float decimal_of_binary_bef_dot = 0.0;
        for (int index_before_dot = index_of_dot - 1; index_before_dot > -1; --index_before_dot)
        {
            if (vec_binary[index_before_dot] == '1')
            {
                decimal_of_binary_bef_dot = decimal_of_binary_bef_dot + multiplier_of_2;

            }
            multiplier_of_2 = multiplier_of_2 * 2;
        }
        //following section  of code is to convert the binary values after the binary point to the decimal equivalent
        float multiplier_after_dot = 0.5;
        double decimal_of_binary_after_dot = 0.0;
        for (int index_after_dot = index_of_dot + 1; index_after_dot < vec_binary.size(); ++index_after_dot)
        {
            if (vec_binary[index_after_dot] == '1')
            {
                decimal_of_binary_after_dot = decimal_of_binary_after_dot + multiplier_after_dot;

            }
            multiplier_after_dot = multiplier_after_dot * (0.5);
        }
        cout << "decimal value is ::" << decimal_of_binary_bef_dot + decimal_of_binary_after_dot << endl;
    }
    else // if number entered is of simple form like 1101 and not of the form 1101.10
    {
        float multiplier_of_2 = 1;
        float decimal_of_binary_bef_dot = 0.0;
        for (int index_before_dot = vec_binary.size() - 1; index_before_dot > -1; --index_before_dot)
        {
            if (vec_binary[index_before_dot] == '1')
            {
                decimal_of_binary_bef_dot = decimal_of_binary_bef_dot + multiplier_of_2;

            }
            multiplier_of_2 = multiplier_of_2 * 2;
        }
        cout << "decimal value of the binary is = " << decimal_of_binary_bef_dot << endl;
    }
}


int main()
{
    // i am getting input as a string because that is more convenient for the user. 
    string binary_number;
    cout << "This program converts a positive binary number into decimal" << endl;
    cout << "Examples of type of binary numbers to their decimal equivalent is: (e.g.1) 1101 (e.g.2) 1101.110011" << endl;
    cout << "enter the binary number : ";
    cin >> binary_number;
    binary_to_decimal(binary_number);//invoking function which converts a positive binary number to its decimal equivalent
    return 0;

}


