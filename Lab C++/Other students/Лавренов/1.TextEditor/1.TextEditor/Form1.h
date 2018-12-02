#pragma once

#include "ClassFile.h"
#include "addForm.h"

namespace My1TextEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;


	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			text = gcnew MyText();
			path = gcnew String("path.txt");
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::StatusStrip^  statusBar;

#pragma region Controls

	private: System::Windows::Forms::MenuStrip^  mainMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearToolStripMenuItem;
	private: System::Windows::Forms::RichTextBox^  VisualTextEsc;
	private: System::Windows::Forms::TreeView^  treeView1;

	private: System::Windows::Forms::Panel^  mainPanel;
	private: System::Windows::Forms::ToolStripStatusLabel^  MaxDeepLabel;



	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  insertNextSectionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  insertDownSectionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteNextSectionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteDownSectionToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  deleteDownLineToolStripMenuItem;

	private: System::ComponentModel::IContainer^  components;

#pragma endregion

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->statusBar = (gcnew System::Windows::Forms::StatusStrip());
			this->MaxDeepLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->mainMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->VisualTextEsc = (gcnew System::Windows::Forms::RichTextBox());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->insertNextSectionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->insertDownSectionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteNextSectionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteDownSectionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteDownLineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->statusBar->SuspendLayout();
			this->mainMenu->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->mainPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// statusBar
			// 
			this->statusBar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->MaxDeepLabel});
			this->statusBar->Location = System::Drawing::Point(0, 480);
			this->statusBar->Name = L"statusBar";
			this->statusBar->Size = System::Drawing::Size(650, 22);
			this->statusBar->TabIndex = 0;
			this->statusBar->Text = L"statusStrip1";
			// 
			// MaxDeepLabel
			// 
			this->MaxDeepLabel->Name = L"MaxDeepLabel";
			this->MaxDeepLabel->Size = System::Drawing::Size(0, 17);
			// 
			// mainMenu
			// 
			this->mainMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->optionToolStripMenuItem});
			this->mainMenu->Location = System::Drawing::Point(0, 0);
			this->mainMenu->Name = L"mainMenu";
			this->mainMenu->Size = System::Drawing::Size(650, 24);
			this->mainMenu->TabIndex = 1;
			this->mainMenu->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->openToolStripMenuItem, 
				this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->openToolStripMenuItem->Text = L"&Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->saveToolStripMenuItem->Text = L"&Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->saveAsToolStripMenuItem->Text = L"Save as...";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveAsToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::E));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->exitToolStripMenuItem->Text = L"&Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// optionToolStripMenuItem
			// 
			this->optionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->clearToolStripMenuItem});
			this->optionToolStripMenuItem->Name = L"optionToolStripMenuItem";
			this->optionToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->optionToolStripMenuItem->Text = L"Option";
			// 
			// clearToolStripMenuItem
			// 
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->clearToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->clearToolStripMenuItem->Text = L"&Clear";
			this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::clearToolStripMenuItem_Click);
			// 
			// VisualTextEsc
			// 
			this->VisualTextEsc->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->VisualTextEsc->Location = System::Drawing::Point(3, 3);
			this->VisualTextEsc->Name = L"VisualTextEsc";
			this->VisualTextEsc->Size = System::Drawing::Size(620, 202);
			this->VisualTextEsc->TabIndex = 2;
			this->VisualTextEsc->Text = L"";
			this->VisualTextEsc->TextChanged += gcnew System::EventHandler(this, &Form1::VisualTextEsc_TextChanged);
			// 
			// treeView1
			// 
			this->treeView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->treeView1->ContextMenuStrip = this->contextMenuStrip1;
			this->treeView1->FullRowSelect = true;
			this->treeView1->HotTracking = true;
			this->treeView1->LabelEdit = true;
			this->treeView1->Location = System::Drawing::Point(3, 240);
			this->treeView1->Name = L"treeView1";
			this->treeView1->ShowNodeToolTips = true;
			this->treeView1->Size = System::Drawing::Size(620, 207);
			this->treeView1->TabIndex = 3;
			this->treeView1->AfterLabelEdit += gcnew System::Windows::Forms::NodeLabelEditEventHandler(this, &Form1::treeView1_AfterLabelEdit);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->insertNextSectionToolStripMenuItem, 
				this->insertDownSectionToolStripMenuItem, this->deleteNextSectionToolStripMenuItem, this->deleteDownSectionToolStripMenuItem, 
				this->deleteDownLineToolStripMenuItem});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(213, 114);
			// 
			// insertNextSectionToolStripMenuItem
			// 
			this->insertNextSectionToolStripMenuItem->Checked = true;
			this->insertNextSectionToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->insertNextSectionToolStripMenuItem->Name = L"insertNextSectionToolStripMenuItem";
			this->insertNextSectionToolStripMenuItem->Size = System::Drawing::Size(212, 22);
			this->insertNextSectionToolStripMenuItem->Text = L"Insert Next Section / Line";
			this->insertNextSectionToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::insertNextSectionToolStripMenuItem_Click);
			// 
			// insertDownSectionToolStripMenuItem
			// 
			this->insertDownSectionToolStripMenuItem->Checked = true;
			this->insertDownSectionToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->insertDownSectionToolStripMenuItem->Name = L"insertDownSectionToolStripMenuItem";
			this->insertDownSectionToolStripMenuItem->Size = System::Drawing::Size(212, 22);
			this->insertDownSectionToolStripMenuItem->Text = L"Insert Down Section / Line";
			this->insertDownSectionToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::insertDownSectionToolStripMenuItem_Click);
			// 
			// deleteNextSectionToolStripMenuItem
			// 
			this->deleteNextSectionToolStripMenuItem->Checked = true;
			this->deleteNextSectionToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->deleteNextSectionToolStripMenuItem->Name = L"deleteNextSectionToolStripMenuItem";
			this->deleteNextSectionToolStripMenuItem->Size = System::Drawing::Size(212, 22);
			this->deleteNextSectionToolStripMenuItem->Text = L"Delete Next Section";
			this->deleteNextSectionToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::deleteNextSectionToolStripMenuItem_Click);
			// 
			// deleteDownSectionToolStripMenuItem
			// 
			this->deleteDownSectionToolStripMenuItem->Checked = true;
			this->deleteDownSectionToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->deleteDownSectionToolStripMenuItem->Name = L"deleteDownSectionToolStripMenuItem";
			this->deleteDownSectionToolStripMenuItem->Size = System::Drawing::Size(212, 22);
			this->deleteDownSectionToolStripMenuItem->Text = L"Delete Down Section";
			this->deleteDownSectionToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::deleteDownSectionToolStripMenuItem_Click);
			// 
			// deleteDownLineToolStripMenuItem
			// 
			this->deleteDownLineToolStripMenuItem->Checked = true;
			this->deleteDownLineToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->deleteDownLineToolStripMenuItem->Name = L"deleteDownLineToolStripMenuItem";
			this->deleteDownLineToolStripMenuItem->Size = System::Drawing::Size(212, 22);
			this->deleteDownLineToolStripMenuItem->Text = L"Delete Down Line";
			this->deleteDownLineToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::deleteDownLineToolStripMenuItem_Click);
			// 
			// mainPanel
			// 
			this->mainPanel->Controls->Add(this->VisualTextEsc);
			this->mainPanel->Controls->Add(this->treeView1);
			this->mainPanel->Location = System::Drawing::Point(12, 27);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(626, 450);
			this->mainPanel->TabIndex = 5;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(650, 502);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->statusBar);
			this->Controls->Add(this->mainMenu);
			this->MainMenuStrip = this->mainMenu;
			this->MinimumSize = System::Drawing::Size(666, 540);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Text Editor";
			this->statusBar->ResumeLayout(false);
			this->statusBar->PerformLayout();
			this->mainMenu->ResumeLayout(false);
			this->mainMenu->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			this->mainPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private:
	MyText^ text;
	String^ path;

private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }
private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ oFileDialog = gcnew OpenFileDialog();
			 oFileDialog->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
			 oFileDialog->Title = "Open file for reading";
			 if (oFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 clearToolStripMenuItem_Click(sender, e);
				 path = oFileDialog->FileName;
				 try 
				 {
					text->readFromFileToText(path);
				 }
				 catch(Exception^ ex)
				 {
					 if (System::Windows::Forms::DialogResult::Retry == 
						 MessageBox::Show(ex->Message, "Error", 
						 MessageBoxButtons::RetryCancel, MessageBoxIcon::Error))
						 openToolStripMenuItem_Click(sender, e);
					 else
					 {	
						 this->clearToolStripMenuItem_Click(sender, e);
						 return;
					 }
				 }
				 text->writeToRichTextBoxFromFile(this->VisualTextEsc, path);
				 text->writeToTreeViewFromText(this->treeView1);
			 }
		 }
private: System::Void clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^  e) {
			 VisualTextEsc->Text = "";
			 treeView1->Nodes->Clear();
		 }
private: System::Void VisualTextEsc_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (MyText::isCorrect(VisualTextEsc) && MyText::Editor)
			 {
				 String^ tmp_path = "tmp.txt";
				 MyText::writeToFileFromRichTextBox(VisualTextEsc, tmp_path);
				 text->readFromFileToText(tmp_path);
				 text->writeToTreeViewFromText(treeView1);
			 }
			 this->MaxDeepLabel->Text = "Max Deep: " + Convert::ToString(text->MaxDeep);
		 }
private: System::Void treeView1_AfterLabelEdit(System::Object^  sender, System::Windows::Forms::NodeLabelEditEventArgs^  e) {
			 ((TextLink^)treeView1->SelectedNode->Tag)->Context = e->Label;
			 text->readFromTreeViewToRichTextBox(treeView1, VisualTextEsc);
		 }
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 text->readFromTreeViewToFile(this->treeView1, path);
		 }
private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveFileDialog^ sFileDialog = gcnew SaveFileDialog();
			 sFileDialog->Filter = "Text (*.txt)|*.txt|All files (*.*)|*.*";
			 sFileDialog->Title = "Save text as ...";
			 if (System::Windows::Forms::DialogResult::OK == sFileDialog->ShowDialog())
				 text->readFromTreeViewToFile(this->treeView1, path = sFileDialog->FileName);
		 }
private: System::Void insertNextSectionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		     addForm^ Buffer = gcnew addForm();
			 if (System::Windows::Forms::DialogResult::OK == Buffer->ShowDialog())
			 {
				 text->Current = (TextLink^)(treeView1->SelectedNode->Tag);
				 TextLink^ buffer = text->Current->NextSection;
			     text->InsertNextSection(Buffer->recordName);
				 text->Current->NextSection = buffer;
			 }
			 text->writeToTreeViewFromText(treeView1);
			 text->readFromTreeViewToRichTextBox(treeView1, VisualTextEsc);
		 }
private: System::Void insertDownSectionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 addForm^ Buffer = gcnew addForm();
			 if (System::Windows::Forms::DialogResult::OK == Buffer->ShowDialog())
			 {
				 text->Current = ((TextLink^)(treeView1->SelectedNode->Tag));
				 TextLink^ buffer = nullptr;
				 if (text->Current->DownSection)
					 buffer = text->Current->DownSection;
				 text->InsertDownSection(Buffer->recordName);
				 text->Current->NextSection = buffer;
			 }
			 text->writeToTreeViewFromText(treeView1);
			 text->readFromTreeViewToRichTextBox(treeView1, VisualTextEsc);
		 }
private: System::Void deleteNextSectionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 TextLink^ tmp = ((TextLink^)treeView1->SelectedNode->Tag);
			 if (tmp->NextSection)
				 tmp->NextSection = tmp->NextSection->NextSection;
			 text->writeToTreeViewFromText(treeView1);
			 text->readFromTreeViewToRichTextBox(treeView1, VisualTextEsc);
		 }
private: System::Void deleteDownSectionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 TextLink^ buffer = ((TextLink^)treeView1->SelectedNode->Tag);
			 if (buffer->DownSection)
				 buffer->DownSection = buffer->DownSection->NextSection;
			 text->writeToTreeViewFromText(treeView1);
			 text->readFromTreeViewToRichTextBox(treeView1, VisualTextEsc);
		 }
private: System::Void deleteDownLineToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 TextLink^ current = (TextLink^)(treeView1->SelectedNode->Tag);
			 TextLink^ downLevel = nullptr;
			 if (downLevel = current->DownSection)
			 {
				 // next level for disposing's TextLink;
				 TextLink^ nextLevel = downLevel->NextSection;
				 // down level for disposing's TextLink;
				 downLevel = downLevel->DownSection;
				 if (downLevel)
				 {
					 current->DownSection = downLevel;
					 current = current->DownSection;
					 while(current->NextSection)
						current = current->NextSection;
					 current->NextSection = nextLevel;
				 }
				 else
					 current->DownSection = nextLevel;
			 }
			 text->writeToTreeViewFromText(treeView1);
			 text->readFromTreeViewToRichTextBox(treeView1, VisualTextEsc);
		 }
};
}
