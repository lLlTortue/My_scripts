#!/bin/bash
until read -s -n 1 -t 0.5; do
    clear
    progress
done
echo
