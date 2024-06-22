int is_power_of_two(int number) {
  return (number != 0) && (number & (number - 1)) == 0;
}
