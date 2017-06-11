clc
clear

A=1;C=1.7; %C=63
Gauss=zeros(4096,1);
GaussF=zeros(4096,1);
EnSpc=zeros(4096,1);

%load e:\SAGE\nai_2z\N6051101.DAT
%spcER=N6051101(:,5);

load d:\AMoRE\NIKAt\samples\FonNearPPD2016_1015hours.dat
spcEFON=FonNearPPD2016_1015hours;

%RawCo60Spc=spcER-spcEFON;

load d:\AMoRE\NIKAt\samples\bkgrnd_bi214.dat
spcEBi214=bkgrnd_bi214(:,2);

load d:\AMoRE\NIKAt\samples\bkgrnd_pb214.dat
spcEPb214=bkgrnd_pb214(:,2);

spcEG4=spcEBi214;%+spcEPb214;

%SpcECo60=resample(spcER,1173,770)*0.656;
%SpcECo60=resample(RawCo60Spc,1173,770)*0.656;

for j=1:4095
    for i1=1:4095
        Gauss(i1)=0;
        GaussF(i1)=0;
    end
    for i2=1:4095
        Gauss(i2)=A*exp(-((i2-j)^2/C^2));
    end
    %stairs(Gauss);grid on;
    %waitforbuttonpress
    for i3=1:4095
        GaussF(i3)=Gauss(i3)*spcEG4(j);
    end
    %stairs(GaussF);grid on;
    %waitforbuttonpress
    for i4=1:4095
        EnSpc(i4)=EnSpc(i4)+GaussF(i4);
    end
    %stairs(EnSpc);grid on;
    %waitforbuttonpress
end


%figure;stairs(EnSpc,'r');grid on;hold on;stairs(spcEG4,'k');hold off;

figure;stairs(spcEFON,'r');grid on;hold on;stairs(EnSpc/10,'k');hold off;
