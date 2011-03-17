% Digital Current Feedback GUI for MATLAB 2010a <-> XMOS

function DCF
dll_path = 'C:\Thesycon\TUSBAudio_v1.22.0\CustomizationKit\DriverInstaller\debug\';
h_path = 'C:\Thesycon\TUSBAudio_v1.22.0\EvaluationKit\DriverInstaller\release\DCF\';
if(libisloaded('tusbaudioapi'))
unloadlibrary('tusbaudioapi');
end
if ((isdir(dll_path) && isdir(h_path))==0)
    error('Paths was not found on this computer');
end
exist([dll_path 'tusbaudioapi.dll'],'file');
NULL=uint32(0);

main_windows_pos=[100 100 800 600];
Z=zeros(128,1);
f=logspace(1,log10(1500),128);
Position=[25 480 250 20];
deltaPosition =-75;

s=tf([1 0],1);

fh = figure('Position',main_windows_pos,...
    'MenuBar','none',...
    'NumberTitle','off',...
    'Name','Digital Current Feedback');
   
  %lh_deviceArrivalEvent = addlistener(aec,'deviceArrivalEvent',@deviceArrivalEvent)
  %lh_deviceRemovedEvent = addlistener(aec,'deviceRemovedEvent',@deviceRemovedEvent)

[NOTFOUND, WARNINGS] = loadlibrary([dll_path 'tusbaudioapi.dll'],[h_path 'tusbaudioapi.h'] );
libf=libfunctions('tusbaudioapi');
ApiVersion=uint32(calllib('tusbaudioapi','TUSBAUDIO_GetApiVersion'));
%TUsbAudioStatus=uint32(calllib('tusbaudioapi','TUSBAUDIO_RegisterPnpNotification',lh_deviceArrivalEvent,lh_deviceRemovedEvent,[],0,0))

DeviceCount=uint32(calllib('tusbaudioapi','TUSBAUDIO_GetDeviceCount'));
EnumerateDevices=calllib('tusbaudioapi','TUSBAUDIO_EnumerateDevices');


s_BPfc = uicontrol(fh,'Style','slider',...
    'Max',120,'Min',10,'Value',50,...
    'SliderStep',[0.01 0.1],...
    'Position',Position,...
    'Callback',@slider_BPfc_callback);
et_BPfc = uicontrol(fh,'Style','edit',...
     'String',sprintf('Fc=%.1f Hz',get(s_BPfc,'Value')),...
     'HorizontalAlignment','left',...
     'Position',[Position(1:2)+25 75 20],...
     'Callback',@edittext_BPfc_callback);
Position(2)=Position(2)+deltaPosition;

s_BPQ = uicontrol(fh,'Style','slider',...
    'Max',10,'Min',0.1,'Value',1,...
    'SliderStep',[0.01 0.1],...
    'Position',Position,...
    'Callback',@slider_BPQ_callback);
et_BPQ = uicontrol(fh,'Style','edit',...
     'String',sprintf('Q=%.2f ',get(s_BPQ,'Value')),...
     'HorizontalAlignment','left',...
     'Position',[Position(1:2)+25 75 20],...
     'Callback',@edittext_BPQ_callback);
 Position(2)=Position(2)+deltaPosition;

s_BPR = uicontrol(fh,'Style','slider',...
    'Max',10,'Min',-10,'Value',0,...
    'SliderStep',[0.01 0.1],...
    'Position',Position,...
    'Callback',@slider_BPR_callback);
 et_BPR = uicontrol(fh,'Style','edit',...
     'String',sprintf('R=%.1f Ohm',get(s_BPR,'Value')),...
     'HorizontalAlignment','left',...
     'Position',[Position(1:2)+25 75 20],...
     'Callback',@edittext_BPG_callback);
 Position(2)=Position(2)+deltaPosition;
 
 s_Re = uicontrol(fh,'Style','slider',...
     'Max',10,'Min',-10,'Value',0,...
     'SliderStep',[0.01 0.1],...
     'Position',Position,...
     'Callback',@slider_Re_callback);
 et_Re = uicontrol(fh,'Style','edit',...
     'String',sprintf('Re=%.1f Ohm',get(s_Re,'Value')),...
     'HorizontalAlignment','left',...
     'Position',[Position(1:2)+25 75 20],...
     'Callback',@edittext_Re_callback);
 Position(2)=Position(2)+deltaPosition;
 
  s_LPf = uicontrol(fh,'Style','slider',...
     'Max',1400,'Min',50,'Value',1000,...
     'SliderStep',[0.01 0.1],...
     'Position',Position,...
     'Callback',@slider_LPf_callback);
 et_LPf = uicontrol(fh,'Style','edit',...
     'String',(sprintf('LP f=%.2f kHz',get(s_LPf,'Value')/1000)),...
     'HorizontalAlignment','left',...
     'Position',[Position(1:2)+25 75 20],...
     'Callback',@edittext_LPf_callback);
  Position(2)=Position(2)+deltaPosition;
  

      uicontrol(fh,'Style','text',...
     'HorizontalAlignment','left',...
     'String',sprintf('tusbaudioapi.dll\nAPI version = %x\nFound %d audio devices\nEnumerated %d devices',ApiVersion,DeviceCount,EnumerateDevices),...
     'Position',[Position(1) 10 125 75]);
  
  t_LC = uicontrol(fh,'Style','text',...
     'HorizontalAlignment','left',...
     'Position',[Position(1:2) 125 40],...
     'Callback',@edittext_LC_mcallback);
  Position(1:2)=Position(1:2)+[150 -100];
 t_z = uicontrol(fh,'Style','text',...
    'String','FIXED-POINT',... 
    'HorizontalAlignment','left',...
     'Position',[Position(1:2) 125 140],...
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
Fs=192000/4;
Re=get(s_Re,'Value');   
R=get(s_BPR,'Value');
fc=get(s_BPfc,'Value');
Q=get(s_BPQ,'Value');
flp=get(s_LPf,'Value');
wc=2*pi*fc;
wlp=2*pi*flp;
L=R/(wc*Q);
C=1/(L*wc*wc);
set(t_LC,'String',sprintf('L=%.2f mH\nC=%.2f mF',1000*L,C*1000));
if(abs(R)>0)
    L_BP=s*L/(1 +s*L/R + s*s*L*C);
    L=Re+L_BP;
    [NUMBPd,DENBPd]=bilinear(L.num{:} , L.den{:} , Fs);
    set(t_z,'String',sprintf('FIXED-POINT BP\nB0=%d\nB1=%d\nB2=%d\nA1=%d\nA2=%d\nFIXED-POINT LP\nB0=\nB1=\nA1=',int32(NUMBPd*2^30),int32(DENBPd(2:3)*2^30)) );
    
else
    L=tf(Re);
end
L=L*1/(s/wlp+1);
[mag,phase] = bode(L,f*2*pi);
set(plot_Z(1),'YData',cos(pi/180*phase(:)).*mag(:));
set(plot_Z(2),'YData',sin(pi/180*phase(:)).*mag(:));
set(plot_Z(3),'YData',mag(:));


end
end
