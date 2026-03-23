function [] = draw_rover(P1, P2, P3, P4, P5, P6, P7, P8, P9, ax1)
    %getting the points on the other side of the rover
    P1prime = P1 * [1 0 0 0; 0 1 0 0.530; 0 0 1 0; 0 0 0 1];
    P2prime = P2 * [1 0 0 0; 0 1 0 0.530; 0 0 1 0; 0 0 0 1];
    P3prime = P3 * [1 0 0 0; 0 1 0 0.530; 0 0 1 0; 0 0 0 1];
    P4prime = P4 * [1 0 0 0; 0 1 0 0.530; 0 0 1 0; 0 0 0 1];
    P5prime = P5 * [1 0 0 0; 0 1 0 0.530; 0 0 1 0; 0 0 0 1];
    P6prime = P6 * [1 0 0 0; 0 1 0 0.530; 0 0 1 0; 0 0 0 1];
    P7prime = P7 * [1 0 0 0; 0 1 0 0.530; 0 0 1 0; 0 0 0 1];
    P8prime = P8 * [1 0 0 0; 0 1 0 0.530; 0 0 1 0; 0 0 0 1];
    P9prime = P9 * [1 0 0 0; 0 1 0 0.530; 0 0 1 0; 0 0 0 1];

    %getting cartesian coordinates
    frames1 = [P1, P2, P3, P4, P5, P9, P6, P7, P8, P1];

    positions1 = zeros(4, max(size(frames1))/4);
    for i = 1:max(size(frames1))/4
        positions1(:, i) = frames1(:, 4*i);
    end
    Xs1 = positions1(1, :);
    Ys1 = positions1(2, :);
    Zs1 = positions1(3, :);

    %getting cartesian coordinates
    frames2 = [P1prime, P2prime, P3prime, P4prime, P5prime, P9prime, P6prime, P7prime, P8prime, P1prime];

    positions2 = zeros(4, max(size(frames2))/4);
    for i = 1:max(size(frames2))/4
        positions2(:, i) = frames2(:, 4*i);
    end
    Xs2 = positions2(1, :);
    Ys2 = positions2(2, :);
    Zs2 = positions2(3, :);

    %plotting points in 3d space
    %fig1 = figure('Name', 'robotic arm test', 'NumberTitle', 'off');
    %ax1 = axes('Parent', fig1, 'Projection', 'perspective');
    hold on;
    plot3(ax1, Xs1, Ys1, Zs1, '-o', 'LineWidth', 10, 'MarkerSize', 6, 'Color', "blue");
    plot3(ax1, Xs2, Ys2, Zs2, '-o', 'LineWidth', 10, 'MarkerSize', 6, 'Color', 'blue');

    for i = 1:max(size(Xs1))
        plot3(ax1, [Xs1(i), Xs2(i)], [Ys1(i), Ys2(i)], [Zs1(i), Zs2(i)], '-o', 'LineWidth', 10, 'MarkerSize', 6, 'Color', "blue");
    end


    grid(ax1, 'on');
    axis(ax1, 'equal');
    xlim(ax1, [-1, 1]);
    ylim(ax1, [-1, 1]);
    zlim(ax1, [-0.5, 1]);
    xlabel(ax1, 'X');
    ylabel(ax1, 'Y');
    zlabel(ax1, 'Z');
    hold off;
end
