#define MyAppName "VU Studentu Programa"
#define MyAppVersion "3.0"
#define MyAppPublisher "VU - Jakub Rogoza"
#define MyAppExeName "StudentaiMyVector.exe"

[Setup]
AppId={{8F9F6A9D-54C7-41F6-8D20-2A84B6D52C10}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={autopf}\VU\Vardenis-Pavardenis
DefaultGroupName=VU\Vardenis-Pavardenis
OutputDir=.
OutputBaseFilename=Setup
Compression=lzma
SolidCompression=yes
WizardStyle=modern
PrivilegesRequired=admin
DisableProgramGroupPage=no

[Dirs]
Name: "{app}\Data"; Permissions: users-modify

[Files]
Source: "StudentaiMyVector.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "README.md"; DestDir: "{app}"; Flags: ignoreversion
Source: "Data\kursiokai.txt"; DestDir: "{app}\Data"; Flags: ignoreversion
Source: "Data\studentai10000.txt"; DestDir: "{app}\Data"; Flags: ignoreversion
Source: "Data\studentai100000.txt"; DestDir: "{app}\Data"; Flags: ignoreversion
Source: "Data\studentai1000000.txt"; DestDir: "{app}\Data"; Flags: ignoreversion

[Registry]
Root: HKLM; Subkey: "SOFTWARE\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers"; \
    ValueType: string; ValueName: "{app}\{#MyAppExeName}"; ValueData: "RUNASADMIN"; Flags: uninsdeletevalue

[Icons]
Name: "{group}\VU Studentu Programa"; Filename: "{app}\{#MyAppExeName}"; WorkingDir: "{app}"
Name: "{commondesktop}\VU Studentu Programa"; Filename: "{app}\{#MyAppExeName}"; WorkingDir: "{app}"
Name: "{group}\Uninstall VU Studentu Programa"; Filename: "{uninstallexe}"