# Only argument is the observable

echo "Producing histograms for $1"
echo "   "

./hist_building.sh $1 cW
./hist_building.sh $1 cHW
./hist_building.sh $1 cHWB
./hist_building.sh $1 cHDD
./hist_building.sh $1 cHbox
./hist_building.sh $1 cHq1
./hist_building.sh $1 cHq3
./hist_building.sh $1 cqq1
./hist_building.sh $1 cqq11
./hist_building.sh $1 cqq3
./hist_building.sh $1 cqq31
./hist_building.sh $1 cHl1
./hist_building.sh $1 cHl3
./hist_building.sh $1 cll
./hist_building.sh $1 cll1

echo "  Do you want to proceed with merging? y/n"
echo "( Note: proceed only if all EFT contributions have been considered )"
read answ

if [ $answ == 'y' ]; then
  if [ $1 == 'Zeppenfeld' ];   then
    ./merge $1_1
    ./merge $1_2
    ./merge $1_12
  elif [ $1 == 'Eta' ] || [ $1 == 'PT' ];   then
    ./merge $1_l1
    ./merge $1_l2
    ./merge $1_j1
    ./merge $1_j2
  else
    ./merge $1  
  fi
else 
  echo "Ok, see you!"
fi

echo "   "
echo "Good job, Lord Miao is proud of you."
echo "                   _____________  "  
echo "   /\\___/\\        /             \\  "
echo "  ( >°.°< )      <  Now feed me |   "
echo "  /***O***\\       \\_____________/  "
echo "  | \\   / |                        "
echo "  \\ U   U /~~*                     "

