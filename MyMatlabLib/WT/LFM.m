clc
clear all
close all
T = 1;%����ʱ��
f = 1e5;%������
t = 0:1/f:(T-1/f); % ������
n = length(t); % ��������
% ���Ե�Ƶ�ź� s(t)=a(t)cos[2��f0 t+��kt^2]��a(t)�ǰ��磬f0�ǵ�ƵƵ��
A_lfm = 10;
f_lfm = 1000;
k_lfm = 800000;
y_lfm = A_lfm*cos(2*pi*f_lfm*t+pi*k_lfm*t.^2);