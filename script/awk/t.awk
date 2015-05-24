{
    if (NR % 5 == 0) {
        ORS="\n";
        print $0;
    } else {
        ORS=",";
        print $0;
    }
}
