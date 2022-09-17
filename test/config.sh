mkdir build
cd build
cmake ../
make
make install
cd ..

chmod +x combine_histos.sh
chmod +x hist_building.sh

mkdir data
mkdir histos4datacards
mkdir histos
mkdir prova_histo
cd histos
mkdir deltaEtajj
mkdir deltaPhijj
mkdir MET
mkdir M1T
mkdir Mo1
mkdir mll
mkdir mjj
mkdir Zeppenfeld_1
mkdir Zeppenfeld_2
mkdir Zeppenfeld_12
mkdir Eta_l1
mkdir Eta_l2
mkdir Eta_j1
mkdir Eta_j2
mkdir PT_l1
mkdir PT_l2
mkdir PT_j1
mkdir PT_j2
cd ..
