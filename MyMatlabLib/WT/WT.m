clear,clc
close all
%%%%%%��С���任��%%%%%%%%%%%%%%%%
fs=4096;
t=1/fs:1/fs:1;
T = 2;%����ʱ��
f = 1000;%������
t = 0:1/f:(T-1/f); % ������
n = length(t); % ��������
A_lfm = 1;
f_lfm = 10;
k_lfm = 200;
y_lfm = A_lfm*cos(2*pi*f_lfm*t+pi*k_lfm*t.^2);
s=y_lfm;
subplot(211)
plot(t,s,'b')
title('ԭʼ��Ƶ�ź�')

%%%%%%%%%%%%%%%%%%%%%%% С��ʱƵͼ���� %%%%%%%%%%%%%%%%%%%%%
wavename='cmor4-4';%%ѡ�ô������������Ƶ�ʾ�Ϊ4 �ĸ�morletС��
totalscal=256;%�߶����еĳ��ȣ���scal�ĳ���
fc=centfrq(wavename);

%%%%%%%%% ����ʱ����С������ %%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

cparam=2*fc*totalscal;
a=totalscal:-1:1;
scal=cparam./a;
coefs=cwt(s,scal,wavename,1/fs);

f=scal2frq(scal,wavename,1/fs);
subplot(212)
imagesc(t,f,abs(coefs));
colormap(jet)
colorbar
xlabel('ʱ�� t/s')
ylabel('Ƶ�� f/Hz')
title('С��ʱƵͼ')