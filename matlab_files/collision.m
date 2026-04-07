function out = collision(cornerA, cornerB, cornerC, cornerD, pointA, pointB)
    %pointA, pointB: 3D coordinates of the line segment endpoints
    %cornerA, cornerB, cornerC, cornerD: 3D coordinates of the rectangle vertices

    %calculate the plane normal vector
    AB = cornerB - cornerA;
    AD = cornerD - cornerA;
    n = cross(AB, AD);
    n = n / norm(n); % normalize the normal vector

    %line equation: p(t) = pointA + t * u, where u = pointB - pointA
    u = pointB - pointA;

    %check if line is parallel to the plane
    if abs(dot(n, u)) < 1e-6
        out = false; % Line is parallel to plane
        return;
    end

    t = dot(n, cornerA - pointA) / dot(n, u);

    %check if intersection is on the line segment
    if t < 0 || t > 1
        out = false; % intersection point outside segment range
        return;
    end

    %intersection point
    I = pointA + t * u;

    %check if I is within the bounds using dot products:
    %dot product with AB should be between 0 and dot(AB, AB)
    %dot product with AD should be between 0 and dot(AD, AD)
    AI = I - cornerA;
    dot_AI_AB = dot(AI, AB);
    dot_AI_AD = dot(AI, AD);
    dot_AB_AB = dot(AB, AB);
    dot_AD_AD = dot(AD, AD);

    if (dot_AI_AB >= 0 && dot_AI_AB <= dot_AB_AB) && (dot_AI_AD >= 0 && dot_AI_AD <= dot_AD_AD)
        out = true;
    else
        out = false;
    end
end
