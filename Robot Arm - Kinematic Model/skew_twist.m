
function skew_twist = unit_twist_to_skew(unit_twist)
% Extract angular components (omega) and linear components (v)
    omega = unit_twist(1:3); % [omega_x, omega_y, omega_z]
    v = unit_twist(4:6);     % [v_x, v_y, v_z]

    % Construct the skew-symmetric matrix for omega
    omega_hat = [0       -omega(3) omega(2);
                 omega(3) 0       -omega(1);
                -omega(2) omega(1) 0      ];

    % Construct the full 4x4 twist matrix
    skew_twist = [omega_hat, v(:);  % Place v as the last column (converted to column vector)
                    0 0 0 0];
end
