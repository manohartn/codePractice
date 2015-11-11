bool isEverybitOne(int number)
{
	if (number == 0) {
		return false;
	}
	while (number != 0) {
		if ((0x01 & number) == 0) {
			return false;
		}
		number = number >> 1;
	}

	return true;
}
