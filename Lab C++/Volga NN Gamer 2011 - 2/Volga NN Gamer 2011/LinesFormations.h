#pragma once

namespace VNNG2011{

	#pragma region LineFormation
	ref class LineFormation{
		
		#pragma region Поля
			public:
			System::String^ Text;
			cli::array<System::Drawing::Point^>^ Positions;
		#pragma endregion

		#pragma region Конструктор
			public:
			LineFormation(System::String^ Text, int CountOfPlayers){
				this->Text = Text;
				this->Positions = gcnew cli::array<System::Drawing::Point^> (CountOfPlayers);
			}
		#pragma endregion

		#pragma region Задать позицию
			public:
			void InitPlayerPosition(int Number, int X, int Y){
				this->Positions[Number] = gcnew System::Drawing::Point(X, Y);
			}
		#pragma endregion

		#pragma region Получить позицию
			public:
			System::Drawing::Point^ GetPlayerPosition(int Number){
				return this->Positions[Number];
			}
		#pragma endregion
	};
	#pragma endregion

	#pragma region LineFormations
	ref class LineFormations{
		
		#pragma region Поля
			public:
			int CountOfLineFormations;
			cli::array<VNNG2011::LineFormation^>^ Formations;
		#pragma endregion

		#pragma region Конструктор
			public:
			LineFormations(int CountOfLineFormations){
				this->CountOfLineFormations = CountOfLineFormations;
				this->Formations = gcnew cli::array<VNNG2011::LineFormation^> (this->CountOfLineFormations);
			}
		#pragma endregion

		#pragma region Перегрузка []
			public:
			LineFormation^ LineFormations::operator[](int I){
				return this->Formations[I];
			}
		#pragma endregion
	};
	#pragma endregion

	#pragma region LinesFormations
	ref class LinesFormations{
		
		#pragma region Поля
			public:
			cli::array<VNNG2011::LineFormations^>^ Formations;
		#pragma endregion

		#pragma region Конструктор
			public:
			LinesFormations(){
				this->Formations = gcnew cli::array<VNNG2011::LineFormations^> (5);
			}
		#pragma endregion

		#pragma region Перегрузка []
			public:
			LineFormations^ LinesFormations::operator[](int I){
				return this->Formations[I];
			}
		#pragma endregion
	};
	#pragma endregion
}
