#pragma once
#include "Rachunek.h"
#include "Waluta.h"
#include <iostream>
namespace projekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	public:
		Rachunek* wybranyRachunek;
		Waluta* walutaRachunku;
		System::Windows::Forms::Form^ clientPanelForm;
	private: System::Windows::Forms::TextBox^ numerRachunkuTextBox;
	public:

	public:
	private: System::Windows::Forms::Label^ srodkiLbl;
	private: System::Windows::Forms::TextBox^ kwotaTextBox;

	private: System::Windows::Forms::TextBox^ tytulTextBox;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ wykonajBtn;

	private: System::Windows::Forms::Button^ wyjdzBtn;

	private: System::Windows::Forms::GroupBox^ groupBox4;
	public:
		MyForm3(System::Windows::Forms::Form^ clientPanel, Rachunek* rachunek, Waluta* waluta)
		{
			wybranyRachunek = rachunek;
			walutaRachunku = waluta;
			clientPanelForm = clientPanel;
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm3()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->wykonajBtn = (gcnew System::Windows::Forms::Button());
			this->wyjdzBtn = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->srodkiLbl = (gcnew System::Windows::Forms::Label());
			this->numerRachunkuTextBox = (gcnew System::Windows::Forms::TextBox());
			this->kwotaTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tytulTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->numerRachunkuTextBox);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(223, 50);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Numer rachunku odbiorcy";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->srodkiLbl);
			this->groupBox2->Location = System::Drawing::Point(12, 68);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(223, 50);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Dostêpne œrodki";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->kwotaTextBox);
			this->groupBox3->Location = System::Drawing::Point(12, 124);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(223, 50);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Kwota";
			// 
			// wykonajBtn
			// 
			this->wykonajBtn->Location = System::Drawing::Point(130, 240);
			this->wykonajBtn->Name = L"wykonajBtn";
			this->wykonajBtn->Size = System::Drawing::Size(105, 23);
			this->wykonajBtn->TabIndex = 3;
			this->wykonajBtn->Text = L"Wykonaj";
			this->wykonajBtn->UseVisualStyleBackColor = true;
			this->wykonajBtn->Click += gcnew System::EventHandler(this, &MyForm3::wykonajBtn_Click);
			// 
			// wyjdzBtn
			// 
			this->wyjdzBtn->Location = System::Drawing::Point(12, 240);
			this->wyjdzBtn->Name = L"wyjdzBtn";
			this->wyjdzBtn->Size = System::Drawing::Size(105, 23);
			this->wyjdzBtn->TabIndex = 4;
			this->wyjdzBtn->Text = L"WyjdŸ";
			this->wyjdzBtn->UseVisualStyleBackColor = true;
			this->wyjdzBtn->Click += gcnew System::EventHandler(this, &MyForm3::wyjdzBtn_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tytulTextBox);
			this->groupBox4->Location = System::Drawing::Point(12, 180);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(223, 50);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Tytu³";
			// 
			// srodkiLbl
			// 
			this->srodkiLbl->AutoSize = true;
			this->srodkiLbl->Location = System::Drawing::Point(85, 20);
			this->srodkiLbl->Name = L"srodkiLbl";
			this->srodkiLbl->Size = System::Drawing::Size(52, 13);
			this->srodkiLbl->TabIndex = 0;
			this->srodkiLbl->Text = L"0.00 PLN";
			this->srodkiLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox1
			// 
			this->numerRachunkuTextBox->Location = System::Drawing::Point(7, 19);
			this->numerRachunkuTextBox->Name = L"numerRachunkuTextBox";
			this->numerRachunkuTextBox->Size = System::Drawing::Size(210, 20);
			this->numerRachunkuTextBox->TabIndex = 0;
			// 
			// textBox2
			// 
			this->kwotaTextBox->Location = System::Drawing::Point(7, 19);
			this->kwotaTextBox->Name = L"kwotaTextBox";
			this->kwotaTextBox->Size = System::Drawing::Size(210, 20);
			this->kwotaTextBox->TabIndex = 0;
			// 
			// textBox3
			// 
			this->tytulTextBox->Location = System::Drawing::Point(7, 20);
			this->tytulTextBox->Name = L"tytulTextBox";
			this->tytulTextBox->Size = System::Drawing::Size(210, 20);
			this->tytulTextBox->TabIndex = 0;
			// 
			// MyForm3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(247, 280);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->wyjdzBtn);
			this->Controls->Add(this->wykonajBtn);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm3";
			this->Text = L"Zleæ przelew";
			this->Load += gcnew System::EventHandler(this, &MyForm3::MyForm3_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm3_Load(System::Object^ sender, System::EventArgs^ e) {
		Rachunek rachunek = *wybranyRachunek;
		Waluta waluta = *walutaRachunku;
		std::string saldo = std::to_string(rachunek.Saldo());
		srodkiLbl->Text = gcnew String((saldo.substr(0, (saldo.length() - 4)) + " " + waluta.Nazwa()).c_str());
	}
	private: System::Void wyjdzBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->clientPanelForm->Show();
		this->Close();
	}
	private: System::Void wykonajBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		char* end;
		msclr::interop::marshal_context context;
		std::string kwota = context.marshal_as<std::string>(this->kwotaTextBox->Text);
		kwota = kwota.substr(0, (kwota.length() - 4));
		float nowy = std::strtof(kwota.c_str(), &end);
	}
};
}
