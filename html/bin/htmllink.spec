Summary: HTML link parser.
Name: htmllink
Version: 0.1
Release: 1
License: GPL
Group: Applications/Internet
Url: http://www.cnweblog.com/xiaoranzzz
Source: http://www.cnweblog.com/xiaoranzzz/htmllink-%{version}.tar.gz 
BuildRoot: %{_tmppath}/%{name}-root

%description
A HTML links parser.

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
%{_bindir}/htmllink

%changelog
* Tue Mar 27 2007 xrLiN <xiaoranzzz@gmail.com> 0.1-1
- First released.

