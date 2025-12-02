% Computes the geometric Jacobian matrix of a serial chain mechanism
% Input: unit_twists - cell array of n 6x1 matrices - unit twists of the joints T_i^{(i-1), (i-1)}
%        H0s - cell array of (at least) n-1 4x4 matrices - reference configurations of the joints H_i^{i-1}(0)
%        q - nx1 matrix - joint variables q^i

function J = get_jacobian(unit_twists, H0s, q)
    n = length(unit_twists);
    % >>>>>> MODIFY >>>>>>
    J = zeros(6, n);
    % <<<<<<<<<<<<<<<<<<<<
    H = eye(4);
    for i = 1:n
        % Compute the skew-symmetric matrix for the current unit twist
        skew_twist_i  = unit_twist_to_skew(unit_twists{i});
        % Apply the exponential map to get the current transformation
        H_i = exp_so3(skew_twist_i, q(i))*H0s{i};
        H = H*H_i; % Update H
        % Step 3: Compute the adjoint transformation for H_prev
        Ad_H_prev = compute_adjoint(H);
        % Step 4: Compute the twist in the base frame
        T_i = Ad_H_prev * unit_twists{i}; % Apply the adjoint to map to base frame
        % Step 5: Store the twist as a column in the Jacobian
        J(:, i) = T_i; % Each column of J is the twist mapped to the base frame
    end
end 


    % Function to compute the adjoint matrix of a 4x4 transformation matrix H
function Ad_H = compute_adjoint(H)
    R = H(1:3, 1:3); % Rotation part
    p = H(1:3, 4);   % Position part
    % Skew-symmetric matrix of the position vector
    p_hat = [0    -p(3) p(2);
             p(3)  0   -p(1);
            -p(2) p(1)  0  ];
    % Construct the 6x6 adjoint matrix
    Ad_H = [R, zeros(3, 3);
            p_hat * R, R];
end