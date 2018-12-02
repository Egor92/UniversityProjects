using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::Collections;

public ref class TextLink
{
	String^ context;
	TextLink^ nextSection;
	TextLink^ downSection;
public:

#pragma region Constuctors
	TextLink(String^ name)
	{
		context = name;
		nextSection = nullptr;
		downSection = nullptr;
	}
#pragma endregion

#pragma region Properties
	property String^ Context
	{
		Void set(String^ value)
		{
			context = value;
		}
		String^ get(void)
		{
			return context;
		}
	}
	property TextLink^ NextSection
	{
		Void set(TextLink^ value)
		{
			nextSection = value;
		}
		TextLink^ get(void)
		{
			return nextSection;
		}
	}
	property TextLink^ DownSection
	{
		Void set(TextLink^ value)
		{
			downSection = value;
		}
		TextLink^ get(void)
		{
			return downSection;
		}
	}
#pragma endregion
};


public ref class MyText
{
	TextLink^ root;
	TextLink^ current;
	Int32 maxDeep;
	static Boolean editor;

#pragma region Private Metods
	static Boolean isCorrect(String^ path)
	{
		try 
		{
			Int32 counter = 0;
			String^ buffer_string = nullptr;
			StreamReader^ sReader = gcnew StreamReader(path);
			try 
			{
				while (buffer_string = sReader->ReadLine())
					if (!Convert::ToBoolean(buffer_string->CompareTo("{")))
						++counter;
					else
						if (!Convert::ToBoolean(buffer_string->CompareTo("}")))
							--counter; 
				if (Convert::ToBoolean(counter))
					throw gcnew Exception(String::Format("Неверная структрура файла {0}", path));
			}
			finally
			{
				if (sReader)
					delete (IDisposable^)sReader;
			}
		}
		catch(Exception^ ex)
		{
			throw gcnew Exception(ex->Message);
		}
		return true;
	}
	TreeNode^ makeChildNode(TextLink^ currenter, Int32 deep)
	{
		TreeNode^ curNode = gcnew TreeNode(currenter->Context);
		curNode->Tag = currenter;
		maxDeep = maxDeep < deep ? deep : maxDeep;
		while(currenter)
		{
			TreeNode^ tNode = gcnew TreeNode(currenter->Context);
			tNode->Tag = currenter;
			if(currenter->DownSection)
			{
				TreeNode^ b = makeChildNode(currenter->DownSection, deep + 1);
				for (int i = 0; i < b->Nodes->Count; ++i)
					tNode->Nodes->Add(b->Nodes[i]);
			}
			curNode->Nodes->Add(tNode);
			currenter = currenter->NextSection;
		}
		return curNode;
	}
	Void readFromFileToTextPrivate(StreamReader^ Buffer)
	{
		String^ strReaded = nullptr;
		while ( (strReaded = Buffer->ReadLine()) != nullptr)
			if (strReaded->CompareTo("{") == 0)
			{
				TextLink^ curLevel = current;
				InsertDownSection(Buffer->ReadLine());
				readFromFileToTextPrivate(Buffer);
				current = curLevel;
			}
			else
				if (strReaded->CompareTo("}") == 0)
					return ;
				else 
					InsertNextSection(strReaded);
	}
	static Void readFromTreeViewToFilePrivate(StreamWriter^ sWriter, TreeNode^ buffer)
	{
		sWriter->WriteLine("{");
		for (int i = 0; i < buffer->Nodes->Count; ++i)
		{
			sWriter->WriteLine(((TextLink^)(buffer->Nodes[i]->Tag))->Context);
			if (buffer->Nodes[i]->Nodes->Count)
				readFromTreeViewToFilePrivate(sWriter, buffer->Nodes[i]);
		}
		sWriter->WriteLine("}");
	}
	static String^ readFromTreeViewToRichTextBoxPrivate(TreeNode^ buffer)
	{
		String^ text = "{\n";
		for (int i = 0; i < buffer->Nodes->Count; ++i)
		{
			text += ((TextLink^)(buffer->Nodes[i]->Tag))->Context + "\n";
			if (buffer->Nodes[i]->Nodes->Count)
				text += readFromTreeViewToRichTextBoxPrivate(buffer->Nodes[i]);
		}
		return (text += "}\n");
	}

#pragma endregion

public:

#pragma region Constructors
	MyText(Void)
	{
		editor = true;
		maxDeep = 0;
		current = root = nullptr;
	}
#pragma endregion

#pragma region Properties
	property Int32 MaxDeep
	{
		Int32 get(void)
		{
			return maxDeep;
		}
	}
	property TextLink^ Root
	{
		Void set(TextLink^ value)
		{
			root = value;
		}
		TextLink^ get(void)
		{
			return root; 
		}
	}
	static property Boolean Editor
	{
		void set(Boolean value)
		{
			editor = value;
		}
		Boolean get(Void)
		{
			return editor;
		}
	}
	property TextLink^ Current
	{
		Void set(TextLink^ value)
		{
			current = value;
		}
		TextLink^ get(void)
		{
			return current;
		}
	}
	property Boolean isEmpty
	{
		Boolean get(void)
		{
			return Convert::ToBoolean(root == nullptr);
		}
	}
#pragma endregion

#pragma region Public Metods
	Void InsertNextSection(String^ Buffer)
	{
		current->NextSection = gcnew TextLink(Buffer);
		current = current->NextSection;
	}
	Void InsertDownSection(String^ str)
	{
		current->DownSection = gcnew TextLink(str);
		current = current->DownSection;
	}
	static Boolean isCorrect(RichTextBox^ richText)
	{
		Int32 counter = 0;
		array<String^>^ arString = richText->Lines;
		for (int i = 0; i < arString->Length; ++i)
			if (!Convert::ToBoolean(arString[i]->CompareTo("{")))
				counter++;
			else
				if (!Convert::ToBoolean(arString[i]->CompareTo("}")))
					--counter;
		return !Convert::ToBoolean(counter);
	}
	static Void writeToFileFromRichTextBox(RichTextBox^ rText, String^ tmp_path)
	{
		array<String^>^ texts = rText->Lines;
		try
		{
			StreamWriter^ sWriter = gcnew StreamWriter(tmp_path);
			try
			{
				for(int i = 0; i < texts->Length; ++i)
					sWriter->WriteLine(texts[i]);
			}
			finally
			{
				if (sWriter)
					delete (IDisposable^)sWriter;
			}
		}
		catch(Exception^ ex)
		{
			MessageBox::Show("Text couldn't be write\n" + ex->Message, "Error", 
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	Void readFromFileToText(String^ fileName)
	{
		try
		{
			if (isCorrect(fileName))
			{
				StreamReader^ sReader = gcnew StreamReader(fileName);
				try
				{
					root = gcnew TextLink(sReader->ReadLine());
					current = root;
					readFromFileToTextPrivate(sReader);
				}
				finally
				{
					if (sReader)
						delete (IDisposable^)sReader;
				}
			}
		}
		catch(Exception^ ex)
		{
			throw gcnew Exception(ex->Message);				
		}

	}
	static Void writeToRichTextBoxFromFile(RichTextBox^ Buffer, String^ path)
	{
		String^ strReaded = nullptr;
		try
		{
			StreamReader^ sReader = gcnew StreamReader(path);
			try 
			{
				while( strReaded = sReader->ReadLine() )
					Buffer->Text += strReaded + "\n";
				if ( Convert::ToBoolean(Buffer->Text->Length))
					Buffer->Text = Buffer->Text->Remove(Buffer->Text->Length - 1);
			}
			finally
			{
				if (sReader)
					delete (IDisposable^)sReader;
			}
		}
		catch(Exception^ ex)
		{
			throw gcnew Exception(ex->Message);
		}
	}
	Void writeToTreeViewFromText(TreeView^ tView)
	{
		if (isEmpty)
			return;
		TextLink^ buffer = root;
		tView->Nodes->Clear();
		maxDeep = 0;
		while(buffer)
		{
			TreeNode^ tNode = gcnew TreeNode(buffer->Context);
			tNode->Tag = buffer;
			if(buffer->DownSection)
			{
				TreeNode^ b = makeChildNode(buffer->DownSection, 1);
				for(int i = 0; i < b->Nodes->Count; ++i)
					tNode->Nodes->Add(b->Nodes[i]);
			}
			tView->Nodes->Add(tNode);
			buffer = buffer->NextSection;
		}
	}
	static Void readFromTreeViewToFile(TreeView^ buffer, String^ path)
	{
		try 
		{
			StreamWriter^ sWriter = gcnew StreamWriter(path);
			try
			{
				array<TreeNode^>^ arrayNode = gcnew array<TreeNode^>(buffer->Nodes->Count);
				((ICollection^)buffer->Nodes)->CopyTo(arrayNode, 0);
				for (int i = 0; i < arrayNode->Length; ++i)
				{
					sWriter->WriteLine(((TextLink^)arrayNode[i]->Tag)->Context);
					if (arrayNode[i]->Nodes->Count)
						readFromTreeViewToFilePrivate(sWriter, arrayNode[i]);
				}
			}
			finally
			{
				if (sWriter)
					delete (IDisposable^)sWriter;
			}
		}
		catch (Exception^ ex)
		{
			Exception^ exep = gcnew Exception(ex->Message);
			throw exep;
		}
	}
	Void readFromTreeViewToRichTextBox(TreeView^ tView, RichTextBox^ richText)
	{
		String^ text = "";
		array<TreeNode^>^ arrayNode = gcnew array<TreeNode^>(tView->Nodes->Count);
		((ICollection^)tView->Nodes)->CopyTo(arrayNode, 0);
		for (int i = 0; i < arrayNode->Length; ++i)
		{
			text += ((TextLink^)arrayNode[i]->Tag)->Context + "\n";
			if (arrayNode[i]->Nodes->Count)
				text += readFromTreeViewToRichTextBoxPrivate(arrayNode[i]);
		}
		if ( Convert::ToBoolean(richText->Text->Length))
		{
			editor = false;
			richText->Text = text->Remove(text->Length - 1);
			editor = true;
		}
	}
#pragma endregion

};
