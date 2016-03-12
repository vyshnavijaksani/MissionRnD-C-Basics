
		
int strLength(char *);
int isOlder(char *dob1, char *dob2) {
	int day1=0;
	int month1=0;
	int year1=0;
	int day2=0;
	int month2=0;
	int year2=0, res = 0, temp = 0, len1 = 0, len2 = 0, temp1 = 0, temp2 = 0;
	
	day1 = ((dob1[0] - '0') * 10) + ((dob1[1] - '0') * 1);
	month1 = ((dob1[3] - '0') * 10) + ((dob1[4] - '0') * 1);
	year1 = ((dob1[6] - '0') * 1000) + ((dob1[7] - '0') * 100) + ((dob1[8] - '0') * 10) + ((dob1[9] - '0') * 1);
	day2 = ((dob2[0] - '0') * 10) + ((dob2[1] - '0') * 1);
	month2 = ((dob2[3] - '0') * 10) + ((dob2[4] - '0') * 1);
	year2 = ((dob2[6] - '0') * 1000) + ((dob2[7] - '0') * 100) + ((dob2[8] - '0') * 10) + ((dob2[9] - '0') * 1);
	len1 = strLength(dob1);
	len2 = strLength(dob2);
	//check for invalid length
	if (len1 != 10 || len2 != 10)
		return -1;

	//check for invalid month
	if (month1 > 12 || month2 > 12)
		return -1;
	//check for leap year
	if (year1 % 4 != 0 && month1 == 2 && day1 > 28)
	{

		return -1;
	}
	if (year2 % 400 != 0 && month2 == 2 && day2 > 28)
	{

		return -1;
	}
	//check for older or younger
	if (year1 < year2)
	{
		return 1;
	}
	else if (year1 > year2)
	{
		return 2;
	}
	else
	{
		if (month1 < month2)
			return 1;
		else if (month1 > month2)
			return 2;
		else
		{
			if (day1 < day2)
				return 1;
			else if (day1 > day2)
				return 2;
			else return 0;
		}
	}
	
}
int strLength(char *str)
{
	int i = 0, count = 0;
	while (str[i] != '\0')
	{
		i++;
		count++;
	}
	return count;
}
