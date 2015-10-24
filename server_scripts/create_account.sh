#!/bin/bash

if [ "$#" -ne 2 ]
then
	echo "Invalid arguments"
	exit 1
fi

if id -u $1 > /dev/null 2>&1; then
	echo "User already exists"
	exit 2
fi

useradd -M -G sshuser -U $1
echo "$1:$2" | chpasswd
mkdir /gudtimes/userfiles/$1
chown $1 /gudtimes/userfiles/$1
chgrp $1 /gudtimes/userfiles/$1
chmod 0750 /gudtimes/userfiles/$1
echo "User created"
exit 0
