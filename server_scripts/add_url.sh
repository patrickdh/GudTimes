if [ $# -ne 1 ]; then
	echo "Invalid parameters"
	exit 3
fi

user=$1

url=$(head -n 1 /gudtimes/userfiles/$user/urladd.txt)

name=$(basename $url)

if [ -f /gudtimes/userfiles/$user/$name ]; then
	echo "File with this name already exists"
	exit 4
fi

if [[ "$name" != *.ics ]]; then
	echo "URL doesn't appear to be a .ics file"
	exit 2
fi

curl $url --insecure --silent > /gudtimes/userfiles/$user/ro_$name

if [ $? -ne 0 ]; then
	echo "Download failed"
	rm -f /gudtimes/userfiles/$user/$name
	exit 1
fi

echo "$user;$url" >> /gudtimes/serverfiles/urlfetchlist.txt

echo "Add successful"
exit 0
