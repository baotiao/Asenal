BEGIN {
    printf "The Awk is begin\n============\n"
} {
    printf "%d: %s\n",FNR,$0
}
