function [ff,cc]=fourier2
ai=analoginput('winsound')   
   addchannel(ai,1:2);
   ai.samplerate=8000;
   ai.samplespertrigger=8000;
     ai.triggertype='immediate';
   start(ai);
   [d,t]=getdata(ai);
   u1=d(:,1);
   y=fft(u1,1024);
   p=y.*conj(y);
   c=abs(p.^(1/2));
   f = 0:20:10000;
   ff=f(10:400);
   cc=c(10:400)
   cc=cc/max(cc);
   plot(ff,cc)
   grid
   delete(ai)
clear ai




