function baversion = bam2l(S)
key = {
    'PHI1','\Phi_1(s)';
    'PHI2','\Phi_2(s)';
    'THETA','\Theta(s)';
    'T','T(s)';
    'DELTAF','\Delta{F(s)}';
    'Jm','J_m';
    'J1','J_1';
    'J2','J_2';
    'br','b_r';
    'R1','R_1';
    'R2','R_2';
    'kr','k_r';
    'e','e';
    };
[keyLength,keyWidth] = size(key);
%test = key{1,1}
%strcat('\mathrm{',test,'}')
stock = latex(S);
baversion = stock;
for i = 1:keyLength
    bad = key{i,1};
    good = key{i,2};
    fullbad = strcat('\mathrm{',bad,'}');
    fullgood = strcat('{',good,'}');
    baversion = strrep(baversion,fullbad,fullgood);
end
return