% Computes the joint velocities dq to move the end effector to the setpoint
% Input: q - nx1 matrix - joint variables q^i
%        setpoint - 3x1 matrix - desired end-effector position
%        dsetpoint - 3x1 matrix - desired end-effector velocity
%        H0s - cell array of n 4x4 matrices - reference (q = 0) configurations of the links H_i^{i-1}(0)
%        unit_twists - cell array of n 6x1 matrices - unit twists of the joints T_i^{(i-1), (i-1)}
% Output: dq - nx1 matrix - joint velocities dq^i

function dq = calculate_dq(q, setpoint, dsetpoint, H0s, unit_twists)
k=30;

% Setpoint is x,y,z location 
p_set = setpoint;
% Setpoint is x,y,z location of H_e^0
p_set_dot = dsetpoint;

% p_ee is determined using the kinematics part
Hs = direct_kinematics(unit_twists, H0s, q);
Hs_e = Hs{end};
p_ee = Hs_e(1:3, 4);

% error e = p_set - p_ee
error_matrix =  p_set - p_ee;
% p_set_dot
%p_set_dot = sqrt((p_set_dot_coordinates(1)^2+p_set_dot_coordinates(2)^2+p_set_dot_coordinates(3)^2));

% Determine dp_ee
dp_ee = p_set_dot + k*error_matrix;

% Limit the end-effector velocity
if norm(dp_ee) > 700
    dp_ee = 700*(dp_ee/norm(dp_ee));
end

% H_e and H^e, gechecken en is goed
H_e = determine_H_e(p_ee);
He = inv(H_e);

% Adjoint He
AdHe = compute_adjoint(He);

% Jacobian J(q)
jacobian = get_jacobian(unit_twists, H0s, q);

% Jbar
Jbar_complete = AdHe * jacobian;
rows = size(Jbar_complete,1);
Jbar = Jbar_complete(rows-2:rows, :); 
% Transpose Jbar
Jtranspose = Jbar';
% Pseudo inverse
J_pseudo_inverse = Jtranspose*inv(Jbar*Jtranspose);

% second_matrix
second_matrix = p_set_dot+k*error_matrix;
% dq  = q^dot 
dq = J_pseudo_inverse*second_matrix;

end

% Functions H^0_e
function H_e = determine_H_e(p_ee)
    H_e = eye(4);
    H_e(1:3, 4) = p_ee;
end

% Adjoint calculator
function Ad_He = compute_adjoint(He)
    R = He(1:3, 1:3); % Rotation part
    p = He(1:3, 4);   % Position part
    % Skew-symmetric matrix of the position vector
    p_hat = [0    -p(3) p(2);
             p(3)  0   -p(1);
            -p(2) p(1)  0  ];
    % Construct the 6x6 adjoint matrix
    Ad_He = [R, zeros(3, 3);
            p_hat * R, R];
end
