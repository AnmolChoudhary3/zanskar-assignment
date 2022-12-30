# Shell Scripting exercise: Q1
read -p "Enter true or false: " input
i=24
if [[ "$input" == "true" ]]
then
    echo $(($RANDOM%25 * 2 + 50 )) > random_1.txt
    while [ $i -gt 0 ]
    do
        echo $(($RANDOM%25 * 2 + 50 )) >> random_1.txt
        i=$(( $i - 1 ))
        sleep 1s
    done
else
    echo $(($RANDOM%25 * 2 + 51 )) > random_1.txt
    while [ $i -gt 0 ]
    do
        echo $(($RANDOM%25 * 2 + 51 )) >> random_1.txt
        i=$(( $i - 1 ))
        sleep 1s
    done
fi