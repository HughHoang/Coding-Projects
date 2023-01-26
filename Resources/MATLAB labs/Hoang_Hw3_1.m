A = [0.5 0.5 0.5 0.5;0.5 0.5 -0.5 -0.5;0.5 -0.5 0.5 -0.5;0.5 -0.5 -0.5 0.5];
a = vecnorm(A(:,1));
b = vecnorm(A(:,2));
c = vecnorm(A(:,3));
d = vecnorm(A(:,4));
result=A(:,1) .* A(:,2).*A(:,1).*A(:,3).*A(:,1) .* A(:,4).* A(:,2) .*A(:,3).* A(:,2).*A(:,4) .*A(:,3) .* A(:,4);
normresult = vecnorm(result);
disp(result);
for i = 1:5
    u = randi([0 9],4,1);
    vecu = vecnorm(u);
    Au=A*u;
    disp(u);
    disp(Au);
end