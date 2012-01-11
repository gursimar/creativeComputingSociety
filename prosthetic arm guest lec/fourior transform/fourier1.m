function ffourier
close all
sign=1;
z=input('what function you need to transform enter 1 for retangular, 2 for triangular, 3 for saw-tooth, 4 for half wave, 5 for full wave');
N=input('How many terms in the expansion are needed  ')
t=0:pi/1000:2*pi;
if z==1
    for n=1:2:N
    y(n,:)=4*(1/n)*sin(n.*t)/pi;
end
plot(t,y')
hold
plot(t,sum(y),'.-k')
end
if z==2
    for n=1:2:N
    y(n,:)=sign*8*(1/n^2)*sin(n.*t)/pi^2;
    sign=sign*(-1);
end
plot(t,y')
hold
plot(t,sum(y),'.-k')
end
if z==3
    for n=1:N
    y(n,:)=-(1/n)*sin(n.*t)/pi;
    
end
plot(t,y')
hold
plot(t,sum(y),'.-k')
end
if z==4
    for n=2:2:2*N
        y(n,:)=-(2/pi)*cos(n*t)/((n-1)*(n+1));
end
plot(t,y')
hold
U=(1/pi)+.5*sin(t)+sum(y);
plot(t,.5*sin(t));
plot(t,U,'.-k')
plot(t,1/pi,'r')
end
if z==5
    for n=2:2:2*N
        y(n,:)=-(4/pi)*cos(n*t)/((n-1)*(n+1));
end
plot(t,y')
hold
UU=2/pi;
plot(t,UU,'r')
U=(2/pi)+sum(y);
plot(t,U,'.-k')
end
grid
xlabel('wt')
ylabel('amplitudes (arbitrary normalized units)')

