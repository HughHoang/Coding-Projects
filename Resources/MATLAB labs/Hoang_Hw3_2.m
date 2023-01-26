A = [3 -4 10 7 -4;-5 -3 -7 -11 15;4 3 5 2 1; 8 -7 23 4 15];
B = rref(A);

j=1;
for i = 1:size(B)-1
    if B(i,j) == 0
        A(:,i) = [];
    end
    j= j+1;
end
    
disp(A)
