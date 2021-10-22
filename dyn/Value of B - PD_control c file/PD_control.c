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

  //_______________________________Value of B______________________________
  double B;
  double G = 1.176; // obtained when angular velocity and angular acceleration are zero i.e when arm stops
  torque = 0.9; // torque applied
  // determine B, at τ = constant + G*cos(0), Θ"=0, Θ'= constant
  // compensate for gravitational force => torque + G*cos(theta) = I*(theta_dot_dot) + B*theta_dot + G*cos(theta);
  // value of B = (torque + G*cos(theta) - I*theta_dot_dot - G*cos(theta))/theta_dot;
  B = torque/theta_dot; // for theta_dot = constant i.e theta_dot_dot = 0 
  printf("Value of B: %f\n", B);
  return(torque + G*cos(theta)); // compensated for gravity
}



