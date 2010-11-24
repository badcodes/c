Summary: A Task Monitor .
Name: batchman
Version: 0.2
Release: 6
License: GPL
Group: Applications/Internet
Url: http://www.cnweblog.com/xiaoranzzz
Source: http://www.cnweblog.com/xiaoranzzz/batchman-%{version}.tar.gz 
BuildRoot: %{_tmppath}/%{name}-root

%description
A simple task monitor , Useful for downloading.

%prep
%setup -q

%build
%configure
make

%install
rm -rf $RPM_BUILD_ROOT
%makeinstall

%post

%preun

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%doc AUTHORS NEWS README COPYING ChangeLog INSTALL
%{_bindir}/batchman

%changelog
* Tue Apr 03 2007 xrLiN <xiaoranzzz@gmail.com> 0.2-6
* Fix Bug,quote arguments when do system call.
* Mon Mar 19 2007 xrLiN <xiaoranzzz@gmail.com> 0.2-5
- Change prompt message.
* Wed Jan 10 2007 xrLiN <xiaoranzzz@gmail.om> 0.2-4
- Add a "PROCESS_INPUT" macro, define it to turn on interactive mode which is by default off.
* Wed Jan 10 2007 xrLiN <xiaoranzzz@gmail.com> 0.2-3
- Handle SIGTTIN,in order to stay in background.
* Tue Jan 9 2007 xrLiN <xiaoranzzz@gmail.com> 0.2-2
- Implement a shell like interface.
* Tue Jan 9 2007 xrLiN <xiaoranzzz@gmail.com> 0.2-1
- Rewritten.
* Mon Jan 8 2007 xrLiN <xiaoranzzz@gmail.com> 0.1-3
- Reduce sleeping time to 1 second.
* Mon Jan 8 2007 xrLiN <xiaoranzzz@gmail.com> 0.1-2
- Add signal for jobs controling
* Sun Jan 7 2007 xrLin <xiaoranzzz@gmail.com> 0.1-1
- first release.

