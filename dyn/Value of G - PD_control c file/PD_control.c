#include <stdio.h>
#include <math.h>

double temp = 0;

void initial_theta_dot(double x){
  temp = x;
}

double PD_control(theta, theta_dot, theta_ref, theta_dot_ref)
double theta, theta_dot, theta_ref, theta_dot_ref;
{
  double previous_theta_dot = temp;
  initial_theta_dot(theta_dot);

  double torque;
  double cos(double x);
  double frequency = 500;
  double theta_dot_dot;
  theta_dot_dot = (theta_dot-previous_theta_dot)/(1/frequency);

  printf("\nValue of theta: %f\n", theta);
  printf("Value of previous_theta_dot: %f\n", previous_theta_dot);
  printf("Value of theta_dot: %f\n", theta_dot);
  printf("Value of theta_dot_dot: %f\n", theta_dot_dot);

  // dynamic model form: τ = IΘ" + BΘ' + G(Θ) i.e torque = I*theta_dot_dot + B*theta_dot + G*cos(theta);

  //_______________________________Value of G______________________________
  double G; // assume G = mgl, [ G(Θ) = mglcos(Θ) ]
  torque = 1.15; // torque applied
  // determine G, at τ = constant, Θ"=0, Θ'=0
  // value of G = (torque - I*theta_dot_dot - B*theta_dot)/cos(theta); 
  G = torque/cos(theta); // for torque = constant, theta_dot_dot = 0, theta_dot = 0
  printf("Value of G: %f\n", G);
  return(torque);
}



