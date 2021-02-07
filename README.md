# Stryxus.Lib
This library consists of all the tools used by Stryxus in multiple projects.

## Contributing
Everyone is welcome to contribute if interested. There are no instructions but there are requirements, obviously.

#### Code Style
There is no set code style, everyone can contribute in their own prefered ways as long as it isnt complicated enough that it isnt universally understood across all contributors.

#### Requirements & Instructions
- Windows 10 1909 or later.
- Visual Studio 2019 16.8.
- C++ with Cmake & CLR.
- .NET 5 SDK.
- Windows Subsystem For Linux
- [Download curl 7.74 x64](https://curl.se/windows/) & extract the 'include' & 'lib' folders into 'Stryxus.Lib/curl/include' & 'Stryxus.Lib/curl/lib' & 'Stryxus.Lib/curl/bin/libcurl-x64.dll'.
- [Download OpenSSL 1.1.1i x64](https://curl.se/windows/) & extract the 'libssl-1_1-x64.dll' & 'libcrypto-1_1-x64.dll' files into the 'Stryxus.Lib/curl/bin' folder.
- Run ```./build.cmd``` in the View -> Terminal window just once unless the dependencies break.