program Sort_and_Search;
uses Utils;
type
 DateTime=record
 Day, Month, Year, Hour, Minute, Second, Milliseconds: integer;
end;

const
 max_dimension=10000;

var
 menu_select,dimension,shifts:integer;
 i,j,a,b,d,e:integer;
 c:real;
 massiv, massiv_memory:array [0..max_dimension] of real;
 start, finish: DateTime;
 f,f2,f_exit:boolean;


 //EXIT FROM PROGRAM:
 procedure exit_from_program;
 begin
  writeln('Program has been stopped');
  f_exit:=true;
 end;


 //INPUT THE DIMENSION OF ARRAY:
 //Arbitrary input
 procedure arbitrary_input;
 begin
  writeln('Specify the interval:');
  writeln('Input the lowest number');
  write('-> ');readln(a);
  writeln('Input the uppest number');
  write('-> ');readln(b);
  if b<a then
  begin
   writeln('The lowest number is bigger than the uppest number.');
   writeln('The numbers have been changed places.');
   i:=a; a:=b; b:=i;
  end;
  for i:=1 to dimension do
  begin
   massiv[i]:=random(b-a+1)+a;
  end;
 f:=true;
 end;

 //Algebraic progression
 procedure algebraic_progression;
 begin
  writeln('Progression of type A+B*(x-1)');
  writeln('Input coefficient "A" (The first member of progression)');
  write('-> ');readln(a);
  writeln('Input coefficient "B" (The factor of number "x")');
  write('-> ');readln(b);
  for i:=1 to dimension do massiv[i]:=a+b*(i-1);
  f:=true;
 end;

 //Geometric progression
 procedure geometric_progression;
 begin
  writeln('Progression of type A*B^(x-1)');
  writeln('Input coefficient "A" (The first member of progression)');
  write('-> ');readln(a);
  writeln('Input coefficient "B" (The number, which raise to the power "x")');
  write('-> ');readln(b);
  for i:=1 to dimension do massiv[i]:=a;
  for i:=1 to dimension do
  begin
   for j:=1 to i-1 do massiv[i]:=massiv[i]*b;
  end;
  f:=true;
 end;

 //Manual input
 procedure manual_input;
 begin
  for i:=1 to dimension do
  begin
   writeln('Input the ',i,' member of array');
   write('-> ');readln(massiv[i]);
  end;
  f:=true;
 end;

 //Input the dimension of array
 procedure input_the_dimension_of_array;
 begin
  f:=false;
  while f=false do
  begin
   f2:=true;
   while f2=true do
   begin
    f2:=false;
    writeln('Input the dimension of array');
    write('-> ');readln(dimension);
    if (dimension<1) or (dimension>max_dimension) then
    begin
     writeln('The dimension must be on the interval [1..',max_dimension,']');
     f2:=true;
    end;
   end;
   writeln('Select the type of input of array:');
   writeln('1. Arbitrary input');
   writeln('2. Algebraic progression');
   writeln('3. Geometric progression');
   writeln('4. Manual input');
   writeln('0. Exit from program');
   write('-> ');readln(menu_select);
   case menu_select of
    1: arbitrary_input;
    2: algebraic_progression;
    3: geometric_progression;
    4: manual_input;
    0: exit_from_program;
   end;
  end;
  writeln('The array has been created');
  writeln('Press ENTER');readln();
 end;


 //SELECT THE TYPE OF SORT:
 //Selection
 procedure sortirovka_selection;
 begin
  shifts:=0;
  start := CurrentDateTime;
  for i:=1 to dimension do
  begin
   for j:=i+1 to dimension do
   begin
    if massiv[i]>massiv[j] then
    begin
     c:=massiv[i];
     massiv[i]:=massiv[j];
     massiv[j]:=c;
     shifts:=shifts+1;
    end;
   end;
  end;
  finish := CurrentDateTime;
 end;

 //Bubble
 procedure sortirovka_bubble;
 begin
  shifts:=0;
  start := CurrentDateTime;
  f:=false;
  while f=false and (i<=dimension) do
  begin
   f:=true;
   for j:=1 to (dimension-1) do
    if massiv[j]>massiv[j+1] then
    begin
     c:=massiv[j];
     massiv[j]:=massiv[j+1];
     massiv[j+1]:=c;
     f:=false;
     shifts:=shifts+1;
    end;
  end;
  finish := CurrentDateTime;
 end;

 //Sort of Shell
 procedure sortirovka_shell;
 begin
  shifts:=0;
  start := CurrentDateTime;
  a:=dimension div 3;
  f:=false;
  while (f=false) or (a>1) do
  begin
   f:=true;
   for i:=1 to dimension-a do
   begin
    if massiv[i]>massiv[i+a] then
    begin
     c:=massiv[i];
     massiv[i]:=massiv[i+a];
     massiv[i+a]:=c;
     f:=false;
     shifts:=shifts+1;
    end;
   end;
   a:=a div 3;
   if a=0 then a:=1;
  end;
  finish := CurrentDateTime;
 end;

 //Insert
 procedure sortirovka_insert;
 begin
  shifts:=0;
  start := CurrentDateTime;
  for i := 2 to dimension do
  begin
   c := massiv[i];
   j := i-1;
   while (c<massiv[j]) and (j>0) do
   begin
    massiv[j+1] := massiv[j];
    shifts:=shifts+1;
    j := j-1;
   end;
   massiv[j+1] := c;
  end;
  finish := CurrentDateTime;
 end;

 //SELECT THE OPERATION OVER ARRAY:
 //Sort the array
 procedure sort_the_array;
 begin
  writeln('Select the type of sort the array:');
  writeln('1. Selection');
  writeln('2. Bubble');
  writeln('3. Sort of Shell');
  writeln('4. Insert');
  writeln('0. Exit from program');
  write('-> ');readln(menu_select);
  writeln('Waiting...');
  case menu_select of
   1: sortirovka_selection;
   2: sortirovka_bubble;
   3: sortirovka_shell;
   4: sortirovka_insert;
   0: exit_from_program;
  end;
  writeln('Sort has been completed');
  a:= (finish.Hour-start.Hour)*3600000 + (finish.Minute-start.Minute)*60000 + (finish.Second-start.Second)*1000 + (finish.Milliseconds-start.Milliseconds);
  finish.Hour:=a div 3600000; a:=a-finish.Hour*3600000;
  finish.Minute:=a div 60000; a:=a-finish.Minute*60000;
  finish.Second:=a div 1000; a:=a-finish.Second*1000;
  writeln('h',finish.Hour,' m',finish.Minute,' s',finish.Second,' ms',finish.Milliseconds);
  writeln('Shifts - ',shifts);
  writeln('Press ENTER');readln();
 end;

 //Mix the array
 procedure mix_the_array;
 begin
  for i:=1 to 25 do
  begin
   for j:=1 to dimension do
   begin
    a:=random(dimension+1);
    if a=0 then a:=1;
    c:=massiv[a];
    massiv[a]:=massiv[j mod dimension+1];
    massiv[j mod dimension+1]:=c;
   end;
  end;
  writeln('The array has been mixed');
  writeln('Press ENTER');readln();
 end;

 //Change the array
 procedure change_the_array;
 begin
  input_the_dimension_of_array;
 end;

 //Change a member of array
 procedure change_a_member_of_array;
 begin
  writeln('Input number of the changeable member of the array');
  write('-> ');readln(i);
  a:=1;
  if i>dimension then
  begin
   writeln('The array is selected on the interval [1..',dimension,']');
   writeln('Press ENTER');readln();
   a:=0;
  end;
  if a=1 then
  begin
   writeln('The last value of the ',i,' member of the array is ',massiv[i]);
   writeln('Input new value');
   write('-> ');readln(massiv[i]);
   writeln('The array have been changed');
   writeln('Press ENTER');readln();
  end;
 end;

 //View the array
 procedure view_the_array;
 begin
  for i:=1 to dimension do writeln('The ',i:6,' member is ',massiv[i]);
  writeln('Press ENTER');readln();
 end;

 //View a member of array
 procedure view_a_member_of_array;
 begin
  writeln('Input number of the viewed member of the array');
  write('-> ');readln(i);
  a:=1;
  if i>dimension then
  begin
   writeln('The array is selected on the interval [1..',dimension,']');
   writeln('Press ENTER');readln();
   a:=0;
  end;
  if a=1 then
  begin
   writeln('The value of the ',i,' member of the array is ',massiv[i]);
   writeln('Press ENTER');readln();
  end;
 end;

 //Search a member of array
 procedure search_a_member_of_array;
 begin
   writeln('Input the searched member');
   write('-> ');readln(c);
   writeln('Select the type of search:');
   writeln('1. Linear');
   writeln('2. Binary');
   write('-> ');readln(menu_select);
   case menu_select of
    1: begin
        f:=false;
        for i:=1 to dimension do
        begin
         if massiv[i]=c then
         begin
          writeln('The ',i:5,' member of the array has value ',c);
          f:=true;
         end;
        end;
        if f=false then writeln('The array has not the member with value ',c);
        writeln('Press ENTER');readln();
       end;
    2: begin
        f:=true;
        for i:=1 to (dimension-1) do
        begin
         if massiv[i]>massiv[i+1] then f:=false;
        end;

        if f=true then
        begin
         i:=1; j:=dimension; f2:=false;
         while f2=false do
         begin
          b:=(j+i) div 2;
          if (b=i) then
          begin
           f2:=true;
           f:=false;
          end;
          if massiv[b]=c then f2:=true;
          if massiv[j]=c then
          begin
           f2:=true;
           b:=j;
          end;
          if massiv[b]<c then i:=b;
          if massiv[b]>c then j:=b;
         end;
         i:=b; j:=b;
         while massiv[i-1]=massiv[i] do i:=i-1;
         while massiv[j+1]=massiv[i] do j:=j+1;
         if f=false then
          writeln('The array has not the member with value ',c);
         if f=true then
          for b:=i to j do writeln('The ',b:5,' member of the array has value ',c);
        end
        else
        begin
         writeln('The array is not sorted');
        end;
        writeln('Press ENTER');readln();
       end;
   end;
  end;

 //Comparison of sorts the array
 procedure comparison_of_sorts_the_array;
 begin
  for e:=1 to dimension do massiv_memory[e]:= massiv[e];
  writeln('Waiting...');
  writeln('Comparison of sorts the array:');
  writeln('Type          time:   h   m   s  ms  shifts:');
  for d:=1 to 4 do
  begin
   for e:=1 to dimension do massiv[e]:= massiv_memory[e];
   case d of
    1: sortirovka_selection;
    2: sortirovka_bubble;
    3: sortirovka_shell;
    4: sortirovka_insert;
   end;
   a:= (finish.Hour-start.Hour)*3600000 + (finish.Minute-start.Minute)*60000 + (finish.Second-start.Second)*1000 + (finish.Milliseconds-start.Milliseconds);
   finish.Hour:=a div 3600000; a:=a-finish.Hour*3600000;
   finish.Minute:=a div 60000; a:=a-finish.Minute*60000;
   finish.Second:=a div 1000; a:=a-finish.Second*1000;
   case d of
    1: write('Selection          ');
    2: write('Bubble             ');
    3: write('Sort of Shell      ');
    4: write('Insert             ');
   end;
  write(finish.Hour:4);write(finish.Minute:4);write(finish.Second:4);write(finish.Milliseconds:4);writeln(shifts:9);
  end;
  writeln('Comparison has been completed');
  writeln('Press ENTER');readln();
 end;

 //Select the operation over array
 procedure select_the_operation_over_array;
 begin
  f:=false;
  while f=false do
  begin
   f:=true;
   writeln('Select the operation:');
   writeln('1. Sort the array');
   writeln('2. Mix the array');
   writeln('3. Change the array');
   writeln('4. Change a member of array');
   writeln('5. View the array');
   writeln('6. View a member of array');
   writeln('7. Search a member of array');
   writeln('8. Comparison of sorts the array');
   writeln('0. Exit from program');
   write('-> ');readln(menu_select);
   case menu_select of
    1: sort_the_array;
    2: mix_the_array;
    3: change_the_array;
    4: change_a_member_of_array;
    5: view_the_array;
    6: view_a_member_of_array;
    7: search_a_member_of_array;
    8: comparison_of_sorts_the_array;
    0: exit_from_program;
    else f:=false;
   end;
  end;
 end;



begin
 start := CurrentDateTime;
 writeln('h',start.Hour,'m',start.Minute,'s',start.Second,'ms',start.Milliseconds);
 writeln('Sort and Search program');
 input_the_dimension_of_array;
 f_exit:=false;
 while f_exit=false do
 begin
  select_the_operation_over_array;
 end;

end.
