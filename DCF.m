% Digital Current Feedback GUI for MATLAB 2010a <-> XMOS

function DCF
dll_path = 'C:\Thesycon\TUSBAudio_v1.22.0\EvaluationKit\DriverInstaller\release\';
h_path = 'C:\Thesycon\TUSBAudio_v1.22.0\EvaluationKit\DriverInstaller\release\DCF\';
%[NOTFOUND, WARNINGS] = loadlibrary([dll_path 'tusbaudioapi.dll'],[h_path 'tusbaudioapi.h'] );
%libfunctions('tusbaudioapi')

main_windows_pos=[100 100 800 600];
Z=zeros(128,1);
f=logspace(1,log10(1500),128);
fs=192000;


s=tf([1 0],1);

fh = figure('Position',main_windows_pos,...
    'MenuBar','none',...
    'NumberTitle','off',...
    'Name','Digital Current Feedback');

s_BPfc = uicontrol(fh,'Style','slider',...
    'Max',120,'Min',10,'Value',50,...
    'SliderStep',[0.01 0.1],...
    'Position',[25 500 250 20],...
    'Callback',@slider_BPfc_callback);

s_BPQ = uicontrol(fh,'Style','slider',...
    'Max',10,'Min',0.1,'Value',1,...
    'SliderStep',[0.01 0.1],...
    'Position',[25 400 250 20],...
    'Callback',@slider_BPQ_callback);

s_BPR = uicontrol(fh,'Style','slider',...
    'Max',10,'Min',-10,'Value',0,...
    'SliderStep',[0.01 0.1],...
    'Position',[25 300 250 20],...
    'Callback',@slider_BPR_callback);
 
 s_Re = uicontrol(fh,'Style','slider',...
     'Max',10,'Min',-10,'Value',0,...
     'SliderStep',[0.01 0.1],...
     'Position',[25 200 250 20],...
     'Callback',@slider_Re_callback);
 
  s_LPf = uicontrol(fh,'Style','slider',...
     'Max',1400,'Min',50,'Value',1000,...
     'SliderStep',[0.01 0.1],...
     'Position',[25 100 250 20],...
     'Callback',@slider_LPf_callback);
 
 et_BPfc = uicontrol(fh,'Style','edit',...
     'String',sprintf('Fc=%.1f Hz',get(s_BPfc,'Value')),...
     'HorizontalAlignment','left',...
     'Position',[150 525 75 20],...
     'Callback',@edittext_BPfc_callback);

  et_BPQ = uicontrol(fh,'Style','edit',...
     'String',sprintf('Q=%.2f ',get(s_BPQ,'Value')),...
     'HorizontalAlignment','left',...
     'Position',[150 425 75 20],...
     'Callback',@edittext_BPQ_callback);
 
 et_BPR = uicontrol(fh,'Style','edit',...
     'String',sprintf('R=%.1f Ohm',get(s_BPR,'Value')),...
     'HorizontalAlignment','left',...
     'Position',[150 325 75 20],...
     'Callback',@edittext_BPG_callback);
 
 et_Re = uicontrol(fh,'Style','edit',...
     'String',sprintf('Re=%.1f Ohm',get(s_Re,'Value')),...
     'HorizontalAlignment','left',...
     'Position',[150 225 75 20],...
     'Callback',@edittext_Re_callback);

  et_LPf = uicontrol(fh,'Style','edit',...
     'String',(sprintf('LP f=%.2f kHz',get(s_LPf,'Value')/1000)),...
     'HorizontalAlignment','left',...
     'Position',[150 125 75 20],...
     'Callback',@edittext_LPf_callback);
 
  t_LC = uicontrol(fh,'Style','text',...
     'HorizontalAlignment','left',...
     'Position',[100 25 125 40],...
     'Callback',@edittext_LC_mcallback);
 
 
 Fmax=1500;
 
 axes_Z=axes('Units','pixels','position',[350 100 400 400]);
 plot_Z=plot(f,real(Z),f,imag(Z),f,abs(Z),'linewidth',2);
 xlabel('Frekvens [Hz]');
 ylabel('Impedans [Ohm]');
 xlim([get(s_BPfc,'Min') Fmax]);
 ylim([-15 15]);
 grid on;
 set(axes_Z,'XScale','log');
 XTick=get(axes_Z,'XTick');set(axes_Z,'XTickLabel',num2str(XTick'));
 legend('Resistans','Reaktans','Impedans')
 title('Virtuell utimpedans')
 updateL

 
function slider_BPfc_callback(hObject,eventdata)
set(et_BPfc,'String',sprintf('Fc=%.1f Hz',get(s_BPfc,'Value')) );
updateL;
end

function slider_BPQ_callback(hObject,eventdata)
set(et_BPQ,'String',sprintf('Q=%.2f ',get(s_BPQ,'Value')) );
updateL;
end

function slider_BPR_callback(hObject,eventdata)
set(et_BPR,'String',sprintf('R=%.1f Ohm',get(s_BPR,'Value')) );
updateL;
end


function slider_Re_callback(hObject,eventdata)
set(et_Re,'String',sprintf('Re=%.1f Ohm',get(s_Re,'Value')) );
updateL;
end

function slider_LPf_callback(hObject,eventdata)
set(et_LPf,'String',sprintf('LP f=%.2f kHz',get(s_LPf,'Value')/1000) );
updateL;
end


function updateL()
Re=get(s_Re,'Value');   
R=get(s_BPR,'Value');
fc=get(s_BPfc,'Value');
Q=get(s_BPQ,'Value');
flp=get(s_LPf,'Value');
wc=2*pi*fc;
wlp=2*pi*flp;
L=R/(wc*Q);
C=1/(L*wc*wc);
set(t_LC,'String',sprintf('L=%.2f mH\nC=%.2f uF',1000*L,C*10^6));

if(abs(R)>0)
    Z=Re+s*L/(1 +s*L/R + s*s*L*C);
else
    Z=tf(Re);
end
Z=Z*1/(s/wlp+1);
[mag,phase] = bode(Z,f*2*pi);
set(plot_Z(1),'YData',cos(pi/180*phase(:)).*mag(:));
set(plot_Z(2),'YData',sin(pi/180*phase(:)).*mag(:));
set(plot_Z(3),'YData',mag(:));

end
end
