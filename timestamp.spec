Summary: A pipe utility that timestamps lines.
Name: timestamp
Version: 1.0
Release: 1
Copyright: BSD
Vendor: Erik Greenwald
Url: http://math.smsu.edu/~erik/software.php?id=95
Group: Applications/Text
Source0: http://math.smsu.edu/~erik/files/timestamp-1.0.tar.gz
Buildroot: /var/tmp/ts

%description
Read stdin, timestamp lines, output to stdout. The timestamp format
can be set in the same fashion as 'date' output, and can be set
for timezone using the TZ variable, or UTC using -u. The timestamp
for the line is set when the first character of that line is recieved.

%prep
%setup -q
%build
CFLAGS="$RPM_OPT_FLAGS" ./configure --prefix=/usr

make

%install
rm -rf $RPM_BUILD_ROOT
make DESTDIR=$RPM_BUILD_ROOT install

%clean
rm -rf $RPM_BUILD_ROOT

%files
/usr/*

%changelog

