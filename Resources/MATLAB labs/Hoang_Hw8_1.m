u1=[1;2;0;-1];
u2=[0;2;-1;1];
u3=[3;4;1;-4];
v1=[-2;-2;-1;3];
v2=[2;3;2;6];
v3=[-1;4;6;-2];
H = [v1 v2 v3];
A=rref(H);
K = [v1 v2 v3];
B=rref(K);
HK=H+K;
C=rref(HK);
disp(A);
disp(B);
disp(C);
%{u1, u2, u3} is a basis for H.
%{v1, v2, v3} is a basis for K.
%All vectors is a basis for H+K.

