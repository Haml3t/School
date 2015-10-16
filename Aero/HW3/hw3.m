clc; clear all;

syms u v w u0 v0 alphan betan lambdan etan n t x y z x0 y0 t0;

cases = {
        1 1 5 5 2 2;
        1 1 5 2 5 5;
        1 1 2 2 2 2;
        1 1 2 2 2 5;
        };
casesHeader = {
              u0 v0 alphan betan etan lambdan;
              };

u = ((-1) ^ n) * u0 * ((cos(alphan * t) + alphan * t * sin(alphan * ...
                                                  t))/((t ^ 2) ...
                                                  *sinh(etan * x)));
v = v0 * ((betan * t * cos(betan * t) - sin(betan * t))/((t ^ 2) * ...
                                                  cosh(lambdan * ...
                                                  y)));
w = 0;

V = [u v w];

% a) vorticity field
vort = curl(V,[x y z]);

% b) streamline equation
% dy/dx = v/u
psi = int((1 / v), y, y0, y) - int((1 / u), x, x0, x);

% c) pathline function
% pathX = int(u, t, t0, t);
% pathY = int(v, t, t0, t);
pathX = (1 / etan) * acosh(etan * int(u * sinh(etan * x), t));
pathY = (1 / lambdan) * asinh(lambdan * int(v * cosh(lambdan * y), ...
                                            t));

% d) streakline

% e)
meshx = meshgrid(0:0.1:1);
meshy = meshgrid(0:0.1:1);
%[meshx, meshy] = meshgrid(0:0.1:1, 0:0.1:1);
startx = (0.1:0.1:1);
starty = ones(size(startx));
for(i = 1:4)
    subs([u, v], casesHeader, cases(i,:));
    subs([u, v], n, i);
    subs([u, v], {x, y}, {meshx, meshy});
    figure
    quiver(meshx, meshy, u, v);
    subplot(2, 2, i);
    streamline(meshx, meshy, u, v, startx, starty);
    hold on;
end
