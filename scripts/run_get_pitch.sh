#!/bin/bash

umaxnorm=${1:+-m ${1}} #Si fiquem algo agafo el valor, sinó agafarà valor per defecte de get_pitch.cpp
u1norm=${2:+-1 ${2}}
upot=${3:+-p ${3}}
ucclip=${4:+-c ${4}}


# Put here the program (maybe with path)
GETF0="get_pitch $umaxnorm $u1norm $upot $ucclip"

for fwav in pitch_db/train/*.wav; do
    ff0=${fwav/.wav/.f0}
    echo "$GETF0 $fwav $ff0 ----"
    $GETF0 $fwav $ff0 > /dev/null || (echo "Error in $GETF0 $fwav $ff0"; exit 1)
done

exit 0
