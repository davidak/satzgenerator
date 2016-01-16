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

# PyPy
ver="$(/usr/bin/env pypy --version 2>&1)"
if [[ $ver == "Python"* ]] ; then
	cd python
	ver="$(/usr/bin/env pypy --version 2>&1 | grep PyPy | cut -f2 -d' ')"
	starttime="$(date +%s%N)"
	/usr/bin/env pypy satzgenerator.py 1000000 >/dev/null 2>&1
	echo "PyPy $ver |" $(duration $starttime)
	cd ..
else
	echo "PyPy not installed"
fi

# Ruby
ver="$(/usr/bin/env ruby --version 2>&1)"
if [[ $ver == "ruby "* ]] ; then
	cd ruby
	ver="$(/usr/bin/env ruby --version 2>&1 | cut -f2 -d' ')"
	starttime="$(date +%s%N)"
	/usr/bin/env ruby satzgenerator.rb 1000000 >/dev/null 2>&1
	echo "Ruby $ver |" $(duration $starttime)
	cd ..
else
	echo "Ruby not installed"
fi

# JRuby
ver="$(/usr/bin/env jruby -v 2>&1 | cut -f1-3 -d' ')"
if [[ $ver == "jruby"* ]] ; then
	cd ruby
	starttime="$(date +%s%N)"
	/usr/bin/env jruby satzgenerator.rb 1000000 >/dev/null 2>&1
	echo "$ver |" $(duration $starttime)
	/usr/bin/env jruby satzgenerator.rb 10
	cd ..
else
	echo "JRuby not installed"
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
ver="$(valac --version 2>&1)"
if [[ $ver == "Vala "* ]] ; then
	cd genie
	starttime="$(date +%s%N)"
	./satzgenerator 1000000 >/dev/null 2>&1
	echo "Genie ($ver) |" $(duration $starttime)
	cd ..
else
	echo "valac not installed"
fi

# Java
ver="$(java -version 2>&1)"
if [[ $ver == "java "* ]] ; then
	cd java
	ver="$(java -version 2>&1 | grep version | cut -d '"' -f2)"
	starttime="$(date +%s%N)"
	java Satzgenerator 1000000 >/dev/null 2>&1
	echo "Java $ver |" $(duration $starttime)
	cd ..
else
	echo "Java not installed"
fi

# Crystal
ver="$(crystal --version 2>&1 | cut -f1 -d[ | cut -f1 -d'(')"
if [[ $ver == "Crystal "* ]] ; then
	cd crystal
	starttime="$(date +%s%N)"
	./Satzgenerator 1000000 >/dev/null 2>&1
	echo "$ver|" $(duration $starttime)
	cd ..
else
	echo "crystal not installed"
fi
