/**
 * Hint: resolve the TODOs in grade_list.h first.
 * 
 * TODO: Write a program that declares a GradeList
 *       variable and adds to it all the even
 *       numbers 0-100:
 *       
 *       {0, 2, 4, ..., 98, 100}
 * 
 *       then prints out the minimum, maximum,
 *       median, mean and 75th percentile, all
 *       nicely labelled.
 */

 #include "grade_list.h"
 #include <iostream>

 using std::cout;
 using std::endl;

 int main(void)
 {
    GradeList gl;

    for(int i = 0; i <= 100; i += 2)
    {
        gl.add(i);
    }

    cout << "Mean: " << gl.mean() << endl;
    cout << "Min: " << gl.percentile(0) << endl;
    cout << "Max: " << gl.percentile(100) << endl;
    cout << "Median: " << gl.median() << endl;
    cout << "75th percentile: " << gl.percentile(75) << endl;
    return 0;
 }
