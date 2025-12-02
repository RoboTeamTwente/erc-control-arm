% Computes the configuration all the links of a serial chain mechanism relative to the base frame Psi_0
% Input: unit_twists - cell array of n 6x1 matrices - unit twists of the joints T_i^{(i-1), (i-1)}
%        H0s - cell array of n 4x4 matrices - reference (q = 0) configurations of the links H_i^{i-1}(0)
%        q - nx1 matrix - joint variables q^i
% Output: Hs - cell array of n+1 4x4 matrices - current configurations of the links 0 to n of the serial chain mechanism relative to the base frame Psi_0

function Hs = direct_kinematics(unit_twists, H0s, q)
    n = length(unit_twists);
    Hs = cell(1, n+1);
    skew_twists = cell(1, n);
    % >>>>>> INSERT YOUR CODE HERE <<<<<<
    % Make unit twist
    for i = 1:n
    % Extract current unit twist (1x6 vector)
        skew_twists{i} = unit_twist_to_skew(unit_twists{i});
    end
    
    % Base frame
    Hs{1} = eye(4); 
    
    % Loop through each joint and compute the transformation
    for i = 2:7
        % Transformation for joint i-1
        Hs{i} = Hs{i-1} * exp_so3(skew_twists{i-1}, q(i-1)) * H0s{i-1};
        % debugging
        % disp(Hs{i});
    end
end


