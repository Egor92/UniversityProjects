#pragma once
#include <stdio.h>
using namespace System::Windows::Forms;

namespace Egor{
	namespace Funcs{

		#pragma region Перевод "System::String^" в "const char*"
			static const char* SysStr_To_ConstChar(System::String^ SysStr){
				return (const char*) (System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(SysStr)).ToPointer();
			}
		#pragma endregion

		#pragma region Перевод "const char*" в "System::String^"
			static System::String^ ConstChar_To_SysStr(const char* CharStr){
				return gcnew System::String(CharStr);
			}
		#pragma endregion

		#pragma region Нормализация букв русского алфавита
			static int NormalizeRussianWords(char Symbol){
				if (Symbol == -72){
					return (1105);
				}else if (Symbol == -88){
					return (1025);
				}else if (Symbol < 0){
					return (Symbol + 1104);
				}else{
					return Symbol;
				}
			}
		#pragma endregion

	}

	namespace FileWork{
		class FileReader{

		#pragma region Поля
		private:
			const char* FileName;
			FILE *File;
		#pragma endregion

		#pragma region Конструктор
		public:
			FileReader(System::String^ FileName){
				this->FileName = Egor::Funcs::SysStr_To_ConstChar(FileName);
				this->File = fopen(this->FileName, "r");
				if (!this->File){
					MessageBox::Show("Не удаётся открыть файл " + Egor::Funcs::ConstChar_To_SysStr(this->FileName) , "Ошибка!",
										System::Windows::Forms::MessageBoxButtons::OK,
										System::Windows::Forms::MessageBoxIcon::Error );
				}
			}
		#pragma endregion

		#pragma region Деструктор
		protected:
			~FileReader(){
				delete File;
			}
		#pragma endregion

		#pragma region Проверка на правильность открытия файла
		public:
			bool IsOpenedSuccessfully(bool DoMessage = true){
				if (!this->File){
					if (DoMessage){
						MessageBox::Show("Файл " + Egor::Funcs::ConstChar_To_SysStr(this->FileName) + " не считан", "Ошибка!",
											System::Windows::Forms::MessageBoxButtons::OK,
											System::Windows::Forms::MessageBoxIcon::Error );
					}
					return false;
				}else{
					return true;
				}
			}
		#pragma endregion

		#pragma region Простое чтение
		private:
			System::String^ Read(){
				char Symbol;
				System::String^ Result;

				if (this->IsOpenedSuccessfully(true)){
					while (true){
						if (feof(this->File)){
							break;
						}
						try{
							fscanf(this->File, "%c" ,&Symbol);
						}catch(Exception^ ex){
							MessageBox::Show("Ошибка при чтении файла\n" + ex->ToString(), "Ошибка!",
												System::Windows::Forms::MessageBoxButtons::OK,
												System::Windows::Forms::MessageBoxIcon::Error );
						}
						if (Symbol == 59 || Symbol == 10){
							//Считывание символов происходит до символа ';' или 'переход на новую строку'
							break;
						}
						Result += System::Convert::ToChar(Egor::Funcs::NormalizeRussianWords(Symbol)).ToString();
					}
				}else{
					MessageBox::Show("Не удаётся открыть файл " + Egor::Funcs::ConstChar_To_SysStr(this->FileName) , "Ошибка!",
										System::Windows::Forms::MessageBoxButtons::OK,
										System::Windows::Forms::MessageBoxIcon::Error );
				}

				//Отлавливание комментариев
				System::String^ S1 = Result;
				S1->Trim();
				if (S1->Length >= 2){
					if (S1->IndexOf("//") == 0){
						Result = this->Read();
					}
				}

				return Result;
			}
		#pragma endregion

		#pragma region Чтение строки
		public:
			System::String^ ReadString(){
				return this->Read();
			}
		#pragma endregion

		#pragma region Чтение целого числа
		public:
			int ReadInteger(){
				System::String^ S1 = this->Read();
				int Result;
				try{
					Result = System::Convert::ToInt32( S1 );
				}catch(Exception^ ex){
					MessageBox::Show("Не удаётся конвертировать строку \"" + S1 + "\" в целое число." + "\n" + "Файл: " + Egor::Funcs::ConstChar_To_SysStr(this->FileName) , "Ошибка!",
										System::Windows::Forms::MessageBoxButtons::OK,
										System::Windows::Forms::MessageBoxIcon::Error );
					ex->ToString();
				}
				return Result;
			}
		#pragma endregion

		#pragma region Чтение вещественного числа
		public:
			double ReadDouble(){
				System::String^ S1 = this->Read();
				double Result;
				try{
					Result = System::Convert::ToDouble( S1 );
				}catch(Exception^ ex){
					MessageBox::Show("Не удаётся конвертировать строку \"" + S1 + "\" в вещественное число." + "\n" + "Файл: " + Egor::Funcs::ConstChar_To_SysStr(this->FileName) , "Ошибка!",
										System::Windows::Forms::MessageBoxButtons::OK,
										System::Windows::Forms::MessageBoxIcon::Error );
					ex->ToString();
				}
				return Result;
			}
		#pragma endregion

		};
	}

}


