for((i = 0; i<=12; ++i)); do
    echo Test Case $i
    # ./avl < in$i.txt
    # ./rbt < in$i.txt
    # ./treap < in$i.txt
    # ./map < in$i.txt
    ./splay < in$i.txt
    # diff -w out1 out2 && echo "Accepted" || break
done