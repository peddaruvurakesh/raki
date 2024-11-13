
#!/bin/bash
read -p "Enter a day: " day
case $day in
  mon|Mon)
    echo "It's Monday."
    ;;
  tue|Tue)
    echo "It's Tuesday."
    ;;
  *)
    echo "Invalid day."
    ;;
esac

