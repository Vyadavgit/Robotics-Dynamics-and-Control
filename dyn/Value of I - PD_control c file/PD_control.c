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

  //_______________________________Value of I______________________________
  double I;
  double B=0.100115; //
  double G=1.176; // obtained when arm stops i.e Θ'=0 and Θ"=0
  torque = 7; // torque applied
  // determine I, at τ = constant + G*cos(0) + B*theta_dot, Θ"=constant, Θ'= keeps changing at a constant rate
  // compensate for gravitational force and viscous friction => torque + G*cos(theta) + B*theta_dot = I*(theta_dot_dot) + B*theta_dot + G*cos(theta);
  // Value of I = (torque + G*cos(theta) + B*theta_dot - G*cos(theta) - B*theta_dot)/theta_dot_dot;
  I = torque/theta_dot_dot; // for Θ"=constant i.e Θ'= keeps changing at a constant rate
  printf("Value of I: %f\n", I);
  return(torque + G*cos(theta) + B*theta_dot); // compensated for gravity and friction
}



