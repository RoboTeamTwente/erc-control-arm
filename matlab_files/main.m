 
alpha = 60 * (pi/180);

width = 0.530;

P0 = [1 0 0 0.4;
      0 1 0 0;
      0 0 1 0;
      0 0 0 1];

dimentions = [
    0.230
    0.412
    0.210
    0.383
    0.258
    0.230
    0.285
    0.765
];

%getting all reachable point with the current gripper angle
reachablePoints = [];
for x = -1:0.1:1
  for y = -1:0.1:1
      for z = -1:0.1:1
          [theta0, theta1, theta3, theta4, error] = inverse_kinematics(x, y, z, alpha);
          if ~error
              [armPbase, armP1, armP2, armP3, armP4, armP5, armP6, armP7] = points_arm(theta0, theta1, theta3, theta4, P0);
              [roverP1, roverP2, roverP3, roverP4, roverP5, roverP6, roverP7, roverP8, roverP9] = points_rover(P0, width, dimentions);
              if is_reachable([armPbase, armP1, armP2, armP3, armP4, armP5, armP6, armP7], width, [roverP1, roverP2, roverP3, roverP4, roverP5, roverP6, roverP7, roverP8, roverP9])
                  reachablePoints = [reachablePoints, [x+0.4; y; z]]; %x+0.4 is to convert point reference from the base of the arm to the world
              end
          end
      end
  end
end

x = -0.4 - 0.4;
y = -0.265;
z = 0.100;

size(reachablePoints, 2);

[theta0, theta1, theta3, theta4, error] = inverse_kinematics(x, y, z, alpha);


[armPbase, armP1, armP2, armP3, armP4, armP5, armP6, armP7] = points_arm(theta0, theta1, theta3, theta4, P0);

draw_arm(armPbase, armP1, armP2, armP3, armP4, armP5, armP6, armP7);

%[x, y, z] = forward_kinematics(theta0, theta1, theta3, theta4)


[roverP1, roverP2, roverP3, roverP4, roverP5, roverP6, roverP7, roverP8, roverP9] = points_rover(P0, width, dimentions);

draw_rover(roverP1, roverP2, roverP3, roverP4, roverP5, roverP6, roverP7, roverP8, roverP9, width);

for i = 1:size(reachablePoints, 2)
    %if (reachablePoints(1, i) > -0.495 && reachablePoints(1, i) < 0.535) ...
    %&& (reachablePoints(2, i) > -0.265 && reachablePoints(2, i) < 0.265) ...
    %&& (reachablePoints(3, i) > -0.23 && reachablePoints(3, i) < 0.21) 
         plot3([reachablePoints(1, i)], [reachablePoints(2, i)], [reachablePoints(3, i)], '-o', 'MarkerSize', 10, 'Color', 'green');
    %end
end

%{
P1 = [0 4 3];
P2 = [-3 -4 -3];

A = [1 0 1];
B = [-1 0 1];
C = [-1 0 -1];
D = [1 0 -1];

test = collision(A, B, C, D, P1, P2)

Xs = [A(1), B(1), C(1), D(1), A(1)];
Ys = [A(2), B(2), C(2), D(2), A(2)];
Zs = [A(3), B(3), C(3), D(3), A(3)];

figure;
plot3(Xs, Ys, Zs, '-o', 'LineWidth', 10, 'MarkerSize', 6, 'Color', "red");
hold on;
plot3([P1(1) P2(1)], [P1(2) P2(2)], [P1(3) P2(3)], '-o', 'LineWidth', 10, 'MarkerSize', 6, 'Color', "blue");
%}
