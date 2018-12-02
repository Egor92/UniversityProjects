#pragma once

namespace VNNG2011{

	#pragma region LineFormation
	ref class LineFormation{
		
		#pragma region ����
			public:
			System::String^ Text;
			cli::array<System::Drawing::Point^>^ Positions;
		#pragma endregion

		#pragma region �����������
			public:
			LineFormation(System::String^ Text, int CountOfPlayers){
				this->Text = Text;
				this->Positions = gcnew cli::array<System::Drawing::Point^> (CountOfPlayers);
			}
		#pragma endregion

		#pragma region ������ �������
			public:
			void InitPlayerPosition(int Number, int X, int Y){
				this->Positions[Number] = gcnew System::Drawing::Point(X, Y);
			}
		#pragma endregion

		#pragma region �������� �������
			public:
			System::Drawing::Point^ GetPlayerPosition(int Number){
				return this->Positions[Number];
			}
		#pragma endregion
	};
	#pragma endregion

	#pragma region LineFormations
	ref class LineFormations{
		
		#pragma region ����
			public:
			int CountOfLineFormations;
			cli::array<VNNG2011::LineFormation^>^ Formations;
		#pragma endregion

		#pragma region �����������
			public:
			LineFormations(int CountOfLineFormations){
				this->CountOfLineFormations = CountOfLineFormations;
				this->Formations = gcnew cli::array<VNNG2011::LineFormation^> (this->CountOfLineFormations);
			}
		#pragma endregion

		#pragma region ���������� []
			public:
			LineFormation^ LineFormations::operator[](int I){
				return this->Formations[I];
			}
		#pragma endregion
	};
	#pragma endregion

	#pragma region LinesFormations
	ref class LinesFormations{
		
		#pragma region ����
			public:
			cli::array<VNNG2011::LineFormations^>^ Formations;
		#pragma endregion

		#pragma region �����������
			public:
			LinesFormations(){
				this->Formations = gcnew cli::array<VNNG2011::LineFormations^> (5);
			}
		#pragma endregion

		#pragma region ���������� []
			public:
			LineFormations^ LinesFormations::operator[](int I){
				return this->Formations[I];
			}
		#pragma endregion
	};
	#pragma endregion
}
