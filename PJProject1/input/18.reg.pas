PROGRAM stressRegisters;

VAR a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19 : LONGINT;
    a20, a21: BOOLEAN;
BEGIN
	a0 := 0;
	a1 := 1;
	a2 := 2;
	a3 := 3;
	a4 := 4;
	a5 := 5;
	a6 := 6;
	a7 := 7;
	a8 := 8;
	a9 := 9;
	a10 := 10;
	a11 := 11;
	a12 := 12;
	a13 := 13;
	a14 := 14;
	a15 := 15;
	a16 := 16;
	a17 := 17;
	a18 := 18;
	WRITE('a19= ');
	READ(a19);
	WRITELN(a19*a2);
	a0 := (((a1 * 8) + a2) * 8 + a3)*8 + a4;
	WRITELN(a0);
	a20 := (a16 = 16) AND (a17 = 17);
	a21 := NOT a20;
	WRITELN(a21 OR a20)
END.
