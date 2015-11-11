bool Optimized_isEverybitOne(int number)
{
	if (number == 0) {
		return false;
	}

	number++;

	if ((number & (number-1)) == 0) {
		return true;
	}

	return false;
}
