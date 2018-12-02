#pragma once
#using "..\Bin\Microsoft.DirectX.AudioVideoPlayback.dll"


namespace VolgaNNGamer2011 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace Microsoft::DirectX::AudioVideoPlayback;

	public ref class VideoForm : public System::Windows::Forms::Form
	{
	public:
		VideoForm(System::String^ Name_Of_VideoFile){
			InitializeComponent();
			this->Name_Of_VideoFile = Name_Of_VideoFile;
		}

	protected:
		~VideoForm(){
			if (components){
				delete components;
			}
		}

	private: Video^ VIDEO;
	private: System::String^ Name_Of_VideoFile;
	private: System::ComponentModel::Container ^components;

	#pragma region Windows Form Designer generated code
		void InitializeComponent(){
			this->SuspendLayout();
			// 
			// VideoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"VideoForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Volga NN Gamer 2011";
			this->Load += gcnew System::EventHandler(this, &VideoForm::VideoForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VideoForm::VideoForm_MouseDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &VideoForm::VideoForm_KeyPress);
			this->ResumeLayout(false);

		}
	#pragma endregion



	#pragma region ѕроигрывает ‘айл при открытии
	System::Void VideoForm_Load(System::Object^  sender, System::EventArgs^  e) {
		try{
			this->VIDEO = gcnew Video("..\\Data\\Video\\" + this->Name_Of_VideoFile);
			this->VIDEO->Ending += gcnew System::EventHandler(this, &VideoForm::VIDEO_Ending);
			this->VIDEO->Owner = this;
			this->VIDEO->Play();
		}catch(Exception^ ex){
			this->Close();
			ex->ToString();
		}
	}
	#pragma endregion

	#pragma region ¬оспроизведение закончено - закрыть форму
	System::Void VIDEO_Ending(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	#pragma endregion

	#pragma region ѕользователь нажимает клавишу - остановить воспроизведение и закрыть форму
	System::Void VideoForm_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		this->VIDEO->Stop();
		this->Close();
	}
	#pragma endregion

	#pragma region ѕользователь кликает мышью - остановить воспроизведение и закрыть форму
	System::Void VideoForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->VIDEO->Stop();
		this->Close();
	}
	#pragma endregion

	};
}

