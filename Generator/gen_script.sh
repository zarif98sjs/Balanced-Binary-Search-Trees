for((i = 0,n=100; i<3; ++i,n*=10)); do
    echo Test Case $i
    ./Gen $i $n > in$i.txt
    # ./brute < int > out2
    # diff -w out1 out2 && echo "Accepted" || break
done