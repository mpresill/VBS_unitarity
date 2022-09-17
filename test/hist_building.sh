# first argument is observable, second argument is name of Wilson coefficient

echo "Wilson coefficient: $2"

./definitivo $1 full $2_1
./definitivo $1 full $2_m1
./definitivo $1 full SM

if [ $1 == 'Zeppenfeld' ];   then
  ./split_eft_contr $1_1 $2
  ./split_eft_contr $1_2 $2
  ./split_eft_contr $1_12 $2
elif [ $1 == 'Eta' ] || [ $1 == 'PT' ];   then
  ./split_eft_contr $1_l1 $2
  ./split_eft_contr $1_l2 $2
  ./split_eft_contr $1_j1 $2
  ./split_eft_contr $1_j2 $2
else
  ./split_eft_contr $1 $2
fi

echo "Full $2 and SM histograms are ready."
