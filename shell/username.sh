#!/bin/bash
read -p "Enter a username: " username
grep "^$username:" /etc/passwd > /dev/null
if [ $? -eq 0 ]; then
    echo "User '$username' exists."
else
    echo "User '$username' does not exist."
fi

