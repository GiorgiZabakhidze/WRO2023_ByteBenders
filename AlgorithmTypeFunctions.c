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
	Abrunebs Or Floats Shoris Maqsimums.

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


/*
	Abrunebs Dros Timer1-is Or Gazomvas Shoris

	[
		Es Punqcia Sachiroa Radgan T1 Aris 16 Bit-iani,
		Shesabamisad Tu Or Gazomvebs Shoris Dro Daemtxva Im Moments Roca T1 Ganicdis Overflow-s (65535 Is Shemdeg 65536 Is Magivrad Xdeba 0),
		Mashin Or Gazomvas Shoris Ubralo Sxvaoba Iqneba Uaryopiti Ricxvi Da Kodis Nawili Imushavebs Xarvezit
	]

	@param [int] time_first						T1-is Pirveli Gazomvdan Migebuli Ricxvi (Miliwamebshi)
	@param [int] time_second					T1-is Meore Gazomvidan Migebuli Ricxvi (Miliwamebshi)
	@return [int] Or Gazomvas Shoris Gasuli Dro

*/
int timer_count(int time_first, int time_second)
{
	// Tu Pirveli gazomili Metia Meoreze, Anu Meorem 16 Bit-is Overflow Ganicada Da Unda Davumatot 65536(2^16) Da Davabrunebt Mat Sxvaobas
	if(time_first > time_second)
		return (time_second + 65536 - time_first);

	// Sxva Shemtxvevashi Ubralod Vabrunebt Magat Sxvaobas
	return time_second - time_first;
}


/*
	Ayovnebs Konkretul Task-s Ragac Droit ( Ara Mtlian Programas )

	@param [int] time 					Dro, Ramdeni Xnitac Gvinda Task-is Sheyovneba (Milisamebshi)
*/
void wait(int time)
{
	int t = 0; // Gasuli Dro

	int t0 = time1(T1); // Sawyisi Dro

	while(t < time) // Imushavebs Manam Sanam Gasuli Dro Naklebia Sasurvel Droze
	{
		t = timer_count(t0, time1(T1)); // Anaxlebs Axlandel Dros
	}
}
