theta_deg=0:1:360;
theta=theta_deg/360*2*pi;
index=6.0:0.1:10;
rho=zeros(length(theta),length(index));
rho_zoom=zeros(length(theta),length(index));
for i=1:1:length(index)
    %rho(:,i)=abs(sin(3/4*theta).^index(1,i))+abs(cos(3/4*theta).^index(1,i));
    rho(:,i)=abs(sin(3/4*theta).^index(1,i))+abs(cos(3/4*theta).^index(1,i))+...
             abs(sin(3/4*(theta-pi/3)).^index(1,i))+abs(cos(3/4*(theta-pi/3)).^index(1,i));
    %rho_2=abs(sin(3/4*theta).^4)+abs(cos(3/4*theta).^4);
    %rho_3=abs(sin(3/4*theta).^3)+abs(cos(3/4*theta).^3);
    rho_zoom(:,i)=index(1,i)*rho(:,i)/min(rho(:,i));
    %rho_zoom(:,i)=rho(:,i);
    %polar(theta,rho);hold on
    polar(theta',rho_zoom(:,i));hold on
end
