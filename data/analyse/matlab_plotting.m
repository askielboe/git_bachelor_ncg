%% Load data
load uU_Z_uU_20_500_gnu.txt;
load uU_G_uU_20_500_gnu.txt;

m34 = uU_G_uU_20_500_gnu(:,1);
G = uU_G_uU_20_500_gnu(:,2);
Z = uU_Z_uU_20_500_gnu(:,2);

%% Calculations
ZG = 0.1*G + Z;

%Zerror = uU_Z_uU_20_500_gnu(:,3);
%Gerror = uU_G_uU_20_500_gnu(:,3);
%ZGerror = Zerror + Gerror;

%% Draw the plot (ZG together with Z)
hold off
semilogy(m34,ZG,'-b');
hold on
semilogy(m34,Z,'-r');

%% Plot labels
title('u,U -> u,U');
xlabel('M34 (GeV)');
ylabel('Diff. cross section [pb/GeV]');
legend('0.1 * (G -> uU) + (Z -> uU)','Z -> uU');