% Exponential map
function H = exp_so3(skew_twist, angle)
    % Computes matrix exponential of the twist matrix scaled by angle
    H = expm(skew_twist * angle);
end