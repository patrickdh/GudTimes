if [ $# -ne 2 ]; then
	echo "Invalid arguments"
	exit 1
fi

searcher=$1
timelength=$2

/gudtimes/scripts/check_account.sh $searcher > /dev/null

if [ $? -ne 1 ]; then
	echo "Invalid search user"
	exit 2
fi

rm -f /gudtimes/userfiles/$searcher/combined.ics
rm -f /gudtimes/userfiles/$searcher/found_times.txt
rm -f /gudtimes/userfiles/$searcher/find_errors.txt

for user in $(cat /gudtimes/userfiles/$searcher/userslist.txt); do
	/gudtimes/scripts/check_account.sh $user > /dev/null
	if [ $? -eq 1 ]; then
		for file in $(find /gudtimes/userfiles/$user/ -type f \( -iname "*.ics" \)); do
			cat $file >> /gudtimes/userfiles/$searcher/combined.ics
		done
	else
		echo "$user is not a valid user, skipped" >> /gudtimes/userfiles/$searcher/find_errors.txt
	fi
done

# Call program to compute available times

rm /gudtimes/userfiles/$searcher/combined.ics
