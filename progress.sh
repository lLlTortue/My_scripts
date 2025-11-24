#!/bin/bash
until read -s -n 1 -t 1; do
    clear
    progress
done
echo
