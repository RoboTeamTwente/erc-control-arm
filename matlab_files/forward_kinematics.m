function [x, y, z] = forward_kinematics(theta0, theta1, theta3, theta4)
    %defining dimentions
    LbaseToP1 = 0.065;
    LbaseToP3 = 0.149;

    LP1toP2 = 0.350;
    LP5toP6 = 0.620;
    LP5toP2 = 0.120;
    LP6toP7 = 0.300;

    LP3toP4 = 0.120;
    LP4toP5 = 0.280;

    %rotation z
    TP0toPbase = [cos(theta0) -sin(theta0) 0 0;
                  sin(theta0)  cos(theta0) 0 0;
                  0            0           1 0;
                  0            0           0 1];

    %translation z then rotation x
    TPbasetoP1 = [1 0 0  0;
                  0 0 -1 0;
                  0 1 0  LbaseToP1;
                  0 0 0  1];

    %rotation z
    TPbasetoP1 = TPbasetoP1 * [cos(theta1) -sin(theta1) 0 0;
                               sin(theta1)  cos(theta1) 0 0;
                               0            0           1 0;
                               0            0           0 1];

    %translation z then rotation x
    TPbasetoP3 = [1 0  0 0;
                  0 0 -1 0;
                  0 1  0 LbaseToP3;
                  0 0  0 1];

    %rotation z
    TPbasetoP3 = TPbasetoP3 * [cos(theta4) -sin(theta4) 0 0;
                               sin(theta4)  cos(theta4) 0 0;
                               0            0           1 0;
                               0            0           0 1];

    %translation x
    TP1toP2 = [1 0 0 LP1toP2;
               0 1 0 0;
               0 0 1 0;
               0 0 0 1];

    %translation x then rotation z
    TP5toP6 = [cos(theta3) -sin(theta3) 0 LP5toP6;
               sin(theta3)  cos(theta3) 0 0;
               0            0           1 0;
               0            0           0 1];

    %translation x
    TP6toP7 = [1 0 0 LP6toP7;
               0 1 0 0;
               0 0 1 0;
               0 0 0 1];
    
    %translation x
    TP3toP4 = [1 0 0 LP3toP4;
               0 1 0 0;
               0 0 1 0;
               0 0 0 1];

    %initial position
    P0 = [1 0 0 0;
          0 1 0 0;
          0 0 1 0;
          0 0 0 1];

    %getting position for paralellagram angles
    P2planar = P0 * TPbasetoP1 * TP1toP2;
    P4planar = P0 * TPbasetoP3 * TP3toP4;

    L_1 = LP4toP5; L_2 = LP5toP2;
    XE = P4planar(1, 4) - P2planar(1, 4);
    YE = P4planar(3, 4) - P2planar(3, 4);
    theta5 = 2*atan((2*L_1*YE + sqrt(- L_1^4 + 2*L_1^2*L_2^2 + 2*L_1^2*XE^2 + 2*L_1^2*YE^2 - L_2^4 + 2*L_2^2*XE^2 + 2*L_2^2*YE^2 - XE^4 - 2*XE^2*YE^2 - YE^4))/(L_1^2 + 2*L_1*XE - L_2^2 + XE^2 + YE^2));
    theta6 = -2*atan(sqrt((- L_1^2 + 2*L_1*L_2 - L_2^2 + XE^2 + YE^2)*(L_1^2 + 2*L_1*L_2 + L_2^2 - XE^2 - YE^2))/(- L_1^2 + 2*L_1*L_2 - L_2^2 + XE^2 + YE^2));
    %adding pi-theta4 to make the actual rotation angle
    theta5 = theta5+(pi-theta4);

    %translation x then rotation z
    TP3toP4 = [cos(theta5) -sin(theta5) 0 LP3toP4;
               sin(theta5)  cos(theta5) 0 0;
               0            0           1 0;
               0            0           0 1];

    %translation x then rotation z
    TP4toP5 = [cos(theta6) -sin(theta6) 0 LP4toP5;
               sin(theta6)  cos(theta6) 0 0;
               0            0           1 0;
               0            0           0 1];

    %calculating all needed points
    Pbase = TP0toPbase;
    P3 = Pbase * TPbasetoP3;
    P4 = P3 * TP3toP4;
    P5 = P4 * TP4toP5;
    P6 = P5 * TP5toP6;
    P7 = P6 * TP6toP7;

    %extracting position
    x = P7(1,4);
    y = P7(2,4);
    z = P7(3,4);
end