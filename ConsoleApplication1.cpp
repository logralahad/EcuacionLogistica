// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <random>

using namespace std;

double esquema_explicito(int n, double r0, double delta_t) {
    vector<double> y_(n);
    y_[0] = r0;

    for (int i = 0; i < n - 1; i++)
    {
        double rn = y_[i];
        y_[i + 1] = rn + (delta_t * (rn * (1 - rn)));
    }
    return y_[n - 1];
}

double esquema_implicito(int n, double r0, double delta_t) {
    vector<double> z_(n);
    z_[0] = r0;

    for (int i = 0; i < n - 1; i++)
    {
        double zn = z_[i];
        double parte1 = (double)1 / (double)(2 * delta_t);
        double parte2 = delta_t - 1;
        double raiz1 = pow((1 - delta_t), 2);
        double raiz2 = (double)-4 * delta_t * -zn;
        double raiz = parte2 + sqrt(raiz1 + raiz2);
        
        z_[i + 1] = parte1 * raiz;
    }
    return z_[n - 1];
}

int main()
{   

    double valor_real = 0.7310585786;
    printf("    Valor real con r(1) = %1.10f    \n\n", valor_real);
    for (int n = 1; n <= 1000000; n *= 10)
    {
        double r0 = (double)1 / 2;

        double delta_t = (double)1 / (double)n;
        double yn = esquema_explicito(n + 1, r0, delta_t);
        double error_y = abs(valor_real - yn);

        double zn = esquema_implicito(n + 1, r0, delta_t);
        double error_z = abs(valor_real - zn);

        printf("   N: %7d   |   t: %1.8f   |   Yn: %1.8f   |   EYn: %1.8f   |   Zn: %6.8f   |   EZn: %7.8f\n",
            n, delta_t, yn, error_y, zn, error_z);
    }


}
    
    


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
