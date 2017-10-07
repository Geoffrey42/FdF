echo "Unit test de is_not_fdf_extension()\n"

rm a.out
gcc launcher.c -I ../../inc ../../../../libft/libft.a
./a.out "/Users/ggane/FdF/test_maps/42.fdf"
./a.out "/Users/ggane/FdF/test_maps/42.txt"
./a.out "/Users/ggane/FdF/test_maps/42.fdf.txt"
./a.out "/Users/ggane/FdF/test_maps/42.fdff"
