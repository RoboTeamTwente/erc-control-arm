function [ax1] = draw_arm(Pbase, P1, P2, P3, P4, P5, P6, P7)
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
    frames2 = [P3, P4, P5];

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
    plot3(ax1, Xs1, Ys1, Zs1, '-o', 'LineWidth', 10, 'MarkerSize', 6, 'Color', "red");
    hold on;
    plot3(ax1, Xs2, Ys2, Zs2, '-o', 'LineWidth', 10, 'MarkerSize', 6, 'Color', 'red');

    grid(ax1, 'on');
    axis(ax1, 'equal');
    xlim(ax1, [-1, 1]);
    ylim(ax1, [-1, 1]);
    zlim(ax1, [-0.5, 1]);
    xlabel(ax1, 'X');
    ylabel(ax1, 'Y');
    zlabel(ax1, 'Z');
end
