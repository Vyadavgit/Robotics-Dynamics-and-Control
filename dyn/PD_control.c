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
  printf("Value of theta_ref: %f\n", theta_ref);
  printf("Value of theta_dot_ref: %f\n", theta_dot_ref);

  // values found after system identification procedure
  double I=0.36;
  double B=0.100115;
  double G=1.176;
  double Kp;
  double Kd;

  Kd = 50; // arbitrary value that staisfies the relation: Kp = (Kd*Kd)/4
  Kp = (Kd*Kd)/4;// Kd = 2*sqrt(Kp);
  // Control force: 𝐹𝑐 = 𝑚(𝐾𝑝(𝑥 − 𝑥𝑑) + 𝐾𝑑(𝑥')) + 𝑏𝑥' + 𝑚𝑔𝑠𝑖𝑛(𝛼), 𝐾𝑑^2 = 4𝑚𝐾𝑝 // xd = theta_def
  // similarly the control torque for rotational configuration is given as:
  torque = I*(Kp*(theta_ref - theta) - Kd*theta_dot) + B*theta_dot + G*cos(theta); 
  printf("Value of Torque being applied: %f\n", torque);
  return torque;
}



