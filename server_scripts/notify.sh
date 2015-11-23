if [ $# -ne 1 ]; then
	echo "Invalid parameters"
	exit 1
fi

user=$1

input="/gudtimes/userfiles/$user/outboundNotices.txt"

while IFS='' read -r line; do
	sendTo=$(echo $line | awk -F';' '{print $1}')
	notice=$(echo $line | sed "s/^$sendTo;//")
	echo "$notice" >> /gudtimes/userfiles/$sendTo/notify.txt
done <"$input"
