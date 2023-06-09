task Cimcimi()
{
	while(1)
	{
	 	wait(50);

		getColorAmbient(color2); // Gadavrtavt Ambient Mode-ze

		wait(50);

		getColorName(color2);

		wait(50);

	 	checkedColor = getColorName(color2);

	 	checkStatus = !checkStatus;
	}
}
