#pragma once
#include "API.h"
#include <msclr\marshal_cppstd.h>
#include "Logowanie.h"
#include "MyForm1.h"

namespace projekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ loginTextBox;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ hasloTextBox;
	private: System::Windows::Forms::Button^ zalogujBtn;




	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->loginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->hasloTextBox = (gcnew System::Windows::Forms::TextBox());
			this->zalogujBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// loginTextBox
			// 
			this->loginTextBox->Location = System::Drawing::Point(43, 57);
			this->loginTextBox->MaxLength = 6;
			this->loginTextBox->Name = L"loginTextBox";
			this->loginTextBox->Size = System::Drawing::Size(186, 20);
			this->loginTextBox->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(40, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"ID U¿ytkownika";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(40, 107);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Has³o";
			// 
			// hasloTextBox
			// 
			this->hasloTextBox->BackColor = System::Drawing::SystemColors::Window;
			this->hasloTextBox->Location = System::Drawing::Point(43, 123);
			this->hasloTextBox->Name = L"hasloTextBox";
			this->hasloTextBox->PasswordChar = '*';
			this->hasloTextBox->Size = System::Drawing::Size(186, 20);
			this->hasloTextBox->TabIndex = 2;
			// 
			// zalogujBtn
			// 
			this->zalogujBtn->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->zalogujBtn->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->zalogujBtn->ForeColor = System::Drawing::SystemColors::ControlText;
			this->zalogujBtn->Location = System::Drawing::Point(79, 178);
			this->zalogujBtn->Name = L"zalogujBtn";
			this->zalogujBtn->Size = System::Drawing::Size(113, 38);
			this->zalogujBtn->TabIndex = 4;
			this->zalogujBtn->Text = L"Zaloguj";
			this->zalogujBtn->UseVisualStyleBackColor = false;
			this->zalogujBtn->Click += gcnew System::EventHandler(this, &MyForm::zalogujBtn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(271, 257);
			this->Controls->Add(this->zalogujBtn);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->hasloTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->loginTextBox);
			this->Name = L"MyForm";
			this->Text = L"Logowanie";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void zalogujBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		
		msclr::interop::marshal_context context;
		Logowanie* logowanie = new Logowanie(context.marshal_as<std::string>(this->loginTextBox->Text), context.marshal_as<std::string>(this->hasloTextBox->Text));

		if (logowanie->Powodzenie() == 1) { //pomyœlne logowanie
			this->Hide();
			MyForm1 clientPanel;
			clientPanel.ShowDialog();
		} 
		else if (logowanie->Powodzenie() == 0) { //b³êdne has³o
			::MessageBox(0, L"Podano b³êdne has³o. Po 3 nieudanych próbach logowania, dostêp do konta zostanie czasowo zablokowany.", L"Uwaga", MB_ICONWARNING);
		}
		else if (logowanie->Powodzenie() == -1) { //brak u¿ytkownika
			::MessageBox(0, L"U¿ytkownik o podanym ID nie istnieje", L"Uwaga", MB_ICONWARNING);
		}
		else if (logowanie->Powodzenie() == -2) { //zablokowanie logowania
			::MessageBox(0, L"Mo¿liwoœæ logowania do Twojego konta zosta³a zablokowana, z powodu 3-krotnego podania b³êdnego has³a. Kolejn¹ próbê mo¿esz podj¹æ po 24 godzinach od pierwszego nieduanego logowania", L"B³¹d", MB_ICONERROR);
		}
		else {
			::MessageBox(0, L"Napotkano nieoczekiwany b³¹d. Spróbuj ponownie póŸniej", L"B³¹d", MB_ICONERROR);
		}

	}
};
}
