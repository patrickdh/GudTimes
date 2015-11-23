if [ $# -ne 1 ]; then
	echo "Invalid parameters"
	exit 1
fi

user=$1

if [ ! -f /gudtimes/userfiles/$user/urldel.txt ]; then
        echo "Input data missing"
        exit 2
fi

roname=$(head -n 1 /gudtimes/userfiles/$user/urldel.txt)
name=$(echo $roname | sed 's/^ro_//')

cat /gudtimes/serverfiles/urlfetchlist.txt | sed "/^$user;.*$name$/d" > /gudtimes/serverfiles/urlfetchtmp.txt

mv /gudtimes/serverfiles/urlfetchtmp.txt /gudtimes/serverfiles/urlfetchlist.txt

echo "Deleted URL"
exit 0
