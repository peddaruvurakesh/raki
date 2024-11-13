read -p "Enter a number: " n
if [ $n -ge 0 ]; then
  if [ $n -eq 0 ]; then
    echo "$n is zero."
  else
    echo "$n is positive."
  fi
else
  echo "$n is negative."
fi

