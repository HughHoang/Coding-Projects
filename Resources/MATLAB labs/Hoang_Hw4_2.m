A = randi([0 1], 5,5);
B = randi([0 1], 5,5);
I = randi([1 1], 5,5);
out;
out = (A + I) * (A - I) - (A^2 - I);
isempty(out)

out = (A + B) * (A - B) - (A^2 - B^2);
disp(out);
isempty(out)