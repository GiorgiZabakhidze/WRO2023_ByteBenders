/*
	Igebs Integeris Nishans.

	@param [int] a     Ricxvi Romlis Nishanic Gvainteresebs.
	@return [int] 0, -1 an 1. Integeris Nishani.
*/
int sign(int a)
{
	if(a == 0) // Tu Ricxvi Nulia, Vabrunebt 0-s.
		return 0;

	return (a / abs(a)); // Vabrunebt Nishans.
}


/*
	Igebs Floatis Nishans.

	@param [float] a     Ricxvi Romlis Nishanic Gvainteresebs.
	@return [float] 0, -1 an 1. Floatis Nishani.
*/
float sign(float a)
{
	if(a == 0) // Tu Ricxvi Nulia, Vabrunebt 0-s.
		return 0;

	return (a / abs(a)); // Vabrunebt Nishans.
}


/*
	Igebs Or Integers Shoris Maqsimums.

	@param [int] a		Pirveli Ricxvi.
	@param [int] b    Meore Ricxvi.
	@return [int] Or Integers Shoris Maqsimumi.
*/
int max(int a, int b)
{
	// Tu 'a' Metia An Tolia 'b'-ze, Vabrunebt 'a'-s.
	if(a >= b)
		return a;

	// Sxva Variantshi Vabrunebt 'b'-s.
	return b;
}


/*
	Igebs Or Floats Shoris Maqsimums.

	@param [float] a		Pirveli Ricxvi.
	@param [float] b    Meore Ricxvi.
	@return [float] Or Floats Shoris Maqsimumi.
*/
float max(float a, float b)
{
	// Tu 'a' Metia An Tolia 'b'-ze, Vabrunebt 'a'-s.
	if(a >= b)
		return a;

	// Sxva Variantshi Vabrunebt 'b'-s.
	return b;
}

float timer_count(float time_first, float time_second)
{
	// Tu Pirveli gazomili Metia Meoreze, Anu Meorem 16 Bit-is Overflow Ganicada Da Unda Davumatot 65536(2^16) Da Davabrunebt Mat Sxvaobas
	if(time_first > time_second)
		return (time_second + 65536 - time_first);

	// Sxva Shemtxvevashi Ubralod Vabrunebt Magat Sxvaobas
	return time_second - time_first;
}
