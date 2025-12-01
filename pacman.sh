#!/bin/bash

echo -ne "\033[?25l"  # Cache curseur

download_file() {
    local file=$1
    local size=$2

    for i in $(seq 0 5 100); do
        local filled=$((i / 5))
        printf "\r%-25s [" "$file"
        for ((j=0; j<20; j++)); do
            [ $j -lt $filled ] && printf "#" || printf " "
        done
        printf "] %3d%% %4s" $i "$size"
        sleep 0.1
    done
    echo
}

echo "Téléchargement des paquets..."
download_file "linux-6.6.tar.xz" "140M"
download_file "gcc-13.2.tar.gz" "89M"
download_file "python-3.12.tar.xz" "25M"

echo "Terminé!"
