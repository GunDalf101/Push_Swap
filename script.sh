i=0
args=0
num=0
checker_out="OK"

while [ "$num" -lt "5500" ] && [ "$checker_out" = "OK" ]; do
    args=$(seq 0 499 | sort -R)
    num=$(./push_swap $args > pop && cat pop | wc -l);
    checker_out=$(cat pop | ./checker $args)
    echo $i "\t" $num "\t" $checker_out
    ((i=i+1))
done;

echo $args > failed.txt