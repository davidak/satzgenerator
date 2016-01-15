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
echo "--- | ---"

# Python 2
ver="$(/usr/bin/env python --version 2>&1)"
if [[ $ver == "Python 2"* ]] ; then
	starttime="$(date +%s%N)" # nanoseconds_since_epoch
	sleep 1.5s
	echo $ver "|" $(duration $starttime)
else
	echo "Python 2 not installed"
fi
