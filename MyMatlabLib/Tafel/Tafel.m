data=load('C:\Users\X270\Desktop\20200111-Sub\Data1\IT-1.txt');
T=data(:,1);
I=-1*data(:,2);
for i=1:length(T)
    if(I(i)>=4e-3)
        I(i)=4e-3+0.1*(I(i)-4e-3);
    end
end
plot(T,I)
% data=load('C:\Users\X270\Desktop\20200111-Sub\Data1\LSV-1.txt');
% V=1000*data(:,1);
% V_aim=zeros(size(V));
% I=-1*data(:,2);
% DertaV=V(2)-V(1);
% Slope=DertaV./diff(log10(I));
% TS_size=size(Slope);
% TS=min(abs(Slope(floor(1/3*TS_size(1)):TS_size(1))));
% fprintf('the value of Tafel is:%6.2f\n',TS);
% Aim_TS=input('Enter your aim Tafel slope:');
% FixPoint=input('Enter your Fix Point(0-100):');
% Rate=Aim_TS/TS;
% FP=FixPoint/100*length(I);
% for i=1:length(I)
%     V_aim(i)=V(i)*Rate+V(FP)*(1-Rate);
% end
% plot(V_aim,I); hold on
% plot(V,I);