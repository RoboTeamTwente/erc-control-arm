%calculating points from Pbase
Pbase = P0 * TP0toPbase;
P1 = Pbase * TPbasetoP1;
P2 = P1 * TP1toP2;
P6 = P2 * TP2toP6;
P7 = P6 * TP6toP7;

P5 = P2 * TP2toP5;

P3 = Pbase * TPbasetoP3;
P4 = P3 * TP3toP4;
P5prime = P4 * TP4toP5;

%getting cartesian coordinates
frames1 = [Pbase, P1, P2, P5, P6, P7];

positions1 = zeros(4, max(size(frames1))/4);
for i = 1:max(size(frames1))/4
    positions1(:, i) = frames1(:, 4*i);
end
Xs1 = positions1(1, :);
Ys1 = positions1(2, :);
Zs1 = positions1(3, :);

%getting cartesian coordinates
frames2 = [P3, P4, P5prime];

positions2 = zeros(4, max(size(frames2))/4);
for i = 1:max(size(frames2))/4
    positions2(:, i) = frames2(:, 4*i);
end
Xs2 = positions2(1, :);
Ys2 = positions2(2, :);
Zs2 = positions2(3, :);

%plotting points in 3d space
fig1 = figure('Name', 'robotic arm test', 'NumberTitle', 'off');
ax1 = axes('Parent', fig1, 'Projection', 'perspective');
plot3(ax1, Xs1, Ys1, Zs1, '-o', 'LineWidth', 10, 'MarkerSize', 6, 'Color', "blue");
hold on;
plot3(ax1, Xs2, Ys2, Zs2, '-o', 'LineWidth', 10, 'MarkerSize', 6, 'Color', "blue");%, 'Color', 'red');

%{
frames3 = [P6i, P7i];
positions3 = zeros(4, max(size(frames3))/4);
for i = 1:max(size(frames3))/4
    positions3(:, i) = frames3(:, 4*i);
end
Xs3 = positions3(1, :);
Ys3 = positions3(2, :);
Zs3 = positions3(3, :);

plot3(ax1, Xs3, Ys3, Zs3, '-o', 'LineWidth', 10, 'MarkerSize', 6, 'Color', 'yellow');
%}

grid(ax1, 'on');
axis(ax1, 'equal');
xlim(ax1, [-1000, 1000]);
ylim(ax1, [-1000, 1000]);
zlim(ax1, [-500, 1000]);
xlabel(ax1, 'X');
ylabel(ax1, 'Y');
zlabel(ax1, 'Z');
hold off;