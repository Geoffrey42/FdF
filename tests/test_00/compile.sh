echo "Unit test de copy_map_in_a_string()\n"

rm a.out
rm copied_map.fdf
rm tests.fdf
gcc errors.c launcher.c copy_map_in_a_string.c -I ../../inc ../../../../libft/libft.a
chmod +x a.out
touch copied_map.fdf
chmod 777 copied_map.fdf
./a.out "/Users/ggane/FdF/test_maps/42.fdf"
diff copied_map.fdf /Users/ggane/FdF/test_maps/42.fdf > tests.fdf
