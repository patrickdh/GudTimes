#!/bin/bash

if [ "$#" -ne 2 ]
then
	echo "Invalid arguments"
	exit 1
fi

usercharsre='^[0-9a-zA-Z_]+$'

if ! [[ $1 =~ $usercharsre ]] ; then
	echo "Invalid username"
	exit 3
fi

if id -u $1 > /dev/null 2>&1; then
	echo "User already exists"
	exit 2
fi

useradd -M -G sftponly -U $1
echo "$1:$2" | chpasswd
mkdir /gudtimes/userfiles/$1
chown $1 /gudtimes/userfiles/$1
chgrp $1 /gudtimes/userfiles/$1
chmod 0751 /gudtimes/userfiles/$1
touch /gudtimes/userfiles/$1/notify.txt
chown $1 /gudtimes/userfiles/$1/notify.txt
chgrp $1 /gudtimes/userfiles/$1/notify.txt
chmod 662 /gudtimes/userfiles/$1/notify.txt
echo "User created"
exit 0
