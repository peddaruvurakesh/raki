

#!/bin/bash
read -p "Enter two numbers: " a b
if [ $a -ge 0 ] && [ $b -ge 0 ]; then
  echo "Both numbers are non-negative."
fi

