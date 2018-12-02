#pragma once
#include <stdio.h>
using namespace System::Windows::Forms;

namespace Egor{
	namespace Funcs{

		#pragma region ������� "System::String^" � "const char*"
			static const char* SysStr_To_ConstChar(System::String^ SysStr){
				return (const char*) (System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(SysStr)).ToPointer();
			}
		#pragma endregion

		#pragma region ������� "const char*" � "System::String^"
			static System::String^ ConstChar_To_SysStr(const char* CharStr){
				return gcnew System::String(CharStr);
			}
		#pragma endregion

		#pragma region ������������ ���� �������� ��������
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

		#pragma region ����
		private:
			const char* FileName;
			FILE *File;
		#pragma endregion

		#pragma region �����������
		public:
			FileReader(System::String^ FileName){
				this->FileName = Egor::Funcs::SysStr_To_ConstChar(FileName);
				this->File = fopen(this->FileName, "r");
				if (!this->File){
					MessageBox::Show("�� ������ ������� ���� " + Egor::Funcs::ConstChar_To_SysStr(this->FileName) , "������!",
										System::Windows::Forms::MessageBoxButtons::OK,
										System::Windows::Forms::MessageBoxIcon::Error );
				}
			}
		#pragma endregion

		#pragma region ����������
		protected:
			~FileReader(){
				delete File;
			}
		#pragma endregion

		#pragma region �������� �� ������������ �������� �����
		public:
			bool IsOpenedSuccessfully(bool DoMessage = true){
				if (!this->File){
					if (DoMessage){
						MessageBox::Show("���� " + Egor::Funcs::ConstChar_To_SysStr(this->FileName) + " �� ������", "������!",
											System::Windows::Forms::MessageBoxButtons::OK,
											System::Windows::Forms::MessageBoxIcon::Error );
					}
					return false;
				}else{
					return true;
				}
			}
		#pragma endregion

		#pragma region ������� ������
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
							MessageBox::Show("������ ��� ������ �����\n" + ex->ToString(), "������!",
												System::Windows::Forms::MessageBoxButtons::OK,
												System::Windows::Forms::MessageBoxIcon::Error );
						}
						if (Symbol == 59 || Symbol == 10){
							//���������� �������� ���������� �� ������� ';' ��� '������� �� ����� ������'
							break;
						}
						Result += System::Convert::ToChar(Egor::Funcs::NormalizeRussianWords(Symbol)).ToString();
					}
				}else{
					MessageBox::Show("�� ������ ������� ���� " + Egor::Funcs::ConstChar_To_SysStr(this->FileName) , "������!",
										System::Windows::Forms::MessageBoxButtons::OK,
										System::Windows::Forms::MessageBoxIcon::Error );
				}

				//������������ ������������
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

		#pragma region ������ ������
		public:
			System::String^ ReadString(){
				return this->Read();
			}
		#pragma endregion

		#pragma region ������ ������ �����
		public:
			int ReadInteger(){
				System::String^ S1 = this->Read();
				int Result;
				try{
					Result = System::Convert::ToInt32( S1 );
				}catch(Exception^ ex){
					MessageBox::Show("�� ������ �������������� ������ \"" + S1 + "\" � ����� �����." + "\n" + "����: " + Egor::Funcs::ConstChar_To_SysStr(this->FileName) , "������!",
										System::Windows::Forms::MessageBoxButtons::OK,
										System::Windows::Forms::MessageBoxIcon::Error );
					ex->ToString();
				}
				return Result;
			}
		#pragma endregion

		#pragma region ������ ������������� �����
		public:
			double ReadDouble(){
				System::String^ S1 = this->Read();
				double Result;
				try{
					Result = System::Convert::ToDouble( S1 );
				}catch(Exception^ ex){
					MessageBox::Show("�� ������ �������������� ������ \"" + S1 + "\" � ������������ �����." + "\n" + "����: " + Egor::Funcs::ConstChar_To_SysStr(this->FileName) , "������!",
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


