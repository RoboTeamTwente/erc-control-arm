function out = is_reachable(armPoints, width, roverPoints)
    %getting cartesian coordinates
    armVerteces = zeros(3, size(armPoints, 2)/4);
    for i = 1:size(armPoints, 2)/4
        armVerteces(1:3, i) = armPoints(1:3, 4*i);
    end

    roverVerteces = zeros(3, size(roverPoints, 2)/2);
    prime = size(roverVerteces, 2)/2;
    for i = 1:size(roverPoints, 2)/4
        roverVerteces(1:3, i) = roverPoints(1:3, 4*i);
        roverVerteces(1:3, i+prime) = roverPoints(1:3, 4*i);
    end

    for i = 1:prime
        roverVerteces(2, i+prime) = roverVerteces(2, i) + width;
    end

    %defining relavant joint connections for detemining collisions
    armJoints = [armVerteces(:,2) armVerteces(:,3) armVerteces(:,7) armVerteces(:,8)];
    intersection = false;
    %going over every relevant collision
    for i = 1:size(armJoints, 2)-1
        %z-axis facing faces
        intersection = intersection | collision(roverVerteces(:,2), roverVerteces(:,3), roverVerteces(:,3+prime), roverVerteces(:,2+prime), armJoints(:,i), armJoints(:,i+1));
        intersection = intersection | collision(roverVerteces(:,4), roverVerteces(:,5), roverVerteces(:,5+prime), roverVerteces(:,4+prime), armJoints(:,i), armJoints(:,i+1));
        intersection = intersection | collision(roverVerteces(:,9), roverVerteces(:,6), roverVerteces(:,6+prime), roverVerteces(:,9+prime), armJoints(:,i), armJoints(:,i+1));

        %x-axis facing faces
        intersection = intersection | collision(roverVerteces(:,1), roverVerteces(:,2), roverVerteces(:,2+prime), roverVerteces(:,1+prime), armJoints(:,i), armJoints(:,i+1));
        intersection = intersection | collision(roverVerteces(:,3), roverVerteces(:,4), roverVerteces(:,4+prime), roverVerteces(:,3+prime), armJoints(:,i), armJoints(:,i+1));
        intersection = intersection | collision(roverVerteces(:,5), roverVerteces(:,9), roverVerteces(:,9+prime), roverVerteces(:,5+prime), armJoints(:,i), armJoints(:,i+1));
        intersection = intersection | collision(roverVerteces(:,6), roverVerteces(:,7), roverVerteces(:,7+prime), roverVerteces(:,6+prime), armJoints(:,i), armJoints(:,i+1));

        %y-axis facing faces
        %TODO

        if intersection
            out = false;
            return;
        end
    end
    out = true;
end
