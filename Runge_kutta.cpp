#include <iostream>
#include <cmath>
using namespace std;
// Define the ODE dx/dt
double f(double t, double x) {
    return (t-1)*(t-1)*(1+x);
}



// Fourth-order Runge-Kutta method
double rungeKutta(double t0, double x0, double h , double n) {
    double t = t0;
    double x = x0;
    double x_anal = 0.947734041054675856639; // this is e^(2/3) -1
    int i = 0;
    //cout << "t" << " ,  " << "x" << "\n";
    cout << "0.0" << " " << "0.0" << "\n";
    while (i < n) {
        double k1 = h * f(t, x);
        double k2 = h * f(t + h / 2, x + k1 / 2);
        double k3 = h * f(t + h / 2, x + k2 / 2);
        double k4 = h * f(t + h, x + k3);
        

    

        x = x + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        t = t + h;

        cout << t << "  " << x << "\n";


     
       

        if (t > 2-h) {
            cout << "# x is equal to " << x <<  " at endpoint t = 2." << "\n";
            cout << "# This differs from our analytical solution by" << (x - x_anal) << "  When step size is : " << h;

        }
        i++;

        

    }

    return x;
}

int main() {

    
    double t0 = 0.0;        // Initial t
    double x0 = 0.0;        // Initial x
    double h = 0.02;         // Step size 
    //h= 0.05 accurate to 7 Figures,
    //Error equal to -2.76373e-08
    // h=0.025
    //Error equal to -1.44673e-09
    //So it is close but still too large an error to be to 8 places
    //h = 0.02
    //ERror equal to -5.6893e-10
    //So h= 0.02 gives accurate to 8 places
    
    double n = 2 / h; // t= 2 , x = 0.94773404 is accurate to 8 places.    
    // It has error less than = 1.05467579e-9
   
    double result = rungeKutta(t0, x0, h, n);
    // analytic solution is 
    // 
    // x= exp((t-1)^3/3+1/3) -1;
  
    //std::cout << "The approtimate solution at t = " << t_target << " is x = " << result << std::endl;
    //std::cout << "x      , t \n";
    
    return 0;
}
