#!/bin/sh
case $SSH_ORIGINAL_COMMAND in
	"sudo "*)
		$SSH_ORIGINAL_COMMAND
		;;
	*)
		echo "Must run an approved script, Permission Denied."
		exit 1
		;;
esac
