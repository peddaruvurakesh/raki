
if  [ -z $1 ]
then
rental="*** unknown vehicle ***"
elif [ -n $1 ]
then 
	rental=$1
fi
case $rental in
	"car") echo "for $rental rental is Rs.20 per k/m.";;
	"jeep") echo "for $rental rental is Rs.5 per k/m.";;
	"bicyle") echo "for $rental rental is Rs.10 per k/m.";;
	"van") echo "for $rental rental is Rs.50 per k/m.";;
esac


