#pragma once
#include "ContactList.h"
#include "History.h"

namespace ContactsApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Home
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
	public:
		Home(void)
		{
			cl = gcnew ContactList();
			history = gcnew History();
			InitializeComponent();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Contacts;
	protected:

	private: System::Windows::Forms::Button^ hist;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ heading;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
		ContactList^ cl;
		History^ history;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Home::typeid));
			this->Contacts = (gcnew System::Windows::Forms::Button());
			this->hist = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->heading = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// Contacts
			// 
			this->Contacts->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Contacts->BackColor = System::Drawing::Color::DarkCyan;
			this->Contacts->FlatAppearance->BorderColor = System::Drawing::Color::DarkCyan;
			this->Contacts->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Contacts->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Contacts->ForeColor = System::Drawing::Color::White;
			this->Contacts->Location = System::Drawing::Point(191, 368);
			this->Contacts->Name = L"Contacts";
			this->Contacts->Padding = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->Contacts->Size = System::Drawing::Size(182, 33);
			this->Contacts->TabIndex = 18;
			this->Contacts->Text = L"View Contacts";
			this->Contacts->UseVisualStyleBackColor = false;
			this->Contacts->Click += gcnew System::EventHandler(this, &Home::Contacts_Click);
			// 
			// hist
			// 
			this->hist->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->hist->BackColor = System::Drawing::Color::DarkCyan;
			this->hist->FlatAppearance->BorderColor = System::Drawing::Color::DarkCyan;
			this->hist->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->hist->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hist->ForeColor = System::Drawing::Color::White;
			this->hist->Location = System::Drawing::Point(431, 368);
			this->hist->Name = L"hist";
			this->hist->Padding = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->hist->Size = System::Drawing::Size(182, 33);
			this->hist->TabIndex = 20;
			this->hist->Text = L"Search History";
			this->hist->UseVisualStyleBackColor = false;
			this->hist->Click += gcnew System::EventHandler(this, &Home::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(278, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(256, 241);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			// 
			// heading
			// 
			this->heading->AutoSize = true;
			this->heading->Font = (gcnew System::Drawing::Font(L"Montserrat ExtraBold", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->heading->Location = System::Drawing::Point(296, 282);
			this->heading->Name = L"heading";
			this->heading->Size = System::Drawing::Size(229, 37);
			this->heading->TabIndex = 22;
			this->heading->Text = L"Contacts Book";
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(813, 441);
			this->Controls->Add(this->heading);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->hist);
			this->Controls->Add(this->Contacts);
			this->Name = L"Home";
			this->Text = L"Home";
			this->Load += gcnew System::EventHandler(this, &Home::Home_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void groups_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		history->ShowDialog();
		history->Focus();
		this->Show();
	}
	private: System::Void Contacts_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		cl->ShowDialog();
		cl->Focus();
		this->Show();
	}
	private: System::Void Home_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
