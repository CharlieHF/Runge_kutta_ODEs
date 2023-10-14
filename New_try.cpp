#include <iostream>
#include <cmath>
//using namespace std;

// m1=h*u
// n1=h*v
// p1=h*t
// q1=h*f(x,u,v,t)
//
// m2=h*(u+(0.5)*n1)
// n2=h*(v+(0.5)*p1)
// p2=h*(t+(0.5)*q1)
// q2=h*(f(x+(0.5)*h, y+(0.5)*m1, u+(0.5)*n1, v+(0.5)*p1, t+(0.5)*q1))
// 
// m3=h*(u+(0.5)*n2)
// n3=h*(v+(0.5)*p2)
// p3=h*(t+(0.5)*q2)
// q3=h*f(x+(0.5)*h,y+(0.5)*m2, u+(0.5)*n2, v+(0.5)*p2, t+(0.5)* q2)
// 
// m4=h*(u*n3)
// n4=h*(v+p3)
// p4=h*(t+q3)
// q4=h*f(x+h,y+m3,u+n3,v+p3,t+q3)


// Define the ODE dx/dt


//u= y'
//v=y''
// t=y'''
// s=y''''=f(x)
//

double f(double x, double y, double u, double v, double t) {
    return (-5.0 * v - (0.1) * x * y * y * y);

}




double Runge_kutta(double h,double n,double x){
    //initialize
    double y = 1;
    double u = 0; //u=y'
    double v = 0; //v=y''
    double t = 0; //t=y'''
    int i = 0;
    
    while (i < n) {
        double m1 = h * u;
        double n1 = h * v;
        double p1 = h * t;
        double q1 = h * f(x, y, u, v, t);
        //

        double m2 = h * (u + 0.5 * n1);
        double n2 = h * (v + 0.5 * p1);
        double p2 = h * (t + (0.5) * q1);
        double q2 = h * (f(x + (0.5) * h, y + (0.5) * m1, u + (0.5) * n1, v + (0.5) * p1, t + (0.5) * q1));
        //

        double m3 = h * (u + (0.5) * n2);
        double n3 = h * (v + (0.5) * p2);
        double p3 = h * (t + (0.5) * q2);
        double q3 = h * f(x + (0.5) * h, y + (0.5) * m2, u + (0.5) * n2, v + (0.5) * p2, t + (0.5) * q2);
        //
        double m4 = h * (u * n3);
        double n4 = h * (v + p3);
        double p4 = h * (t + q3);
        double q4 = h * f(x + h, y + m3, u + n3, v + p3, t + q3);
        //double onesix = 1.0 / 6.0;
        y = y + (1.0 / 6.0) * (m1 + 2 * m2 + 2 * m3 + m4);
        u = u + (1.0 / 6.0) * (n1 + 2 * n2 + 2 * n3 + n4);
        v = v + (1.0 / 6.0) * (p1 + 2 * p2 + 2 * p3 + p4);
        t = t + (1.0 / 6.0) * (q1 + 2 * q2 + 2 * q3 + q4);
        x = x + h;
        std::cout << x << "  " << y << "\n";
        i++;
    }


    return x;

}



int main() {
    double x = 0;
    double h = 0.05;
    double n = 30/ h;
    double result = Runge_kutta(h, n,x);
    // at h = 0.05, y(30) = -0.593634

    //std::cout << f(1, 1, 3, 2, 1);
    return 0;
}