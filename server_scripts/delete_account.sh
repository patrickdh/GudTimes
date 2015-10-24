#!/bin/bash

if [ "$#" -ne 2 ]
then
	echo "Invalid arguments"
	exit 1
fi

id -u $1 > /dev/null 2>&1

if [ "$?" -ne 0 ]
then
	echo "User doesn't exist"
	exit 2
fi

if [ ! -d "/gudtimes/userfiles/$1" ];
then
	echo "User doesn't appear to be a calendar user account"
	exit 3
fi

salt=$(getent shadow $1 | cut -d$ -f3)
epassword=$(getent shadow $1 | cut -d: -f2)
match=$(python -c 'import crypt; print crypt.crypt("'"$2"'", "$6$'${salt}'")')

if [ "$match" != "$epassword" ]
then
	echo "Invalid password"
	exit 4
else
	echo "Deleting account"
	if userdel $1; then
		rm -rf /gudtimes/userfiles/$1
		echo "User deleted"
		exit 0
	else
		echo "Unable to delete user, ensure they aren't logged into ssh"
		exit 5
	fi
fi
