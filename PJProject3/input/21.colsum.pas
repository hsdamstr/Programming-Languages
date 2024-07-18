PROGRAM ColumnSum;
VAR  a : ARRAY[1..10, 1..20] OF LONGINT;
     i, j, s : LONGINT; 

BEGIN 
  i := 1;
  WHILE (i <= 10) DO
  BEGIN
     j := 1;
     WHILE (j <= 20) DO 
     BEGIN 
       a[i, j] := i*20+j;
       WRITE(a[i, j]);
       WRITE('  ');
       j := j+1
     END;
     WRITELN('*');
     i := i+1
   END;

   WRITELN('column sum:');
   j := 1;
   WHILE (j <= 20) DO
   BEGIN
     i := 1;
     s := 0;
     WHILE (i <= 10) DO
     BEGIN
       s := s + a[i, j];
       i := i+1 
     END;
     WRITE(s);
     WRITE('  ');
     j := j+1
   END;
   WRITELN('*')
END.
