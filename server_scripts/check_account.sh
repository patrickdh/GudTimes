#!/bin/bash

if [ "$#" -ne 1 ]
then
	echo "Invalid arguments"
	exit 2
fi

usercharsre='^[0-9a-zA-Z_]+$'

if ! [[ $1 =~ $usercharsre ]] ; then
	echo "Invalid username"
	exit 3
fi

if id -u $1 > /dev/null 2>&1; then
	if [ ! -d "/gudtimes/userfiles/$1" ];
	then
		echo "User doesn't appear to be a calendar user account"
		exit 0
	fi
	echo "User exists"
	exit 1
else
	echo "User not found"
	exit 0
fi
