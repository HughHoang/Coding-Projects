for n = [2 4 5 6 7]
    A=randi([0 9],n,n);
    B=randi([0 9],n,n);
    out=det(A + B) - det(A) - det(B) ;
    format long
    disp(out)
    %45

    %-1.071400000000000e+04

    %-6.945800000000001e+04

    %1.127920000000000e+05

    %1.340819999999998e+05
    %first run was above and is nonzero
end
