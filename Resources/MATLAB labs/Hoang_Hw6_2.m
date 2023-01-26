M = eye(100);

M(2:101:end) = -1;
M(1:101:end) = 3;
M(101:101:end) = -2;
A=det(M);
disp(A)