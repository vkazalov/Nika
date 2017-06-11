clc
clear

load f:\!WORK\HPGe_samples\bkrgndNIKA990h.dat
BkrgnrdNika=bkrgndNIKA990h;
figure;stairs(BkrgnrdNika,'k');grid on;

% load D:\AMoRE\NIKAt\samples\moliOxFomosMay2016\MoX1_19h.dat
% MoX_1=MoX1_19h;
% load D:\AMoRE\NIKAt\samples\moliOxFomosMay2016\MoX2_74h.dat
% MoX2=MoX2_74h;
% load D:\AMoRE\NIKAt\samples\moliOxFomosMay2016\MoX3_190h.dat
% MoX3=MoX3_190h;
% load D:\AMoRE\NIKAt\samples\moliOxFomosMay2016\MoX4_220h.dat
% MoX4=MoX4_220h;
% load D:\AMoRE\NIKAt\samples\moliOxFomosMay2016\MoX5_155h.dat
% MoX5=MoX5_155h;
% load D:\AMoRE\NIKAt\samples\moliOxFomosMay2016\MoX6_54h.dat
% MoX6=MoX6_54h;
% 
% MoXFull=MoX3+MoX4+MoX5+MoX6;
% %figure;stairs(MoXFull,'r');grid on;
% figure;stairs((MoXFull*100)/619,'r');grid on;hold on;stairs((BkrgnrdNika*100)/990.1,'k');hold off;



% load D:\AMoRE\NIKAt\samples\Nd2O3\Nd2O3_75.588h.dat
% NdoX= Nd2O3_75_588h;
% %figure;stairs(NdoX,'b');grid on;
% figure;stairs((NdoX*100)/75.588,'r');grid on;hold on;stairs((BkrgnrdNika*100)/990.1,'k');hold off;



load f:\!WORK\HPGe_samples\CMO\CMO_77.6.dat
CMO=CMO_77_6;
figure;stairs(CMO,'b');grid on;
figure;stairs((CMO*100)/77.6,'r');grid on;hold on;stairs((BkrgnrdNika*100)/990.1,'k');hold off;



