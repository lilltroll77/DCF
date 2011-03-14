/*

Thesycon®  Systemsoftware & Consulting GmbH 

TUSBAudio 

USB Audio 2.0 Class Driver for Windows 

Reference Manual 

Version:      1.22.0 
Date:         02 December 2010 

Authors:      Udo Eberhardt 
              Frank Senf 

Thesycon Systemsoftware & Consulting GmbH 
Werner-von-Siemens-Str. 2 
D-98693 Ilmenau 
Germany 

Tel: +49 3677 8462 0 
Fax: +49 3677 8462 18 

http://www.thesycon.de 
*/
 #include <wchar.h> //added by MB
 typedef unsigned int TUsbAudioStatus; //added by MB
 typedef unsigned long* WCHAR; added by MB
 #define TUSBAUDIO_MAX_STRDESC_STRLEN 200 //?? SIZE
  
 
/*TUsbAudioDeviceProperties 

This structure provides static information associated with a USB audio device. 

Deﬁnition */

typedef struct /*tagTUsbAudioDeviceProperties*/{ 
   unsigned int usbVendorId; 
   unsigned int usbProductId; 
   unsigned int usbRevisionId; 
   WCHAR serialNumberString[TUSBAUDIO_MAX_STRDESC_STRLEN]; //UTF-32 or UTF-16??
   WCHAR manufacturerString[TUSBAUDIO_MAX_STRDESC_STRLEN]; 
   WCHAR productString[TUSBAUDIO_MAX_STRDESC_STRLEN]; 
   unsigned int flags; 
 } TUsbAudioDeviceProperties; 
/*Members 

usbVendorId 
   Speciﬁes the USB vendor ID (VID) as reported by the device in the USB device descriptor. 

usbProductId 
   Speciﬁes the USB product ID (PID) as reported by the device in the USB device descriptor. 

usbRevisionId 
   Speciﬁes the revision code (bcdDevice) as reported by the device in the USB device descriptor. 

serialNumberString[TUSBAUDIO_MAX_STRDESC_STRLEN] 
   Contains the serial number string as reported by the device per string descriptor. If the device 
   does not support a USB serial number then the string contains a device instance ID generated 
   internally by Windows. This ﬁeld contains a sequence of UNICODE characters which is 
   guaranteed to be terminated by a UNICODE null character. 

manufacturerString[TUSBAUDIO_MAX_STRDESC_STRLEN] 
   Contains the Manufacturer string as reported by the device per string descriptor. If the device 
   does not support a Manufacturer string then this ﬁeld is set to an empty string. This ﬁeld 
   contains a sequence of UNICODE characters which is guaranteed to be terminated by a 
   UNICODE null character. 

productString[TUSBAUDIO_MAX_STRDESC_STRLEN] 
   Contains the Product string as reported by the device per string descriptor. If the device does 
   not support a Product string then this ﬁeld is set to an empty string. This ﬁeld contains a 
   sequence of UNICODE characters which is guaranteed to be terminated by a UNICODE null 
   character. 

flags 
   Contains a set of ﬂags as a bitwise-or combination of the following constants. 

   TUSBAUDIO_DEVPROP_FLAG_HIGH_SPEED_SUPPORTED 
      If this ﬂag is set then the device is capable of USB high-speed mode. If this ﬂag is clear 
      then the device supports USB full-speed mode only. 
   TUSBAUDIO_DEVPROP_FLAG_HIGH_SPEED 
      If this ﬂag is set then the device is currently connected to a high-speed USB port and works 
      in high-speed mode. If this ﬂag is clear then the device is currently connected to a USB 
      port which supports full-speed mode only. 
   TUSBAUDIO_DEVPROP_FLAG_DFU_SUPPORTED 
      If this ﬂag is set then the device supports device ﬁrmware upgrade (DFU). 
   TUSBAUDIO_DEVPROP_FLAG_DSP_PLUGIN_PRESENT 
      If this ﬂag is set then a DSP plugin is loaded for the device. 
   TUSBAUDIO_DEVPROP_FLAG_AUDIOCLASS10_SUPPORTED 
      If this ﬂag is set the device complies to USB Audio Class 1.0. 
   TUSBAUDIO_DEVPROP_FLAG_AUDIOCLASS20_SUPPORTED 
      If this ﬂag is set the device complies to USB Audio Class 2.0. 

Comments 

   An application can use the USB VID, PID and serial number information provided by this 
   struct to unambiguously identify a particular device instance. 

See Also 

   TUSBAUDIO_GetDeviceProperties (page 18) */

/*TUsbAudioClockSource 

This structure provides detailed information on a speciﬁc Clock Source of the USB Audio 
Function. 

Deﬁnition */
typedef struct /*tagTUsbAudioClockSource*/{ 
   unsigned int clockSourceId; 
   unsigned int clockSourceUnitId; 
   unsigned int clockSelectorPinNumber; 
   unsigned int clockIsValid; 
   unsigned int sampleRate; 
   WCHAR clockNameString[TUSBAUDIO_MAX_STRDESC_STRLEN]; 
 } TUsbAudioClockSource; 
/*Members 

clockSourceId 
   Contains the unique ID that unambiguously identiﬁes the clock source at the driver API. 

   The ID values are driver-deﬁned. An application must not interpret the value. 

clockSourceUnitId 
   Contains the unit ID of the Clock Source entity within the audio function. 

clockSelectorPinNumber 
   Contains the zero-based index of the clock selector input pin where the clock selector is 
   connected. 

clockIsValid 
   Speciﬁes the current state of the clock source (validity). 

   This member will be set to 1 of the clock is stable or to zero otherwise. 

sampleRate 
   Current sample rate of the clock source, in samples per second. 

   This member is only valid of clockIsValidis set to 1. 

clockNameString[TUSBAUDIO_MAX_STRDESC_STRLEN] 
   Zero-terminated wide character string that describes the clock source (taken from USB string 
   descriptor). 

See Also 

   TUSBAUDIO_GetSupportedClockSources (page 25) 
   TUSBAUDIO_GetCurrentClockSource (page 26) 
   TUSBAUDIO_SetCurrentClockSource (page 27) */

/*TUsbAudioStreamFormat 

This structure provides information on a speciﬁc stream format supported by the device. 

Deﬁnition */
typedef struct /*tagTUsbAudioStreamFormat*/{ 
   unsigned int formatId; 
   unsigned int bitsPerSample; 
   unsigned int numberOfChannels; 
   WCHAR formatNameString[TUSBAUDIO_MAX_STRDESC_STRLEN]; 
 } TUsbAudioStreamFormat; 
/*Members 

formatId 
   Contains the unique ID that unambiguously identiﬁes the stream format at the driver API. 

   The ID values are driver-deﬁned. An application must not interpret the value. 

bitsPerSample 
   Contains the number of valid bits per sample (16 or 24). 

numberOfChannels 
   Contains the number of audio channels covered by the stream format. 

formatNameString[TUSBAUDIO_MAX_STRDESC_STRLEN] 
   Zero-terminated wide character string that describes the stream format (taken from USB string 
   descriptor). 

See Also 

   TUSBAUDIO_GetSupportedStreamFormats (page 28) 
   TUSBAUDIO_GetCurrentStreamFormat (page 30) 
   TUSBAUDIO_SetCurrentStreamFormat (page 31) */

/*TUsbAudioChannelProperty 

This structure provides information on a speciﬁc audio channel of the device. 

Deﬁnition */
typedef struct /*tagTUsbAudioChannelProperty*/{ 
   unsigned int channelIndex; 
   unsigned int isInput; 
   unsigned int flags; 
   unsigned char featureUnitId; 
   unsigned char featureUnitLogicalChannel; 
   short volumeRangeMin; 
   short volumeRangeMax; 
   unsigned short volumeRangeStep; 
   WCHAR channelNameString[TUSBAUDIO_MAX_STRDESC_STRLEN]; 
 } TUsbAudioChannelProperty; 
/*Members 

channelIndex 
   Contains the zero-based index of the channel within the associated stream. 

isInput 
   Contains the channel direction. This member is set to one for input (record) channels and to 
   zero for output (playback) channels. 

flags 
   Contains a set of ﬂags as a bitwise-or combination of the following constants. 

   TUSBAUDIO_CHANPROP_FLAG_VOLUME_MAPPED 
      If this ﬂag is set then the Windows Audio volume control for the channel is mapped to the 
      feature unit speciﬁed in featureUnitId. 
   TUSBAUDIO_CHANPROP_FLAG_MUTE_MAPPED 
      If this ﬂag is set then the Windows Audio mute control for the channel is mapped to the 
      feature unit speciﬁed in featureUnitId. 

featureUnitId 
   Contains the ID of the feature unit within the audio function that is used by Windows Audio to 
   control volume and/or mute of the channel. 

   This ID has to be used as entityIDwhen calling the private API to send volume or mute 
   control requests for this channel to the device. 

   The ID is valid only if one of TUSBAUDIO_CHANPROP_FLAG_VOLUME_MAPPEDor 
   TUSBAUDIO_CHANPROP_FLAG_MUTE_MAPPEDis set in the flagsmember. 

featureUnitLogicalChannel 
   Contains the logical channel number within the feature unit that corresponds with the channel. 

   This number has to be used as channelOrMixerControlwhen calling the private API to 
   send volume or mute control requests for this channel to the device. 

volumeRangeMin 
   Contains the minimum volume value that is supported by the channel. 

   This ﬁeld is only valid if TUSBAUDIO_CHANPROP_FLAG_VOLUME_MAPPEDis set in the 
   flagsmember. 

volumeRangeMax 
   Contains the maximum volume value that is supported by the channel. 

   This ﬁeld is only valid if TUSBAUDIO_CHANPROP_FLAG_VOLUME_MAPPEDis set in the 
   flagsmember. 

volumeRangeStep 
   Contains the step size for volume values supported for the channel. 

   This ﬁeld is only valid if TUSBAUDIO_CHANPROP_FLAG_VOLUME_MAPPEDis set in the 
   flagsmember. 

channelNameString[TUSBAUDIO_MAX_STRDESC_STRLEN] 
   Zero-terminated wide character string that describes the channel. The channel name is taken 
   from the USB string descriptor if available or generated internally otherwise. 

Comments 

   The values that are returned in volumeRangeMin, volumeRangeMaxand 
   volumeRangeStepare in the range as deﬁned by the USB Audio Class speciﬁcation 
   (-127.9961 decibels to +127.9961 decibels in 1/256 decibel steps). 

See Also 

   TUSBAUDIO_GetChannelProperties (page 32) 
   TUSBAUDIO_AudioControlRequestGet (page 37) 
   TUSBAUDIO_AudioControlRequestSet (page 35) */

/*TUsbAudioNotifyEvent 

This enumeration type deﬁnes constants that identify notiﬁcation event messages issued by the 
device or the driver. 

Deﬁnition */
typedef enum tagTUsbAudioNotifyEvent{ 
   NotifyEvent_SampleRateChanged, 
   NotifyEvent_StreamFormatChanged, 
   NotifyEvent_AcNodeInterrupt, 
   NotifyEvent_VolumeChanged, 
   NotifyEvent_MuteChanged 
 } TUsbAudioNotifyEvent; 
/*Entries 

NotifyEvent_SampleRateChanged 
   This event message is issued by the driver when the sample rate changes. This event belongs 
   to the TUSBAUDIO_NOTIFY_CATEGORY_SAMPLE_RATE_CHANGEcategory. 

   Data ﬁeld: No data ﬁeld is attached to this type of event. 

NotifyEvent_StreamFormatChanged 
   This event message is issued by the driver when the stream format changes. This event 
   belongs to the TUSBAUDIO_NOTIFY_CATEGORY_STREAM_CHANGEcategory. 

   Data ﬁeld: No data ﬁeld is attached to this type of event. 

NotifyEvent_AcNodeInterrupt 
   This event message is issued by an audio control node (unit) of the device. This event belongs 
   to the TUSBAUDIO_NOTIFY_CATEGORY_AC_NODE_INTERRUPTcategory. 

   Data ﬁeld: The data ﬁeld attached to this event contains the interrupt data message deﬁned by 
   the USB audio class 2.0 speciﬁcation. The size of this message is 6 bytes. The data layout is 
   deﬁned by the USB audio class 2.0 speciﬁcation. See also the 
   T_UsbClsAudio20_AC_InterruptDataMessagestruct type deﬁned in 
   tusb_cls_audio20.h. 

NotifyEvent_VolumeChanged 
   This event message is issued by the driver if the volume of a speciﬁc channel is changed 
   through the Windows mixer API. For example, this happens if a user modiﬁes volume in the 
   standard windows sound panel. This event belongs to the 
   TUSBAUDIO_NOTIFY_CATEGORY_VOLUME_CHANGEcategory. 

   Data ﬁeld: The data ﬁeld attached to this event contains a TUsbAudioNotifyVolumeChange 
   structure. 

NotifyEvent_MuteChanged 
   This event message is issued by the driver if the mute state of a speciﬁc channel is changed 
   through the Windows mixer API. For example, this happens if a user modiﬁes mute in the 
   standard windows sound panel. This event belongs to the 
   TUSBAUDIO_NOTIFY_CATEGORY_VOLUME_CHANGEcategory. 

   Data ﬁeld: The data ﬁeld attached to this event contains a TUsbAudioNotifyVolumeChange 
   structure. 

Comments 

   An application can ﬁlter event messages to be received by means of event categories. 
   Categories are deﬁned by TUSBAUDIO_NOTIFY_CATEGORY_xxxconstants. See 
   TUSBAUDIO_RegisterDeviceNotiﬁcation for more information. 

See Also 

   TUSBAUDIO_RegisterDeviceNotiﬁcation (page 19) 
   TUSBAUDIO_ReadDeviceNotiﬁcation (page 21) 
   TUsbAudioNotifyVolumeChange (page 66) */

/*TUsbAudioDfuProcState 

This enumeration type deﬁnes constants that indicate the current state of the DFU operation. 

Deﬁnition */
typedef enum tagTUsbAudioDfuProcState{ 
   DfuProcState_Idle, 
   DfuProcState_Initializing, 
   DfuProcState_EnteringDfuMode, 
   DfuProcState_InProgress, 
   DfuProcState_EnteringAppMode, 
   DfuProcState_Finished, 
   DfuProcState_Failed 
 } TUsbAudioDfuProcState; 
/*Entries 

DfuProcState_Idle 
   No DFU operation is in progress. 

DfuProcState_Initializing 
   The DFU operation is about to start. 

DfuProcState_EnteringDfuMode 
   The device is entering DFU mode (DFU ﬁrmware is about to be started). 

DfuProcState_InProgress 
   The DFU operation is in progress. 

DfuProcState_EnteringAppMode 
   The device is entering APP mode (application is about to be started). 

DfuProcState_Finished 
   The DFU operation has completed successfully. 

DfuProcState_Failed 
   The DFU operation has completed with error. 

Comments 

   An application calls TUSBAUDIO_GetDfuStatus to query the current state of the DFU 
   operation. 

See Also 

   TUSBAUDIO_GetDfuStatus (page 61) */

/*TUsbAudioDeviceRunMode 

This enumeration type deﬁnes constants that indicate the ﬁrmware that is currently running on 
the device. 

Deﬁnition */
typedef enum tagTUsbAudioDeviceRunMode{ 
   DeviceRunMode_APP, 
   DeviceRunMode_DFU 
 } TUsbAudioDeviceRunMode; 
/*Entries 

DeviceRunMode_APP 
   The application ﬁrmware is running (APP mode). 

DeviceRunMode_DFU 
   The DFU ﬁrmware is running (DFU mode). 

Comments 

   An application calls TUSBAUDIO_GetDeviceUsbMode to query the ﬁrmware that is 
   running on the device. 

See Also 

   TUSBAUDIO_GetDeviceUsbMode (page 48) */

 /*----------------- Functions --------------------------------------*/
   
 
/*TUSBAUDIO_GetApiVersion 

This function returns the current version number of the application programming interface (API) 
exported by the DLL. 

Deﬁnition 
*/
   unsigned int 
   TUSBAUDIO_GetApiVersion(); 
/* Return Value 

   The function returns the TUSBAUDIO_API_VERSIONconstant the DLL was compiled with. 
   The high-order 16 bits contain the major version number, the low-order 16 bits contain the 
   minor version number. 

Comments 

   Regarding the API version of the DLL the following convention is deﬁned: If changes are 
   made to the programming interface that are compatible with previous versions (e.g. a new 
   function is added) then the minor version number will be incremented. If changes are made 
   that cause an incompatibility with previous versions of the interface then the major version 
   number will be incremented. 

   Applications should call TUSBAUDIO_CheckApiVersion to check if the DLL’s API is 
   compatible with the version of the header ﬁle the application was compiled with. 
----------------------------------------------------------------------------------------

TUSBAUDIO_CheckApiVersion 

This function checks if the application programming interface of the DLL is compatible with the 
version the application was compiled with. 

Deﬁnition 
*/
    int 
   TUSBAUDIO_CheckApiVersion( 
      unsigned long majorVersion, 
      unsigned long minorVersion 
       ); 
/* Parameters 

majorVersion 
   Speciﬁes the major API version that the application expects. Callers should set this parameter 
   to the TUSBAUDIO_API_VERSION_MJconstant. 

minorVersion 
   Speciﬁes the minor API version that the application expects. Callers should set this parameter 
   to the TUSBAUDIO_API_VERSION_MNconstant. 

Return Value 

   The function returns 1if the DLL is compatible with the caller. The function returns 0if the 
   version does not match and the calling application is incompatible with the DLL. 

Comments 

   Regarding the API version of the DLL the following convention is deﬁned: If changes are 
   made to the programming interface that are compatible with previous versions (e.g. a new 
   function is added) then the minor version number will be incremented. If changes are made 
   that cause an incompatibility with previous versions of the interface then the major version 
   number will be incremented. 

   Applications should call this function to check if the DLL’s API is compatible with the version 
   of the header ﬁle the application was compiled with. 

   The function succeeds if the major version of the DLL is equal to the expected major version 
   and if the minor version of the DLL is greater than or equal to the expected minor version. 

See Also 

   TUSBAUDIO_GetApiVersion (page 8) 

---------------------------------------------------------------------
TUSBAUDIO_RegisterPnpNotiﬁcation 

Register with the driver to receive notiﬁcations when devices are plugged or unplugged. 

Deﬁnition 
*/
   TUsbAudioStatus 
   TUSBAUDIO_RegisterPnpNotification( 
      HANDLE deviceArrivalEvent, 
      HANDLE deviceRemovedEvent, 
      void* windowHandle, 
      unsigned int windowMsgCode, 
      unsigned int flags 
       ); 
/* Parameters 

deviceArrivalEvent 
   Handle to a user-created Win32 event object that will be signaled by the driver when a new 
   device is connected to the system. This parameter is optional and can be set to NULL if no 
   event object is to be registered. 

deviceRemovedEvent 
   Handle to a user-created Win32 event object that will be signaled by the driver when a device 
   is disconnected from the system. This parameter is optional and can be set to NULL if no 
   event object is to be registered. 

windowHandle 
   Handle (HWND) that identiﬁes a window in the user’s application. The driver posts a message 
   to this window when a device is connected or disconnected. For more information, see the 
   Comments section below. 

   This parameter is optional and can be set to NULL. The driver will not post a window 
   message in this case. 

windowMsgCode 
   User-deﬁned message code that identiﬁes the window message posted by the driver. An 
   application should use a numeric code that is greater than WM_USER, for example 
   (WM_USER + 100). 

   This parameter will be ignored if windowHandleis set to NULL. 

flags 
   This parameter is reserved for future use and should be set to zero. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   Depending on the application type an application can implement two different approaches as 
   discussed in the following. 

   Event object based notiﬁcation: 
   The application creates event objects using the Win32 call CreateEvent and then passes the 
   handles returned by Windows to TUSBAUDIO_RegisterPnpNotification. The 
   argument windowHandleis set to NULL in this case. Typically the application uses a 
   dedicated thread to wait on the event objects, e.g. by using the Win32 call 
   WaitForMultipleObjects. The thread gets triggered when one of the events is signalled by the 
   driver. The driver just calls SetEvent with the provided handle. It is up to application designer 
   to decide which type of event object (auto-reset or manual-reset) is to be used. 

   Window message based notiﬁcation: 
   The application deﬁnes a private window message code. e.g. set to (WM_USER + 100), and 
   passes this code to TUSBAUDIO_RegisterPnpNotificationas windowMsgCode 
   argument. The arguments deviceArrivalEventand deviceRemovedEventare both 
   set to NULL in this case. The application also passes a window handle (typically the main 
   window handle) as windowHandleargument. In case a device plug or unplug event occurs, 
   the driver posts the speciﬁed message to the speciﬁed window using the Win32 call 
   PostMessage. If a new device is connected (plugged in) the wParamparameter of the 
   message will be set to TUSBAUDIO_DEVICE_ARRIVAL_MSG. If a device is disconnected 
   (unplugged) the wParamparameter of the message will be set to 
   TUSBAUDIO_DEVICE_REMOVED_MSG. 

See Also 

   TUSBAUDIO_UnregisterPnpNotiﬁcation (page 12) 

TUSBAUDIO_UnregisterPnpNotiﬁcation 

Remove any plug/unplug event registration previously created by a call to 
TUSBAUDIO_RegisterPnpNotiﬁcation. 

Deﬁnition 
*/
   void 
   TUSBAUDIO_UnregisterPnpNotification(); 
/*Comments 

   An application must call this function before it destroys any objects previously passed to 
   TUSBAUDIO_RegisterPnpNotiﬁcation. It is safe to call this function if no registration 
   currently exists. The function performs no operation in this case. 

See Also 

   TUSBAUDIO_RegisterPnpNotiﬁcation (page 10) 

------------------------------------------------------------------------------
TUSBAUDIO_EnumerateDevices 

Enumerate the USB audio devices available in the system that may be controlled by the DLL. 

Deﬁnition 
*/
   TUsbAudioStatus 
   TUSBAUDIO_EnumerateDevices(); 
/*Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   This function needs to be called once before a device instance can be opened via 
   TUSBAUDIO_OpenDeviceByIndex. 

   A successful call to this function creates an internal device list which represents all supported 
   USB audio devices available in the system. Device instances (USB devices) are addressed by 
   means of a zero-based index that is passed to TUSBAUDIO_OpenDeviceByIndex. 

   Even if the function succeeds, there may be no devices available in the system. An application 
   should call TUSBAUDIO_GetDeviceCount to check for available devices. 

   A call to this function invalidates all open device instance handles. All current handles must 
   be closed via TUSBAUDIO_CloseDevice before this function is called. After this function is 
   called, handles can be opened again by calling TUSBAUDIO_OpenDeviceByIndex. 

See Also 

   TUSBAUDIO_OpenDeviceByIndex (page 15) 
   TUSBAUDIO_CloseDevice (page 17) 
   TUSBAUDIO_GetDeviceCount (page 14) 

/**************************************************************************/

/* TUSBAUDIO_GetDeviceCount 

Query the number of USB audio devices available in the system that may be controlled by the 
DLL. 

Deﬁnition 
*/
   unsigned int 
   TUSBAUDIO_GetDeviceCount(); 
/*Return Value 

   The function returns the number of supported USB audio devices. 

Comments 

   Supported USB audio devices are enumerated by calling TUSBAUDIO_EnumerateDevices. 
   Even if the TUSBAUDIO_EnumerateDevices function succeeds, there may be no devices 
   available in the system. An application should query the device count to check for available 
   devices. 

See Also 

   TUSBAUDIO_EnumerateDevices (page 13) 
/**************************************************************************/

/* TUSBAUDIO_OpenDeviceByIndex 

Open a device instance (USB audio device). 

Deﬁnition 
*/
   TUsbAudioStatus 
   TUSBAUDIO_OpenDeviceByIndex( 
      unsigned int deviceIndex, 
      TUsbAudioHandle* deviceHandle 
       ); 
/*Parameters 

deviceIndex 
   Zero-based index that speciﬁes the device instance to be opened. Device instances count from 
   zero to deviceCount-1. The deviceCountvalue is returned by 
   TUSBAUDIO_GetDeviceCount. 

deviceHandle 
   Address of a caller-provided variable that will be set to the device instance handle if the 
   function succeeds. If the function fails deviceHandlewill be set to NULL which is an 
   invalid handle value. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

   TSTATUS_ENUM_REQUIREDis returned if TUSBAUDIO_EnumerateDevices was not yet 
   called. 

Comments 

   A device instance opened by this function corresponds to a USB audio device. 
   TUSBAUDIO_EnumerateDevices needs to be called before any device instance can be 
   opened. 

   Each device index value corresponds to a physical device instance (USB audio device) present 
   in the system. The device index that is associated with a particular device may change by a 
   call to TUSBAUDIO_EnumerateDevices and must not be used to identify a device. An 
   application can query device identiﬁcation information by calling 
   TUSBAUDIO_GetDeviceProperties. 

See Also 

   TUSBAUDIO_GetDeviceCount (page 14) 
   TUSBAUDIO_EnumerateDevices (page 13) 
   TUSBAUDIO_GetDeviceProperties (page 18) 
   TUSBAUDIO_CloseDevice (page 17) */
 
 /*TUSBAUDIO_CloseDevice 

Close the speciﬁed device instance. 

Deﬁnition */
   TUsbAudioStatus 
   TUSBAUDIO_CloseDevice( 
      TUsbAudioHandle deviceHandle 
      ); 
/*Parameter 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

   TSTATUS_INVALD_HANDLEis returned if the given deviceHandleis invalid. 

Comments 

   Important: The speciﬁed device handle becomes invalid after this call and must not be used 
   in any subsequent function call. 

See Also 

   TUSBAUDIO_OpenDeviceByIndex (page 15) 
*/


/*TUSBAUDIO_GetDeviceProperties 

Query USB IDs and properties for a speciﬁc device. 

Deﬁnition*/ 

   // TUsbAudioStatus 
   // TUSBAUDIO_GetDeviceProperties( 
      // TUsbAudioHandle deviceHandle, 
      // TUsbAudioDeviceProperties* properties 
       // ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

properties 
   Points to a caller provided struct of type TUsbAudioDeviceProperties that receives the 
   requested information. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   This function reports static information associated with the speciﬁed device. This includes 
   USB vendor and product IDs, serial number, etc. See TUsbAudioDeviceProperties for more 
   information. 

See Also 

   TUSBAUDIO_OpenDeviceByIndex (page 15) 
   TUsbAudioDeviceProperties (page 69) */
     
/*TUSBAUDIO_RegisterDeviceNotiﬁcation 

Register for notiﬁcations to be issued by the driver on device state changes. 

Deﬁnition */

   TUsbAudioStatus 
   TUSBAUDIO_RegisterDeviceNotification( 
      TUsbAudioHandle deviceHandle, 
      unsigned int categoryFilter, 
      HANDLE sharedEvent, 
      unsigned int flags 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

categoryFilter 
   Speciﬁes the class of events to be received as a bitwise OR combination of bit ﬂags. 

   TUSBAUDIO_NOTIFY_CATEGORY_NONE 
      No event will be posted. Use this to unregister with the driver. 
   TUSBAUDIO_NOTIFY_CATEGORY_ALL 
      All kind of events will be posted. 
   TUSBAUDIO_NOTIFY_CATEGORY_SAMPLE_RATE_CHANGE 
      Device sample rate changed events will be posted. See TUsbAudioNotifyEvent for more 
      information. 
   TUSBAUDIO_NOTIFY_CATEGORY_STREAM_CHANGE 
      Device stream format changed events will be posted. See TUsbAudioNotifyEvent for 
      more information. 
   TUSBAUDIO_NOTIFY_CATEGORY_VOLUME_CHANGE 
      Volume or Mute changed events will be posted. See TUsbAudioNotifyEvent for more 
      information. 
   TUSBAUDIO_NOTIFY_CATEGORY_AC_NODE_INTERRUPT 
      Audio control node events will be posted. See TUsbAudioNotifyEvent for more 
      information. 

sharedEvent 
   Refers to a Win32 event object created by the caller. The driver will set this event to signaled 
   state if event messages are available and can be retrieved through 
   TUSBAUDIO_ReadDeviceNotiﬁcation. The driver will reset this event to not-signaled state 
   if no event messages are available. The event shared with the driver should be of auto-reset 
   type. 

   This parameter is optional. If an application does not need to share an event with the driver, it 
   passes NULL. 

flags 
   This parameter is reserved for future use and should be set to zero. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   A call to this function with categoryFilter != 
   TUSBAUDIO_NOTIFY_CATEGORY_NONEwill enable delivery of notiﬁcation event 
   messages in the driver. 

   To stop receiving event messages, an application can unregister with the driver by calling this 
   function with categoryFilterset to TUSBAUDIO_NOTIFY_CATEGORY_NONEand 
   sharedEventset to NULL. 

   If an application shares an event object with the driver then on every state change of the 
   driver-internal event queue the driver updates the state of this event object to reﬂect the current 
   state of the queue. The driver will signal the event object if the queue is not empty. The driver 
   will clear the event object if the queue is empty. 

   In order to guarantee correct functionality, an application should use an auto-reset type event 
   object. Typically, an application uses the shared event object to trigger an internal worker 
   thread. Once this thread awakes the event object will be automatically reset (auto-reset 
   behavior). 

   The application uses TUSBAUDIO_ReadDeviceNotiﬁcation to retrieve a message from the 
   driver-internal queue. Each call to TUSBAUDIO_ReadDeviceNotiﬁcation causes the driver 
   to update the state of the shared event. 

   If the application shares a manual-reset type event and needs to clear the event manually then 
   it must clear the event before it calls TUSBAUDIO_ReadDeviceNotiﬁcation. 

See Also 

   TUSBAUDIO_ReadDeviceNotiﬁcation (page 21) 
   TUSBAUDIO_OpenDeviceByIndex (page 15) 
   TUsbAudioNotifyEvent (page 75) 
*/

/*TUSBAUDIO_ReadDeviceNotiﬁcation 

Retrieve an event message from the driver-internal queue. 

Deﬁnition */

   TUsbAudioStatus 
   TUSBAUDIO_ReadDeviceNotification( 
      TUsbAudioHandle deviceHandle, 
      TUsbAudioNotifyEvent* eventType, 
      unsigned char* dataBuffer, 
      unsigned int dataBufferSize, 
      unsigned int* dataBytesReturned 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

eventType 
   Points to a caller-provided variable that will receive the type of the event. See 
   TUsbAudioNotifyEvent for more information. 

dataBuffer 
   Points to a caller-provided buffer that will receive additional data that may be attached to the 
   event. An application should provide a buffer of at least 
   TUSBAUDIO_NOTIFY_EVENT_MAX_DATA_BYTESbytes in size. See also the Comments 
   section below. 

dataBufferSize 
   Speciﬁes the size, in bytes, of the buffer pointed to by dataBuffer. An application should 
   provide a buffer of at least TUSBAUDIO_NOTIFY_EVENT_MAX_DATA_BYTESbytes in 
   size. See also the Comments section below. 

dataBytesReturned 
   Points to a caller-provided variable that will be set to the number of bytes returned in the 
   buffer pointed to by dataBuffer. This variable is optional. An application can set 
   dataBytesReturnedto NULL if the information is not needed. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. The event message 
   has been removed from the driver-internal queue in this case. 

   The function returns TSTATUS_NO_MORE_ITEMSif the driver-internal event message 
   queue is empty. No event message has been returned in this case. 

   The function returns TSTATUS_BUFFER_TOO_SMALLif the buffer provided at 
   dataBufferis too small to receive the data ﬁeld attached to the event message. The current 
   event message has not been removed from the driver-internal queue in this case. The 
   application needs to call this function again providing a larger buffer. 

Comments 

   An application calls this function to retrieve an event message from the driver-internal event 
   message queue. To receive messages, an application needs to register for notiﬁcations via 
   TUSBAUDIO_RegisterDeviceNotiﬁcation. 

   If the application registered a shared event object with the driver, the driver will update that 
   event’s state on every call to this function. Fore more information on how to register an event 
   object, see also TUSBAUDIO_RegisterDeviceNotiﬁcation. 

   Some types of messages have an attached data ﬁeld. See TUsbAudioNotifyEvent for more 
   information. To reveive this data ﬁeld (if present), an application should provide a data buffer 
   with each call to this function. The buffer must be at least 
   TUSBAUDIO_NOTIFY_EVENT_MAX_DATA_BYTESbytes in size. 

See Also 

   TUSBAUDIO_RegisterDeviceNotiﬁcation (page 19) 
   TUSBAUDIO_OpenDeviceByIndex (page 15) 
   TUsbAudioNotifyEvent (page 75) */
   
/*TUSBAUDIO_GetSupportedSampleRates 

Query the list of sampling rates that are supported by a speciﬁc device. 

Deﬁnition */

   TUsbAudioStatus 
   TUSBAUDIO_GetSupportedSampleRates( 
      TUsbAudioHandle deviceHandle, 
      unsigned int sampleRateMaxCount, 
      unsigned int sampleRateArray[], 
      unsigned int* sampleRateCount 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

sampleRateMaxCount 
   Speciﬁes the maximum number of sampling rates that can be stored to sampleRateArray. 

sampleRateArray[] 
   Caller-provided buffer that will receive the supported sampling rates. The sampling rates are 
   speciﬁed in 1/s. 

sampleRateCount 
   Caller-provided variable that will be set to the number of valid entries in 
   sampleRateArrayon return. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

See Also 

   TUSBAUDIO_GetCurrentSampleRate (page 24)*/ 
   
/*TUSBAUDIO_GetCurrentSampleRate 

Query the sampling rate that is currently set for a speciﬁc device. 

Deﬁnition */

   TUsbAudioStatus 
   TUSBAUDIO_GetCurrentSampleRate( 
      TUsbAudioHandle deviceHandle, 
      unsigned int* sampleRate 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

sampleRate 
   Caller-provided variable that will be set to the current sampling rate. The sampling rate is 
   speciﬁed in 1/s. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

See Also 

   TUSBAUDIO_GetSupportedSampleRates (page 23) */
   
/*TUSBAUDIO_GetSupportedClockSources 

Query the list of clock sources that are supported by a speciﬁc device. 

Deﬁnition */

   TUsbAudioStatus 
   TUSBAUDIO_GetSupportedClockSources( 
      TUsbAudioHandle deviceHandle, 
      unsigned int clockSourceMaxCount, 
      TUsbAudioClockSource clockSourceArray[], 
      unsigned int* clockSourceCount 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

clockSourceMaxCount 
   Speciﬁes the maximum number of clock sources that can be stored to clockSourceArray. 

clockSourceArray[] 
   Caller-provided array of TUsbAudioClockSource structures that will receive the supported 
   clock sources. 

clockSourceCount 
   Caller-provided variable that will be set to the number of valid entries in 
   clockSourceArrayon return. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

See Also 

   TUSBAUDIO_GetCurrentClockSource (page 26) 
   TUSBAUDIO_SetCurrentClockSource (page 27) 
   TUsbAudioClockSource (page 71) */
 
/*TUSBAUDIO_GetCurrentClockSource 

Query the clock source that is currently set for a speciﬁc device. 

Deﬁnition */

   TUsbAudioStatus 
   TUSBAUDIO_GetCurrentClockSource( 
      TUsbAudioHandle deviceHandle, 
      TUsbAudioClockSource* clockSource 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

clockSource 
   Caller-provided TUsbAudioClockSource structure that will be set to the current clock source. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

See Also 

   TUSBAUDIO_GetSupportedClockSources (page 25) 
   TUsbAudioClockSource (page 71) */

/*TUSBAUDIO_SetCurrentClockSource 

Select the active clock source of a speciﬁc device. 

Deﬁnition*/ 

   TUsbAudioStatus 
   TUSBAUDIO_SetCurrentClockSource( 
      TUsbAudioHandle deviceHandle, 
      unsigned int clockSourceId 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

clockSourceId 
   Unique ID that identiﬁes the clock source to be selected. This ID is returned in the 
   clockSourceIdmember of the TUsbAudioClockSource structure. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   An application uses TUSBAUDIO_GetSupportedClockSources to retrieve a list of available 
   clock sources. Each clock source is described by a TUsbAudioClockSource structure. 

See Also 

   TUSBAUDIO_GetSupportedClockSources (page 25) 
   TUSBAUDIO_GetCurrentClockSource (page 26) 
   TUsbAudioClockSource (page 71) */

/*TUSBAUDIO_GetSupportedStreamFormats 

Query the stream formats that are supported by the input or output stream of the USB audio 
device. 

Deﬁnition*/ 

   TUsbAudioStatus 
   TUSBAUDIO_GetSupportedStreamFormats( 
      TUsbAudioHandle deviceHandle, 
      unsigned int inputStream, 
      unsigned int formatMaxCount, 
      TUsbAudioStreamFormat formatArray[], 
      unsigned int* formatCount 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

inputStream 
   Speciﬁes the stream format set to be returned. Set to one for input stream formats and to zero 
   for output stream formats. 

formatMaxCount 
   Speciﬁes the maximum number of items that can be stored to the formatArraybuffer. 

formatArray[] 
   Caller-provided buffer that will receive the TUsbAudioStreamFormat structures (one item 
   per format). 

formatCount 
   Caller-provided variable that will be set to the number of valid entries in formatArray. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   The function returns TSTATUS_NOT_AVAILABLEif there are no stream formats supported 
   for the given direction. This indicates that the device has no stream for this direction 
   (OUT-only or IN-only conﬁguration). 

See Also 

   TUsbAudioStreamFormat (page 72) 
   TUSBAUDIO_GetCurrentStreamFormat (page 30) 
   TUSBAUDIO_SetCurrentStreamFormat (page 31) */
   
/*TUSBAUDIO_GetCurrentStreamFormat 

Query the stream format that is currently set for the input or output stream of the USB audio 
device. 

Deﬁnition*/ 

   TUsbAudioStatus 
   TUSBAUDIO_GetCurrentStreamFormat( 
      TUsbAudioHandle deviceHandle, 
      unsigned int inputStream, 
      unsigned int* format 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

inputStream 
   Speciﬁes what stream format will be queried. Set to one to query the current input stream 
   format and to zero to query the current output stream format. 

format 
   Caller-provided variable that will receive information on the current stream format. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   The function returns TSTATUS_NOT_AVAILABLEif there is no current stream format for 
   the given direction. This indicates that the device has no stream for this direction (OUT-only 
   or IN-only conﬁguration). 

See Also 

   TUsbAudioStreamFormat (page 72) 
   TUSBAUDIO_GetSupportedStreamFormats (page 28) 
   TUSBAUDIO_SetCurrentStreamFormat (page 31) */
   
/*TUSBAUDIO_SetCurrentStreamFormat 

Set the stream format for the input or output stream of the USB audio device. 

Deﬁnition*/ 

   TUsbAudioStatus 
   TUSBAUDIO_SetCurrentStreamFormat( 
      TUsbAudioHandle deviceHandle, 
      unsigned int inputStream, 
      unsigned int formatId 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

inputStream 
   Speciﬁes what stream format will be set. Set to one to set the input stream format and to zero 
   to set the output stream format. 

formatId 
   Contains the unique ID that identiﬁes the stream format to be set. 

   Set to the formatIdof the TUsbAudioStreamFormat structure that corresponds with the 
   stream format. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

See Also 

   TUsbAudioStreamFormat (page 72) 
   TUSBAUDIO_GetSupportedStreamFormats (page 28) 
   TUSBAUDIO_SetCurrentStreamFormat (page 31) */

/*TUSBAUDIO_GetChannelProperties 

Query the channel properties for the input or output channels of the USB audio device. 

Deﬁnition */

   TUsbAudioStatus 
   TUSBAUDIO_GetChannelProperties( 
      TUsbAudioHandle deviceHandle, 
      unsigned int inputChannels, 
      unsigned int channelMaxCount, 
      TUsbAudioChannelProperty channelArray[], 
      unsigned int* channelCount 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

inputChannels 
   Speciﬁes the channel set to be returned. Set to one for input channel set and to zero for output 
   channel set. 

channelMaxCount 
   Speciﬁes the maximum number of items that can be stored to the channelArraybuffer. 

channelArray[] 
   Caller-provided buffer that will receive the TUsbAudioChannelProperty structures (one item 
   per channel). 

channelCount 
   Caller-provided variable that will be set to the number of valid entries in channelArray. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

See Also 

   TUsbAudioChannelProperty (page 73) */

/*TUSBAUDIO_GetUsbConﬁgDescriptor 

Query the USB Conﬁguration Descriptor of a speciﬁc device. 

Deﬁnition */

   TUsbAudioStatus 
   TUSBAUDIO_GetUsbConfigDescriptor( 
      TUsbAudioHandle deviceHandle, 
      unsigned char* descBuffer, 
      unsigned int bufferSize, 
      unsigned int* bytesReturned 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

descBuffer 
   Caller-provided buffer that will receive the USB Conﬁguration Descriptor. 

bufferSize 
   Speciﬁes the size of the descBufferbuffer in bytes. 

bytesReturned 
   Caller-provided variable that will be set to the number of valid bytes in descBufferon 
   return. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

See Also 

   TUSBAUDIO_GetUsbStringDescriptorString (page 34) */
   
/*TUSBAUDIO_GetUsbStringDescriptorString 

Query the string of a speciﬁc USB String Descriptor of a speciﬁc device. 

Deﬁnition */

   TUsbAudioStatus 
   TUSBAUDIO_GetUsbStringDescriptorString( 
      TUsbAudioHandle deviceHandle, 
      unsigned char stringIndex, 
      int languageId, 
      WCHAR descString, 
      unsigned int descStringMaxChars 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

stringIndex 
   Speciﬁes the index of the string descriptor. 
   String index 0 is reserved for the list of language IDs and will be rejected by this function. 

languageId 
   Speciﬁes the language ID of the string descriptor. 
   If set to a negative value the ﬁrst language ID reported by the device is used. 

descString 
   Caller-provided buffer that will receive the string of the USB String Descriptor. 
   The string is returned as a wide character string and is always zero-terminated. 

descStringMaxChars 
   Speciﬁes the maximum number of characters (including terminating null) in descString 
   buffer. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

See Also 

   TUSBAUDIO_GetUsbConﬁgDescriptor (page 33) */
   
/*TUSBAUDIO_AudioControlRequestSet 

Execute a USB Audio Class Control Set request with a speciﬁc device. 

Deﬁnition */

   TUsbAudioStatus 
   TUSBAUDIO_AudioControlRequestSet( 
      TUsbAudioHandle deviceHandle, 
      unsigned char entityID, 
      unsigned char request, 
      unsigned char controlSelector, 
      unsigned char channelOrMixerControl, 
      const void* paramBlock, 
      unsigned int paramBlockLength, 
      unsigned int* bytesTransferred, 
      unsigned int timeoutMillisecs 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

entityID 
   Speciﬁes the ID of the entity that is addressed by the request. 

request 
   Speciﬁes the attribute (CUR or RANGE) to be manipulated by the request. 

controlSelector 
   Speciﬁes the Control Selector (CS) of the request. 

channelOrMixerControl 
   Speciﬁes the Channel Number (CN) or the Mixer Control Number (MCN) of the request. 

paramBlock 
   Caller-provided buffer that holds the parameter block of the request. 
   This parameter is optional and must be set to NULL if the request has no parameter block. 

paramBlockLength 
   Speciﬁes the size of paramBlockin bytes. 

bytesTransferred 
   Caller-provided variable that will be set to the number of bytes that were transferred by the 
   request. 
   This parameter is optional and can be set to NULL if this information is not of interest. 

timeoutMillisecs 
   Speciﬁes the request timeout in milliseconds. 

Reurn Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

See Also 

   TUSBAUDIO_AudioControlRequestGet (page 37) */

/*TUSBAUDIO_AudioControlRequestGet 

Execute a USB Audio Class Control Get request with a speciﬁc device. 

Deﬁnition */

   TUsbAudioStatus 
   TUSBAUDIO_AudioControlRequestGet( 
      TUsbAudioHandle deviceHandle, 
      unsigned char entityID, 
      unsigned char request, 
      unsigned char controlSelector, 
      unsigned char channelOrMixerControl, 
      const void* paramBlock, 
      unsigned int paramBlockLength, 
      unsigned int* bytesTransferred, 
      unsigned int timeoutMillisecs 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

entityID 
   Speciﬁes the ID of the entity that is addressed by the request. 

request 
   Speciﬁes the attribute (CUR or RANGE) to be retrieved by the request. 

controlSelector 
   Speciﬁes the Control Selector (CS) of the request. 

channelOrMixerControl 
   Speciﬁes the Channel Number (CN) or the Mixer Control Number (MCN) of the request. 

paramBlock 
   Caller-provided buffer that receives the parameter block of the request. 
   This parameter is optional and must be set to NULL if the request has no parameter block. 

paramBlockLength 
   Speciﬁes the size of paramBlockin bytes. 

bytesTransferred 
   Caller-provided variable that will be set to the number of bytes that were transferred by the 
   request. 
   This parameter is optional and can be set to NULL if this information is not of interest. 

timeoutMillisecs 
   Speciﬁes the request timeout in milliseconds. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

See Also 

   TUSBAUDIO_AudioControlRequestSet (page 35) */
 
/*TUSBAUDIO_GetDriverInfo 

Retrieve driver version information. 

Deﬁnition */
   TUsbAudioStatus 
   TUSBAUDIO_GetDriverInfo( 
      TUsbAudioDriverInfo* driverInfo 
       ); 

/*Parameter 

driverInfo 
   Points to a caller provided struct of type TUsbAudioDriverInfo that receives the requested 
   information. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

   The function returns TSTATUS_ENUM_REQUIREDif TUSBAUDIO_EnumerateDevices 
   was not called prior to the call to this function. 

Comments 

   This function reports static information about the device driver. See TUsbAudioDriverInfo 
   for more information. 

   An application needs to call TUSBAUDIO_EnumerateDevices before this function can be 
   used. 

See Also 

   TUSBAUDIO_EnumerateDevices (page 13) 
   TUsbAudioDriverInfo (page 67) */
   
/*TUSBAUDIO_GetStreamingBufferSizeSet 

Query the set of streaming buffer sizes that are supported by the driver. 

Deﬁnition */
   TUsbAudioStatus 
   TUSBAUDIO_GetStreamingBufferSizeSet( 
      unsigned int bufferSizeMaxCount, 
      unsigned int bufferSizeArray_us[], 
      unsigned int* bufferSizeCount, 
      unsigned int* bufferSizeCurrentIndex 
       ); 

/*Parameters 

bufferSizeMaxCount 
   Speciﬁes the maximum number of streaming buffer sizes that can be stored to 
   bufferSizeArray_us. 

bufferSizeArray_us[] 
   Caller-provided buffer that will receive the set of supported streaming buffers sizes. A buffer 
   size is speciﬁed in microseconds. 

bufferSizeCount 
   Caller-provided variable that will be set to the number of valid entries in 
   bufferSizeArray_us. 

bufferSizeCurrentIndex 
   Caller-provided variable that will be set to the current streaming buffer size (speciﬁed as an 
   index into bufferSizeArray_us). 
   This parameter is optional and can be set to NULL if this information is not of interest. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

   The function returns TSTATUS_ENUM_REQUIREDif TUSBAUDIO_EnumerateDevices 
   was not called prior to the call to this function. 

Comments 

   An application needs to call TUSBAUDIO_EnumerateDevices before this function can be 
   used. 

See Also 

   TUSBAUDIO_GetStreamingBufferSize (page 42) 
   TUSBAUDIO_SetStreamingBufferSize (page 43) 
   TUSBAUDIO_GetAsioBufferSizeSet (page 44) 
   TUSBAUDIO_EnumerateDevices (page 13) */

/*TUSBAUDIO_GetStreamingBufferSize 

Query the current streaming buffer size. 

Deﬁnition */
   TUsbAudioStatus 
   TUSBAUDIO_GetStreamingBufferSize( 
      unsigned int* sizeMicroseconds 
       ); 

/*Parameter 

sizeMicroseconds 
   Caller-provided variable that will be set to the current streaming buffer size. The buffer size is 
   speciﬁed in microseconds. 

   The function returns TSTATUS_ENUM_REQUIREDif TUSBAUDIO_EnumerateDevices 
   was not called prior to the call to this function. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

   The function returns TSTATUS_ENUM_REQUIREDif TUSBAUDIO_EnumerateDevices 
   was not called prior to the call to this function. 

Comments 

   An application needs to call TUSBAUDIO_EnumerateDevices before this function can be 
   used. 

See Also 

   TUSBAUDIO_GetStreamingBufferSizeSet (page 40) 
   TUSBAUDIO_SetStreamingBufferSize (page 43) 
   TUSBAUDIO_GetAsioBufferSize (page 46) 
   TUSBAUDIO_EnumerateDevices (page 13) */

/*TUSBAUDIO_SetStreamingBufferSize 

Set a new streaming buffer size. 

Deﬁnition */
   TUsbAudioStatus 
   TUSBAUDIO_SetStreamingBufferSize( 
      unsigned int sizeMicroseconds 
      ); 

/*Parameter 

sizeMicroseconds 
   Speciﬁes the new streaming buffer size in microseconds. This must be one of the supported 
   streaming buffer sizes. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

   The function returns TSTATUS_ENUM_REQUIREDif TUSBAUDIO_EnumerateDevices 
   was not called prior to the call to this function. 

Comments 

   An application needs to call TUSBAUDIO_EnumerateDevices before this function can be 
   used. 

See Also 

   TUSBAUDIO_GetStreamingBufferSizeSet (page 40) 
   TUSBAUDIO_GetStreamingBufferSize (page 42) 
   TUSBAUDIO_SetAsioBufferSize (page 47) 
   TUSBAUDIO_EnumerateDevices (page 13) */

/*TUSBAUDIO_GetAsioBufferSizeSet 

Query the set of ASIO buffer sizes (switch interval) that are supported by the driver. 

Deﬁnition */
   TUsbAudioStatus 
   TUSBAUDIO_GetAsioBufferSizeSet( 
      unsigned int bufferSizeMaxCount, 
      unsigned int bufferSizeArray_us[], 
      unsigned int* bufferSizeCount, 
      unsigned int* bufferSizeCurrentIndex 
       ); 
/*Parameters 

bufferSizeMaxCount 
   Speciﬁes the maximum number of ASIO buffer sizes that can be stored to 
   bufferSizeArray_us. 

bufferSizeArray_us[] 
   Caller-provided buffer that will receive the set of supported ASIO buffers sizes. A buffer size 
   is speciﬁed in microseconds. 

bufferSizeCount 
   Caller-provided variable that will be set to the number of valid entries in 
   bufferSizeArray_us. 

bufferSizeCurrentIndex 
   Caller-provided variable that will be set to the current ASIO buffer size (speciﬁed as an index 
   into bufferSizeArray_us). This parameter is optional and can be set to NULL if this 
   information is not of interest. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

   The function returns TSTATUS_ENUM_REQUIREDif TUSBAUDIO_EnumerateDevices 
   was not called prior to the call to this function. 

Comments 

   An application needs to call TUSBAUDIO_EnumerateDevices before this function can be 
   used. 

See Also 

   TUSBAUDIO_GetAsioBufferSize (page 46) 
   TUSBAUDIO_SetAsioBufferSize (page 47) 
   TUSBAUDIO_GetStreamingBufferSizeSet (page 40) 
   TUSBAUDIO_EnumerateDevices (page 13) */

/*TUSBAUDIO_GetAsioBufferSize 

Query the current ASIO buffer size (switch interval). 

Deﬁnition*/ 
   TUsbAudioStatus 
   TUSBAUDIO_GetAsioBufferSize( 
      unsigned int* sizeMicroseconds 
      ); 
/*Parameter 

sizeMicroseconds 
   Caller-provided variable that will be set to the current ASIO buffer size. The buffer size is 
   speciﬁed in microseconds. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

   The function returns TSTATUS_ENUM_REQUIREDif TUSBAUDIO_EnumerateDevices 
   was not called prior to the call to this function. 

Comments 

   An application needs to call TUSBAUDIO_EnumerateDevices before this function can be 
   used. 

See Also 

   TUSBAUDIO_GetAsioBufferSizeSet (page 44) 
   TUSBAUDIO_SetAsioBufferSize (page 47) 
   TUSBAUDIO_GetStreamingBufferSize (page 42) 
   TUSBAUDIO_EnumerateDevices (page 13) */

/*TUSBAUDIO_SetAsioBufferSize 

Set a new ASIO buffer size (switch interval). 

Deﬁnition */
   TUsbAudioStatus 
   TUSBAUDIO_SetAsioBufferSize( 
      unsigned int sizeMicroseconds 
      ); 
/*Parameter 

sizeMicroseconds 
   Speciﬁes the new ASIO buffer size in microseconds. This must be one of the supported ASIO 
   buffer sizes. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

   The function returns TSTATUS_ENUM_REQUIREDif TUSBAUDIO_EnumerateDevices 
   was not called prior to the call to this function. 

Comments 

   An application needs to call TUSBAUDIO_EnumerateDevices before this function can be 
   used. 

See Also 

   TUSBAUDIO_GetAsioBufferSize (page 46) 
   TUSBAUDIO_SetAsioBufferSize (page 47) 
   TUSBAUDIO_SetStreamingBufferSize (page 43) 
   TUSBAUDIO_EnumerateDevices (page 13) */

/*TUSBAUDIO_GetDeviceUsbMode 

Query the current run mode of the USB device. 

Deﬁnition */

   TUsbAudioStatus 
   TUSBAUDIO_GetDeviceUsbMode( 
      TUsbAudioHandle deviceHandle, 
      TUsbAudioDeviceRunMode* runMode 
      ); 

/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB device). The handle needs to be created by a 
   call to TUSBAUDIO_OpenDeviceByIndex. 

runMode 
   Caller-provided variable that will be set to the current run mode of the USB device. See 
   TUsbAudioDeviceRunMode for more information. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

See Also 

   TUsbAudioDeviceRunMode (page 78) */

/*TUSBAUDIO_StatusCodeStringW 

Convert a status code to a symbolic name (wide-character variant). 

Deﬁnition */
   const WCHAR* 
   TUSBAUDIO_StatusCodeStringW( 
      TSTATUS statusCode 
      ); 
/*Parameter 

statusCode 
   Contains the status code to be converted. 

Return Value 

   The function returns the symbolic name for the given status code as a zero-terminated wide 
   character string. 

See Also 

   TUSBAUDIO_StatusCodeStringA (page 50) */

/*TUSBAUDIO_StatusCodeStringA 

Convert a status code to a symbolic name (ASCII variant). 

Deﬁnition*/ 
   const char* 
   TUSBAUDIO_StatusCodeStringA( 
      TSTATUS statusCode 
      ); 
/*Parameter 

statusCode 
   Contains the status code to be converted. 

Return Value 

   The function returns the symbolic name for the given status code as a zero-terminated ASCII 
   character string. 

See Also 

   TUSBAUDIO_StatusCodeStringW (page 49) */
 
/*TUSBAUDIO_LoadFirmwareImageFromBuffer 

Load a ﬁrmware image from the provided buffer. 

Deﬁnition */

   TUsbAudioStatus 
   TUSBAUDIO_LoadFirmwareImageFromBuffer( 
      const unsigned char* buffer, 
      unsigned int numberOfBytes, 
      unsigned int flags 
       ); 
/*Parameters 

buffer 
   Caller-provided buffer that contains the ﬁrmware image as a whole. 

numberOfBytes 
   Speciﬁes the size of the ﬁrmware image, in bytes. 

flags 
   This parameter is reserved for future use and has to be set to zero. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   An application calls this function to load the ﬁrmware image to be downloaded. 

   Only one ﬁrmware image will be loaded at a given point in time. A previously loaded image 
   will be unloaded automatically when this function is called. 

   If the ﬁrmware image is supplied as a ﬁle on disk the 
   TUSBAUDIO_LoadFirmwareImageFromFile function may be used to load it. 

See Also 

   TUSBAUDIO_LoadFirmwareImageFromFile (page 52) 
   TUSBAUDIO_GetFirmwareImage (page 55) 
   TUSBAUDIO_GetFirmwareImageSize (page 53) 
   TUSBAUDIO_UnloadFirmwareImage (page 54) */

/*TUSBAUDIO_LoadFirmwareImageFromFile 

Load a ﬁrmware image from a ﬁle on disk. 

Deﬁnition */

   TUsbAudioStatus 
   TUSBAUDIO_LoadFirmwareImageFromFile( 
      const WCHAR* fileName, 
      unsigned int flags 
      ); 
/*Parameters 

fileName 
   Speciﬁes the path and name of the ﬁrmware image ﬁle as a zero-terminated string. 

flags 
   This parameter is reserved for future use and has to be set to zero. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   An application calls this function to load the ﬁrmware image to be downloaded. 

   Only one ﬁrmware image will be loaded at a given point in time. A previously loaded image 
   will be unloaded automatically when this function is called. 

   If the ﬁrmware image is not supplied as a ﬁle on disk but is contained in an application buffer 
   the TUSBAUDIO_LoadFirmwareImageFromBuffer function may be used to load it. 

See Also 

   TUSBAUDIO_LoadFirmwareImageFromBuffer (page 51) 
   TUSBAUDIO_GetFirmwareImage (page 55) 
   TUSBAUDIO_GetFirmwareImageSize (page 53) 
   TUSBAUDIO_UnloadFirmwareImage (page 54) */

/*TUSBAUDIO_GetFirmwareImageSize 

Query the size of the ﬁrmware image that is currently loaded. 

Deﬁnition */
   TUsbAudioStatus 
   TUSBAUDIO_GetFirmwareImageSize( 
      unsigned int* numberOfBytes, 
      unsigned int flags 
      ); 
/*Parameters 

numberOfBytes 
   Caller-provided variable that will be set to the size of the ﬁrmware image, in bytes. 

flags 
   This parameter is set to zero or a bitwise-or combination of the following constants: 

   TUSBAUDIO_FLAG_UPLOADED_IMAGE 
      Query the size of a ﬁrmware that was uploaded from the device (see 
      TUSBAUDIO_StartDfuUpload). 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

   TSTATUS_NOT_AVAILABLEis returned if no image was loaded. 

Comments 

   If the flagsparameter is set to zero the function will return the size of the ﬁrmware image 
   that was loaded from buffer or ﬁle (if any). 

See Also 

   TUSBAUDIO_LoadFirmwareImageFromBuffer (page 51) 
   TUSBAUDIO_LoadFirmwareImageFromFile (page 52) 
   TUSBAUDIO_StartDfuUpload (page 58) 
   TUSBAUDIO_GetFirmwareImage (page 55) */

   /*TUSBAUDIO_UnloadFirmwareImage 

Unload the ﬁrmware image that is currently loaded. 

Deﬁnition */
   TUsbAudioStatus 
   TUSBAUDIO_UnloadFirmwareImage(); 
/*Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   An application calls this function to unload a ﬁrmware image that was loaded from buffer or 
   ﬁle and to free associated resources. The function should be called after the DFU operation 
   was completed. 

   It is safe to call this function if no image is currently loaded. 

See Also 

   TUSBAUDIO_LoadFirmwareImageFromBuffer (page 51) 
   TUSBAUDIO_LoadFirmwareImageFromFile (page 52) */

/*TUSBAUDIO_GetFirmwareImage 

Return the ﬁrmware image that was uploaded from the USB device. 

Deﬁnition */
   TUsbAudioStatus 
   TUSBAUDIO_GetFirmwareImage( 
      unsigned char* buffer, 
      unsigned int bufferSize, 
      unsigned int* bytesReturned, 
      unsigned int flags 
       ); 
/*Parameters 

buffer 
   Caller-provided buffer that will receive the uploaded ﬁrmware image. 

bufferSize 
   Speciﬁes the size of the buffer pointed to by buffer, in bytes. 

bytesReturned 
   Caller-provided variable that will be set to the size of the ﬁrmware image, in bytes. 

flags 
   This parameter is reserved for future use and has to be set to zero. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   This function will fail if 

         there is no uploaded ﬁrmware image 

         a DFU operation is currently in progress 

         the uploaded ﬁrmware image does not ﬁt to the provided buffer. 

See Also 

   TUSBAUDIO_GetFirmwareImageSize (page 53) 
   TUSBAUDIO_StartDfuUpload (page 58) */

/*TUSBAUDIO_StartDfuDownload 

Download the current ﬁrmware image to the USB device. 

Deﬁnition */
 TUsbAudioStatus 
   TUSBAUDIO_StartDfuDownload( 
      unsigned int deviceIndex, 
      unsigned int targetIndex, 
      unsigned int flags 
       ); 
/*Parameters 

deviceIndex 
   Zero-based index that speciﬁes the USB device instance to be used for the DFU operation. 
   Device instances count from zero to deviceCount-1. The deviceCountvalue is 
   returned by TUSBAUDIO_GetDeviceCount. 

targetIndex 
   Speciﬁes the target of the download. A value of 0 represents the standard ﬁrmware target. 
   Other values are device speciﬁc. For example, a value of 1 could identify an external (serial) 
   EEPROM device and a value of 2 could represent an SD card. 

flags 
   This parameter is reserved for future use and has to be set to zero. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   Calling this function is only allowed if no DFU operation is in progress 
   (TUSBAUDIO_GetDfuStatus indicates DfuProcState_Idle). If a previous DFU 
   operation has completed the application has to call TUSBAUDIO_EndDfuProc before it can 
   start another DFU operation. 

   This function initiates the DFU download operation and returns after the download has started. 
   An application calls TUSBAUDIO_GetDfuStatus to monitor the state of the download 
   operation. After the download operation has completed the application has to call 
   TUSBAUDIO_EndDfuProc to ﬁnalize it. 

   The ﬁrmware image that will be downloaded is selected by a call to 
   TUSBAUDIO_LoadFirmwareImageFromBuffer or 
   TUSBAUDIO_LoadFirmwareImageFromFile. 

See Also 

   TUSBAUDIO_LoadFirmwareImageFromBuffer (page 51) 
   TUSBAUDIO_LoadFirmwareImageFromFile (page 52) 
   TUSBAUDIO_StartDfuUpload (page 58) 
   TUSBAUDIO_StartDfuRevertToFactoryImage (page 60) 
   TUSBAUDIO_GetDfuStatus (page 61) 
   TUSBAUDIO_EndDfuProc (page 63) */

/*TUSBAUDIO_StartDfuUpload 

Upload the current ﬁrmware image from the USB device. 

Deﬁnition */
   TUsbAudioStatus 
   TUSBAUDIO_StartDfuUpload( 
      unsigned int deviceIndex, 
      unsigned int targetIndex, 
      unsigned int flags 
       ); 
/*Parameters 

deviceIndex 
   Zero-based index that speciﬁes the USB device instance to be used for the DFU operation. 
   Device instances count from zero to deviceCount-1. The deviceCountvalue is 
   returned by TUSBAUDIO_GetDeviceCount. 

targetIndex 
   Speciﬁes the source for the upload. A value of 0 represents the standard ﬁrmware target. 
   Other values are device speciﬁc. For example, a value of 1 could identify an external (serial) 
   EEPROM device and a value of 2 could represent an SD card. 

flags 
   This parameter is reserved for future use and has to be set to zero. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   Calling this function is only allowed if no DFU operation is in progress 
   (TUSBAUDIO_GetDfuStatus indicates DfuProcState_Idle). If a previous DFU 
   operation has completed the application has to call TUSBAUDIO_EndDfuProc before it can 
   start another DFU operation. 

   This function initiates the DFU upload operation and returns after the upload has started. An 
   application calls TUSBAUDIO_GetDfuStatus to monitor the state of the upload operation. 
   After the upload operation has completed the application has to call 
   TUSBAUDIO_EndDfuProc to ﬁnalize it. 

   If the upload has completed successfully the ﬁrmware image can be accessed by calling 
   TUSBAUDIO_GetFirmwareImage. 

See Also 

   TUSBAUDIO_StartDfuDownload (page 56) 
   TUSBAUDIO_StartDfuRevertToFactoryImage (page 60) 
   TUSBAUDIO_GetDfuStatus (page 61) 
   TUSBAUDIO_EndDfuProc (page 63) 
   TUSBAUDIO_GetFirmwareImage (page 55) */

/*TUSBAUDIO_StartDfuRevertToFactoryImage 

Roll the ﬁrmware on the device back to the image that was installed originally (revert to 
factory-default image). 

Deﬁnition */
   TUsbAudioStatus 
   TUSBAUDIO_StartDfuRevertToFactoryImage( 
      unsigned int deviceIndex, 
      unsigned int flags 
       ); 
/*Parameters 

deviceIndex 
   Zero-based index that speciﬁes the USB device instance to be used for the DFU operation. 
   Device instances count from zero to deviceCount-1. The deviceCountvalue is 
   returned by TUSBAUDIO_GetDeviceCount. 

flags 
   This parameter is reserved for future use and has to be set to zero. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   Calling this function is only allowed if no DFU operation is in progress 
   (TUSBAUDIO_GetDfuStatus indicates DfuProcState_Idle). If a previous DFU 
   operation has completed the application has to call TUSBAUDIO_EndDfuProc before it can 
   start another DFU operation. 

   This function initiates the DFU revert operation and returns after it has started. An application 
   calls TUSBAUDIO_GetDfuStatus to monitor the state of the revert operation. After the 
   revert operation has completed the application has to call TUSBAUDIO_EndDfuProc to 
   ﬁnalize it. 

See Also 

   TUSBAUDIO_StartDfuDownload (page 56) 
   TUSBAUDIO_StartDfuUpload (page 58) 
   TUSBAUDIO_GetDfuStatus (page 61) 
   TUSBAUDIO_EndDfuProc (page 63) */

   /*TUSBAUDIO_GetDfuStatus 

Check the status of the current DFU operation. 

Deﬁnition */
   TUsbAudioStatus 
   TUSBAUDIO_GetDfuStatus( 
      TUsbAudioDfuProcState* downloadState, 
      unsigned int* currentBytes, 
      unsigned int* totalBytes, 
      TUsbAudioStatus* completionStatus 
       ); 
/*Parameters 

downloadState 
   Caller-provided variable that will be set to the current state of the DFU operation. See the 
   Comments section below and TUsbAudioDfuProcState for more information. 

currentBytes 
   Caller-provided variable that will be set to the number of bytes already processed by the 
   current DFU operation. 

   This parameter is optional and can be set to NULL if the information is not needed. 

totalBytes 
   Caller-provided variable that will be set to the total number of bytes to be processed by the 
   current DFU operation. 

   This parameter is optional and can be set to NULL if the information is not needed. 

completionStatus 
   Caller-provided variable that will be set to the status of the DFU operation. For more 
   information, see the Comments section below. 

   This parameter is optional and can be set to NULL if the information is not needed. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   The completion of a DFU operation is indicated by setting the downloadStatevariable to 
   DfuProcState_Finishedor DfuProcState_Failed. 

   As long as a DFU operation is in progress this function will set the completionStatus 
   variable to TSTATUS_SUCCESS. If the operation was completed with error 
   (downloadStateis set to DfuProcState_Failed) the completionStatus 
   variable will be set to a TSTATUS_xxxstatus code describing the error. 

   The totalByteswill only be set while a DFU download operation is in progress. It is not 
   available for upload operations and has no meaning for revert operations. 

   The currentBytesvariable will only be set while a download or upload operation is in 
   progress. It has no meaning for revert operations. 

   After a DFU operation has completed the application has to call TUSBAUDIO_EndDfuProc 
   to ﬁnalize it. After that, another DFU operation can be initiated. 

See Also 

   TUSBAUDIO_StartDfuDownload (page 56) 
   TUSBAUDIO_StartDfuUpload (page 58) 
   TUSBAUDIO_StartDfuRevertToFactoryImage (page 60) 
   TUSBAUDIO_EndDfuProc (page 63) 
   TUsbAudioDfuProcState (page 77) */

/*TUSBAUDIO_EndDfuProc 

Finalize a DFU operation. 

Deﬁnition */
	TUsbAudioStatus 
   TUSBAUDIO_EndDfuProc(); 
/*Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   An application calls this function to ﬁnalize a DFU operation that was indicated as completed. 
   After a call to this function the DFU state is set back to DfuProcState_Idle. Another 
   DFU operation can be initiated. 

   If this function is called while a DFU operation is still in progress, the operation is aborted. 

See Also 

   TUSBAUDIO_StartDfuDownload (page 56) 
   TUSBAUDIO_StartDfuUpload (page 58) 
   TUSBAUDIO_StartDfuRevertToFactoryImage (page 60) 
   TUSBAUDIO_GetDfuStatus (page 61) */

   /******************** DSP Plugin Functions ******************************************************/
   
/*TUSBAUDIO_GetDspProperty 

Retrieve a property from the processing plugin. 

Deﬁnition */
   TUsbAudioStatus 
   TUSBAUDIO_GetDspProperty( 
      TUsbAudioHandle deviceHandle, 
      void* propertyBuffer, 
      unsigned int propertySize 
       ); 
/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

propertyBuffer 
   Points the a caller-provided buffer that receives the data. 

propertySize 
   Speciﬁes the size, in bytes, of the caller-provided buffer. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   The set of properties and their meaning is user-deﬁned (deﬁned by the designer of the 
   processing plugin). Likewise, the format of the property data buffer is user-deﬁned. 

   The processing plugin is an optional component of the USB Audio 2.0 Class Driver package. 
   If it is not available this function will fail. Whether or not the plugin is available may be 
   queried by a call to TUSBAUDIO_GetDeviceProperties. 

See Also 

   TUSBAUDIO_SetDspProperty (page 65) */

/*TUSBAUDIO_SetDspProperty 

Set a property in the processing plugin. 

Deﬁnition */
   TUsbAudioStatus 
   TUSBAUDIO_SetDspProperty( 
      TUsbAudioHandle deviceHandle, 
      const void* propertyBuffer, 
      unsigned int propertySize 
       ); 
/*Parameters 

deviceHandle 
   Handle that identiﬁes the device instance (USB audio device). The handle needs to be created 
   by a call to TUSBAUDIO_OpenDeviceByIndex. 

propertyBuffer 
   Points the a caller-provided buffer that holds the data to be set. 

propertySize 
   Speciﬁes the size, in bytes, of the caller-provided buffer. 

Return Value 

   If the operation was successful the function returns TSTATUS_SUCCESS. If the operation 
   failed the function returns one of the TSTATUS_xxxstatus codes. 

Comments 

   The set of properties and their meaning is user-deﬁned (deﬁned by the designer of the 
   processing plugin). Likewise, the format of the property data buffer is user-deﬁned. 

   The processing plugin is an optional component of the USB Audio 2.0 Class Driver package. 
   If it is not available this function will fail. Whether or not the plugin is available may be 
   queried by a call to TUSBAUDIO_GetDeviceProperties. 

See Also 

   TUSBAUDIO_GetDspProperty (page 64) */

/*********************** Structures and Types ***************************************************/

/*TUsbAudioNotifyVolumeChange 

This structure provides additional information for a notiﬁcation event message of the 
TUSBAUDIO_NOTIFY_CATEGORY_VOLUME_CHANGEcategory. 

Deﬁnition */
typedef struct tagTUsbAudioNotifyVolumeChange{ 
   unsigned char featureUnitId; 
   unsigned char featureUnitLogicalChannel; 
   short newValue; 
 } TUsbAudioNotifyVolumeChange; 
/*Members 

featureUnitId 
   Contains the unit ID of the feature unit that has a change in volume or mute. This corresponds 
   to the featureUnitIdﬁeld of the TUsbAudioChannelProperty structure for the channel. 

featureUnitLogicalChannel 
   Contains the channel number of the channel that has a change in volume or mute. This 
   corresponds to the featureUnitLogicalChannelﬁeld of the 
   TUsbAudioChannelProperty structure for the channel. 

newValue 
   Contains the new value that was set for volume or mute of the channel. For 
   NotifyEvent_VolumeChanged messages this ﬁeld contains the volume value set for channel. 
   For NotifyEvent_MuteChanged messages this ﬁeld is set to one if the channel is muted and to 
   zero otherwise. 

Comments 

   The Volume value that is returned in newValuefor NotifyEvent_VolumeChanged messages 
   is in the range as deﬁned by the USB Audio Class speciﬁcation (-127.9961 decibels to 
   +127.9961 decibels in 1/256 decibel steps). 

See Also 

   TUsbAudioNotifyEvent (page 75) 
   TUsbAudioChannelProperty (page 73) */

/*TUsbAudioDriverInfo 

This structure provides driver version information. 

Deﬁnition */
typedef struct tagTUsbAudioDriverInfo{ 
   unsigned int apiVersionMajor; 
   unsigned int apiVersionMinor; 
   unsigned int driverVersionMajor; 
   unsigned int driverVersionMinor; 
   unsigned int driverVersionSub; 
   unsigned int flags; 
 } TUsbAudioDriverInfo; 
/*Members 

apiVersionMajor 
   Major version number of the programming interface (API) that the device driver DLL exports. 
   This corresponds to the high-order 16 bits returned by TUSBAUDIO_GetApiVersion. 

apiVersionMinor 
   Minor version number of the programming interface (API) that the device driver DLL exports. 
   This corresponds to the low-order 16 bits returned by TUSBAUDIO_GetApiVersion. 

driverVersionMajor 
   Major version number of the device driver release. 

driverVersionMinor 
   Minor version number of the device driver release. 

driverVersionSub 
   Sub version number of the device driver release. 

flags 
   Contains a set of ﬂags as a bitwise-or combination of the following constants. 

   TUSBAUDIO_DRIVER_INFOFLAG_CHECKED_BUILD 
      If this ﬂag is set then the underlying driver is a debug build which supports debugging 
      features such as trace messages and asserts. If this ﬂag is clear then the driver is a release 
      build. 
   TUSBAUDIO_DRIVER_INFOFLAG_EVAL_VERSION 
      If this ﬂag is set then the underlying driver is an evaluation version which includes some 
      restrictions. The evaluation driver periodically inserts a beep tone after an evaluation 
      interval of 60 minutes has expired. The evaluation interval starts (or restarts) when the 
      device is plugged in. 
      If this ﬂag is clear then the driver is a full version without any restrictions. 

Comments 

   An application can use the information provided by this struct to display driver version 
   information. 

See Also 

   TUSBAUDIO_GetDriverInfo (page 39) */

