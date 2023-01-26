for k = 1:10
  A(k) = k;
  B = hilb(k);
  C(k) = det(B);
end
loglog(A,C)