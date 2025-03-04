#pragma once
#include "ContactsBook.h"
#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;

namespace ContactsApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Contact_details
	/// </summary>
	// Define a delegate for the button click event
	
	public ref class Contact_details : public System::Windows::Forms::Form
	{
	
	public:

		Contact_details(void)
		{
			InitializeComponent();
			
		}
		Contact_details(Contact& contact, ContactsBook &b)
		{
			bptr = &b;
			id = contact.get_contact_id();
			f_name = gcnew String((contact.get_first_name() + " " + contact.get_last_name()).c_str());
			mobile_no = gcnew String(contact.get_mobile_number().c_str());
			email_id = gcnew String(contact.get_email_address().c_str());
			house = marshal_as<String^>(contact.get_address(0).get_house());
			street = marshal_as<String^>(contact.get_address(0).get_street());
			city_ = marshal_as<String^>(contact.get_address(0).get_city());
			country_ = marshal_as<String^>(contact.get_address(0).get_country());
			deleted = false;
			
			InitializeComponent();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Contact_details()
		{
			bptr = nullptr;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ contact_img;
	private: System::Windows::Forms::Label^ full_name;
	private: System::Windows::Forms::Panel^ info;
	private: System::Windows::Forms::PictureBox^ back;
	private: System::Windows::Forms::Label^ email_label;

	private: System::Windows::Forms::Label^ contact_no_label;
	private: System::Windows::Forms::Label^ contact_id_label;

	private: System::Windows::Forms::Label^ address_label;




	private: System::Windows::Forms::Button^ delete_button;
	private: System::Windows::Forms::Label^ country_label;

	private: System::Windows::Forms::Label^ city_label;
	private: System::Windows::Forms::Label^ street_label;
	private: System::Windows::Forms::Label^ house_label;
	private: System::Windows::Forms::Label^ city;

	private: System::Windows::Forms::Label^ street_no;
	private: System::Windows::Forms::Label^ house_no;
	private: System::Windows::Forms::Label^ email;
	private: System::Windows::Forms::Label^ contact_no;
	private: System::Windows::Forms::Label^ contact_id;
	private: System::Windows::Forms::Label^ country;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		int id;
		String^ f_name;
		String^ mobile_no;
		String^ email_id;
		String^ house;
		String^ street;
		String^ city_;
		String^ country_;
		ContactsBook* bptr;
		bool deleted;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Contact_details::typeid));
			this->contact_img = (gcnew System::Windows::Forms::PictureBox());
			this->full_name = (gcnew System::Windows::Forms::Label());
			this->info = (gcnew System::Windows::Forms::Panel());
			this->country = (gcnew System::Windows::Forms::Label());
			this->city = (gcnew System::Windows::Forms::Label());
			this->street_no = (gcnew System::Windows::Forms::Label());
			this->house_no = (gcnew System::Windows::Forms::Label());
			this->email = (gcnew System::Windows::Forms::Label());
			this->contact_no = (gcnew System::Windows::Forms::Label());
			this->contact_id = (gcnew System::Windows::Forms::Label());
			this->country_label = (gcnew System::Windows::Forms::Label());
			this->city_label = (gcnew System::Windows::Forms::Label());
			this->street_label = (gcnew System::Windows::Forms::Label());
			this->house_label = (gcnew System::Windows::Forms::Label());
			this->address_label = (gcnew System::Windows::Forms::Label());
			this->email_label = (gcnew System::Windows::Forms::Label());
			this->contact_no_label = (gcnew System::Windows::Forms::Label());
			this->contact_id_label = (gcnew System::Windows::Forms::Label());
			this->back = (gcnew System::Windows::Forms::PictureBox());
			this->delete_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->contact_img))->BeginInit();
			this->info->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back))->BeginInit();
			this->SuspendLayout();
			// 
			// contact_img
			// 
			this->contact_img->BackColor = System::Drawing::SystemColors::Window;
			this->contact_img->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"contact_img.Image")));
			this->contact_img->Location = System::Drawing::Point(50, 80);
			this->contact_img->Name = L"contact_img";
			this->contact_img->Size = System::Drawing::Size(180, 180);
			this->contact_img->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->contact_img->TabIndex = 0;
			this->contact_img->TabStop = false;
			// 
			// full_name
			// 
			this->full_name->AutoSize = true;
			this->full_name->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->full_name->Location = System::Drawing::Point(84, 300);
			this->full_name->Name = L"full_name";
			this->full_name->Size = System::Drawing::Size(111, 26);
			this->full_name->TabIndex = 2;
			this->full_name->Text = L"Full Name";
			this->full_name->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// info
			// 
			this->info->BackColor = System::Drawing::Color::DarkSlateGray;
			this->info->Controls->Add(this->country);
			this->info->Controls->Add(this->city);
			this->info->Controls->Add(this->street_no);
			this->info->Controls->Add(this->house_no);
			this->info->Controls->Add(this->email);
			this->info->Controls->Add(this->contact_no);
			this->info->Controls->Add(this->contact_id);
			this->info->Controls->Add(this->country_label);
			this->info->Controls->Add(this->city_label);
			this->info->Controls->Add(this->street_label);
			this->info->Controls->Add(this->house_label);
			this->info->Controls->Add(this->address_label);
			this->info->Controls->Add(this->email_label);
			this->info->Controls->Add(this->contact_no_label);
			this->info->Controls->Add(this->contact_id_label);
			this->info->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->info->Location = System::Drawing::Point(294, 27);
			this->info->Name = L"info";
			this->info->Size = System::Drawing::Size(403, 392);
			this->info->TabIndex = 3;
			// 
			// country
			// 
			this->country->AutoSize = true;
			this->country->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->country->ForeColor = System::Drawing::Color::White;
			this->country->Location = System::Drawing::Point(128, 306);
			this->country->Name = L"country";
			this->country->Size = System::Drawing::Size(46, 16);
			this->country->TabIndex = 18;
			this->country->Text = L"House";
			// 
			// city
			// 
			this->city->AutoSize = true;
			this->city->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->city->ForeColor = System::Drawing::Color::White;
			this->city->Location = System::Drawing::Point(128, 273);
			this->city->Name = L"city";
			this->city->Size = System::Drawing::Size(46, 16);
			this->city->TabIndex = 17;
			this->city->Text = L"House";
			// 
			// street_no
			// 
			this->street_no->AutoSize = true;
			this->street_no->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->street_no->ForeColor = System::Drawing::Color::White;
			this->street_no->Location = System::Drawing::Point(128, 243);
			this->street_no->Name = L"street_no";
			this->street_no->Size = System::Drawing::Size(46, 16);
			this->street_no->TabIndex = 16;
			this->street_no->Text = L"House";
			// 
			// house_no
			// 
			this->house_no->AutoSize = true;
			this->house_no->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->house_no->ForeColor = System::Drawing::Color::White;
			this->house_no->Location = System::Drawing::Point(128, 216);
			this->house_no->Name = L"house_no";
			this->house_no->Size = System::Drawing::Size(46, 16);
			this->house_no->TabIndex = 15;
			this->house_no->Text = L"House";
			// 
			// email
			// 
			this->email->AutoSize = true;
			this->email->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->email->ForeColor = System::Drawing::Color::White;
			this->email->Location = System::Drawing::Point(160, 107);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(52, 20);
			this->email->TabIndex = 14;
			this->email->Text = L"Email:";
			// 
			// contact_no
			// 
			this->contact_no->AutoSize = true;
			this->contact_no->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->contact_no->ForeColor = System::Drawing::Color::White;
			this->contact_no->Location = System::Drawing::Point(160, 71);
			this->contact_no->Name = L"contact_no";
			this->contact_no->Size = System::Drawing::Size(92, 20);
			this->contact_no->TabIndex = 13;
			this->contact_no->Text = L"Contact no:";
			// 
			// contact_id
			// 
			this->contact_id->AutoSize = true;
			this->contact_id->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->contact_id->ForeColor = System::Drawing::Color::White;
			this->contact_id->Location = System::Drawing::Point(160, 36);
			this->contact_id->Name = L"contact_id";
			this->contact_id->Size = System::Drawing::Size(89, 20);
			this->contact_id->TabIndex = 12;
			this->contact_id->Text = L"Contact ID:";
			// 
			// country_label
			// 
			this->country_label->AutoSize = true;
			this->country_label->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->country_label->ForeColor = System::Drawing::Color::LightGray;
			this->country_label->Location = System::Drawing::Point(42, 306);
			this->country_label->Name = L"country_label";
			this->country_label->Size = System::Drawing::Size(57, 16);
			this->country_label->TabIndex = 11;
			this->country_label->Text = L"Country";
			// 
			// city_label
			// 
			this->city_label->AutoSize = true;
			this->city_label->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->city_label->ForeColor = System::Drawing::Color::LightGray;
			this->city_label->Location = System::Drawing::Point(42, 273);
			this->city_label->Name = L"city_label";
			this->city_label->Size = System::Drawing::Size(31, 16);
			this->city_label->TabIndex = 10;
			this->city_label->Text = L"City";
			// 
			// street_label
			// 
			this->street_label->AutoSize = true;
			this->street_label->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->street_label->ForeColor = System::Drawing::Color::LightGray;
			this->street_label->Location = System::Drawing::Point(42, 243);
			this->street_label->Name = L"street_label";
			this->street_label->Size = System::Drawing::Size(43, 16);
			this->street_label->TabIndex = 9;
			this->street_label->Text = L"Street";
			// 
			// house_label
			// 
			this->house_label->AutoSize = true;
			this->house_label->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->house_label->ForeColor = System::Drawing::Color::LightGray;
			this->house_label->Location = System::Drawing::Point(41, 216);
			this->house_label->Name = L"house_label";
			this->house_label->Size = System::Drawing::Size(46, 16);
			this->house_label->TabIndex = 8;
			this->house_label->Text = L"House";
			// 
			// address_label
			// 
			this->address_label->AutoSize = true;
			this->address_label->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->address_label->ForeColor = System::Drawing::Color::White;
			this->address_label->Location = System::Drawing::Point(40, 180);
			this->address_label->Name = L"address_label";
			this->address_label->Size = System::Drawing::Size(68, 20);
			this->address_label->TabIndex = 3;
			this->address_label->Text = L"Address";
			// 
			// email_label
			// 
			this->email_label->AutoSize = true;
			this->email_label->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->email_label->ForeColor = System::Drawing::Color::LightGray;
			this->email_label->Location = System::Drawing::Point(41, 107);
			this->email_label->Name = L"email_label";
			this->email_label->Size = System::Drawing::Size(52, 20);
			this->email_label->TabIndex = 2;
			this->email_label->Text = L"Email:";
			// 
			// contact_no_label
			// 
			this->contact_no_label->AutoSize = true;
			this->contact_no_label->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->contact_no_label->ForeColor = System::Drawing::Color::LightGray;
			this->contact_no_label->Location = System::Drawing::Point(41, 71);
			this->contact_no_label->Name = L"contact_no_label";
			this->contact_no_label->Size = System::Drawing::Size(92, 20);
			this->contact_no_label->TabIndex = 1;
			this->contact_no_label->Text = L"Contact no:";
			// 
			// contact_id_label
			// 
			this->contact_id_label->AutoSize = true;
			this->contact_id_label->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->contact_id_label->ForeColor = System::Drawing::Color::LightGray;
			this->contact_id_label->Location = System::Drawing::Point(41, 36);
			this->contact_id_label->Name = L"contact_id_label";
			this->contact_id_label->Size = System::Drawing::Size(89, 20);
			this->contact_id_label->TabIndex = 0;
			this->contact_id_label->Text = L"Contact ID:";
			// 
			// back
			// 
			this->back->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back.Image")));
			this->back->Location = System::Drawing::Point(42, 14);
			this->back->Name = L"back";
			this->back->Size = System::Drawing::Size(27, 22);
			this->back->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->back->TabIndex = 4;
			this->back->TabStop = false;
			this->back->Click += gcnew System::EventHandler(this, &Contact_details::back_Click);
			// 
			// delete_button
			// 
			this->delete_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->delete_button->BackColor = System::Drawing::Color::Transparent;
			this->delete_button->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->delete_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delete_button->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delete_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->delete_button->Location = System::Drawing::Point(66, 386);
			this->delete_button->Name = L"delete_button";
			this->delete_button->Padding = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->delete_button->Size = System::Drawing::Size(152, 33);
			this->delete_button->TabIndex = 18;
			this->delete_button->Text = L"Delete Contact";
			this->delete_button->UseVisualStyleBackColor = false;
			this->delete_button->Click += gcnew System::EventHandler(this, &Contact_details::delete_button_Click);
			// 
			// Contact_details
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(727, 441);
			this->Controls->Add(this->delete_button);
			this->Controls->Add(this->back);
			this->Controls->Add(this->info);
			this->Controls->Add(this->full_name);
			this->Controls->Add(this->contact_img);
			this->Name = L"Contact_details";
			this->Text = L"Contact_details";
			this->Load += gcnew System::EventHandler(this, &Contact_details::Contact_details_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->contact_img))->EndInit();
			this->info->ResumeLayout(false);
			this->info->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Contact_details_Load(System::Object^ sender, System::EventArgs^ e) {
		full_name->Text = f_name;
		contact_id->Text = id.ToString();
		email->Text = email_id;
		contact_no->Text = mobile_no;
		house_no->Text = house;
		street_no->Text = street;
		city->Text = city_;
		country->Text = country_;
	}
	
	System::Void delete_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (MessageBox::Show("Delete contact?", "Confirmation", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			// Delete the selected contact from the Contacts Book
			bptr->delete_contact(bptr->get_contact(id).get_first_name(), bptr->get_contact(id).get_last_name());
			deleted = true;
			Contact_details::Close();
		}
	}
	public:
		// Mechanism to let the other contact know if a contact has been deleted
		void set_deleted(bool val)
		{
			deleted = val;
		}
		bool get_deleted()
		{
			return deleted;
		}

		void hide_delete()
		{
			delete_button->Enabled = false;
			delete_button->Hide();
		}

private: System::Void back_Click(System::Object^ sender, System::EventArgs^ e) {
	Contact_details::Close();
}
};
}
