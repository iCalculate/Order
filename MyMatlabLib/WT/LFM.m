clc
clear all
close all
T = 1;%采样时间
f = 1e5;%采样率
t = 0:1/f:(T-1/f); % 采样点
n = length(t); % 采样点数
% 线性调频信号 s(t)=a(t)cos[2πf0 t+πkt^2]，a(t)是包络，f0是调频频率
A_lfm = 10;
f_lfm = 1000;
k_lfm = 800000;
y_lfm = A_lfm*cos(2*pi*f_lfm*t+pi*k_lfm*t.^2);