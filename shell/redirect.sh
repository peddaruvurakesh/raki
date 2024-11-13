find user
PASSWD_FILE=/etc/passwd
# get user name
resd -p "enter a user name :" rakesh
grep"^$rakesh" $PASSWD_FILE >	 /dev/null
status=$?
if test $status -eq 0
then
	echo "rakesh '$username' found in $PASSWD_FILE file."
else
	echo "$rakesh" not found in $PASSWD_FILE file."
fi
