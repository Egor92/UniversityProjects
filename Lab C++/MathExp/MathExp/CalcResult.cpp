#include "stack.h"
#include "CalcResult.h"


double CalcResult(bool FlagExp){
	double *DA;
	DA = new double[TBVyrazhenie->Length];
	stack DStack(TBVyrazhenie->Length,DA);
	for (I=0;I<TBVyrazhenie->Length;I++){
	if (SimbolNumber->IndexOf(STR[I])>-1){
		Len=1;
		J=I;
		while (I<STR->Length-1 && SimbolNumber->IndexOf(STR[I+1])>-1){
			Len++;
			I++;
		} 
		NuStack.Put(Convert::ToDouble(STR->Substring(J,Len)));
	}
	if (STR[I]==' '){}
	if (STR[I]=='+'){
		if (OpStack.See() == 2 || OpStack.See() == 3){
			PrintNuStack(NuStack, STR, true);
			NuStack.DeleteAll();
			while (!OpStack.IsEmpty() && OpStack.See() != 4){
				this->TBVyrazhenie->Text += SimbolOperation[OpStack.Get()].ToString() + " ";	
			}
		}
		OpStack.Put(0);
	}
	if (STR[I]=='-'){
		if (OpStack.See() == 2 || OpStack.See() == 3){
			PrintNuStack(NuStack, STR, true);
			NuStack.DeleteAll();
			while (!OpStack.IsEmpty() && OpStack.See() != 4){
				this->TBVyrazhenie->Text += SimbolOperation[OpStack.Get()].ToString() + " ";				
			}
		}
		OpStack.Put(1);
	}
	if (STR[I]=='*'){
		OpStack.Put(2);
	}
	if (STR[I]=='/'){
		OpStack.Put(3);
	}
	if (STR[I]=='(' || STR[I]=='{'){
		OpStack.Put(4);
	}
	if (STR[I]==')' || STR[I]=='}'){
		PrintNuStack(NuStack, STR, true);
		NuStack.DeleteAll();
		while (OpStack.See() != 4){
			this->TBVyrazhenie->Text += SimbolOperation[OpStack.Get()].ToString() + " ";				
		}
		OpStack.Dim--;
	}
}

};