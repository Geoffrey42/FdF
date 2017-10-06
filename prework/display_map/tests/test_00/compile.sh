echo "Unit test de copy_map_in_a_string()\n"

gcc errors.c launcher.c copy_map_in_a_string.c -I ../../inc ../../../../libft/libft.a
./a.out 42.fdf
diff copied_map.txt 42.fdf 2> diff_errors.txt
if [ -s diff_errors.txt]
    cat diff_errors.txt
fi
