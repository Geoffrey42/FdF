test_name="test00"
echo "\n***Unit $test_name de check_errors()***\n"

echo "Set of correct file tests :\n"
~/fdf/tests/$test_name/$test_name ~/fdf/tests/$test_name/10-2
~/fdf/tests/$test_name/$test_name ~/fdf/tests/$test_name/10-2.fdf
~/fdf/tests/$test_name/$test_name ~/fdf/tests/$test_name/basictest.fdf
~/fdf/tests/$test_name/$test_name ~/fdf/tests/$test_name/lot_of_spaces.fdf
~/fdf/tests/$test_name/$test_name ~/fdf/tests/$test_name/pnp_flat.fdf
~/fdf/tests/$test_name/$test_name ~/fdf/tests/$test_name/pyramide.fdf
~/fdf/tests/$test_name/$test_name ~/fdf/tests/$test_name/just_text.fdf
~/fdf/tests/$test_name/$test_name ~/fdf/tests/$test_name/upper_case_a.fdf
echo "\nSet of invalid file tests :\n"
~/fdf/tests/$test_name/$test_name
~/fdf/tests/$test_name/$test_name ~/fdf/tests/$test_name/error01.fdf
~/fdf/tests/$test_name/$test_name ~/fdf/tests/$test_name/error02.fdf
~/fdf/tests/$test_name/$test_name ~/fdf/tests/$test_name/error03.fdf
~/fdf/tests/$test_name/$test_name ~/fdf/tests/$test_name/error04.fdf
~/fdf/tests/$test_name/$test_name ~/fdf/tests/$test_name/basictest.fdf ~/fdf/tests/$test_name/pnp_flat.fdf

echo "-------------------------------------------\n"
