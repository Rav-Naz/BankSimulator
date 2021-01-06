#pragma once
#include <iostream>

#include "MyForm3.h"
#include "MyForm2.h"
#include "MyForm1.h"

namespace projekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{

	public:
		System::Windows::Forms::Form^ loginForm;
		MyForm1(System::Windows::Forms::Form^ login)
		{
			loginForm = login;
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ rachunkiComboBox;
	protected:
	private: System::Windows::Forms::Button^ wylogujBtn;
	private: System::Windows::Forms::Label^ userIdLabel;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ kosztyMiesieczneLabel;
	private: System::Windows::Forms::Label^ oprocentowanieLabel;
	private: System::Windows::Forms::Label^ rodzajRachunkuLabel;
	private: System::Windows::Forms::Button^ zlecPrzelewBtn;
	private: System::Windows::Forms::Button^ limitMiesiecznyBtn;
	private: System::Windows::Forms::Button^ limitDziennyBtn;
	private: System::Windows::Forms::TextBox^ limitMiesiecznyTextBox;
	private: System::Windows::Forms::TextBox^ limitDziennyTextBox;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ saldoLabel;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::ListView^ historiaPrzelewowListView;
	private: System::Windows::Forms::ColumnHeader^ Rodzaj;
	private: System::Windows::Forms::ColumnHeader^ numerKonta;
	private: System::Windows::Forms::ColumnHeader^ kwota;
	private: System::Windows::Forms::ColumnHeader^ tytul;
	private: System::Windows::Forms::ColumnHeader^ data;


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
			this->rachunkiComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->wylogujBtn = (gcnew System::Windows::Forms::Button());
			this->userIdLabel = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->historiaPrzelewowListView = (gcnew System::Windows::Forms::ListView());
			this->Rodzaj = (gcnew System::Windows::Forms::ColumnHeader());
			this->numerKonta = (gcnew System::Windows::Forms::ColumnHeader());
			this->kwota = (gcnew System::Windows::Forms::ColumnHeader());
			this->tytul = (gcnew System::Windows::Forms::ColumnHeader());
			this->data = (gcnew System::Windows::Forms::ColumnHeader());
			this->kosztyMiesieczneLabel = (gcnew System::Windows::Forms::Label());
			this->oprocentowanieLabel = (gcnew System::Windows::Forms::Label());
			this->rodzajRachunkuLabel = (gcnew System::Windows::Forms::Label());
			this->zlecPrzelewBtn = (gcnew System::Windows::Forms::Button());
			this->limitMiesiecznyBtn = (gcnew System::Windows::Forms::Button());
			this->limitDziennyBtn = (gcnew System::Windows::Forms::Button());
			this->limitMiesiecznyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->limitDziennyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->saldoLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// rachunkiComboBox
			// 
			this->rachunkiComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->rachunkiComboBox->FormattingEnabled = true;
			this->rachunkiComboBox->Location = System::Drawing::Point(13, 17);
			this->rachunkiComboBox->Name = L"rachunkiComboBox";
			this->rachunkiComboBox->Size = System::Drawing::Size(595, 21);
			this->rachunkiComboBox->Sorted = true;
			this->rachunkiComboBox->TabIndex = 0;
			this->rachunkiComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm1::comboBox1_SelectedIndexChanged);
			// 
			// wylogujBtn
			// 
			this->wylogujBtn->Location = System::Drawing::Point(815, 12);
			this->wylogujBtn->Name = L"wylogujBtn";
			this->wylogujBtn->Size = System::Drawing::Size(117, 32);
			this->wylogujBtn->TabIndex = 1;
			this->wylogujBtn->Text = L"Wyloguj";
			this->wylogujBtn->UseVisualStyleBackColor = true;
			this->wylogujBtn->Click += gcnew System::EventHandler(this, &MyForm1::wylogujBtn_Click);
			// 
			// userIdLabel
			// 
			this->userIdLabel->AutoSize = true;
			this->userIdLabel->Location = System::Drawing::Point(710, 16);
			this->userIdLabel->Name = L"userIdLabel";
			this->userIdLabel->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->userIdLabel->Size = System::Drawing::Size(79, 13);
			this->userIdLabel->TabIndex = 2;
			this->userIdLabel->Text = L"U¿ytkownik ID:";
			this->userIdLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->historiaPrzelewowListView);
			this->groupBox1->Controls->Add(this->kosztyMiesieczneLabel);
			this->groupBox1->Controls->Add(this->oprocentowanieLabel);
			this->groupBox1->Controls->Add(this->rodzajRachunkuLabel);
			this->groupBox1->Controls->Add(this->zlecPrzelewBtn);
			this->groupBox1->Controls->Add(this->limitMiesiecznyBtn);
			this->groupBox1->Controls->Add(this->limitDziennyBtn);
			this->groupBox1->Controls->Add(this->limitMiesiecznyTextBox);
			this->groupBox1->Controls->Add(this->limitDziennyTextBox);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->saldoLabel);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 50);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(920, 297);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			// 
			// historiaPrzelewowListView
			// 
			this->historiaPrzelewowListView->AllowColumnReorder = true;
			this->historiaPrzelewowListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->Rodzaj,
					this->numerKonta, this->kwota, this->tytul, this->data
			});
			this->historiaPrzelewowListView->HideSelection = false;
			this->historiaPrzelewowListView->Location = System::Drawing::Point(427, 32);
			this->historiaPrzelewowListView->Name = L"historiaPrzelewowListView";
			this->historiaPrzelewowListView->Size = System::Drawing::Size(487, 255);
			this->historiaPrzelewowListView->TabIndex = 20;
			this->historiaPrzelewowListView->UseCompatibleStateImageBehavior = false;
			this->historiaPrzelewowListView->View = System::Windows::Forms::View::Details;
			// 
			// Rodzaj
			// 
			this->Rodzaj->Text = L"Rodzaj";
			this->Rodzaj->Width = 78;
			// 
			// numerKonta
			// 
			this->numerKonta->Text = L"Numer konta";
			this->numerKonta->Width = 106;
			// 
			// kwota
			// 
			this->kwota->Text = L"Kwota";
			this->kwota->Width = 88;
			// 
			// tytul
			// 
			this->tytul->Text = L"Tytu³";
			this->tytul->Width = 119;
			// 
			// data
			// 
			this->data->Text = L"Data";
			this->data->Width = 105;
			// 
			// kosztyMiesieczneLabel
			// 
			this->kosztyMiesieczneLabel->AutoSize = true;
			this->kosztyMiesieczneLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->kosztyMiesieczneLabel->Location = System::Drawing::Point(106, 141);
			this->kosztyMiesieczneLabel->Name = L"kosztyMiesieczneLabel";
			this->kosztyMiesieczneLabel->Size = System::Drawing::Size(0, 16);
			this->kosztyMiesieczneLabel->TabIndex = 19;
			// 
			// oprocentowanieLabel
			// 
			this->oprocentowanieLabel->AutoSize = true;
			this->oprocentowanieLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->oprocentowanieLabel->Location = System::Drawing::Point(106, 102);
			this->oprocentowanieLabel->Name = L"oprocentowanieLabel";
			this->oprocentowanieLabel->Size = System::Drawing::Size(0, 16);
			this->oprocentowanieLabel->TabIndex = 18;
			// 
			// rodzajRachunkuLabel
			// 
			this->rodzajRachunkuLabel->AutoSize = true;
			this->rodzajRachunkuLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->rodzajRachunkuLabel->Location = System::Drawing::Point(106, 63);
			this->rodzajRachunkuLabel->Name = L"rodzajRachunkuLabel";
			this->rodzajRachunkuLabel->Size = System::Drawing::Size(0, 16);
			this->rodzajRachunkuLabel->TabIndex = 17;
			// 
			// zlecPrzelewBtn
			// 
			this->zlecPrzelewBtn->Enabled = false;
			this->zlecPrzelewBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->zlecPrzelewBtn->Location = System::Drawing::Point(13, 255);
			this->zlecPrzelewBtn->Name = L"zlecPrzelewBtn";
			this->zlecPrzelewBtn->Size = System::Drawing::Size(394, 32);
			this->zlecPrzelewBtn->TabIndex = 16;
			this->zlecPrzelewBtn->Text = L"Zleæ przelew";
			this->zlecPrzelewBtn->UseVisualStyleBackColor = true;
			this->zlecPrzelewBtn->Click += gcnew System::EventHandler(this, &MyForm1::zlecPrzelewBtn_Click);
			// 
			// limitMiesiecznyBtn
			// 
			this->limitMiesiecznyBtn->Location = System::Drawing::Point(250, 213);
			this->limitMiesiecznyBtn->Name = L"limitMiesiecznyBtn";
			this->limitMiesiecznyBtn->Size = System::Drawing::Size(157, 22);
			this->limitMiesiecznyBtn->TabIndex = 15;
			this->limitMiesiecznyBtn->Text = L"Zmieñ";
			this->limitMiesiecznyBtn->UseVisualStyleBackColor = true;
			this->limitMiesiecznyBtn->Click += gcnew System::EventHandler(this, &MyForm1::limitMiesiecznyBtn_Click);
			// 
			// limitDziennyBtn
			// 
			this->limitDziennyBtn->Location = System::Drawing::Point(250, 177);
			this->limitDziennyBtn->Name = L"limitDziennyBtn";
			this->limitDziennyBtn->Size = System::Drawing::Size(157, 22);
			this->limitDziennyBtn->TabIndex = 14;
			this->limitDziennyBtn->Text = L"Zmieñ";
			this->limitDziennyBtn->UseVisualStyleBackColor = true;
			this->limitDziennyBtn->Click += gcnew System::EventHandler(this, &MyForm1::limitDziennyBtn_Click);
			// 
			// limitMiesiecznyTextBox
			// 
			this->limitMiesiecznyTextBox->Enabled = false;
			this->limitMiesiecznyTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->limitMiesiecznyTextBox->Location = System::Drawing::Point(109, 213);
			this->limitMiesiecznyTextBox->Name = L"limitMiesiecznyTextBox";
			this->limitMiesiecznyTextBox->Size = System::Drawing::Size(135, 22);
			this->limitMiesiecznyTextBox->TabIndex = 13;
			// 
			// limitDziennyTextBox
			// 
			this->limitDziennyTextBox->Enabled = false;
			this->limitDziennyTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->limitDziennyTextBox->Location = System::Drawing::Point(109, 177);
			this->limitDziennyTextBox->Name = L"limitDziennyTextBox";
			this->limitDziennyTextBox->Size = System::Drawing::Size(135, 22);
			this->limitDziennyTextBox->TabIndex = 12;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(18, 218);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(85, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Limit miesiêczny:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(33, 182);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Limit dzienny:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(10, 143);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Koszty miesiêczne:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(18, 104);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Oprocentowanie:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 65);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Rodzaj rachunku:";
			// 
			// saldoLabel
			// 
			this->saldoLabel->AutoSize = true;
			this->saldoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->saldoLabel->Location = System::Drawing::Point(168, 16);
			this->saldoLabel->Name = L"saldoLabel";
			this->saldoLabel->Size = System::Drawing::Size(0, 31);
			this->saldoLabel->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(104, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 25);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Saldo:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(424, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Historia przelewów";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->rachunkiComboBox);
			this->groupBox2->Location = System::Drawing::Point(12, 6);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(624, 47);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Rachunek";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(944, 353);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->userIdLabel);
			this->Controls->Add(this->wylogujBtn);
			this->Name = L"MyForm1";
			this->Text = L"Panel klienta";
			this->Activated += gcnew System::EventHandler(this, &MyForm1::MyForm1_Activated);
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (rachunkiComboBox->Text == "Utwórz nowy...") {
			this->Hide();
			MyForm2^ clientPanel = gcnew MyForm2(this);
			auto result = clientPanel->ShowDialog();
		}
		else {
			std::list<Rachunek>::iterator iter = API::Get().listaRachunkow.begin();
			std::advance(iter, rachunkiComboBox->SelectedIndex);
			Rachunek aktualnyRachunek = *iter;
			std::list<RodzajRachunku>::iterator iter2 = API::Get().listaRodzajiRachunkow.begin();
			std::advance(iter2, (aktualnyRachunek.RodzajID() - 1));
			RodzajRachunku aktualnyRodzajRachunku = *iter2;
			std::list<Waluta>::iterator iter3 = API::Get().listaWalut.begin();
			std::advance(iter3, (aktualnyRachunek.WalutaID() - 1));
			Waluta aktualnaWaluta = *iter3;
			API::Get().PobierzOperacje(aktualnyRachunek);
			historiaPrzelewowListView->Items->Clear();
			std::list<Operacja>::iterator iter4 = API::Get().listaOperacji.begin();
			for (iter4; iter4 != API::Get().listaOperacji.end(); ++iter4) {
				Operacja aktualnaOperacja = *iter4;
				ListViewItem^ item = gcnew ListViewItem(((aktualnaOperacja.NumerNadawcy() == aktualnyRachunek.Numer()) ? "Obci¹¿enie" : "Uznanie"), 0);
				std::string konto = ((aktualnaOperacja.NumerNadawcy() == aktualnyRachunek.Numer()) ? aktualnaOperacja.NumerOdbiorcy() : aktualnaOperacja.NumerNadawcy());
				item->SubItems->Add(gcnew String(konto.c_str()));
				std::string kwota = std::to_string(aktualnaOperacja.Kwota());
				kwota = (kwota.substr(0, (kwota.length() - 4)) + " " + aktualnaWaluta.Nazwa());
				item->SubItems->Add(gcnew String(kwota.c_str()));
				item->SubItems->Add(gcnew String(aktualnaOperacja.Tytul().c_str()));
				item->SubItems->Add(gcnew String(aktualnaOperacja.Data().c_str()));
				historiaPrzelewowListView->Items->Add(item);
			}
			std::string saldo = std::to_string(aktualnyRachunek.Saldo());
			saldoLabel->Text = gcnew String((saldo.substr(0, (saldo.length() - 4)) + " " + aktualnaWaluta.Nazwa()).c_str());
			rodzajRachunkuLabel->Text = gcnew String(aktualnyRodzajRachunku.Nazwa().c_str());
			std::string oprocentowanie = std::to_string(aktualnyRodzajRachunku.Oprocentowanie());
			oprocentowanieLabel->Text = gcnew String((oprocentowanie.substr(0, (oprocentowanie.length() - 4)) + " %").c_str());
			std::string kosztyMiesieczne = std::to_string(aktualnyRodzajRachunku.KosztyMiesieczne());
			kosztyMiesieczneLabel->Text = gcnew String((kosztyMiesieczne.substr(0, (kosztyMiesieczne.length() - 4)) + " " + aktualnaWaluta.Nazwa()).c_str());
			std::string limitDzienny = std::to_string(aktualnyRachunek.LimitDzienny());
			limitDziennyTextBox->Text = gcnew String((limitDzienny.substr(0, (limitDzienny.length() - 4)) + " " + aktualnaWaluta.Nazwa()).c_str());
			std::string limitMiesieczny = std::to_string(aktualnyRachunek.LimitMiesieczny());
			limitMiesiecznyTextBox->Text = gcnew String((limitMiesieczny.substr(0, (limitMiesieczny.length() - 4)) + " " + aktualnaWaluta.Nazwa()).c_str());
			limitDziennyBtn->Enabled = true;
			limitMiesiecznyBtn->Enabled = true;
			limitDziennyTextBox->Enabled = false;
			limitMiesiecznyTextBox->Enabled = false;
			limitDziennyBtn->Text = "Zmieñ";
			limitMiesiecznyBtn->Text = "Zmieñ";
			zlecPrzelewBtn->Enabled = true;
		}
	}
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
		API::Get().PobierzWaluty();
		API::Get().PobierzRodzajeRachunku();
		userIdLabel->Text = "U¿ytkownik ID:\n" + gcnew String(API::Get().uzytkownik->KlientID().c_str());
	}
	private: System::Void MyForm1_Activated(System::Object^ sender, System::EventArgs^ e) {
		API::Get().PobierzListeRachunkow();
		rachunkiComboBox->Items->Clear();
		historiaPrzelewowListView->Items->Clear();
		std::list<Rachunek>::iterator iter = API::Get().listaRachunkow.begin();
		for (iter; iter != API::Get().listaRachunkow.end(); ++iter) {
			Rachunek rachunek = *iter;
			auto managed = gcnew String((rachunek.Numer() + "  |  " + rachunek.Nazwa()).c_str());
			rachunkiComboBox->Items->Add(managed);
		}
		rachunkiComboBox->Items->Add("Utwórz nowy...");
		saldoLabel->Text = "";
		rodzajRachunkuLabel->Text = "";
		oprocentowanieLabel->Text = "";
		kosztyMiesieczneLabel->Text = "";
		limitDziennyTextBox->Text = "";
		limitMiesiecznyTextBox->Text = "";
		limitDziennyBtn->Enabled = false;
		limitMiesiecznyBtn->Enabled = false;
		limitDziennyTextBox->Enabled = false;
		limitMiesiecznyTextBox->Enabled = false;
		limitDziennyBtn->Text = "Zmieñ";
		limitMiesiecznyBtn->Text = "Zmieñ";
		zlecPrzelewBtn->Enabled = false;
	}
	private: System::Void wylogujBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->loginForm->Show();
		this->Hide();
	}
	private: System::Void limitDziennyBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		limitDziennyTextBox->Enabled = !limitDziennyTextBox->Enabled;
		if (limitDziennyTextBox->Enabled) {
			limitDziennyBtn->Text = "Zapisz";
		}
		else
		{
			std::list<Rachunek>::iterator iter = API::Get().listaRachunkow.begin();
			std::advance(iter, rachunkiComboBox->SelectedIndex);
			Rachunek aktualnyRachunek = *iter;
			std::list<Waluta>::iterator iter3 = API::Get().listaWalut.begin();
			std::advance(iter3, (aktualnyRachunek.WalutaID() - 1));
			Waluta aktualnaWaluta = *iter3;
			char* end;
			msclr::interop::marshal_context context;
			std::string nowyLimit = context.marshal_as<std::string>(this->limitDziennyTextBox->Text);
			float nowy = std::strtof(nowyLimit.c_str(), &end);
			if (nowy < 0.0f || nowy > 10000.0f) {
				::MessageBox(0, L"WprowadŸ wartoœæ z przedzia³u 0 - 10 000", L"Informacja", MB_ICONINFORMATION);
				return;
			}
			aktualnyRachunek.AktualizujLimitDzienny(nowy);
			std::string a = std::to_string(aktualnyRachunek.LimitDzienny());
			limitDziennyTextBox->Text = gcnew String((a.substr(0, (a.length() - 4)) + " " + aktualnaWaluta.Nazwa()).c_str());
			limitDziennyBtn->Text = "Zmieñ";
		}
	}
	private: System::Void limitMiesiecznyBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->limitMiesiecznyTextBox->Enabled = !this->limitMiesiecznyTextBox->Enabled;
		if (this->limitMiesiecznyTextBox->Enabled) {
			this->limitMiesiecznyBtn->Text = "Zapisz";
		}
		else
		{
			std::list<Rachunek>::iterator iter = API::Get().listaRachunkow.begin();
			std::advance(iter, rachunkiComboBox->SelectedIndex);
			Rachunek aktualnyRachunek = *iter;
			std::list<Waluta>::iterator iter3 = API::Get().listaWalut.begin();
			std::advance(iter3, (aktualnyRachunek.WalutaID() - 1));
			Waluta aktualnaWaluta = *iter3;
			char* end;
			msclr::interop::marshal_context context;
			std::string nowyLimit = context.marshal_as<std::string>(this->limitMiesiecznyTextBox->Text);
			float nowy = std::strtof(nowyLimit.c_str(), &end);
			if (nowy < 0.0f || nowy > 50000.0f) {
				::MessageBox(0, L"WprowadŸ wartoœæ z przedzia³u 0 - 50 000", L"Informacja", MB_ICONINFORMATION);
				return;
			}
			aktualnyRachunek.AktualizujLimitMiesieczny(nowy);
			std::string a = std::to_string(aktualnyRachunek.LimitMiesieczny());
			limitMiesiecznyTextBox->Text = gcnew String((a.substr(0, (a.length() - 4)) + " " + aktualnaWaluta.Nazwa()).c_str());
			this->limitMiesiecznyBtn->Text = "Zmieñ";
		}
	}
	private: System::Void zlecPrzelewBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		std::list<Rachunek>::iterator iter = API::Get().listaRachunkow.begin();
		std::advance(iter, rachunkiComboBox->SelectedIndex);
		Rachunek aktualnyRachunek = *iter;
		std::list<Waluta>::iterator iter3 = API::Get().listaWalut.begin();
		std::advance(iter3, (aktualnyRachunek.WalutaID() - 1));
		Waluta aktualnaWaluta = *iter3;
		this->Hide();
		MyForm3^ przelewPanel = gcnew MyForm3(this, &aktualnyRachunek, &aktualnaWaluta);
		auto result = przelewPanel->ShowDialog();
	}
};
}
