A = [1 0 0 0; 0 1 5 0; 0 0 1 0; 0 0 0 1];
B = [0 0 0 0; 0 0 0 0; 0 0 0 0; 0 0 0 0];
for i = 1:length(A)
    B(1,i) = A(1,i)-A(3,i)+A(4,i);
    B(2,i) = 4*A(1,i);
    B(3,i) = 3*A(4,i) - 2*A(1,i);
    B(4,i) = A(3,i) /2;
    B(5,i) = 2 * A(2,i) + 5 * A(4,i);
end
    disp(B);

