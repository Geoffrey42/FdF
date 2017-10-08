echo "Unit test de is_not_fdf_extension()\n"

rm a.out
gcc launcher.c -I ../../inc ../../../../libft/libft.a
./a.out "42.fdf"
./a.out "error00.fdf"
./a.out "error01.fdf"
