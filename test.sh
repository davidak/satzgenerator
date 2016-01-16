#!/bin/bash

duration () {
	# Nanoseconds only work in GNU date
	local starttime=$1
	local endtime="$(date +%s%N)"
	# required visible decimal place for seconds (leading zeros if needed)
	local tests_time="$(printf "%010d" "$(( ${endtime/%N/000000000} - ${starttime/%N/000000000} ))")" # in ns
	echo "${tests_time:0:${#tests_time}-9}.${tests_time:${#tests_time}-9:3}"
}

echo "Interpreter | Laufzeit in s"
echo "--- | ---:"

# Python 2
ver="$(/usr/bin/env python --version 2>&1)"
if [[ $ver == "Python 2"* ]] ; then
	cd python
	starttime="$(date +%s%N)" # nanoseconds_since_epoch
	/usr/bin/env python satzgenerator.py 1000000 >/dev/null 2>&1
	echo $ver "|" $(duration $starttime)
	cd ..
else
	echo "Python 2 not installed"
fi

# Python 3
ver="$(/usr/bin/env python3 --version 2>&1)"
if [[ $ver == "Python 3"* ]] ; then
	cd python
	starttime="$(date +%s%N)"
	/usr/bin/env python3 satzgenerator.py 1000000 >/dev/null 2>&1
	echo $ver "|" $(duration $starttime)
	cd ..
else
	echo "Python 3 not installed"
fi

# PyPy 2
ver="$(/usr/bin/env pypy --version 2>&1)"
if [[ $ver == "Python 2"* ]] ; then
	cd python
	starttime="$(date +%s%N)"
	/usr/bin/env pypy satzgenerator.py 1000000 >/dev/null 2>&1
	echo "PyPy 2 |" $(duration $starttime)
	cd ..
else
	echo "PyPy 2 not installed"
fi

# Perl
ver="$(/usr/bin/env perl --version 2>&1 | grep "This is perl" | perl -pe 's/[^(]*\(([^)]*)\)[^(]*/$1\n/g')"
if [[ $ver == "v"* ]] ; then
	cd perl
	starttime="$(date +%s%N)"
	/usr/bin/env perl satzgenerator.pl 1000000 >/dev/null 2>&1
	echo "Perl $ver |" $(duration $starttime)
	cd ..
else
	echo "Perl not installed"
fi

# Genie
ver="$(valac --version)"
if [[ $ver == "Vala "* ]] ; then
	cd genie
	starttime="$(date +%s%N)"
	./satzgenerator 1000000 >/dev/null 2>&1
	echo "Genie ($ver) |" $(duration $starttime)
	cd ..
else
	echo "valac not installed"
fi
