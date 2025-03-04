#pragma once
#include "ContactsBook.h"
#include <msclr/marshal_cppstd.h>

namespace ContactsApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	public ref class Create_contact : public System::Windows::Forms::Form
	{
	public:
		Create_contact(void)
		{
			InitializeComponent();

		}
		Create_contact(ContactsBook &book)
		{
			// Create a pointer to the ContactsBook in order to access it in this form
			b = &book;
			InitializeComponent();

		}
	protected:
		~Create_contact()
		{
			b = nullptr;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ fnameLabel;
	protected:

	private: System::Windows::Forms::Label^ heading;
	public: System::Windows::Forms::Panel^ fname;

	private:
		ContactsBook* b;
	

	private: System::Windows::Forms::PictureBox^ contactImage;
	public: System::Windows::Forms::Panel^ contact_no;

	private:
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Panel^ email;


	private:
	private: System::Windows::Forms::Label^ number;
	public: System::Windows::Forms::Panel^ lname;


	private:	private: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::Panel^ street_no;
	public: System::Windows::Forms::Panel^ house_no;
	
	public: System::Windows::Forms::Panel^ country;
	private:

	private:


	private: System::Windows::Forms::Label^ label3;
	public:
	public: System::Windows::Forms::Panel^ city;
	private:
	private: System::Windows::Forms::TextBox^ search_field;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox4;
	public: System::Windows::Forms::Panel^ panel2;

	private: System::Windows::Forms::Label^ label4;
	public: System::Windows::Forms::Panel^ panel3;
	private:
	private: System::Windows::Forms::Label^ label5;
	public: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ add_button;

	private:
		System::ComponentModel::Container^ components;
		bool is_added = false;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::TextBox^ textBox2;
			System::Windows::Forms::TextBox^ textBox3;
			System::Windows::Forms::TextBox^ textBox;
			System::Windows::Forms::TextBox^ countryBox;
			System::Windows::Forms::TextBox^ cityBox;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Create_contact::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->search_field = (gcnew System::Windows::Forms::TextBox());
			this->fnameLabel = (gcnew System::Windows::Forms::Label());
			this->heading = (gcnew System::Windows::Forms::Label());
			this->fname = (gcnew System::Windows::Forms::Panel());
			this->contactImage = (gcnew System::Windows::Forms::PictureBox());
			this->contact_no = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->email = (gcnew System::Windows::Forms::Panel());
			this->number = (gcnew System::Windows::Forms::Label());
			this->lname = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->street_no = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->house_no = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->country = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->city = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->add_button = (gcnew System::Windows::Forms::Button());
			textBox2 = (gcnew System::Windows::Forms::TextBox());
			textBox3 = (gcnew System::Windows::Forms::TextBox());
			textBox = (gcnew System::Windows::Forms::TextBox());
			countryBox = (gcnew System::Windows::Forms::TextBox());
			cityBox = (gcnew System::Windows::Forms::TextBox());
			this->fname->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->contactImage))->BeginInit();
			this->contact_no->SuspendLayout();
			this->email->SuspendLayout();
			this->lname->SuspendLayout();
			this->street_no->SuspendLayout();
			this->house_no->SuspendLayout();
			this->country->SuspendLayout();
			this->city->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.249999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(12, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(248, 14);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			textBox2->BackColor = System::Drawing::Color::AliceBlue;
			textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			textBox2->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.249999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			textBox2->ForeColor = System::Drawing::Color::Black;
			textBox2->Location = System::Drawing::Point(12, 3);
			textBox2->Name = L"textBox2";
			textBox2->Size = System::Drawing::Size(248, 14);
			textBox2->TabIndex = 0;
			// 
			// textBox3
			// 
			textBox3->BackColor = System::Drawing::Color::AliceBlue;
			textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			textBox3->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.249999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			textBox3->ForeColor = System::Drawing::Color::Black;
			textBox3->Location = System::Drawing::Point(3, 7);
			textBox3->Name = L"textBox3";
			textBox3->Size = System::Drawing::Size(151, 14);
			textBox3->TabIndex = 0;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.249999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->ForeColor = System::Drawing::Color::Black;
			this->textBox4->Location = System::Drawing::Point(3, 7);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(151, 14);
			this->textBox4->TabIndex = 0;
			// 
			// textBox
			// 
			textBox->BackColor = System::Drawing::Color::AliceBlue;
			textBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			textBox->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.249999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			textBox->ForeColor = System::Drawing::Color::Black;
			textBox->Location = System::Drawing::Point(3, 7);
			textBox->Name = L"textBox";
			textBox->Size = System::Drawing::Size(151, 14);
			textBox->TabIndex = 0;
			// 
			// countryBox
			// 
			countryBox->BackColor = System::Drawing::Color::AliceBlue;
			countryBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			countryBox->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.249999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			countryBox->ForeColor = System::Drawing::Color::Black;
			countryBox->Location = System::Drawing::Point(3, 7);
			countryBox->Name = L"countryBox";
			countryBox->Size = System::Drawing::Size(151, 14);
			countryBox->TabIndex = 0;
			// 
			// cityBox
			// 
			cityBox->BackColor = System::Drawing::Color::AliceBlue;
			cityBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			cityBox->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.249999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			cityBox->ForeColor = System::Drawing::Color::Black;
			cityBox->Location = System::Drawing::Point(3, 7);
			cityBox->Name = L"cityBox";
			cityBox->Size = System::Drawing::Size(151, 14);
			cityBox->TabIndex = 0;
			// 
			// search_field
			// 
			this->search_field->BackColor = System::Drawing::Color::AliceBlue;
			this->search_field->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->search_field->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.249999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->search_field->ForeColor = System::Drawing::Color::Black;
			this->search_field->Location = System::Drawing::Point(3, 7);
			this->search_field->Name = L"search_field";
			this->search_field->Size = System::Drawing::Size(151, 14);
			this->search_field->TabIndex = 0;
			// 
			// fnameLabel
			// 
			this->fnameLabel->AutoSize = true;
			this->fnameLabel->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fnameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->fnameLabel->Location = System::Drawing::Point(30, 87);
			this->fnameLabel->Name = L"fnameLabel";
			this->fnameLabel->Size = System::Drawing::Size(74, 16);
			this->fnameLabel->TabIndex = 0;
			this->fnameLabel->Text = L"First Name";
			// 
			// heading
			// 
			this->heading->AutoSize = true;
			this->heading->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->heading->Location = System::Drawing::Point(28, 29);
			this->heading->Name = L"heading";
			this->heading->Size = System::Drawing::Size(161, 26);
			this->heading->TabIndex = 1;
			this->heading->Text = L"Create Contact";
			// 
			// fname
			// 
			this->fname->BackColor = System::Drawing::Color::AliceBlue;
			this->fname->Controls->Add(this->search_field);
			this->fname->Location = System::Drawing::Point(33, 106);
			this->fname->Name = L"fname";
			this->fname->Size = System::Drawing::Size(157, 24);
			this->fname->TabIndex = 3;
			// 
			// contactImage
			// 
			this->contactImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"contactImage.Image")));
			this->contactImage->Location = System::Drawing::Point(417, 85);
			this->contactImage->Name = L"contactImage";
			this->contactImage->Size = System::Drawing::Size(255, 255);
			this->contactImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->contactImage->TabIndex = 4;
			this->contactImage->TabStop = false;
			// 
			// contact_no
			// 
			this->contact_no->BackColor = System::Drawing::Color::AliceBlue;
			this->contact_no->Controls->Add(this->textBox1);
			this->contact_no->Location = System::Drawing::Point(33, 162);
			this->contact_no->Name = L"contact_no";
			this->contact_no->Size = System::Drawing::Size(325, 24);
			this->contact_no->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Location = System::Drawing::Point(198, 87);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Last Name";
			// 
			// email
			// 
			this->email->BackColor = System::Drawing::Color::AliceBlue;
			this->email->Controls->Add(textBox2);
			this->email->Location = System::Drawing::Point(33, 218);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(325, 24);
			this->email->TabIndex = 7;
			// 
			// number
			// 
			this->number->AutoSize = true;
			this->number->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->number->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->number->Location = System::Drawing::Point(33, 144);
			this->number->Name = L"number";
			this->number->Size = System::Drawing::Size(75, 16);
			this->number->TabIndex = 6;
			this->number->Text = L"Contact no";
			// 
			// lname
			// 
			this->lname->BackColor = System::Drawing::Color::AliceBlue;
			this->lname->Controls->Add(textBox3);
			this->lname->Location = System::Drawing::Point(201, 106);
			this->lname->Name = L"lname";
			this->lname->Size = System::Drawing::Size(157, 24);
			this->lname->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(33, 202);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 16);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Email";
			// 
			// street_no
			// 
			this->street_no->BackColor = System::Drawing::Color::AliceBlue;
			this->street_no->Controls->Add(this->textBox4);
			this->street_no->Location = System::Drawing::Point(201, 293);
			this->street_no->Name = L"street_no";
			this->street_no->Size = System::Drawing::Size(157, 24);
			this->street_no->TabIndex = 11;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label3->Location = System::Drawing::Point(198, 274);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 16);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Street no.";
			// 
			// house_no
			// 
			this->house_no->BackColor = System::Drawing::Color::AliceBlue;
			this->house_no->Controls->Add(textBox);
			this->house_no->Location = System::Drawing::Point(33, 293);
			this->house_no->Name = L"house_no";
			this->house_no->Size = System::Drawing::Size(157, 24);
			this->house_no->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label4->Location = System::Drawing::Point(30, 274);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 16);
			this->label4->TabIndex = 9;
			this->label4->Text = L"House no.";
			// 
			// country
			// 
			this->country->BackColor = System::Drawing::Color::AliceBlue;
			this->country->Controls->Add(countryBox);
			this->country->Location = System::Drawing::Point(204, 352);
			this->country->Name = L"country";
			this->country->Size = System::Drawing::Size(157, 24);
			this->country->TabIndex = 15;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label5->Location = System::Drawing::Point(201, 333);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(57, 16);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Country";
			// 
			// city
			// 
			this->city->BackColor = System::Drawing::Color::AliceBlue;
			this->city->Controls->Add(cityBox);
			this->city->Location = System::Drawing::Point(36, 352);
			this->city->Name = L"city";
			this->city->Size = System::Drawing::Size(157, 24);
			this->city->TabIndex = 14;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label6->Location = System::Drawing::Point(33, 333);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(31, 16);
			this->label6->TabIndex = 13;
			this->label6->Text = L"City";
			// 
			// add_button
			// 
			this->add_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->add_button->BackColor = System::Drawing::Color::RoyalBlue;
			this->add_button->FlatAppearance->BorderColor = System::Drawing::Color::DarkCyan;
			this->add_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add_button->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add_button->ForeColor = System::Drawing::Color::White;
			this->add_button->Location = System::Drawing::Point(36, 419);
			this->add_button->Name = L"add_button";
			this->add_button->Padding = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->add_button->Size = System::Drawing::Size(117, 33);
			this->add_button->TabIndex = 17;
			this->add_button->Text = L"Create";
			this->add_button->UseVisualStyleBackColor = false;
			this->add_button->Click += gcnew System::EventHandler(this, &Create_contact::add_button_Click);
			// 
			// Create_contact
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(704, 489);
			this->Controls->Add(this->add_button);
			this->Controls->Add(this->country);
			this->Controls->Add(this->street_no);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->city);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->house_no);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lname);
			this->Controls->Add(this->email);
			this->Controls->Add(this->number);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->contactImage);
			this->Controls->Add(this->fname);
			this->Controls->Add(this->heading);
			this->Controls->Add(this->fnameLabel);
			this->Controls->Add(this->contact_no);
			this->Name = L"Create_contact";
			this->Text = L"Create_contact";
			this->Load += gcnew System::EventHandler(this, &Create_contact::Create_contact_Load);
			this->fname->ResumeLayout(false);
			this->fname->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->contactImage))->EndInit();
			this->contact_no->ResumeLayout(false);
			this->contact_no->PerformLayout();
			this->email->ResumeLayout(false);
			this->email->PerformLayout();
			this->lname->ResumeLayout(false);
			this->lname->PerformLayout();
			this->street_no->ResumeLayout(false);
			this->street_no->PerformLayout();
			this->house_no->ResumeLayout(false);
			this->house_no->PerformLayout();
			this->country->ResumeLayout(false);
			this->country->PerformLayout();
			this->city->ResumeLayout(false);
			this->city->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	bool isAdded()
	{
		return is_added;
	}

private: System::Void Create_contact_Load(System::Object^ sender, System::EventArgs^ e) {
}

	   System::Void Create_contact::add_button_Click(System::Object^ sender, System::EventArgs^ e)
	   {
		   // Retrieve input values
		   String^ firstName = fname->Controls["search_field"]->Text;
		   String^ lastName = lname->Controls["textBox3"]->Text;
		   String^ email_ = email->Controls["textBox2"]->Text;
		   String^ contactNo = contact_no->Controls["textBox1"]->Text;
		   Address* add = new Address(marshal_as<std::string>(house_no->Controls["textBox"]->Text), marshal_as<std::string>(street_no->Controls["textBox4"]->Text), marshal_as<std::string>(city->Controls["cityBox"]->Text), marshal_as<std::string>(country->Controls["countryBox"]->Text));

		   // Create a new Contact object
		   Contact newContact(marshal_as<std::string>(firstName), marshal_as<std::string>(lastName), marshal_as<std::string>(contactNo), marshal_as<std::string>(email_), add);

		   // Add the new contact to the ContactsBook
		   b->add_contact(newContact);
		   MessageBox::Show("Contact added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		   is_added = true;
		   fname->Controls["search_field"]->Text = "";
		   lname->Controls["textBox3"]->Text = "";
		   contact_no->Controls["textBox1"]->Text = "";
		   email->Controls["textBox2"]->Text = "";
		   house_no->Controls["textBox"]->Text = "";
		   street_no->Controls["textBox4"]->Text = "";
		   city->Controls["cityBox"]->Text = "";
		   country->Controls["countryBox"]->Text = "";
		   this->Close();


	   }

};
}
