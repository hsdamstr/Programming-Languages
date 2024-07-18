PROGRAM temperatureArrays;
 VAR  fahrenheit : ARRAY [-10..100] OF LONGINT;
      i: LONGINT;
      celsius: ARRAY [-10..100] OF LONGINT;
      frozen: ARRAY [-10..100] OF BOOLEAN;
      
BEGIN
	i := -10;
	WHILE (i <= 100) DO BEGIN
	  fahrenheit[i] := i;
	  i := i+1
	END;

  	i := 100;
	WHILE (i >= -10) DO BEGIN
	  celsius[i] := (fahrenheit[i]-32)*10 DIV 18;
	  frozen[i] := celsius[i]<0;
	  i := i-1
	END;

        i := -10;
	WHILE (i <= 100) DO BEGIN
	   WRITE(fahrenheit[i]:10);
	   WRITE(celsius[i]:10);
	   WRITELN(frozen[i]:10);
	   i := i+1
       END
END.
