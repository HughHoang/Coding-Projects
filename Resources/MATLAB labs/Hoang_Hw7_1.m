I = eye(3);
syms x(t);
for i = [32, 31.9, 31.8, 32.1, 32.2]
    A=[-6 28 21;4 -15 -12;-8 i 25];
    e=eig(A);
    fplot(det(A-t*I),[-1 4])
end
