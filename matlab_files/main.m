x = -0.8;
y = -0.265;
z = 0.100;
alpha = 60 * (pi/180);

P0 = [1 0 0 0.4;
      0 1 0 0;
      0 0 1 0;
      0 0 0 1];

[theta0, theta1, theta3, theta4] = inverse_kinematics(x, y, z, alpha);

[Pbase, P1, P2, P3, P4, P5, P6, P7] = points_arm(theta0, theta1, theta3, theta4, P0);

fig1 = draw_arm(Pbase, P1, P2, P3, P4, P5, P6, P7); 

[x, y, z] = forward_kinematics(theta0, theta1, theta3, theta4);

[P1, P2, P3, P4, P5, P6, P7, P8, P9] = points_rover(P0);

draw_rover(P1, P2, P3, P4, P5, P6, P7, P8, P9, fig1);
