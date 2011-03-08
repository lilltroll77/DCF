% Digital Current Feedback GUI for MATLAB 2010a <-> XMOS

dll_path = 'C:\Thesycon\TUSBAudio_v1.22.0\EvaluationKit\DriverInstaller\release\';
h_path = 'C:\Thesycon\TUSBAudio_v1.22.0\EvaluationKit\DriverInstaller\release\DCF\';

[NOTFOUND, WARNINGS] = loadlibrary([dll_path 'tusbaudioapi.dll'],[h_path 'tusbaudioapi.h'] );
libfunctions('tusbaudioapi')

