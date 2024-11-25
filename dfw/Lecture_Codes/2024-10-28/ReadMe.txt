Today, we performed volatility3 on WannaCry virus raw file !!
Simply we ran volatility3 plugins as listed in Asg10 in Terminal !!

┌──(ashutosh㉿kali)-[~/Desktop/GitHub/volatility3]
└─$ python3 vol.py -f wcry.raw windows.psxview | grep 740
                                                                                                      
┌──(ashutosh㉿kali)-[~/Desktop/GitHub/volatility3]
└─$ python3 vol.py -f wcry.raw windows.cmdline | grep 740
740     @WanaDecryptor@ @WanaDecryptor@.exe
                                                                                                      
┌──(ashutosh㉿kali)-[~/Desktop/GitHub/volatility3]
└─$ python3 vol.py -f wcry.raw windows.envars | grep 740
740     @WanaDecryptor@ 0x20048 ALLUSERSPROFILE C:\Documents and Settings\All Users
740     @WanaDecryptor@ 0x20048 APPDATA C:\Documents and Settings\donny\Application Data
740     @WanaDecryptor@ 0x20048 CLIENTNAME      Console
740     @WanaDecryptor@ 0x20048 CommonProgramFiles      C:\Program Files\Common Files
740     @WanaDecryptor@ 0x20048 COMPUTERNAME    INFOSECL-5A7C18
740     @WanaDecryptor@ 0x20048 ComSpec C:\WINDOWS\system32\cmd.exe
740     @WanaDecryptor@ 0x20048 FP_NO_HOST_CHECK        NO
740     @WanaDecryptor@ 0x20048 HOMEDRIVE       C:
740     @WanaDecryptor@ 0x20048 HOMEPATH        \Documents and Settings\donny
740     @WanaDecryptor@ 0x20048 LOGONSERVER     \\INFOSECL-5A7C18
740     @WanaDecryptor@ 0x20048 NUMBER_OF_PROCESSORS    1
740     @WanaDecryptor@ 0x20048 OS      Windows_NT
740     @WanaDecryptor@ 0x20048 Path    C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem
740     @WanaDecryptor@ 0x20048 PATHEXT .COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH
740     @WanaDecryptor@ 0x20048 PROCESSOR_ARCHITECTURE  x86
740     @WanaDecryptor@ 0x20048 PROCESSOR_IDENTIFIER    x86 Family 6 Model 78 Stepping 3, GenuineIntel
740     @WanaDecryptor@ 0x20048 PROCESSOR_LEVEL 6
740     @WanaDecryptor@ 0x20048 PROCESSOR_REVISION      4e03
740     @WanaDecryptor@ 0x20048 ProgramFiles    C:\Program Files
740     @WanaDecryptor@ 0x20048 SESSIONNAME     Console
740     @WanaDecryptor@ 0x20048 SystemDrive     C:
740     @WanaDecryptor@ 0x20048 SystemRoot      C:\WINDOWS
740     @WanaDecryptor@ 0x20048 TEMP    C:\DOCUME~1\donny\LOCALS~1\Temp
740     @WanaDecryptor@ 0x20048 TMP     C:\DOCUME~1\donny\LOCALS~1\Temp
740     @WanaDecryptor@ 0x20048 USERDOMAIN      INFOSECL-5A7C18
740     @WanaDecryptor@ 0x20048 USERNAME        donny
                                                                                                      
┌──(ashutosh㉿kali)-[~/Desktop/GitHub/volatility3]
└─$ python3 vol.py -f wcry.raw windows.getsids | grep 740
740     @WanaDecryptor@ S-1-5-21-602162358-764733703-1957994488-1003    donny
740     @WanaDecryptor@ S-1-5-21-602162358-764733703-1957994488-513     Domain Users
740     @WanaDecryptor@ S-1-1-0 Everyone
740     @WanaDecryptor@ S-1-5-32-544    Administrators
740     @WanaDecryptor@ S-1-5-32-545    Users
740     @WanaDecryptor@ S-1-5-4 Interactive
740     @WanaDecryptor@ S-1-5-11        Authenticated Users
740     @WanaDecryptor@ S-1-5-5-0-39677 Logon Session
740     @WanaDecryptor@ S-1-2-0 Local (Users with the ability to log in locally)
                                                                                                      
┌──(ashutosh㉿kali)-[~/Desktop/GitHub/volatility3]
└─$ python3 vol.py -f wcry.raw windows.privileges | grep 740
740     @WanaDecryptor@ 23      SeChangeNotifyPrivilege Present,Enabled,Default Receive notifications of changes to files or directories
740     @WanaDecryptor@ 8       SeSecurityPrivilege     Present Manage auditing and security log
740     @WanaDecryptor@ 17      SeBackupPrivilege       Present Backup files and directories
740     @WanaDecryptor@ 18      SeRestorePrivilege      Present Restore files and directories
740     @WanaDecryptor@ 12      SeSystemtimePrivilege   Present Change the system time
740     @WanaDecryptor@ 19      SeShutdownPrivilege     Present Shut down the system
740     @WanaDecryptor@ 24      SeRemoteShutdownPrivilege       Present Force shutdown from a remote system
740     @WanaDecryptor@ 9       SeTakeOwnershipPrivilege        Present Take ownership of files/objects
740     @WanaDecryptor@ 20      SeDebugPrivilege        Present Debug programs
740     @WanaDecryptor@ 22      SeSystemEnvironmentPrivilege    Present Edit firmware environment values
740     @WanaDecryptor@ 11      SeSystemProfilePrivilege        Present Profile system performance
740     @WanaDecryptor@ 13      SeProfileSingleProcessPrivilege Present Profile a single process
740     @WanaDecryptor@ 14      SeIncreaseBasePriorityPrivilege Present Increase scheduling priority
740     @WanaDecryptor@ 10      SeLoadDriverPrivilege   Present,Enabled Load and unload device drivers
740     @WanaDecryptor@ 15      SeCreatePagefilePrivilege       Present Create a pagefile
740     @WanaDecryptor@ 5       SeIncreaseQuotaPrivilege        Present Increase quotas
740     @WanaDecryptor@ 25      SeUndockPrivilege       Present,Enabled Remove computer from docking station
740     @WanaDecryptor@ 28      SeManageVolumePrivilege Present Manage the files on a volume
740     @WanaDecryptor@ 29      SeImpersonatePrivilege  Present,Enabled,Default Impersonate a client after authentication
740     @WanaDecryptor@ 30      SeCreateGlobalPrivilege Present,Enabled,Default Create global objects
                                                                                                      
┌──(ashutosh㉿kali)-[~/Desktop/GitHub/volatility3]
└─$ python3 vol.py -f wcry.raw windows.malfind | grep 740
WARNING  volatility3.plugins.windows.malfind: [proc_id 620] Found suspicious DIRTY + PAGE_EXECUTE_READ page at 0x595000
WARNING  volatility3.plugins.windows.malfind: [proc_id 620] Found suspicious DIRTY + PAGE_EXECUTE_READ page at 0x7f6f4000
