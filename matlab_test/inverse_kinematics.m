x = 500;
y = -500;
z = -200;
alpha = 90 * (pi/180);

%all the lengths are in millimeters
LbaseToP1 = 32;
LbaseToP3 = 112;

LP1toP2 = 350;
LP2toP6 = 620;
LP6toP7 = 105;

LP3toP4 = 120;
LP4toP5 = 280;
LP5toP2 = 120;

if x < 0
    theta0 = atan(y/x) + pi;
else
    theta0 = atan(y/x);
end
angToBase = theta0 - pi;

%setting end position, rotated towards the base
P7i = [cos(angToBase) -sin(angToBase) 0 x;
       sin(angToBase)  cos(angToBase) 0 y;
       0               0              1 z;
       0               0              0 1];

%rotation x
P7i = P7i * [1 0  0 0;
             0 0 -1 0;
             0 1  0 0;
             0 0  0 1];

%rotation z
TP7toP6i = [cos(alpha) -sin(alpha) 0 0;
            sin(alpha)  cos(alpha) 0 0;
            0           0          1 0;
            0           0          0 1];

%translation x
TP7toP6i = TP7toP6i * [1 0 0 LP6toP7;
                       0 1 0  0;
                       0 0 1  0;
                       0 0 0  1];

P6i = P7i * TP7toP6i;

%translation z
P1i = [1 0 0 0;
       0 1 0 0;
       0 0 1 LbaseToP1;
       0 0 0 1];


%calculating theta1, theta2 and theta3
L_1i = LP1toP2; L_2i = LP2toP6;
dx = P6i(1,4) - P1i(1,4);
dy = P6i(2,4) - P1i(2,4);
XEi = sqrt(dx*dx + dy*dy);
YEi = P6i(3,4) - P1i(3,4);

theta1 = 2*atan((2*L_1i*YEi + sqrt(- L_1i^4 + 2*L_1i^2*L_2i^2 + 2*L_1i^2*XEi^2 + 2*L_1i^2*YEi^2 - L_2i^4 + 2*L_2i^2*XEi^2 + 2*L_2i^2*YEi^2 - XEi^4 - 2*XEi^2*YEi^2 - YEi^4))/(L_1i^2 + 2*L_1i*XEi - L_2i^2 + XEi^2 + YEi^2));
theta2 = -2*atan(sqrt((- L_1i^2 + 2*L_1i*L_2i - L_2i^2 + XEi^2 + YEi^2)*(L_1i^2 + 2*L_1i*L_2i + L_2i^2 - XEi^2 - YEi^2))/(- L_1i^2 + 2*L_1i*L_2i - L_2i^2 + XEi^2 + YEi^2));

theta3 = 2*pi - alpha -theta1 -theta2;


%getting currently known transforms
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

%translation x then rotation z
TP1toP2 = [cos(theta2) -sin(theta2) 0 LP1toP2;
           sin(theta2)  cos(theta2) 0 0;
           0            0           1 0;
           0            0           0 1];

%translation x then rotation z
TP2toP6 = [cos(theta3) -sin(theta3) 0 LP2toP6;
           sin(theta3)  cos(theta3) 0 0;
           0            0           1 0;
           0            0           0 1];

%translation x
TP6toP7 = [1 0 0 LP6toP7;
           0 1 0 0;
           0 0 1 0;
           0 0 0 1];

%translation z then rotation x
TPbasetoP3 = [1 0 0  0;
              0 0 -1 0;
              0 1 0  LbaseToP3;
              0 0 0  1];

%translation x
TP2toP5 = [1 0 0 -LP5toP2;
           0 1 0 0;
           0 0 1 0;
           0 0 0 1];

%initial position
P0 = [1 0 0 0;
      0 1 0 0;
      0 0 1 0;
      0 0 0 1];

%translation x
TP4toP5 = [1 0 0 LP4toP5;
           0 1 0 0;
           0 0 1 0;
           0 0 0 1];


%getting position for paralellagram angles
P3planar = P0 * TPbasetoP3;
P5planar = P0 * TPbasetoP1 * TP1toP2 * TP2toP5;

%getting parallelageram angles
L_1 = 120; L_2 = 280;
XE = P5planar(1, 4) - P3planar(1, 4);
YE = P5planar(3, 4) - P3planar(3, 4);
theta4 = 2*atan((2*L_1*YE + sqrt(- L_1^4 + 2*L_1^2*L_2^2 + 2*L_1^2*XE^2 + 2*L_1^2*YE^2 - L_2^4 + 2*L_2^2*XE^2 + 2*L_2^2*YE^2 - XE^4 - 2*XE^2*YE^2 - YE^4))/(L_1^2 + 2*L_1*XE - L_2^2 + XE^2 + YE^2));
theta5 = -2*atan(sqrt((- L_1^2 + 2*L_1*L_2 - L_2^2 + XE^2 + YE^2)*(L_1^2 + 2*L_1*L_2 + L_2^2 - XE^2 - YE^2))/(- L_1^2 + 2*L_1*L_2 - L_2^2 + XE^2 + YE^2));


%getting the last transforms
%rotation z
TPbasetoP3 = TPbasetoP3 * [cos(theta4) -sin(theta4) 0 0;
                           sin(theta4)  cos(theta4) 0 0;
                           0            0           1 0;
                           0            0           0 1];

%translation x then rotation z
TP3toP4 = [cos(theta5) -sin(theta5) 0 LP3toP4;
           sin(theta5)  cos(theta5) 0 0;
           0            0           1 0;
           0            0           0 1];


%passing the angles to the forward kinematics file
angles = [theta0, theta1, theta2, theta3, theta4, theta5];

%forward_kinematics;