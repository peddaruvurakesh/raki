#Write a script that receives four parameters, and outputs them in reverse order.
#!/bin/bash

if [ "$#" -ne 4 ]; then
 echo "Usage: $0 <param1> < param2> <param3> <param4>"
 exit 1 
fi
#print in reverse order
reverse="$4$3$2$1"
echo reverse
echo "$reverse" | rev
