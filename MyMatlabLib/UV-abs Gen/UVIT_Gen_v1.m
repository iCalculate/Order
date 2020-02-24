%%	Data Import
%data=load('C:\Users\X270\Desktop\20200111-Sub\Data1\IT-1.txt');
load UV;
UV_derta.Neutral = UV(2).Neutral(:,2) - UV(1).Neutral(:,2);
UV_derta.Alkaline = UV(2).Alkaline(:,2) - UV(1).Alkaline(:,2);
UV_derta.Acid = UV(2).Acid(:,2) - UV(1).Acid(:,2);
sprintf('Select the chronoamperometry file:\r\n');
[CA_name,CA_path]=uigetfile('*.*','ÇëÑ¡ÔñÎÄ¼þ');
CAF = importdata(strcat(CA_path,CA_name));
if length(CAF.data)<=100
    CAF = importdata(strcat(CA_path,CA_name),' ',17);
    CAF.data(:,1)=[];
    CA.data = CAF.data;
else
    CAF.data(:,2)=[];
    CA.data = CAF.data;
end
%%  Parameter Import
Per.Time = input('Working Time(s):\n');
if isempty(Per.Time)
    Per.Time = 7200;
end
Per.Vol = input('Electrolyte Volume(mL):\n');
if isempty(Per.Vol)
    Per.Vol = 50;
end
Per.Load = input('Load(mg):\n');
Per.Yield = input('Yield(ug h-1 mg-1):\n');
Per.Efficiency = 0.01*input('Efficiency(%):\n');
%%	Data Process
CA.data(:,1) = (1:(Per.Time-1)/(length(CA.data)-1):Per.Time)';
%plot(CA.data(:,1),CA.data(:,2),'.','color','r','MarkerSize',20);hold on;
IT.Time = 1:1:Per.Time;
IT.Current = interp1(CA.data(:,1),CA.data(:,2),IT.Time,'Spline');
%plot(IT.Time,IT.Current,'.','color','b','MarkerSize',10);hold off;
%IT.Charge = sum(IT.Current);
Per.Mass = Per.Yield*Per.Time/3600*Per.Load/Per.Efficiency;
IT.Charge = Per.Mass/1.7e7*3*96485;
IT.Current = (IT.Charge/abs(sum(IT.Current))).*IT.Current;
%Per.Mass = 1.7e7*abs(IT.Charge)/3/96485;%Unit:ug
Per.Con = Per.Mass*Per.Efficiency/Per.Vol;%Unit:ug/mL
Abs.Wavelength = UV(1).Neutral(:,1)';
Abs.Absorption = (UV(1).Neutral(:,2)+Per.Con*UV_derta.Neutral)';
subplot(1,2,1);
plot(Abs.Wavelength,Abs.Absorption,'.','color','r','MarkerSize',10);hold on;
plot(UV(1).Neutral(:,1),UV(1).Neutral(:,2),'.','color','b','MarkerSize',10)
plot(UV(2).Neutral(:,1),UV(2).Neutral(:,2),'.','color','b','MarkerSize',10);hold off;
subplot(1,2,2);
plot(IT.Time,IT.Current,'.','color','b','MarkerSize',10);
%%	Data Output
filename = input('Please input the file name:','s');
filename = strcat(filename,'.xlsx');
xlswrite(filename,IT.Time',1,'A1');
xlswrite(filename,IT.Current',1,'B1');
xlswrite(filename,Abs.Wavelength',2,'A1');
xlswrite(filename,Abs.Absorption',2,'B1');
%xlswrite('test.xlsx',data)