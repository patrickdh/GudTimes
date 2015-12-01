while read -r line; do
	user=$(echo "$line" | awk -F ";" '{print $1}')
	url=$(echo "$line" | awk -F ";" '{print $2}')
	name=$(basename $url)

	curl $url --insecure --silent > /gudtimes/userfiles/$user/ro_$name.tmp

	if [ $? -ne 0 ]; then
		echo "Download failed for $user fetching $name from $url"
		rm -f /gudtimes/userfiles/$user/ro_$name.tmp
	else
		mv /gudtimes/userfiles/$user/ro_$name.tmp /gudtimes/userfiles/$user/ro_$name
	fi
done < /gudtimes/serverfiles/urlfetchlist.txt
