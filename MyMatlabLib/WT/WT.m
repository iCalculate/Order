clear,clc
close all
%%%%%%　小波变换　%%%%%%%%%%%%%%%%
fs=4096;
t=1/fs:1/fs:1;
T = 2;%采样时间
f = 1000;%采样率
t = 0:1/f:(T-1/f); % 采样点
n = length(t); % 采样点数
A_lfm = 1;
f_lfm = 10;
k_lfm = 200;
y_lfm = A_lfm*cos(2*pi*f_lfm*t+pi*k_lfm*t.^2);
s=y_lfm;
subplot(211)
plot(t,s,'b')
title('原始单频信号')

%%%%%%%%%%%%%%%%%%%%%%% 小波时频图绘制 %%%%%%%%%%%%%%%%%%%%%
wavename='cmor4-4';%%选用带宽参数和中心频率均为4 的复morlet小波
totalscal=256;%尺度序列的长度，即scal的长度
fc=centfrq(wavename);

%%%%%%%%% 绘制时间域小波波形 %%%%%
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
xlabel('时间 t/s')
ylabel('频率 f/Hz')
title('小波时频图')