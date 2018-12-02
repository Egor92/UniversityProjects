#pragma once
#include "dataok.h"
#include "stack.h"
#include "dstack.h"

namespace kalkulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textbox;
	protected: 

	private: System::Windows::Forms::Label^  label;

	private: System::Windows::Forms::Button^  button;
	private: System::Windows::Forms::Label^  rezult;
	private: System::Windows::Forms::Label^  Info;
	private: System::Windows::Forms::Button^  Help;
	private: System::Windows::Forms::Label^  attention;

	private: System::Windows::Forms::Label^  error;
	void schitat(stack &st,dstack &dst){//делает одну операцию (st стек операторов dst стек чисел)
		double tmp1,tmp2;
		if (st.See()==3){tmp1=dst.Get(); tmp2=dst.Get(); dst.Put(tmp2+tmp1); st.Get();}//сложение
		if (st.See()==4){tmp1=dst.Get(); tmp2=dst.Get(); dst.Put(tmp2-tmp1); st.Get();}//вычитание
		if (st.See()==5){tmp1=dst.Get(); tmp2=dst.Get(); dst.Put(tmp2*tmp1); st.Get();}//умножение
		if (st.See()==6){tmp1=dst.Get(); tmp2=dst.Get(); dst.Put(tmp2/tmp1); st.Get();}//деление
	}
	void sdelat(String ^s){//вычисляет выражение s
		String ^num="1234567890,"; //строка для идендификации чисел
		String ^kod=" ()+-*/{}"; //код оператора соотвествует позиции оператора в этой строке
		String ^post="";  //строка выражения в постфиксном виде для вывода в метку
		double *dmem; //память под стек чисел
		dmem=new double [s->Length];
		dstack dst(dmem,s->Length);//стек чисел
		int* mem;//память под стек операторов
		mem=new int [s->Length];
		stack st(mem,s->Length);//стек операторов
		int i=0; int ln;//длина числа в символах
		int tmp1;
		while (i<s->Length){
			if (num->IndexOf(s[i])>-1){
				ln=1; tmp1=i;//запоминает где начинается число
				while ((i<s->Length-1)&&(num->IndexOf(s[i+1])>-1))//пока следующий символ относится к числу
				{ln++; i++;} //увеличиваем счетчик длины, общий счетчие увеличиваем чтобы заново не анализировать это же число
				this->rezult->Text+=s->Substring(tmp1,ln)+" ";//выводим число
				dst.Put(Convert::ToDouble(s->Substring(tmp1,ln)));//кладем в стек чисел
			}
			if (s[i]==kod[7]) // '{'
				{st.Put(7);}//кладем в стек
			if (s[i]==kod[8]){// '}'
				while (st.See()!=7){this->rezult->Text+=kod[st.See()]+" "; schitat(st,dst);}
				st.Get();//выталкиваем операторы и скобку, производя подсчет
			}
			if (s[i]==kod[1]) // '('
				{st.Put(1);}  //действия такие же как и с фигурными скобками
			if (s[i]==kod[2]){// ')'
				while (st.See()!=1){this->rezult->Text+=kod[st.See()]+" "; schitat(st,dst);}
				st.Get();
			}
			if (s[i]==kod[3]){// '+'
				while ((!st.IsEmpty())&&((st.See()==5)||(st.See()==6)||(st.See()==4)))//выталкиваем оператры в соотвествии с правилом о приоритетах
					{this->rezult->Text+=kod[st.See()]+" "; schitat(st,dst);}// при выталкивании делаем подсчет и выводим соответсвующий оператор в постфиксную строку 
				st.Put(3);
			}
			if (s[i]==kod[4]){// '-'   с остальными операторами аналогично
				while ((!st.IsEmpty())&&((st.See()==4)||(st.See()==5)||(st.See()==6)||(st.See()==3)))
					{this->rezult->Text+=kod[st.See()]+" "; schitat(st,dst);}
				st.Put(4);
			}
			if (s[i]==kod[5]){// '*'
				while ((!st.IsEmpty())&&(st.See()==6))
					{this->rezult->Text+=kod[st.See()]+" "; schitat(st,dst);}
				st.Put(5);
			}
			if (s[i]==kod[6]){// '/'
				while ((!st.IsEmpty())&&(st.See()==5))
					{this->rezult->Text+=kod[st.See()]+" "; schitat(st,dst);}
				st.Put(6);
			}
			i++;//не забываем увеличивать счетчик =)
		}
		while (!st.IsEmpty()){this->rezult->Text+=kod[st.See()]+" "; schitat(st,dst);}//досчитывваем выражение с оставшимися операторами
		this->rezult->Text+="= "+Convert::ToString(dst.Get())+" "; //выводим результат
	}




	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->textbox = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->button = (gcnew System::Windows::Forms::Button());
			this->rezult = (gcnew System::Windows::Forms::Label());
			this->error = (gcnew System::Windows::Forms::Label());
			this->Info = (gcnew System::Windows::Forms::Label());
			this->Help = (gcnew System::Windows::Forms::Button());
			this->attention = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textbox
			// 
			this->textbox->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textbox->Location = System::Drawing::Point(12, 33);
			this->textbox->Name = L"textbox";
			this->textbox->Size = System::Drawing::Size(390, 20);
			this->textbox->TabIndex = 0;
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label->Location = System::Drawing::Point(130, 9);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(173, 21);
			this->label->TabIndex = 1;
			this->label->Text = L"Введите выражение:";
			// 
			// button
			// 
			this->button->Location = System::Drawing::Point(408, 31);
			this->button->Name = L"button";
			this->button->Size = System::Drawing::Size(75, 23);
			this->button->TabIndex = 2;
			this->button->Text = L"Посчитать";
			this->button->UseVisualStyleBackColor = true;
			this->button->Click += gcnew System::EventHandler(this, &Form1::button_Click);
			// 
			// rezult
			// 
			this->rezult->AutoSize = true;
			this->rezult->Location = System::Drawing::Point(9, 64);
			this->rezult->Name = L"rezult";
			this->rezult->Size = System::Drawing::Size(159, 13);
			this->rezult->TabIndex = 3;
			this->rezult->Text = L"ДЛЯ ВЫДАЧИ РЕЗУЛЬТАТА";
			// 
			// error
			// 
			this->error->AutoSize = true;
			this->error->ForeColor = System::Drawing::Color::Red;
			this->error->Location = System::Drawing::Point(8, 77);
			this->error->Name = L"error";
			this->error->Size = System::Drawing::Size(82, 13);
			this->error->TabIndex = 4;
			this->error->Text = L"ДЛЯ ОШИБОК";
			// 
			// Info
			// 
			this->Info->AutoSize = true;
			this->Info->Location = System::Drawing::Point(8, 90);
			this->Info->Name = L"Info";
			this->Info->Size = System::Drawing::Size(86, 13);
			this->Info->TabIndex = 5;
			this->Info->Text = L"ДЛЯ СПРАВКИ";
			// 
			// Help
			// 
			this->Help->Location = System::Drawing::Point(355, 268);
			this->Help->Name = L"Help";
			this->Help->Size = System::Drawing::Size(123, 23);
			this->Help->TabIndex = 6;
			this->Help->Text = L"Показать справку";
			this->Help->UseVisualStyleBackColor = true;
			this->Help->Click += gcnew System::EventHandler(this, &Form1::Help_Click);
			// 
			// attention
			// 
			this->attention->AutoSize = true;
			this->attention->Location = System::Drawing::Point(11, 278);
			this->attention->Name = L"attention";
			this->attention->Size = System::Drawing::Size(147, 13);
			this->attention->TabIndex = 7;
			this->attention->Text = L"ДЛЯ ПРЕДУПРЕЖДЕНИЙ";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(490, 303);
			this->Controls->Add(this->attention);
			this->Controls->Add(this->Help);
			this->Controls->Add(this->Info);
			this->Controls->Add(this->error);
			this->Controls->Add(this->rezult);
			this->Controls->Add(this->button);
			this->Controls->Add(this->label);
			this->Controls->Add(this->textbox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Calc 1.6";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 this->error->Text="";   //при старте программы метки ошибки
				 this->rezult->Text="";  //и результата пусты
				 this->attention->Text="";
				 this->Info->Text="Каждое выражение заключается в фигурные скобки, выражения, не заключенные"+"\n";
				 this->Info->Text+="в фигурные скобки, не считаютя! Выражения могут содержать в себе другие "+"\n";	
				 this->Info->Text+="выражения, в этом случае считаются оба выражения, а фигурные скобки для"+"\n";
				 this->Info->Text+="внешнего выражения значат то же, что и круглые. "+"\n";
				 this->Info->Text+="Целая и дробная части чила разделяются запятой."+"\n";
				 this->Info->Text+="Нумерация символов в строке начинается с нуля."+"\n";
				 this->Info->Text+="Доступные операции: + - * /, а так же ( ) для указания приоритета."+"\n";
				 this->Info->Text+="Пример входной строки {1-{2,7+0,3}} {3*2-1}"+"\n";
			 }
	private: System::Void button_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->error->Text=""; //в начале новой проверки считаем что ошибок нет
				 this->rezult->Text="";//обновляем результат
				 this->Info->Visible=false;//скрываем справку
				 this->attention->Text="";
				 String ^s=this->textbox->Text;
				 int i=0;
				 String ^tmp="1234567890()*/+-{}, "; //строка допустимых символов
				 bool flag=false;
				 bool korrekt=true;  //флаг корректности выражения, сначала считаем что выражение корректно
				 for (i=0;i<s->Length;i++){
					 if (tmp->IndexOf(s[i])==-1) { //если символа нет в строке допустимых символов
						 this->error->Text+=s[i]+" ";//выводим его в ошибку
						 flag=true;
						 korrekt=false; //выражение не корректным
					 }
				 }
				 if (flag) {  //если были недопустимые символы
					 this->error->Text+="  недопустимые символы";
				 }
				 int *mem;
				 mem = new int [s->Length]; //память под стек
				 stack st(mem,s->Length);
				 int tmp1;
				 flag = false;
				 for (i=0;i<s->Length;i++){
					 if (s[i]=='(') {st.Put(i);}//открывающуюся скобку ложим в стек
					 if (s[i]==')') {tmp1=st.Get();}//вынимаем из стека
					 if (st.GetErrCode()==ERR) {//если при вынимании стек был пустой
						this->error->Text+=" \n"+"неправильно расставлены скобки! "+"("+i.ToString()+")";
						flag=true; //флаг для того чтобы не выводить два раза ошибку в скобках
						korrekt=false;
						break;
					 }
				 }
				 if ((!flag)&&(!st.IsEmpty())){//если стек не пуст по окончании проверки строки и ошибка еще не выводилась
					tmp1=st.See();
					this->error->Text+=" \n"+"неправильно расставлены скобки! "+"("+tmp1.ToString()+")";
					korrekt=false;
				 }
				 flag = false;
				 st.SetMem(mem,s->Length);
				 for (i=0;i<s->Length;i++){//аналогичная проверка с фигурными скобками
					 if (s[i]=='{') {st.Put(i);}
					 if (s[i]=='}') {tmp1=st.Get();}
					 if (st.GetErrCode()==ERR) {
						this->error->Text+=" \n"+"неправильно расставлены фигурные скобки! "+"("+i.ToString()+")";
						flag=true;
						korrekt=false;
						break;
					 }
				 }
				 if ((!flag)&&(!st.IsEmpty())){
					tmp1=st.See();
					this->error->Text+=" \n"+"неправильно расставлены фигурные скобки! "+"("+tmp1.ToString()+")";
					korrekt=false;
				 }
				 String ^num="1234567890";
				 for (i=0;i<s->Length;i++)
					 if ((s[i]==',')&&((i==0)||(i==s->Length-1)||(num->IndexOf(s[i-1])==-1)||(num->IndexOf(s[i+1])==-1))){
						korrekt=false;
						this->error->Text+="\n"+"неправильно поставлен разделитель целой и дробной частей"+"("+i.ToString()+")";
						break;
					 }
				 if (korrekt&&s!=""){ //если выражение прошло проверки и не пустое
					 if (s[0]!='{') {this->attention->Text="Основное выражение тоже нужно заключать в фигурные скобки!";}
					 st.SetMem(mem,s->Length);//обновляем стек
					 for (i=0; i<s->Length; i++){
						 if (s[i]=='{') {st.Put(i);}//запоминаем позицию открытия скобки
						 if (s[i]=='}') {
							 this->rezult->Text+=s->Substring(st.See(),i-st.See()+1)+" = "; //выводим выражение
							 sdelat(s->Substring(st.See(),i-st.Get()+1)); //считаем выражение, при подсчете выводим постфиксную запись и результат
							 this->rezult->Text+="\n";
						 }
						
					}
					
				}
				}
				 
				
			 private: System::Void Help_Click(System::Object^  sender, System::EventArgs^  e) {
						  this->error->Text="";//очищаем лшибку и результат
						  this->rezult->Text="";
						  this->attention->Text="";//и предупреждение
						  this->Info->Visible=true;//показываем справку
					  }
};

};


