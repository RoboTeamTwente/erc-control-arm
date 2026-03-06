x = 0.500;
y = -0.500;
z = -0.200;
alpha = 90 * (pi/180);

[theta0, theta1, theta3, theta4] = inverse_kinematics(x, y, z, alpha);

[Pbase, P1, P2, P3, P4, P5, P6, P7] = points(theta0, theta1, theta3, theta4);

draw_arm(Pbase, P1, P2, P3, P4, P5, P6, P7);

[x, y, z] = forward_kinematics(theta0, theta1, theta3, theta4)